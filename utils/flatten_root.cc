#include <ROOT/RDataFrame.hxx>
#include <ROOT/RVec.hxx>
#include <TFile.h>
#include <TTree.h>
#include <iostream>

int main() {
    ROOT::EnableImplicitMT();

    const std::string inputFileName = "/data1/users/dndus0107/skimmed_data/WWtoLNu2Q_TuneCP5_13p6TeV_powheg-pythia8_9.root";
    const std::string treeName = "muonJet/Events";
    ROOT::RDataFrame df(treeName, inputFileName);

    // Jet 개수 정의
    auto dfWithNJets = df.Define("nJets", "Jet_pt.size()");

    // Jet 인덱스 벡터 생성
    auto dfWithJetIndex = dfWithNJets.Define("Jet_index", "ROOT::VecOps::RVec<int> idx(nJets); std::iota(idx.begin(), idx.end(), 0); return idx;");

    // Jet 정보를 평탄화하여 새로운 RDataFrame 생성
    auto dfFlat = dfWithJetIndex
        .Define("Jet_pt_flat", "Jet_pt")
        .Define("Jet_eta_flat", "Jet_eta")
        .Define("Jet_phi_flat", "Jet_phi")
        .Define("Jet_mass_flat", "Jet_mass")
        .Define("Jet_energy_flat", "Jet_energy")
        .Define("Jet_chHadEF_flat", "Jet_chHadEF")
        .Define("Jet_photonEF_flat", "Jet_photonEF")
        .Define("Jet_neuHadEF_flat", "Jet_neuHadEF")
        .Define("Jet_eleEF_flat", "Jet_eleEF")
        .Define("Jet_muEF_flat", "Jet_muEF")
        .Define("Jet_genJetIdx_flat", "Jet_genJetIdx")
        .Define("Jet_muonMultiplicity_flat", "Jet_muonMultiplicity")
        .Define("Jet_ID_flat", "Jet_ID")
        .Define("Jet_index_flat", "Jet_index");

    // 평탄화된 데이터를 새로운 TTree로 저장
    dfFlat.Snapshot("JetTree", "flattened.root", {
        "Jet_pt_flat", "Jet_eta_flat", "Jet_phi_flat", "Jet_mass_flat", "Jet_energy_flat",
        "Jet_chHadEF_flat", "Jet_photonEF_flat", "Jet_neuHadEF_flat", "Jet_eleEF_flat", "Jet_muEF_flat",
        "Jet_genJetIdx_flat", "Jet_muonMultiplicity_flat", "Jet_ID_flat", "Jet_index_flat"
    });

    std::cout << "Flattened ROOT file 'flattened.root' has been created." << std::endl;

    return 0;
}
