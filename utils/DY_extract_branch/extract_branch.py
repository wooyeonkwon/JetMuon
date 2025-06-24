import os, glob
import ROOT
from concurrent.futures import ProcessPoolExecutor, as_completed
import gc
# ROOT의 ImplicitMT 활성화는 각 프로세스에서 필요하다면 개별적으로 호출할 수 있음
#ROOT.ROOT.EnableImplicitMT()

# 2. 입력: 폴더 리스트와 추출할 tree/branch 리스트
folder_patterns = [ "/data1/users/dndus0107/skimmed_data/crab_DYto2L-2Jets_MLL-50_2J/250521_085436/0000/"
                   ]
directoy_list =["muonJet"]
branch_list = [
    "Events/GenWeight",

    "Events/Jet_pt", 
    "Events/Jet_eta",

    "Events/Jet_chHadEF",
    "Events/Jet_photonEF",
    "Events/Jet_neuHadEF",
    "Events/Jet_eleEF",
    "Events/Jet_muEF",
    "Events/Jet_ID",
    "Events/Jet_idxBacktoBack"

]
output_path = './crab_DYto2L-2Jets_MLL-50_2J/250521_085436/'
if not os.path.exists(output_path):
    os.makedirs(output_path)

# 2. 필터링 함수 정의 (필요시)
def Filter(df):
    df = df.Filter(f"""
                    if (Jet_pt.size() < 2) return false;
                    int nGoodJets = 0; 
                    for (size_t i = 0; i < Jet_pt.size(); ++i) {{
                        if ((Jet_pt[i] > 56) && (Jet_pt[i] < 74) && (std::fabs(Jet_eta[i]) < 2.5) && Jet_ID[i] > 1) nGoodJets++;
                    }}
                    if (nGoodJets > 1) return true;
                    else{{
                        return false;
                    }} 
                    """)
    
    df = df.Define("Jet_idxBacktoBack",f"""
                    std::vector<int> BacktoBack;
                    for (size_t i = 0; i < Jet_pt.size(); ++i) {{
                        if ((Jet_pt[i] > 56) && (Jet_pt[i] < 74) && (std::fabs(Jet_eta[i]) < 2.5) && Jet_ID[i] > 1){{
                            continue;
                        }}
                        for(size_t j = i + 1; j < Jet_pt.size(); ++j){{
                            if ((Jet_pt[j] > 56) && (Jet_pt[j] < 74) && (std::fabs(Jet_eta[j]) < 2.5) && Jet_ID[j] > 1){{
                                continue;
                            }}                            
                            if (std::fabs(Jet_phi[i] - Jet_phi[j]) > 2.7) {{
                                BacktoBack.push_back(i);
                                BacktoBack.push_back(j);
                                break;
                            }}
                        }}
                        if (BacktoBack.size() > 0) break;
                    }}
                    return BacktoBack;
                    """)
    df = df.Filter(f"""
                    if (Jet_idxBacktoBack.size() > 0) return true;
                    else return false;
                    """)
    return df

# 3. branch_list를 tree별로 그룹화
tree_branches = {}
for tb in branch_list:
    try:
        tree, branch = tb.split("/")
    except ValueError:
        print(f"입력 형식 오류: '{tb}'는 'tree/branch' 형식이어야 합니다.")
        continue
    tree_branches.setdefault(tree, []).append(branch)

# 4. output_path의 마지막 폴더 이름 ("Run3Summer22NanoAODv12") 추출
output_last = os.path.basename(os.path.normpath(output_path))

# 5. 폴더 패턴 확장: 각 폴더에서 ROOT 파일과 하위 폴더(QCD*; depth 1) 추출
root_files = []
file_subfolders = {}  # 각 파일에 대해 하위 폴더명 저장

for folder_pattern in folder_patterns:
    actual_folders = glob.glob(folder_pattern)
    for folder in actual_folders:
        if os.path.isdir(folder):
            parts = os.path.normpath(folder).split(os.path.sep)
            subfolder = ""
            if output_last in parts:
                idx = parts.index(output_last)
                if idx + 1 < len(parts):
                    subfolder = parts[idx + 1]  # depth 1만 사용
            root_files_in_folder = glob.glob(os.path.join(folder, "*.root"))
            root_files.extend(root_files_in_folder)
            for file in root_files_in_folder:
                file_subfolders[file] = subfolder

if not root_files:
    print("입력 폴더에 ROOT 파일이 없습니다.")
    exit(1)

# 6. 파일 단위 Snapshot 작업 함수 (각 프로세스에서 호출)
def process_file(args):
    file, tree, branches, output_path, file_subfolders = args
    try:
        # 각 worker 프로세스에서 ROOT 초기화 (필요시)
#        ROOT.ROOT.EnableImplicitMT()
        if (directoy_list != []):
            tree = directoy_list[0]  + "/" +  tree
            print (tree)

        df = ROOT.RDataFrame(tree, file)
        df = Filter(df)
        
        subfolder = file_subfolders.get(file, "")
        if subfolder:
            out_dir = os.path.join(output_path, subfolder)
            if not os.path.exists(out_dir):
                os.makedirs(out_dir)
        else:
            out_dir = output_path
        base = os.path.basename(file)
        out_file = os.path.join(out_dir, base)
        df.Snapshot(tree, out_file, branches)
        
        gc.collect()
        return file  # 성공적으로 처리된 파일 반환

    except Exception as e:
        # 에러 발생 시 로그 기록 후 None 반환
        log_message = f"Error processing {file}: {e}\n"
        with open('error_log.txt', 'a') as log_file:
            log_file.write(log_message)
        return None

# 7. 메인 프로세스에서 실패한 파일 목록을 관리하여 중복 시도 방지
failed_files = set()

# tree별로 병렬 처리 (동일 파일이 여러 tree에서 재시도되는 것을 방지)
for tree, branches in tree_branches.items():
    print(f"Processing tree '{tree}' with branches: {branches}")
    # 이전에 실패한 파일은 제외
    files_to_process = [f for f in root_files if f not in failed_files]
    tasks = [(file, tree, branches, output_path, file_subfolders) for file in files_to_process]
    
    with ProcessPoolExecutor(max_workers=255) as executor:
        future_to_file = {executor.submit(process_file, task): task[0] for task in tasks}
        for future in as_completed(future_to_file):
            file_result = future.result()
            if file_result is not None:
                print(f"Processed: {file_result}")
            else:
                failed_file = future_to_file[future]
                print(f"Skipped file due to error: {failed_file}")
                failed_files.add(failed_file)