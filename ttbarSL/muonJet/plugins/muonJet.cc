#include <memory>
#include <mutex>
#include <array>
#include <iostream>
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/one/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Utilities/interface/InputTag.h"
#include "SimDataFormats/GeneratorProducts/interface/GenEventInfoProduct.h" 
#include "DataFormats/PatCandidates/interface/Muon.h"

#include "DataFormats/Math/interface/LorentzVector.h"
#include "DataFormats/MuonReco/interface/MuonSelectors.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "TFile.h"
#include "TTree.h"
#include <cstdlib>
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "TSystem.h"

class muonJet : public edm::one::EDAnalyzer<> {
public:
  explicit muonJet(const edm::ParameterSet&);
  ~muonJet() override;

  static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

private:
  void beginJob() override;
  void analyze(const edm::Event&, const edm::EventSetup&) override;
  void endJob() override;

  // ----------member data ---------------------------
  edm::EDGetTokenT<pat::MuonCollection> muonToken_;
  edm::EDGetTokenT<pat::JetCollection> jetToken_;
  edm::EDGetTokenT<reco::GenParticleCollection> genParticleToken_;
  edm::EDGetTokenT<reco::GenJetCollection> genJetToken_;
  edm::EDGetTokenT<GenEventInfoProduct> generatorToken_;

  std::vector<short> Muon_charge;
  std::vector<double> Muon_pt;
  std::vector<double> Muon_eta;
  std::vector<double> Muon_phi;
  std::vector<double> Muon_mass;
  std::vector<short> Muon_jetIdx;
  std::vector<short> Muon_genPartIdx;

  std::vector<double> Jet_pt;
  std::vector<double> Jet_eta;
  std::vector<double> Jet_phi;
  std::vector<double> Jet_mass;
  std::vector<double> Jet_muEF;
  std::vector<std::vector<short>> Jet_muonIdx;
  std::vector<short> Jet_genJetIdx;

  std::vector<double> GenPart_pdgId;
  std::vector<short> GenPart_charge;
  std::vector<double> GenPart_pt;
  std::vector<double> GenPart_eta;
  std::vector<double> GenPart_phi;
  std::vector<double> GenPart_iso;
  std::vector<double> GenPart_mass;
  std::vector<short> GenPart_genJetIdx;

  std::vector<double> GenJet_pt;
  std::vector<double> GenJet_eta;
  std::vector<double> GenJet_phi;
  std::vector<double> GenJet_mass;
  std::vector<double> GenJet_muEF;
  std::vector<std::vector<short>> GenJet_genMuonIdx;

};


muonJet::muonJet(const edm::ParameterSet& iConfig)
  : muonToken_(consumes<pat::MuonCollection>(iConfig.getParameter<edm::InputTag>("muons"))),
    jetToken_(consumes<pat::JetCollection>(iConfig.getParameter<edm::InputTag>("jets"))),
    genParticleToken_(consumes<reco::GenParticleCollection>(iConfig.getParameter<edm::InputTag>("genParticles"))),
    genParticleToken_(consumes<reco::GenJetCollection>(iConfig.getParameter<edm::InputTag>("genJets"))),  
    generatorToken_(consumes<GenEventInfoProduct>(iConfig.getParameter<edm::InputTag>("generator"))){
}


muonJet::~muonJet() {
}

// ------------ method called once each job just before starting event loop  ------------
void muonJet::beginJob() {
  // Create a new TTree named "Events"
  TTree* tree = new TTree("Events", "Events");
  
  // Add branches for the variables
  tree->Branch("Muon_pt", &Muon_pt);
  tree->Branch("Muon_eta", &Muon_eta);
  tree->Branch("Muon_phi", &Muon_phi);
  tree->Branch("Muon_mass", &Muon_mass);
  tree->Branch("Muon_jetIdx", &Muon_jetIdx);
  tree->Branch("Muon_genPartIdx", &Muon_genPartIdx);

  tree->Branch("Jet_pt", &Jet_pt);
  tree->Branch("Jet_eta", &Jet_eta);
  tree->Branch("Jet_phi", &Jet_phi);
  tree->Branch("Jet_mass", &Jet_mass);
  tree->Branch("Jet_muEF", &Jet_muEF);
  tree->Branch("Jet_muonIdx", &Jet_muonIdx);
  tree->Branch("Jet_genJetIdx", &Jet_genJetIdx);

  tree->Branch("GenPart_pdgId", &GenPart_pdgId);
  tree->Branch("GenPart_charge", &GenPart_charge);
  tree->Branch("GenPart_pt", &GenPart_pt);
  tree->Branch("GenPart_eta", &GenPart_eta);
  tree->Branch("GenPart_phi", &GenPart_phi);
  tree->Branch("GenPart_iso", &GenPart_iso);
  tree->Branch("GenPart_mass", &GenPart_mass);
  tree->Branch("GenPart_genJetIdx", &GenPart_genJetIdx);

  tree->Branch("GenJet_pt", &GenJet_pt);
  tree->Branch("GenJet_eta", &GenJet_eta);
  tree->Branch("GenJet_phi", &GenJet_phi);
  tree->Branch("GenJet_mass", &GenJet_mass);
  tree->Branch("GenJet_muEF", &GenJet_muEF);
  tree->Branch("GenJet_genMuonIdx", &Jet_genMuonIdx); 
}


// ------------ method called for each event  ------------
void muonJet::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup) {
  using namespace edm;

  for (const auto& track : iEvent.get(tracksToken_)) {
    // do something with track parameters, e.g, plot the charge.
    // int charge = track.charge();
  }

}


// ------------ method called once each job just after ending the event loop  ------------
void muonJet::endJob() {
  // please remove this method if not needed
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void muonJet::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.add<edm::InputTag>("muons", edm::InputTag("muons"));
  desc.add<edm::InputTag>("jets", edm::InputTag("jets"));
  desc.add<edm::InputTag>("genParticles", edm::InputTag("genParticles"));
  desc.add<edm::InputTag>("generator", edm::InputTag("generator"));
  descriptions.add("muonJet", desc);
  //Specify that only 'tracks' is allowed
  //To use, remove the default given above and uncomment below
  //edm::ParameterSetDescription desc;
  //desc.addUntracked<edm::InputTag>("tracks", edm::InputTag("ctfWithMaterialTracks"));
  //descriptions.addWithDefaultLabel(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(muonJet);
