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
#include "DataFormats/PatCandidates/interface/Jet.h"
#include "DataFormats/PatCandidates/interface/PackedGenParticle.h"
#include "DataFormats/PatCandidates/interface/PackedCandidate.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/HepMCCandidate/interface/GenParticleFwd.h"
#include "DataFormats/JetReco/interface/GenJet.h"
#include "DataFormats/JetReco/interface/GenJetCollection.h"
#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/Math/interface/LorentzVector.h"
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

  TTree* tree;

  // ----------member data ---------------------------
  edm::EDGetTokenT<pat::PackedCandidateCollection> packedCandidateToken_;
  edm::EDGetTokenT<pat::MuonCollection> muonToken_;
  edm::EDGetTokenT<pat::JetCollection> jetToken_;
  edm::EDGetTokenT<pat::PackedGenParticleCollection> packedGenParticleToken_;
  edm::EDGetTokenT<reco::GenParticleCollection> genParticleToken_;
  edm::EDGetTokenT<reco::GenJetCollection> genJetToken_;
  edm::EDGetTokenT<edm::Association<reco::GenParticleCollection>> packedPFCandidateToGenAssociationToken_;
  edm::EDGetTokenT<edm::Association<pat::PackedGenParticleCollection>> packedPFCandidateToPackedGenAssociationToken_;
  edm::EDGetTokenT<GenEventInfoProduct> generatorToken_;

  unsigned long long EventNumber;
  float GenWeight;

  std::vector<short> PackedMuon_charge;
  std::vector<double> PackedMuon_pt;
  std::vector<double> PackedMuon_eta;
  std::vector<double> PackedMuon_phi;
  std::vector<double> PackedMuon_mass;
  std::vector<int> PackedMuon_genPartIdx;
  std::vector<int> PackedMuon_packedGenPartIdx;

  std::vector<short> Muon_charge;
  std::vector<double> Muon_pt;
  std::vector<double> Muon_eta;
  std::vector<double> Muon_phi;
  std::vector<double> Muon_mass;
  std::vector<int> Muon_genPartIdx;

  std::vector<double> Jet_pt;
  std::vector<double> Jet_eta;
  std::vector<double> Jet_phi;
  std::vector<double> Jet_mass;
  std::vector<double> Jet_muEF;
  std::vector<std::vector<int>> Jet_packedMuonIdx;
  std::vector<int> OneJet_packedMuonIdx;
  std::vector<int> Jet_genJetIdx;
  std::vector<int> Jet_muonMultiplicity;

  std::vector<double> PackedGenPart_pdgId;
  std::vector<short> PackedGenPart_charge;
  std::vector<double> PackedGenPart_pt;
  std::vector<double> PackedGenPart_eta;
  std::vector<double> PackedGenPart_phi;
  std::vector<double> PackedGenPart_mass;

  std::vector<double> GenPart_pdgId;
  std::vector<short> GenPart_charge;
  std::vector<double> GenPart_pt;
  std::vector<double> GenPart_eta;
  std::vector<double> GenPart_phi;
  std::vector<double> GenPart_mass;

  std::vector<double> GenJet_pt;
  std::vector<double> GenJet_eta;
  std::vector<double> GenJet_phi;
  std::vector<double> GenJet_mass;
  std::vector<double> GenJet_muEF;
  std::vector<std::vector<int>> GenJet_packedGenMuonIdx;
  std::vector<int> OneGenJet_packedGenMuonIdx;
  std::vector<int> GenJet_muonMultiplicity;

};


muonJet::muonJet(const edm::ParameterSet& iConfig)
  : packedCandidateToken_(consumes<pat::PackedCandidateCollection>(iConfig.getParameter<edm::InputTag>("packedMuons"))),
    muonToken_(consumes<pat::MuonCollection>(iConfig.getParameter<edm::InputTag>("muons"))),
    jetToken_(consumes<pat::JetCollection>(iConfig.getParameter<edm::InputTag>("jets"))),
    packedGenParticleToken_(consumes<pat::PackedGenParticleCollection>(iConfig.getParameter<edm::InputTag>("packedGenParticles"))),
    genParticleToken_(consumes<reco::GenParticleCollection>(iConfig.getParameter<edm::InputTag>("genParticles"))),
    genJetToken_(consumes<reco::GenJetCollection>(iConfig.getParameter<edm::InputTag>("genJets"))),
    packedPFCandidateToGenAssociationToken_(consumes<edm::Association<reco::GenParticleCollection>>(iConfig.getParameter<edm::InputTag>("pfToGenAssoc"))),
    packedPFCandidateToPackedGenAssociationToken_(consumes<edm::Association<pat::PackedGenParticleCollection>>(iConfig.getParameter<edm::InputTag>("pfToPackedGenAssoc"))),
    generatorToken_(consumes<GenEventInfoProduct>(iConfig.getParameter<edm::InputTag>("generator"))){
}


muonJet::~muonJet() {
}

// ------------ method called once each job just before starting event loop  ------------
void muonJet::beginJob() {
  // Create a new TTree named "Events"
  edm::Service<TFileService> fs;
  tree = fs->make<TTree>("Events", "Events");

  
  // Add branches for the variables
  tree->Branch("EventNumber", &EventNumber, "EventNumber/l");
  tree->Branch("GenWeight", &GenWeight, "GenWeight/F");

  tree->Branch("PackedMuon_charge", &PackedMuon_charge);
  tree->Branch("PackedMuon_pt", &PackedMuon_pt);
  tree->Branch("PackedMuon_eta", &PackedMuon_eta);
  tree->Branch("PackedMuon_phi", &PackedMuon_phi);
  tree->Branch("PackedMuon_mass", &PackedMuon_mass);
  tree->Branch("PackedMuon_genPartIdx", &PackedMuon_genPartIdx);
  tree->Branch("PackedMuon_packedGenPartIdx", &PackedMuon_packedGenPartIdx);
  
  tree->Branch("Muon_charge", &Muon_charge);
  tree->Branch("Muon_pt", &Muon_pt);
  tree->Branch("Muon_eta", &Muon_eta);
  tree->Branch("Muon_phi", &Muon_phi);
  tree->Branch("Muon_mass", &Muon_mass);
  tree->Branch("Muon_genPartIdx", &Muon_genPartIdx);

  tree->Branch("Jet_pt", &Jet_pt);
  tree->Branch("Jet_eta", &Jet_eta);
  tree->Branch("Jet_phi", &Jet_phi);
  tree->Branch("Jet_mass", &Jet_mass);
  tree->Branch("Jet_muEF", &Jet_muEF);
  tree->Branch("Jet_packedMuonIdx", &Jet_packedMuonIdx);
  tree->Branch("Jet_genJetIdx", &Jet_genJetIdx);
  tree->Branch("Jet_muonMultiplicity", &Jet_muonMultiplicity);

  tree->Branch("PackedGenPart_pdgId", &PackedGenPart_pdgId);
  tree->Branch("PackedGenPart_charge", &PackedGenPart_charge);
  tree->Branch("PackedGenPart_pt", &PackedGenPart_pt);
  tree->Branch("PackedGenPart_eta", &PackedGenPart_eta);
  tree->Branch("PackedGenPart_phi", &PackedGenPart_phi);
  tree->Branch("PackedGenPart_mass", &PackedGenPart_mass);

  tree->Branch("GenPart_pdgId", &GenPart_pdgId);
  tree->Branch("GenPart_charge", &GenPart_charge);
  tree->Branch("GenPart_pt", &GenPart_pt);
  tree->Branch("GenPart_eta", &GenPart_eta);
  tree->Branch("GenPart_phi", &GenPart_phi);
  tree->Branch("GenPart_mass", &GenPart_mass);
  
  tree->Branch("GenJet_pt", &GenJet_pt);
  tree->Branch("GenJet_eta", &GenJet_eta);
  tree->Branch("GenJet_phi", &GenJet_phi);
  tree->Branch("GenJet_mass", &GenJet_mass);
  tree->Branch("GenJet_muEF", &GenJet_muEF);
  tree->Branch("GenJet_packedGenMuonIdx", &GenJet_packedGenMuonIdx);
  tree->Branch("GenJet_muonMultiplicity", &GenJet_muonMultiplicity);
}


// ------------ method called for each event  ------------
void muonJet::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup) {
  //get tokens
  edm::Handle<pat::PackedCandidateCollection> packedMuons;
  edm::Handle<pat::MuonCollection> muons;
  edm::Handle<pat::JetCollection> jets;
  edm::Handle<pat::PackedGenParticleCollection> packedGenParticles;
  edm::Handle<reco::GenParticleCollection> genParticles;
  edm::Handle<reco::GenJetCollection> genJets;
  edm::Handle<GenEventInfoProduct> generator;
  edm::Handle<edm::Association<reco::GenParticleCollection>> pfToGenAssoc;
  edm::Handle<edm::Association<pat::PackedGenParticleCollection>> pfToPackedGenAssoc;
  iEvent.getByToken(packedCandidateToken_, packedMuons);
  iEvent.getByToken(muonToken_, muons);
  iEvent.getByToken(jetToken_, jets);
  iEvent.getByToken(packedGenParticleToken_, packedGenParticles);
  iEvent.getByToken(genParticleToken_, genParticles);
  iEvent.getByToken(genJetToken_, genJets);
  iEvent.getByToken(generatorToken_, generator);
  iEvent.getByToken(packedPFCandidateToGenAssociationToken_, pfToGenAssoc);
  iEvent.getByToken(packedPFCandidateToPackedGenAssociationToken_, pfToPackedGenAssoc);
  
  // clear all vectors
  PackedMuon_charge.clear();
  PackedMuon_pt.clear();
  PackedMuon_eta.clear();
  PackedMuon_phi.clear();
  PackedMuon_mass.clear();
  PackedMuon_genPartIdx.clear();
  PackedMuon_packedGenPartIdx.clear();

  Muon_charge.clear();
  Muon_pt.clear();
  Muon_eta.clear();
  Muon_phi.clear();
  Muon_mass.clear();
  Muon_genPartIdx.clear();

  Jet_pt.clear();
  Jet_eta.clear();
  Jet_phi.clear();
  Jet_mass.clear();
  Jet_muEF.clear();
  Jet_packedMuonIdx.clear();
  Jet_genJetIdx.clear();
  Jet_muonMultiplicity.clear();

  PackedGenPart_pdgId.clear();
  PackedGenPart_charge.clear();
  PackedGenPart_pt.clear();
  PackedGenPart_eta.clear();
  PackedGenPart_phi.clear();
  PackedGenPart_mass.clear();

  GenPart_pdgId.clear();
  GenPart_charge.clear();
  GenPart_pt.clear();
  GenPart_eta.clear();
  GenPart_phi.clear();
  GenPart_mass.clear();

  GenJet_pt.clear();
  GenJet_eta.clear();
  GenJet_phi.clear();
  GenJet_mass.clear();
  GenJet_muEF.clear();
  GenJet_packedGenMuonIdx.clear();
  GenJet_muonMultiplicity.clear();

  //packedMuon
  for (const auto& packedMuon : *packedMuons) {
    if (!packedMuon.isMuon()) continue;
    PackedMuon_charge.push_back(packedMuon.charge());
    PackedMuon_pt.push_back(packedMuon.pt());
    PackedMuon_eta.push_back(packedMuon.eta());
    PackedMuon_phi.push_back(packedMuon.phi());
    PackedMuon_mass.push_back(packedMuon.mass());
    
    // PackedMuon_genPartIdx
    int genPartIdx = -1;
    int gPartIdx = 0;
    edm::Ptr<pat::PackedCandidate> packedMuonPtr(packedMuons, &packedMuon - &packedMuons->front());
    reco::GenParticleRef genPartRef = (*pfToGenAssoc)[packedMuonPtr];
    if (genPartRef.isNonnull()) {
      for (const auto& genPart : *genParticles) {
        if (!(std::fabs(genPart.pdgId()) == 13)) continue;
        if (&genPart == genPartRef.get()){
          genPartIdx = gPartIdx;
          break;
        }
        gPartIdx++;
      }
    }
    PackedMuon_genPartIdx.push_back(genPartIdx);

    // PackedMuon_packedGenPartIdx
    int packedGenPartIdx = -1;
    int pGPartIdx = 0;
    pat::PackedGenParticleRef packedGenPartRef = (*pfToPackedGenAssoc)[packedMuonPtr];
    if (packedGenPartRef.isNonnull()) {
      for (const auto& packedGenPart : *packedGenParticles) {
        if (!(std::fabs(packedGenPart.pdgId()) == 13)) continue;
        if (&packedGenPart == packedGenPartRef.get()){
          packedGenPartIdx = pGPartIdx;
          break;
        }
        pGPartIdx++;
      }
    }
    PackedMuon_packedGenPartIdx.push_back(packedGenPartIdx);    

  }


  //Muon
  for (const auto& muon : *muons) {
    Muon_charge.push_back(muon.charge());
    Muon_pt.push_back(muon.pt());
    Muon_eta.push_back(muon.eta());
    Muon_phi.push_back(muon.phi());
    Muon_mass.push_back(muon.mass());

    int genPartIdx = -1;
    int gPartIdx = 0;
    const reco::GenParticle* cand = nullptr;
    cand = muon.genParticle();
    const auto* candMuon = dynamic_cast<const reco::GenParticle*>(cand);
    for (const auto& genPart : *genParticles) {
      if (!(std::fabs(genPart.pdgId()) == 13)) continue;
      if (&genPart == candMuon){
        genPartIdx = gPartIdx;
        break;
      }
      gPartIdx++;
    }
    Muon_genPartIdx.push_back(genPartIdx);
  }

  // Jet
  for (const auto &jet : *jets) {
    Jet_pt.push_back(jet.pt());
    Jet_eta.push_back(jet.eta());
    Jet_phi.push_back(jet.phi());
    Jet_mass.push_back(jet.mass());
    Jet_muEF.push_back(jet.muonEnergyFraction());
    Jet_muonMultiplicity.push_back(jet.muonMultiplicity());

    // Jet muon Index mathcing
    OneJet_packedMuonIdx.clear();
    // temp container for this jet
    
    for (auto daughter = jet.begin(); daughter != jet.end(); ++daughter) {
      int idxPackedMuon = -1;
      int idx = 0;
      if (jet.muonMultiplicity() == 0) continue;
      const reco::Candidate* constituent = nullptr;
      try {
        constituent = &*daughter;
      } catch (cms::Exception& e) {
        edm::LogWarning("muonJet") << "Failed to dereference daughter in jet: " << e.what();
        continue;
      }
      auto dau = constituent;
      for (const auto& packedMuon : *packedMuons) {
        if (!packedMuon.isMuon()) continue;
        if (&packedMuon == dau) {
          idxPackedMuon = idx;
          break;
        }
        idx++;
      }
      OneJet_packedMuonIdx.push_back(idxPackedMuon);      
    }
    if (OneJet_packedMuonIdx.empty()){
      OneJet_packedMuonIdx.push_back(-2);
    }
    Jet_packedMuonIdx.push_back(OneJet_packedMuonIdx);

    // genJet mathcing
    int genJetIndex = -1;
    if (jet.genJet() != nullptr) {
      int iJet = 0;
      for (const auto &genJet : *genJets) {
        if (jet.genJet() == &genJet){
          genJetIndex = iJet;
          break;
        }
        iJet++;
      }
    }
    Jet_genJetIdx.push_back(genJetIndex);
  }

  //PackedGenPart
  for (const auto& packedGenPart : *packedGenParticles) {
    if (!(std::fabs(packedGenPart.pdgId()) == 13)) continue; 
    PackedGenPart_pdgId.push_back(packedGenPart.pdgId());
    PackedGenPart_charge.push_back(packedGenPart.charge());
    PackedGenPart_pt.push_back(packedGenPart.pt());
    PackedGenPart_eta.push_back(packedGenPart.eta());
    PackedGenPart_phi.push_back(packedGenPart.phi());
    PackedGenPart_mass.push_back(packedGenPart.mass());
  }

  //GenPart
  for (const auto& genPart : *genParticles) {
    if (!(std::fabs(genPart.pdgId()) == 13)) continue; 
    GenPart_pdgId.push_back(genPart.pdgId());
    GenPart_charge.push_back(genPart.charge());
    GenPart_pt.push_back(genPart.pt());
    GenPart_eta.push_back(genPart.eta());
    GenPart_phi.push_back(genPart.phi());
    GenPart_mass.push_back(genPart.mass());
  }

  //GenJet
  for (const auto &genJet : *genJets) {
    GenJet_pt.push_back(genJet.pt());
    GenJet_eta.push_back(genJet.eta());
    GenJet_phi.push_back(genJet.phi());
    GenJet_mass.push_back(genJet.mass());
    GenJet_muEF.push_back((genJet.muonEnergy()/genJet.energy()));
    GenJet_muonMultiplicity.push_back(genJet.muonMultiplicity());
    
    OneGenJet_packedGenMuonIdx.clear();
    // temp container for this jet
    for (auto daughter = genJet.begin(); daughter != genJet.end(); ++daughter) {
      const reco::Candidate* constituent = nullptr;
      try {
        constituent = &*daughter;
      } catch (cms::Exception& e) {
        //edm::LogWarning("muonJet") << "Failed to dereference daughter in genJet: " << e.what();
        continue;
      }
      if (!constituent) continue;
      const auto* dau = dynamic_cast<const pat::PackedGenParticle*>(constituent);
      if (!dau) continue;
      if (std::abs(dau->pdgId()) == 13) {
        int idxGenPart = -1;
        int idx = 0;
        for (const auto& packedGenPart : *packedGenParticles) {
          if (!(std::fabs(packedGenPart.pdgId()) == 13)) continue;
          if (&packedGenPart == dau) {
            idxGenPart = idx;
            break;
          }
          idx++;
        }
        OneGenJet_packedGenMuonIdx.push_back(idxGenPart);
      }      
    }
    if (OneGenJet_packedGenMuonIdx.empty()){
      OneGenJet_packedGenMuonIdx.push_back(-2);
    }
    GenJet_packedGenMuonIdx.push_back(OneGenJet_packedGenMuonIdx);
  }
  EventNumber = iEvent.id().event();
  GenWeight = generator->weight();
  tree->Fill();
}


// ------------ method called once each job just after ending the event loop  ------------
void muonJet::endJob() {
  // please remove this method if not needed
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void muonJet::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {

  edm::ParameterSetDescription desc;
  desc.add<edm::InputTag>("packedMuons", edm::InputTag("packedMuons"));
  desc.add<edm::InputTag>("muons", edm::InputTag("muons"));
  desc.add<edm::InputTag>("jets", edm::InputTag("jets"));
  desc.add<edm::InputTag>("packedGenParticles", edm::InputTag("packedGenParticles"));
  desc.add<edm::InputTag>("genParticles", edm::InputTag("genParticles"));
  desc.add<edm::InputTag>("genJets", edm::InputTag("genJets"));
  desc.add<edm::InputTag>("pfToGenAssoc", edm::InputTag("pfToGenAssoc"));
  desc.add<edm::InputTag>("pfToPackedGenAssoc", edm::InputTag("pfToPackedGenAssoc"));
  desc.add<edm::InputTag>("generator", edm::InputTag("generator"));
  descriptions.add("muonJet", desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(muonJet);
