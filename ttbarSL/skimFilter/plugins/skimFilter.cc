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
  std::string HLT_IsoMu24_v_;
  std::string HLT_Ele32_WPTight_Gsf_v_;
  edm::EDGetTokenT<edm::TriggerResults> triggerToken_;
  edm::EDGetTokenT<pat::ElectronCollection> electronToken_;
  edm::EDGetTokenT<pat::MuonCollection> muonToken_;

  int nIsoLepton;
};

skimFilter::skimFilter(const edm::ParameterSet& iConfig) 
  : HLT_IsoMu24_v_(iConfig.getParameter<std::string>("HLT_IsoMu24_v")),
    HLT_Ele32_WPTight_Gsf_v_(iConfig.getParameter<std::string>("HLT_Ele32_WPTight_Gsf_v")),
    triggerToken_(consumes<edm::TriggerResults>(iConfig.getParameter<edm::InputTag>("triggerResults"))),
    electronToken_(consumes<pat::ElectronCollection>(iConfig.getParameter<edm::InputTag>("electrons"))),
    muonToken_(consumes<pat::MuonCollection>(iConfig.getParameter<edm::InputTag>("muons"))){

}

skimFilter::~skimFilter() {
}

//
// member functions
//

// ------------ method called on each new Event  ------------
bool skimFilter::filter(edm::Event& iEvent, const edm::EventSetup& iSetup) {
  edm::Handle<edm::TriggerResults> triggerResults;
  edm::Handle<pat::ElectronCollection> electrons;
  edm::Handle<pat::MuonCollection> muons;
  iEvent.getByToken(muonToken_, muons);
  iEvent.getByToken(electronToken_, electrons);
  iEvent.getByToken(triggerToken_, triggerResults);
  
  const edm::TriggerNames &triggerNames = iEvent.triggerNames(*triggerResults);

  auto passTrigger = [&] (const edm::TriggerResults& trigResults, const edm::TriggerNames& trigNames) -> bool {
    for (unsigned int i = 0; i < trigResults.size(); ++i) {
      if ((trigNames.triggerName(i).find(HLT_IsoMu24_v_) != std::string::npos) ||
          (trigNames.triggerName(i).find(HLT_Ele32_WPTight_Gsf_v_) != std::string::npos)) {
        if (trigResults.accept(i)) {
          return true;
        }
      }
    }
    return false;
  };

  auto passOnePromptLepton = [&] (const pat::ElectronCollection& elecs, const pat::MuonCollection& mus) -> bool {
    nIsoLepton = 0;
    for (const auto& muon : mus) {
      if (muon.passed(pat::Muon::PFIsoTight)) nIsoLepton++;
    }
    for (const auto& electron : elecs) {
      if (electron.mva_Isolated() > 0.9) nIsoLepton++;
    }
    return (nIsoLepton == 1);
  };

  return passTrigger(*triggerResults, triggerNames) && passOnePromptLepton(*electrons, *muons);
}


void skimFilter::beginStream(edm::StreamID) {
}

void skimFilter::endStream() {
}

void skimFilter::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  edm::ParameterSetDescription desc;
  desc.add<edm::InputTag>("triggerResults", edm::InputTag("TriggerResults"));
  desc.add<std::string>("HLT_IsoMu24_v", "HLT_IsoMu24_v");
  desc.add<std::string>("HLT_Ele32_WPTight_Gsf_v", "HLT_Ele32_WPTight_Gsf_v");
  desc.add<edm::InputTag>("electrons", edm::InputTag("electrons"));
  desc.add<edm::InputTag>("muons", edm::InputTag("muons"));
  descriptions.add("skimFilter", desc);
}
//define this as a plug-in
DEFINE_FWK_MODULE(skimFilter);
