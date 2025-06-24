import ROOT
from array import array

ROOT.EnableThreadSafety()
ROOT.EnableImplicitMT(255)

# 입력 ROOT 파일과 TTree 로드
input_file = ROOT.TFile.Open("/data1/users/dndus0107/skimmed_data/WWtoLNu2Q_TuneCP5_13p6TeV_powheg-pythia8/WWtoLNu2Q_TuneCP5_13p6TeV_powheg-pythia8_1.root")
input_tree = input_file.Get("muonJet/Events")

# 출력 ROOT 파일과 TTree 생성
output_file = ROOT.TFile("gen_WW_flattened.root", "RECREATE")
output_tree = ROOT.TTree("JetTree", "Flattened Jet Tree")

# Jet 속성에 해당하는 변수 정의
jet_pt = array('d', [0.])
jet_eta = array('d', [0.])
#jet_phi = array('d', [0.])
#jet_mass = array('d', [0.])
#jet_energy = array('d', [0.])
jet_chHadEF = array('f', [0.])
jet_photonEF = array('f', [0.])
jet_neuHadEF = array('f', [0.])
jet_eleEF = array('f', [0.])
jet_muEF = array('f', [0.])
#jet_genJetIdx = array('i', [0])
#jet_muonMultiplicity = array('i', [0])
#jet_ID = array('i', [0])
jet_btagPNetB = array('f', [0.])

# 브랜치 생성
output_tree.Branch("Jet_pt", jet_pt, "Jet_pt/D")
output_tree.Branch("Jet_eta", jet_eta, "Jet_eta/D")
#output_tree.Branch("Jet_phi", jet_phi, "Jet_phi/D")
#output_tree.Branch("Jet_mass", jet_mass, "Jet_mass/D")
#output_tree.Branch("Jet_energy", jet_energy, "Jet_energy/D")
output_tree.Branch("Jet_chHadEF", jet_chHadEF, "Jet_chHadEF/F")
output_tree.Branch("Jet_photonEF", jet_photonEF, "Jet_photonEF/F")
output_tree.Branch("Jet_neuHadEF", jet_neuHadEF, "Jet_neuHadEF/F")
output_tree.Branch("Jet_eleEF", jet_eleEF, "Jet_eleEF/F")
output_tree.Branch("Jet_muEF", jet_muEF, "Jet_muEF/F")
#output_tree.Branch("Jet_genJetIdx", jet_genJetIdx, "Jet_genJetIdx/I")
#output_tree.Branch("Jet_muonMultiplicity", jet_muonMultiplicity, "Jet_muonMultiplicity/I")
#output_tree.Branch("Jet_ID", jet_ID, "Jet_ID/I")
output_tree.Branch("Jet_btagPNetB", jet_btagPNetB, "Jet_btagPNetB/F")

# 이벤트 루프를 통해 각 Jet의 속성을 추출하여 새로운 TTree에 저장
for event in input_tree:
    nGoodJets = 0
    for idx in range(len(event.Jet_pt)):
        if ((event.Jet_ID[idx] < 1) or (event.Jet_pt[idx] < 30) or (abs(event.Jet_eta[idx]) > 2.4)):
                continue
        nGoodJets += 1
    if nGoodJets < 1:
        continue
    
    for idx in range(len(event.GenJet_pt)):
        jet_idx = event.GenJet_jetIdx[idx]

        if ((event.Jet_ID[jet_idx] < 1) or (event.Jet_pt[jet_idx] < 30)):
            continue
        if ((abs(event.Jet_eta[jet_idx]) > 2.5) and (abs(event.Jet_eta[jet_idx]) < 3.0) and (event.Jet_pt[jet_idx] < 50)) :
            continue
        if (abs(event.Jet_eta[jet_idx]) >= 3.0):
            continue
        if (event.Jet_Overlap[jet_idx] == 1):
            continue



        jet_pt[0] = event.GenJet_pt[idx]
        jet_eta[0] = event.GenJet_eta[idx]
        #jet_phi[0] = event.Jet_phi[idx]
        #jet_mass[0] = event.Jet_mass[idx]
        #jet_energy[0] = event.Jet_energy[idx]
        jet_chHadEF[0] = event.GenJet_chHadEF[idx]
        jet_photonEF[0] = event.GenJet_photonEF[idx]
        jet_neuHadEF[0] = event.GenJet_neuHadEF[idx]
        jet_eleEF[0] = event.GenJet_eleEF[idx]
        jet_muEF[0] = event.GenJet_muEF[idx]
        #jet_genJetIdx[0] = event.Jet_genJetIdx[idx]
        #jet_muonMultiplicity[0] = event.Jet_muonMultiplicity[idx]
        #jet_ID[0] = event.Jet_ID[idx]
        #jet_btagPNetB[0] = event.Jet_btagPNetB[idx]


        output_tree.Fill()

# 출력 파일 저장
output_file.Write()
output_file.Close()

