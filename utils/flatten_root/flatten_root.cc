#include <ROOT/TTreeProcessorMT.hxx>
#include <ROOT/TThreadedObject.hxx>
#include <TFile.h>
#include <TTree.h>
#include <TTreeReader.h>
#include <TTreeReaderArray.h>
#include <vector>
#include <cmath>
#include <mutex>

struct JetInfo {
    double pt;
    double eta;
    float chHadEF;
    float photonEF;
    float neuHadEF;
    float eleEF;
    float muEF;
};

int main() {
    ROOT::EnableImplicitMT();

    std::string input_file = "/data1/users/dndus0107/skimmed_data/TTtoLNu2Q_TuneCP5_13p6TeV_powheg-pythia8/TTtoLNu2Q_TuneCP5_13p6TeV_powheg-pythia8_6.root";
    std::string tree_name = "muonJet/Events";

    std::mutex mutex;
    std::vector<JetInfo> allJets;  // 최종 저장용 (모든 스레드 병합 결과)

    ROOT::TTreeProcessorMT proc(input_file, tree_name);
    proc.Process([&](TTreeReader &reader) {
        TTreeReaderArray<double> Jet_pt(reader, "Jet_pt");
        TTreeReaderArray<double> Jet_eta(reader, "Jet_eta");
        TTreeReaderArray<int>   Jet_ID(reader, "Jet_ID");

        TTreeReaderArray<double> GenJet_pt(reader, "GenJet_pt");
        TTreeReaderArray<double> GenJet_eta(reader, "GenJet_eta");
        TTreeReaderArray<float> GenJet_chHadEF(reader, "GenJet_chHadEF");
        TTreeReaderArray<float> GenJet_photonEF(reader, "GenJet_photonEF");
        TTreeReaderArray<float> GenJet_neuHadEF(reader, "GenJet_neuHadEF");
        TTreeReaderArray<float> GenJet_eleEF(reader, "GenJet_eleEF");
        TTreeReaderArray<float> GenJet_muEF(reader, "GenJet_muEF");
        TTreeReaderArray<int>   GenJet_jetIdx(reader, "GenJet_jetIdx");
        TTreeReaderArray<bool>   GenJet_overlap(reader, "GenJet_overlap");

        std::vector<JetInfo> localJets;

        while (reader.Next()) {
            int nGoodJets = 0;
            for (size_t i = 0; i < Jet_pt.GetSize(); ++i) {
                if (Jet_ID[i] >= 1 && Jet_pt[i] >= 30 && std::abs(Jet_eta[i]) <= 2.4)
                    ++nGoodJets;
            }
            if (nGoodJets < 1) continue;

            for (size_t idx = 0; idx < GenJet_pt.GetSize(); ++idx) {
                int jet_idx = GenJet_jetIdx[idx];
                if (jet_idx < 0 || jet_idx >= (int)Jet_ID.GetSize()) continue;

                float eta = std::abs(Jet_eta[jet_idx]);
                if (Jet_ID[jet_idx] < 1 || Jet_pt[jet_idx] < 30) continue;
                if ((eta > 2.5 && eta < 3.0 && Jet_pt[jet_idx] < 50) || eta >= 3.0) continue;
                if (GenJet_overlap[idx] == 1) continue;

                localJets.push_back({
                    GenJet_pt[idx],
                    GenJet_eta[idx],
                    GenJet_chHadEF[idx],
                    GenJet_photonEF[idx],
                    GenJet_neuHadEF[idx],
                    GenJet_eleEF[idx],
                    GenJet_muEF[idx]
                });
            }
        }

        // 스레드 병합
        std::scoped_lock lock(mutex);
        allJets.insert(allJets.end(), localJets.begin(), localJets.end());

        return true;
    });

    // 최종 저장
    TFile *fout = TFile::Open("gen_TT_flattened_mt.root", "RECREATE");
    TTree *tree = new TTree("JetTree", "Flattened Jet Tree");

    double pt;
    double eta;
    float chHadEF;
    float photonEF;
    float neuHadEF;
    float eleEF;
    float muEF;

    tree->Branch("Jet_pt", &pt, "Jet_pt/D");
    tree->Branch("Jet_eta", &eta, "Jet_eta/D");
    tree->Branch("Jet_chHadEF", &chHadEF, "Jet_chHadEF/F");
    tree->Branch("Jet_photonEF", &photonEF, "Jet_photonEF/F");
    tree->Branch("Jet_neuHadEF", &neuHadEF, "Jet_neuHadEF/F");
    tree->Branch("Jet_eleEF", &eleEF, "Jet_eleEF/F");
    tree->Branch("Jet_muEF", &muEF, "Jet_muEF/F");

    for (const auto& j : allJets) {
        pt = j.pt;
        eta = j.eta;
        chHadEF = j.chHadEF;
        photonEF = j.photonEF;
        neuHadEF = j.neuHadEF;
        eleEF = j.eleEF;
        muEF = j.muEF;
        tree->Fill();
    }

    fout->Write();
    fout->Close();

    return 0;
}
