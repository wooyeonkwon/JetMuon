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
  edm::EDGetTokenT<pat::ElectronCollection> electronToken_;
  edm::EDGetTokenT<pat::MuonCollection> muonToken_;
  edm::EDGetTokenT<pat::JetCollection> jetToken_;

  int nIsoLepton;
};

skimFilter::skimFilter(const edm::ParameterSet& iConfig) 
  : electronToken_(consumes<pat::ElectronCollection>(iConfig.getParameter<edm::InputTag>("electrons"))),
    muonToken_(consumes<pat::MuonCollection>(iConfig.getParameter<edm::InputTag>("muons"))),
    genJetToken_(consumes<reco::GenJetCollection>(iConfig.getParameter<edm::InputTag>("genJets"))){

}

skimFilter::~skimFilter() {
}

//
// member functions
//

// ------------ method called on each new Event  ------------
bool skimFilter::filter(edm::Event& iEvent, const edm::EventSetup& iSetup) {
  edm::Handle<pat::ElectronCollection> electrons;
  edm::Handle<pat::MuonCollection> muons;
  edm::Handle<pat::JetCollection> jets;
  iEvent.getByToken(muonToken_, muons);
  iEvent.getByToken(electronToken_, electrons);
  iEvent.getByToken(jetToken_, jets);


  auto passOnePromptLepton = [&] (const pat::ElectronCollection& elecs, const pat::MuonCollection& mus) -> bool {
    nIsoLepton = 0;
    for (const auto& muon : mus) {
      if (muon.passed(pat::Muon::PFIsoTight) && muon.passed(pat::Muon::CutBasedIdTight) && (muon.pt() > 24)) nIsoLepton++;
    }
    for (const auto& electron : elecs) {
      if ((electron.mva_Isolated() > 0.9) && (electron.pt() > 30) && (electron.electronID("egmGsfElectronIDs:mvaEleID-RunIIIWinter22-iso-V1-wp90") == 1)) nIsoLepton++;
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
  desc.add<edm::InputTag>("electrons", edm::InputTag("electrons"));
  desc.add<edm::InputTag>("muons", edm::InputTag("muons"));
  desc.add<edm::InputTag>("jets", edm::InputTag("jets"));
  descriptions.add("skimFilter", desc);
}
//define this as a plug-in
DEFINE_FWK_MODULE(skimFilter);
