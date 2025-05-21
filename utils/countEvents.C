#include <TChain.h>
#include <TSystem.h>
#include <TSystemDirectory.h>
#include <TList.h>
#include <TSystemFile.h>

void addAllRootsRecursively(TChain& chain, const char* dirpath) {
    TSystemDirectory dir(dirpath, dirpath);
    TList* files = dir.GetListOfFiles();
    if (!files) return;

    TIter next(files);
    TSystemFile* file;
    while ((file = (TSystemFile*)next())) {
        TString name = file->GetName();
        if (name == "." || name == "..") continue;

        TString full = TString(dirpath) + "/" + name;
        if (file->IsDirectory()) {
            // 하위 디렉토리도 재귀
            addAllRootsRecursively(chain, full.Data());
        }
        else if (name.EndsWith(".root")) {
            chain.Add(full.Data());
        }
    }
    delete files;
}

// 사용 예시
void countEvents(const char* pattern = "data/", const char* treeName = "Events") {
    TChain chain(treeName);
    addAllRootsRecursively(chain, pattern);
    std::cout << "Total entries: " << chain.GetEntries() << std::endl;
}
