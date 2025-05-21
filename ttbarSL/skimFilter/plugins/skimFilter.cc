// -*- C++ -*-

#include <memory>
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/stream/EDFilter.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/Framework/interface/ConsumesCollector.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Utilities/interface/StreamID.h"
#include "FWCore/Common/interface/TriggerNames.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/Electron.h"
//
// class declaration
//

class skimFilter : public edm::stream::EDFilter<> {
public:
  explicit skimFilter(const edm::ParameterSet&);
  ~skimFilter() override;

  static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

private:
  void beginStream(edm::StreamID) override;
  bool filter(edm::Event&, const edm::EventSetup&) override;
  void endStream() override;
<<<<<<< HEAD
=======
//  std::string HLT_IsoMu24_v_;
//  std::string HLT_Ele32_WPTight_Gsf_v_;
//  edm::EDGetTokenT<edm::TriggerResults> triggerToken_;
>>>>>>> 06582b8f23cd32fdd1c60c551b25f8f6a3af9614
  edm::EDGetTokenT<pat::ElectronCollection> electronToken_;
  edm::EDGetTokenT<pat::MuonCollection> muonToken_;
  edm::EDGetTokenT<pat::JetCollection> jetToken_;

  int nIsoLepton;
};

skimFilter::skimFilter(const edm::ParameterSet& iConfig) 
  : electronToken_(consumes<pat::ElectronCollection>(iConfig.getParameter<edm::InputTag>("electrons"))),
<<<<<<< HEAD
    muonToken_(consumes<pat::MuonCollection>(iConfig.getParameter<edm::InputTag>("muons"))),
    genJetToken_(consumes<reco::GenJetCollection>(iConfig.getParameter<edm::InputTag>("genJets"))){
=======
//    HLT_IsoMu24_v_(iConfig.getParameter<std::string>("HLT_IsoMu24_v")),
//    HLT_Ele32_WPTight_Gsf_v_(iConfig.getParameter<std::string>("HLT_Ele32_WPTight_Gsf_v")),
//    triggerToken_(consumes<edm::TriggerResults>(iConfig.getParameter<edm::InputTag>("triggerResults"))),
    muonToken_(consumes<pat::MuonCollection>(iConfig.getParameter<edm::InputTag>("muons"))){
>>>>>>> 06582b8f23cd32fdd1c60c551b25f8f6a3af9614

}

skimFilter::~skimFilter() {
}

//
// member functions
//

// ------------ method called on each new Event  ------------
bool skimFilter::filter(edm::Event& iEvent, const edm::EventSetup& iSetup) {
<<<<<<< HEAD
=======
//  edm::Handle<edm::TriggerResults> triggerResults;
>>>>>>> 06582b8f23cd32fdd1c60c551b25f8f6a3af9614
  edm::Handle<pat::ElectronCollection> electrons;
  edm::Handle<pat::MuonCollection> muons;
  edm::Handle<pat::JetCollection> jets;
  iEvent.getByToken(muonToken_, muons);
  iEvent.getByToken(electronToken_, electrons);
<<<<<<< HEAD
  iEvent.getByToken(jetToken_, jets);

=======
//  iEvent.getByToken(triggerToken_, triggerResults);
  
//  const edm::TriggerNames &triggerNames = iEvent.triggerNames(*triggerResults);

//  auto passTrigger = [&] (const edm::TriggerResults& trigResults, const edm::TriggerNames& trigNames) -> bool {
//    for (unsigned int i = 0; i < trigResults.size(); ++i) {
//      if ((trigNames.triggerName(i).find(HLT_IsoMu24_v_) != std::string::npos) ||
//          (trigNames.triggerName(i).find(HLT_Ele32_WPTight_Gsf_v_) != std::string::npos)) {
//        if (trigResults.accept(i)) {
//          return true;
//        }
//      }
//    }
//    return false;
//  };
>>>>>>> 06582b8f23cd32fdd1c60c551b25f8f6a3af9614

  auto passOnePromptLepton = [&] (const pat::ElectronCollection& elecs, const pat::MuonCollection& mus) -> bool {
    nIsoLepton = 0;
    for (const auto& muon : mus) {
      if (muon.passed(pat::Muon::PFIsoTight) && muon.passed(pat::Muon::CutBasedIdTight) && (muon.pt() > 24)) nIsoLepton++;
    }
    for (const auto& electron : elecs) {
<<<<<<< HEAD
      if ((electron.mva_Isolated() > 0.9) && (electron.pt() > 30) && (electron.electronID("egmGsfElectronIDs:mvaEleID-RunIIIWinter22-iso-V1-wp90") == 1)) nIsoLepton++;
=======
      if ((electron.mva_Isolated() > 0.9) && (electron.pt() > 30) && (electron.electronID("egmGsfElectronIDs:mvaEleID-RunIIIWinter22-iso-V1-wp90")) == 1) nIsoLepton++;
>>>>>>> 06582b8f23cd32fdd1c60c551b25f8f6a3af9614
    } 
    return (nIsoLepton == 1);
  };

  return passOnePromptLepton(*electrons, *muons);
}


void skimFilter::beginStream(edm::StreamID) {
}

void skimFilter::endStream() {
}

void skimFilter::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  edm::ParameterSetDescription desc;
<<<<<<< HEAD
=======
//  desc.add<edm::InputTag>("triggerResults", edm::InputTag("TriggerResults"));
//  desc.add<std::string>("HLT_IsoMu24_v", "HLT_IsoMu24_v");
//  desc.add<std::string>("HLT_Ele32_WPTight_Gsf_v", "HLT_Ele32_WPTight_Gsf_v");
>>>>>>> 06582b8f23cd32fdd1c60c551b25f8f6a3af9614
  desc.add<edm::InputTag>("electrons", edm::InputTag("electrons"));
  desc.add<edm::InputTag>("muons", edm::InputTag("muons"));
  desc.add<edm::InputTag>("jets", edm::InputTag("jets"));
  descriptions.add("skimFilter", desc);
}
//define this as a plug-in
DEFINE_FWK_MODULE(skimFilter);
