//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Jun 16 10:38:18 2025 by ROOT version 6.30/09
// from TTree Events/
// found on file: /data1/users/dndus0107/skimmed_data/TTtoLNu2Q_TuneCP5_13p6TeV_powheg-pythia8/crab_TTtoLNu2Q_TuneCP5_13p6TeV_powheg-pythia8/250610_074241/0000/skimmed_data_21.root
//////////////////////////////////////////////////////////

#ifndef JetTree_h
#define JetTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "DataFormats/Provenance/interface/EventAuxiliary.h"
#include "vector"
#include "vector"
#include "vector"
#include "DataFormats/Common/interface/Wrapper.h"
#include "DataFormats/Common/interface/Wrapper.h"
#include "DataFormats/Common/interface/Wrapper.h"
#include "DataFormats/Common/interface/Wrapper.h"
#include "Math/GenVector/Cartesian3D.h"
#include "Math/GenVector/PtEtaPhiM4D.h"
#include "DataFormats/Candidate/interface/ParticleState.h"
#include "DataFormats/Candidate/interface/CompositePtrCandidate.h"
#include "DataFormats/JetReco/interface/Jet.h"
#include "DataFormats/Common/interface/Ptr.h"
#include "DataFormats/PatCandidates/interface/PATObject.h"
#include "DataFormats/Common/interface/OwnVector.h"
#include "DataFormats/PatCandidates/interface/Jet.h"
#include "DataFormats/Common/interface/SortedCollection.h"
#include "DataFormats/Common/interface/RefVectorBase.h"
#include "DataFormats/Common/interface/Ref.h"
#include "DataFormats/JetMatching/interface/JetFlavourInfo.h"
#include "DataFormats/Common/interface/OwnVector.h"
#include "DataFormats/JetReco/interface/JetID.h"
#include "DataFormats/Common/interface/Wrapper.h"
#include "DataFormats/Common/interface/Wrapper.h"
#include "DataFormats/PatCandidates/interface/PackedCandidate.h"
#include "DataFormats/PatCandidates/interface/PackedCandidate.h"
#include "DataFormats/Common/interface/RefProd.h"
#include "DataFormats/Common/interface/Wrapper.h"
#include "DataFormats/PatCandidates/interface/PackedGenParticle.h"
#include "Math/GenVector/Cartesian3D.h"
#include "DataFormats/Common/interface/Ref.h"
#include "DataFormats/HepMCCandidate/interface/GenStatusFlags.h"
#include "DataFormats/Common/interface/Wrapper.h"
#include "DataFormats/JetReco/interface/GenJet.h"
#include "DataFormats/Common/interface/Wrapper.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"

class JetTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
   static constexpr Int_t kMaxGenEventInfoProduct_generator__SIM = 1;
   static constexpr Int_t kMaxLHEEventProduct_externalLHEProducer__SIM = 1;
   static constexpr Int_t kMaxrecoGenParticlesedmAssociation_packedPFCandidateToGenAssociation__PAT = 1;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT = 1;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_m_state_qx3 = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_m_state_pdgId = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_m_state_status = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_refToOrig__core = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_refToOrig__key = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_triggerObjectMatchesEmbedded = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_efficiencyValues = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_efficiencyNames = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_genParticleRef = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_genParticleEmbedded = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_overlapLabels = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_overlapItems = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_userDataLabels = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_userDataObjects__data = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_userFloatLabels = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_userFloats = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_userIntLabels = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_userInts = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_userCandLabels = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_userCands = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_kinResolutions = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_kinResolutionLabels = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_embeddedCaloTowers = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_caloTowersFwdPtr = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_embeddedPFCandidates = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_pfCandidates = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_pfCandidatesFwdPtr = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_subjetCollections = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_subjetLabels = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_genJet = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_genJetRef__refVector__product = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_genJetRef__refVector__keys = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_genJetFwdRef__ref__product = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_genJetFwdRef__backRef__product = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_bHadrons_refVector__product = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_bHadrons_refVector__keys = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_cHadrons_refVector__product = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_cHadrons_refVector__keys = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_partons_refVector__product = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_partons_refVector__keys = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_leptons_refVector__product = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_leptons_refVector__keys = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_jec = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_currentJECSet = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_currentJECLevel = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_currentJECFlavor = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_pairDiscriVector = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_tagInfoLabels = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_tagInfos__data = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_tagInfosFwdPtr = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_jetCharge = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_associatedTracks__refVector__product = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_associatedTracks__refVector__keys = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_specificCalo = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_specificJPT = 30;
   static constexpr Int_t kMaxpatJets_slimmedJetsPuppi__PAT_obj_specificPF = 30;
   static constexpr Int_t kMaxpatMuons_slimmedMuons__PAT = 1;
   static constexpr Int_t kMaxpatPackedCandidates_packedPFCandidates__PAT = 1;
   static constexpr Int_t kMaxpatPackedCandidates_packedPFCandidates__PAT_obj = 3957;
   static constexpr Int_t kMaxpatPackedCandidates_packedPFCandidates__PAT_obj_packedPt = 3957;
   static constexpr Int_t kMaxpatPackedCandidates_packedPFCandidates__PAT_obj_packedEta = 3957;
   static constexpr Int_t kMaxpatPackedCandidates_packedPFCandidates__PAT_obj_packedPhi = 3957;
   static constexpr Int_t kMaxpatPackedCandidates_packedPFCandidates__PAT_obj_packedM = 3957;
   static constexpr Int_t kMaxpatPackedCandidates_packedPFCandidates__PAT_obj_packedDxy = 3957;
   static constexpr Int_t kMaxpatPackedCandidates_packedPFCandidates__PAT_obj_packedDz = 3957;
   static constexpr Int_t kMaxpatPackedCandidates_packedPFCandidates__PAT_obj_packedDPhi = 3957;
   static constexpr Int_t kMaxpatPackedCandidates_packedPFCandidates__PAT_obj_packedDEta = 3957;
   static constexpr Int_t kMaxpatPackedCandidates_packedPFCandidates__PAT_obj_packedDTrkPt = 3957;
   static constexpr Int_t kMaxpatPackedCandidates_packedPFCandidates__PAT_obj_packedPuppiweight = 3957;
   static constexpr Int_t kMaxpatPackedCandidates_packedPFCandidates__PAT_obj_packedPuppiweightNoLepDiff = 3957;
   static constexpr Int_t kMaxpatPackedCandidates_packedPFCandidates__PAT_obj_rawCaloFraction = 3957;
   static constexpr Int_t kMaxpatPackedCandidates_packedPFCandidates__PAT_obj_rawHcalFraction = 3957;
   static constexpr Int_t kMaxpatPackedCandidates_packedPFCandidates__PAT_obj_caloFraction = 3957;
   static constexpr Int_t kMaxpatPackedCandidates_packedPFCandidates__PAT_obj_hcalFraction = 3957;
   static constexpr Int_t kMaxpatPackedCandidates_packedPFCandidates__PAT_obj_packedTime = 3957;
   static constexpr Int_t kMaxpatPackedCandidates_packedPFCandidates__PAT_obj_packedTimeError = 3957;
   static constexpr Int_t kMaxpatPackedCandidates_packedPFCandidates__PAT_obj_isIsolatedChargedHadron = 3957;
   static constexpr Int_t kMaxpatPackedCandidates_packedPFCandidates__PAT_obj_pdgId = 3957;
   static constexpr Int_t kMaxpatPackedCandidates_packedPFCandidates__PAT_obj_qualityFlags = 3957;
   static constexpr Int_t kMaxpatPackedCandidates_packedPFCandidates__PAT_obj_pvRefProd__product = 3957;
   static constexpr Int_t kMaxpatPackedCandidates_packedPFCandidates__PAT_obj_pvRefKey = 3957;
   static constexpr Int_t kMaxpatPackedCandidates_packedPFCandidates__PAT_obj_packedHits = 3957;
   static constexpr Int_t kMaxpatPackedCandidates_packedPFCandidates__PAT_obj_packedLayers = 3957;
   static constexpr Int_t kMaxpatPackedCandidates_packedPFCandidates__PAT_obj_normalizedChi2 = 3957;
   static constexpr Int_t kMaxpatPackedCandidates_packedPFCandidates__PAT_obj_covarianceVersion = 3957;
   static constexpr Int_t kMaxpatPackedCandidates_packedPFCandidates__PAT_obj_covarianceSchema = 3957;
   static constexpr Int_t kMaxpatPackedCandidates_packedPFCandidates__PAT_obj_firstHit = 3957;
   static constexpr Int_t kMaxpatPackedCandidates_packedPFCandidates__PAT_obj_trkAlgoPacked = 3957;
   static constexpr Int_t kMaxpatPackedGenParticles_packedGenParticles__PAT = 1;
   static constexpr Int_t kMaxpatPackedGenParticles_packedGenParticles__PAT_obj = 1197;
   static constexpr Int_t kMaxpatPackedGenParticles_packedGenParticles__PAT_obj_packedPt = 1197;
   static constexpr Int_t kMaxpatPackedGenParticles_packedGenParticles__PAT_obj_packedY = 1197;
   static constexpr Int_t kMaxpatPackedGenParticles_packedGenParticles__PAT_obj_packedPhi = 1197;
   static constexpr Int_t kMaxpatPackedGenParticles_packedGenParticles__PAT_obj_packedM = 1197;
   static constexpr Int_t kMaxpatPackedGenParticles_packedGenParticles__PAT_obj_dxy = 1197;
   static constexpr Int_t kMaxpatPackedGenParticles_packedGenParticles__PAT_obj_dz = 1197;
   static constexpr Int_t kMaxpatPackedGenParticles_packedGenParticles__PAT_obj_dphi = 1197;
   static constexpr Int_t kMaxpatPackedGenParticles_packedGenParticles__PAT_obj_pdgId = 1197;
   static constexpr Int_t kMaxpatPackedGenParticles_packedGenParticles__PAT_obj_charge = 1197;
   static constexpr Int_t kMaxpatPackedGenParticles_packedGenParticles__PAT_obj_mother__product = 1197;
   static constexpr Int_t kMaxpatPackedGenParticles_packedGenParticles__PAT_obj_statusFlags__flags = 1197;
   static constexpr Int_t kMaxrecoGenJets_slimmedGenJets__PAT = 1;
   static constexpr Int_t kMaxrecoGenJets_slimmedGenJets__PAT_obj = 28;
   static constexpr Int_t kMaxrecoGenJets_slimmedGenJets__PAT_obj_m_state_qx3 = 28;
   static constexpr Int_t kMaxrecoGenJets_slimmedGenJets__PAT_obj_m_state_pdgId = 28;
   static constexpr Int_t kMaxrecoGenJets_slimmedGenJets__PAT_obj_m_state_status = 28;
   static constexpr Int_t kMaxrecoGenParticles_prunedGenParticles__PAT = 1;
   static constexpr Int_t kMaxrecoGenParticles_prunedGenParticles__PAT_obj = 368;
   static constexpr Int_t kMaxrecoGenParticles_prunedGenParticles__PAT_obj_m_state_qx3 = 368;
   static constexpr Int_t kMaxrecoGenParticles_prunedGenParticles__PAT_obj_m_state_pdgId = 368;
   static constexpr Int_t kMaxrecoGenParticles_prunedGenParticles__PAT_obj_m_state_status = 368;
   static constexpr Int_t kMaxrecoGenParticles_prunedGenParticles__PAT_obj_dau_refVector__product = 368;
   static constexpr Int_t kMaxrecoGenParticles_prunedGenParticles__PAT_obj_dau_refVector__keys = 368;
   static constexpr Int_t kMaxrecoGenParticles_prunedGenParticles__PAT_obj_mom_refVector__product = 368;
   static constexpr Int_t kMaxrecoGenParticles_prunedGenParticles__PAT_obj_mom_refVector__keys = 368;
   static constexpr Int_t kMaxrecoGenParticles_prunedGenParticles__PAT_obj_collisionId = 368;
   static constexpr Int_t kMaxrecoGenParticles_prunedGenParticles__PAT_obj_statusFlags__flags = 368;

   // Declaration of leaf types
   edm::EventAuxiliary *EventAuxiliary;
   vector<edm::StoredProductProvenance> *EventProductProvenance;
   vector<edm::Hash<1> > *EventSelections;
   vector<unsigned short> *BranchListIndexes;
 //edm::Wrapper<GenEventInfoProduct> *GenEventInfoProduct_generator__SIM_;
   GenEventInfoProduct GenEventInfoProduct_generator__SIM_obj;
   Bool_t          GenEventInfoProduct_generator__SIM_present;
 //edm::Wrapper<LHEEventProduct> *LHEEventProduct_externalLHEProducer__SIM_;
   LHEEventProduct LHEEventProduct_externalLHEProducer__SIM_obj;
   Bool_t          LHEEventProduct_externalLHEProducer__SIM_present;
 //edm::Wrapper<edm::Association<vector<reco::GenParticle> > > *recoGenParticlesedmAssociation_packedPFCandidateToGenAssociation__PAT_;
   edm::Association<vector<reco::GenParticle> > recoGenParticlesedmAssociation_packedPFCandidateToGenAssociation__PAT_obj;
   Bool_t          recoGenParticlesedmAssociation_packedPFCandidateToGenAssociation__PAT_present;
 //edm::Wrapper<vector<pat::Jet> > *patJets_slimmedJetsPuppi__PAT_;
   Int_t           patJets_slimmedJetsPuppi__PAT_obj_;
   Double32_t      patJets_slimmedJetsPuppi__PAT_obj_m_state_vertex__fCoordinates_fX[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   Double32_t      patJets_slimmedJetsPuppi__PAT_obj_m_state_vertex__fCoordinates_fY[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   Double32_t      patJets_slimmedJetsPuppi__PAT_obj_m_state_vertex__fCoordinates_fZ[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   Double32_t      patJets_slimmedJetsPuppi__PAT_obj_m_state_p4Polar__fCoordinates_fPt[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   Double32_t      patJets_slimmedJetsPuppi__PAT_obj_m_state_p4Polar__fCoordinates_fEta[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   Double32_t      patJets_slimmedJetsPuppi__PAT_obj_m_state_p4Polar__fCoordinates_fPhi[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   Double32_t      patJets_slimmedJetsPuppi__PAT_obj_m_state_p4Polar__fCoordinates_fM[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   Int_t           patJets_slimmedJetsPuppi__PAT_obj_m_state_qx3_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   Int_t           patJets_slimmedJetsPuppi__PAT_obj_m_state_pdgId_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   Int_t           patJets_slimmedJetsPuppi__PAT_obj_m_state_status_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   vector<edm::Ptr<reco::Candidate> > patJets_slimmedJetsPuppi__PAT_obj_dau[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   Float_t         patJets_slimmedJetsPuppi__PAT_obj_mJetArea[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   Float_t         patJets_slimmedJetsPuppi__PAT_obj_mPileupEnergy[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   Int_t           patJets_slimmedJetsPuppi__PAT_obj_mPassNumber[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   Bool_t          patJets_slimmedJetsPuppi__PAT_obj_mIsWeighted[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   edm::RefCore    patJets_slimmedJetsPuppi__PAT_obj_refToOrig__core_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   ULong_t         patJets_slimmedJetsPuppi__PAT_obj_refToOrig__key_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   vector<pat::TriggerObjectStandAlone> patJets_slimmedJetsPuppi__PAT_obj_triggerObjectMatchesEmbedded_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   vector<pat::LookupTableRecord> patJets_slimmedJetsPuppi__PAT_obj_efficiencyValues_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   vector<string>  patJets_slimmedJetsPuppi__PAT_obj_efficiencyNames_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   vector<edm::Ref<vector<reco::GenParticle>,reco::GenParticle,edm::refhelper::FindUsingAdvance<vector<reco::GenParticle>,reco::GenParticle> > > patJets_slimmedJetsPuppi__PAT_obj_genParticleRef_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   vector<reco::GenParticle> patJets_slimmedJetsPuppi__PAT_obj_genParticleEmbedded_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   vector<string>  patJets_slimmedJetsPuppi__PAT_obj_overlapLabels_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   vector<edm::PtrVector<reco::Candidate> > patJets_slimmedJetsPuppi__PAT_obj_overlapItems_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   vector<string>  patJets_slimmedJetsPuppi__PAT_obj_userDataLabels_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   vector<pat::UserData*> patJets_slimmedJetsPuppi__PAT_obj_userDataObjects__data_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   vector<string>  patJets_slimmedJetsPuppi__PAT_obj_userFloatLabels_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   vector<float>   patJets_slimmedJetsPuppi__PAT_obj_userFloats_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   vector<string>  patJets_slimmedJetsPuppi__PAT_obj_userIntLabels_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   vector<int>     patJets_slimmedJetsPuppi__PAT_obj_userInts_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   vector<string>  patJets_slimmedJetsPuppi__PAT_obj_userCandLabels_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   vector<edm::Ptr<reco::Candidate> > patJets_slimmedJetsPuppi__PAT_obj_userCands_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   vector<pat::CandKinResolution> patJets_slimmedJetsPuppi__PAT_obj_kinResolutions_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   vector<string>  patJets_slimmedJetsPuppi__PAT_obj_kinResolutionLabels_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   Bool_t          patJets_slimmedJetsPuppi__PAT_obj_embeddedCaloTowers_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   vector<CaloTower> patJets_slimmedJetsPuppi__PAT_obj_caloTowers__obj[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   vector<edm::FwdPtr<CaloTower> > patJets_slimmedJetsPuppi__PAT_obj_caloTowersFwdPtr_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   Bool_t          patJets_slimmedJetsPuppi__PAT_obj_embeddedPFCandidates_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   vector<reco::PFCandidate> patJets_slimmedJetsPuppi__PAT_obj_pfCandidates_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   vector<edm::FwdPtr<reco::PFCandidate> > patJets_slimmedJetsPuppi__PAT_obj_pfCandidatesFwdPtr_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   vector<vector<edm::Ptr<pat::Jet> > > patJets_slimmedJetsPuppi__PAT_obj_subjetCollections_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   vector<string>  patJets_slimmedJetsPuppi__PAT_obj_subjetLabels_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   vector<reco::GenJet> patJets_slimmedJetsPuppi__PAT_obj_genJet_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   edm::RefCore    patJets_slimmedJetsPuppi__PAT_obj_genJetRef__refVector__product_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   vector<unsigned int> patJets_slimmedJetsPuppi__PAT_obj_genJetRef__refVector__keys_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   edm::RefCoreWithIndex patJets_slimmedJetsPuppi__PAT_obj_genJetFwdRef__ref__product_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   edm::RefCoreWithIndex patJets_slimmedJetsPuppi__PAT_obj_genJetFwdRef__backRef__product_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   edm::RefCore    patJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_bHadrons_refVector__product_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   vector<unsigned int> patJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_bHadrons_refVector__keys_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   edm::RefCore    patJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_cHadrons_refVector__product_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   vector<unsigned int> patJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_cHadrons_refVector__keys_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   edm::RefCore    patJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_partons_refVector__product_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   vector<unsigned int> patJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_partons_refVector__keys_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   edm::RefCore    patJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_leptons_refVector__product_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   vector<unsigned int> patJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_leptons_refVector__keys_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   Int_t           patJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_hadronFlavour[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   Int_t           patJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_partonFlavour[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   vector<pat::JetCorrFactors> patJets_slimmedJetsPuppi__PAT_obj_jec_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   UInt_t          patJets_slimmedJetsPuppi__PAT_obj_currentJECSet_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   UInt_t          patJets_slimmedJetsPuppi__PAT_obj_currentJECLevel_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   Int_t           patJets_slimmedJetsPuppi__PAT_obj_currentJECFlavor_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   vector<pair<string,float> > patJets_slimmedJetsPuppi__PAT_obj_pairDiscriVector_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   vector<string>  patJets_slimmedJetsPuppi__PAT_obj_tagInfoLabels_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   vector<reco::BaseTagInfo*> patJets_slimmedJetsPuppi__PAT_obj_tagInfos__data_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   vector<edm::FwdPtr<reco::BaseTagInfo> > patJets_slimmedJetsPuppi__PAT_obj_tagInfosFwdPtr_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   Float_t         patJets_slimmedJetsPuppi__PAT_obj_jetCharge_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   edm::RefCore    patJets_slimmedJetsPuppi__PAT_obj_associatedTracks__refVector__product_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   vector<unsigned int> patJets_slimmedJetsPuppi__PAT_obj_associatedTracks__refVector__keys_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   vector<reco::CaloJet::Specific> patJets_slimmedJetsPuppi__PAT_obj_specificCalo_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   vector<reco::JPTJet::Specific> patJets_slimmedJetsPuppi__PAT_obj_specificJPT_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   vector<reco::PFJet::Specific> patJets_slimmedJetsPuppi__PAT_obj_specificPF_[kMaxpatJets_slimmedJetsPuppi__PAT_obj];
   Float_t         patJets_slimmedJetsPuppi__PAT_obj_jetID__fHPD[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   Float_t         patJets_slimmedJetsPuppi__PAT_obj_jetID__fRBX[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   Short_t         patJets_slimmedJetsPuppi__PAT_obj_jetID__n90Hits[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   Float_t         patJets_slimmedJetsPuppi__PAT_obj_jetID__fSubDetector1[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   Float_t         patJets_slimmedJetsPuppi__PAT_obj_jetID__fSubDetector2[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   Float_t         patJets_slimmedJetsPuppi__PAT_obj_jetID__fSubDetector3[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   Float_t         patJets_slimmedJetsPuppi__PAT_obj_jetID__fSubDetector4[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   Float_t         patJets_slimmedJetsPuppi__PAT_obj_jetID__restrictedEMF[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   Short_t         patJets_slimmedJetsPuppi__PAT_obj_jetID__nHCALTowers[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   Short_t         patJets_slimmedJetsPuppi__PAT_obj_jetID__nECALTowers[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   Float_t         patJets_slimmedJetsPuppi__PAT_obj_jetID__approximatefHPD[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   Float_t         patJets_slimmedJetsPuppi__PAT_obj_jetID__approximatefRBX[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   Short_t         patJets_slimmedJetsPuppi__PAT_obj_jetID__hitsInN90[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   Short_t         patJets_slimmedJetsPuppi__PAT_obj_jetID__numberOfHits2RPC[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   Short_t         patJets_slimmedJetsPuppi__PAT_obj_jetID__numberOfHits3RPC[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   Short_t         patJets_slimmedJetsPuppi__PAT_obj_jetID__numberOfHitsRPC[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   Float_t         patJets_slimmedJetsPuppi__PAT_obj_jetID__fEB[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   Float_t         patJets_slimmedJetsPuppi__PAT_obj_jetID__fEE[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   Float_t         patJets_slimmedJetsPuppi__PAT_obj_jetID__fHB[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   Float_t         patJets_slimmedJetsPuppi__PAT_obj_jetID__fHE[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   Float_t         patJets_slimmedJetsPuppi__PAT_obj_jetID__fHO[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   Float_t         patJets_slimmedJetsPuppi__PAT_obj_jetID__fLong[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   Float_t         patJets_slimmedJetsPuppi__PAT_obj_jetID__fShort[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   Float_t         patJets_slimmedJetsPuppi__PAT_obj_jetID__fLS[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   Float_t         patJets_slimmedJetsPuppi__PAT_obj_jetID__fHFOOT[kMaxpatJets_slimmedJetsPuppi__PAT_obj];   //[patJets_slimmedJetsPuppi__PAT.obj_]
   Bool_t          patJets_slimmedJetsPuppi__PAT_present;
 //edm::Wrapper<vector<pat::Muon> > *patMuons_slimmedMuons__PAT_;
   vector<pat::Muon> patMuons_slimmedMuons__PAT_obj;
   Bool_t          patMuons_slimmedMuons__PAT_present;
 //edm::Wrapper<vector<pat::PackedCandidate> > *patPackedCandidates_packedPFCandidates__PAT_;
   Int_t           patPackedCandidates_packedPFCandidates__PAT_obj_;
   UShort_t        patPackedCandidates_packedPFCandidates__PAT_obj_packedPt_[kMaxpatPackedCandidates_packedPFCandidates__PAT_obj];   //[patPackedCandidates_packedPFCandidates__PAT.obj_]
   UShort_t        patPackedCandidates_packedPFCandidates__PAT_obj_packedEta_[kMaxpatPackedCandidates_packedPFCandidates__PAT_obj];   //[patPackedCandidates_packedPFCandidates__PAT.obj_]
   UShort_t        patPackedCandidates_packedPFCandidates__PAT_obj_packedPhi_[kMaxpatPackedCandidates_packedPFCandidates__PAT_obj];   //[patPackedCandidates_packedPFCandidates__PAT.obj_]
   UShort_t        patPackedCandidates_packedPFCandidates__PAT_obj_packedM_[kMaxpatPackedCandidates_packedPFCandidates__PAT_obj];   //[patPackedCandidates_packedPFCandidates__PAT.obj_]
   UShort_t        patPackedCandidates_packedPFCandidates__PAT_obj_packedDxy_[kMaxpatPackedCandidates_packedPFCandidates__PAT_obj];   //[patPackedCandidates_packedPFCandidates__PAT.obj_]
   UShort_t        patPackedCandidates_packedPFCandidates__PAT_obj_packedDz_[kMaxpatPackedCandidates_packedPFCandidates__PAT_obj];   //[patPackedCandidates_packedPFCandidates__PAT.obj_]
   UShort_t        patPackedCandidates_packedPFCandidates__PAT_obj_packedDPhi_[kMaxpatPackedCandidates_packedPFCandidates__PAT_obj];   //[patPackedCandidates_packedPFCandidates__PAT.obj_]
   UShort_t        patPackedCandidates_packedPFCandidates__PAT_obj_packedDEta_[kMaxpatPackedCandidates_packedPFCandidates__PAT_obj];   //[patPackedCandidates_packedPFCandidates__PAT.obj_]
   UShort_t        patPackedCandidates_packedPFCandidates__PAT_obj_packedDTrkPt_[kMaxpatPackedCandidates_packedPFCandidates__PAT_obj];   //[patPackedCandidates_packedPFCandidates__PAT.obj_]
   UShort_t        patPackedCandidates_packedPFCandidates__PAT_obj_packedCovariance__dxydxy[kMaxpatPackedCandidates_packedPFCandidates__PAT_obj];   //[patPackedCandidates_packedPFCandidates__PAT.obj_]
   UShort_t        patPackedCandidates_packedPFCandidates__PAT_obj_packedCovariance__dxydz[kMaxpatPackedCandidates_packedPFCandidates__PAT_obj];   //[patPackedCandidates_packedPFCandidates__PAT.obj_]
   UShort_t        patPackedCandidates_packedPFCandidates__PAT_obj_packedCovariance__dzdz[kMaxpatPackedCandidates_packedPFCandidates__PAT_obj];   //[patPackedCandidates_packedPFCandidates__PAT.obj_]
   UShort_t        patPackedCandidates_packedPFCandidates__PAT_obj_packedCovariance__dlambdadz[kMaxpatPackedCandidates_packedPFCandidates__PAT_obj];   //[patPackedCandidates_packedPFCandidates__PAT.obj_]
   UShort_t        patPackedCandidates_packedPFCandidates__PAT_obj_packedCovariance__dphidxy[kMaxpatPackedCandidates_packedPFCandidates__PAT_obj];   //[patPackedCandidates_packedPFCandidates__PAT.obj_]
   UShort_t        patPackedCandidates_packedPFCandidates__PAT_obj_packedCovariance__dptdpt[kMaxpatPackedCandidates_packedPFCandidates__PAT_obj];   //[patPackedCandidates_packedPFCandidates__PAT.obj_]
   UShort_t        patPackedCandidates_packedPFCandidates__PAT_obj_packedCovariance__detadeta[kMaxpatPackedCandidates_packedPFCandidates__PAT_obj];   //[patPackedCandidates_packedPFCandidates__PAT.obj_]
   UShort_t        patPackedCandidates_packedPFCandidates__PAT_obj_packedCovariance__dphidphi[kMaxpatPackedCandidates_packedPFCandidates__PAT_obj];   //[patPackedCandidates_packedPFCandidates__PAT.obj_]
   UChar_t         patPackedCandidates_packedPFCandidates__PAT_obj_packedPuppiweight_[kMaxpatPackedCandidates_packedPFCandidates__PAT_obj];   //[patPackedCandidates_packedPFCandidates__PAT.obj_]
   Char_t          patPackedCandidates_packedPFCandidates__PAT_obj_packedPuppiweightNoLepDiff_[kMaxpatPackedCandidates_packedPFCandidates__PAT_obj];   //[patPackedCandidates_packedPFCandidates__PAT.obj_]
   UChar_t         patPackedCandidates_packedPFCandidates__PAT_obj_rawCaloFraction_[kMaxpatPackedCandidates_packedPFCandidates__PAT_obj];   //[patPackedCandidates_packedPFCandidates__PAT.obj_]
   Char_t          patPackedCandidates_packedPFCandidates__PAT_obj_rawHcalFraction_[kMaxpatPackedCandidates_packedPFCandidates__PAT_obj];   //[patPackedCandidates_packedPFCandidates__PAT.obj_]
   UChar_t         patPackedCandidates_packedPFCandidates__PAT_obj_caloFraction_[kMaxpatPackedCandidates_packedPFCandidates__PAT_obj];   //[patPackedCandidates_packedPFCandidates__PAT.obj_]
   Char_t          patPackedCandidates_packedPFCandidates__PAT_obj_hcalFraction_[kMaxpatPackedCandidates_packedPFCandidates__PAT_obj];   //[patPackedCandidates_packedPFCandidates__PAT.obj_]
   Short_t         patPackedCandidates_packedPFCandidates__PAT_obj_packedTime_[kMaxpatPackedCandidates_packedPFCandidates__PAT_obj];   //[patPackedCandidates_packedPFCandidates__PAT.obj_]
   UChar_t         patPackedCandidates_packedPFCandidates__PAT_obj_packedTimeError_[kMaxpatPackedCandidates_packedPFCandidates__PAT_obj];   //[patPackedCandidates_packedPFCandidates__PAT.obj_]
   Bool_t          patPackedCandidates_packedPFCandidates__PAT_obj_isIsolatedChargedHadron_[kMaxpatPackedCandidates_packedPFCandidates__PAT_obj];   //[patPackedCandidates_packedPFCandidates__PAT.obj_]
   Int_t           patPackedCandidates_packedPFCandidates__PAT_obj_pdgId_[kMaxpatPackedCandidates_packedPFCandidates__PAT_obj];   //[patPackedCandidates_packedPFCandidates__PAT.obj_]
   UShort_t        patPackedCandidates_packedPFCandidates__PAT_obj_qualityFlags_[kMaxpatPackedCandidates_packedPFCandidates__PAT_obj];   //[patPackedCandidates_packedPFCandidates__PAT.obj_]
   edm::RefCore    patPackedCandidates_packedPFCandidates__PAT_obj_pvRefProd__product_[kMaxpatPackedCandidates_packedPFCandidates__PAT_obj];
   UInt_t          patPackedCandidates_packedPFCandidates__PAT_obj_pvRefKey_[kMaxpatPackedCandidates_packedPFCandidates__PAT_obj];   //[patPackedCandidates_packedPFCandidates__PAT.obj_]
   UChar_t         patPackedCandidates_packedPFCandidates__PAT_obj_packedHits_[kMaxpatPackedCandidates_packedPFCandidates__PAT_obj];   //[patPackedCandidates_packedPFCandidates__PAT.obj_]
   UChar_t         patPackedCandidates_packedPFCandidates__PAT_obj_packedLayers_[kMaxpatPackedCandidates_packedPFCandidates__PAT_obj];   //[patPackedCandidates_packedPFCandidates__PAT.obj_]
   UChar_t         patPackedCandidates_packedPFCandidates__PAT_obj_normalizedChi2_[kMaxpatPackedCandidates_packedPFCandidates__PAT_obj];   //[patPackedCandidates_packedPFCandidates__PAT.obj_]
   UShort_t        patPackedCandidates_packedPFCandidates__PAT_obj_covarianceVersion_[kMaxpatPackedCandidates_packedPFCandidates__PAT_obj];   //[patPackedCandidates_packedPFCandidates__PAT.obj_]
   UShort_t        patPackedCandidates_packedPFCandidates__PAT_obj_covarianceSchema_[kMaxpatPackedCandidates_packedPFCandidates__PAT_obj];   //[patPackedCandidates_packedPFCandidates__PAT.obj_]
   UShort_t        patPackedCandidates_packedPFCandidates__PAT_obj_firstHit_[kMaxpatPackedCandidates_packedPFCandidates__PAT_obj];   //[patPackedCandidates_packedPFCandidates__PAT.obj_]
   UShort_t        patPackedCandidates_packedPFCandidates__PAT_obj_trkAlgoPacked_[kMaxpatPackedCandidates_packedPFCandidates__PAT_obj];   //[patPackedCandidates_packedPFCandidates__PAT.obj_]
   Bool_t          patPackedCandidates_packedPFCandidates__PAT_present;
 //edm::Wrapper<vector<pat::PackedGenParticle> > *patPackedGenParticles_packedGenParticles__PAT_;
   Int_t           patPackedGenParticles_packedGenParticles__PAT_obj_;
   UShort_t        patPackedGenParticles_packedGenParticles__PAT_obj_packedPt_[kMaxpatPackedGenParticles_packedGenParticles__PAT_obj];   //[patPackedGenParticles_packedGenParticles__PAT.obj_]
   UShort_t        patPackedGenParticles_packedGenParticles__PAT_obj_packedY_[kMaxpatPackedGenParticles_packedGenParticles__PAT_obj];   //[patPackedGenParticles_packedGenParticles__PAT.obj_]
   UShort_t        patPackedGenParticles_packedGenParticles__PAT_obj_packedPhi_[kMaxpatPackedGenParticles_packedGenParticles__PAT_obj];   //[patPackedGenParticles_packedGenParticles__PAT.obj_]
   UShort_t        patPackedGenParticles_packedGenParticles__PAT_obj_packedM_[kMaxpatPackedGenParticles_packedGenParticles__PAT_obj];   //[patPackedGenParticles_packedGenParticles__PAT.obj_]
   Double_t        patPackedGenParticles_packedGenParticles__PAT_obj_vertex__fCoordinates_fX[kMaxpatPackedGenParticles_packedGenParticles__PAT_obj];   //[patPackedGenParticles_packedGenParticles__PAT.obj_]
   Double_t        patPackedGenParticles_packedGenParticles__PAT_obj_vertex__fCoordinates_fY[kMaxpatPackedGenParticles_packedGenParticles__PAT_obj];   //[patPackedGenParticles_packedGenParticles__PAT.obj_]
   Double_t        patPackedGenParticles_packedGenParticles__PAT_obj_vertex__fCoordinates_fZ[kMaxpatPackedGenParticles_packedGenParticles__PAT_obj];   //[patPackedGenParticles_packedGenParticles__PAT.obj_]
   Float_t         patPackedGenParticles_packedGenParticles__PAT_obj_dxy_[kMaxpatPackedGenParticles_packedGenParticles__PAT_obj];   //[patPackedGenParticles_packedGenParticles__PAT.obj_]
   Float_t         patPackedGenParticles_packedGenParticles__PAT_obj_dz_[kMaxpatPackedGenParticles_packedGenParticles__PAT_obj];   //[patPackedGenParticles_packedGenParticles__PAT.obj_]
   Float_t         patPackedGenParticles_packedGenParticles__PAT_obj_dphi_[kMaxpatPackedGenParticles_packedGenParticles__PAT_obj];   //[patPackedGenParticles_packedGenParticles__PAT.obj_]
   Int_t           patPackedGenParticles_packedGenParticles__PAT_obj_pdgId_[kMaxpatPackedGenParticles_packedGenParticles__PAT_obj];   //[patPackedGenParticles_packedGenParticles__PAT.obj_]
   Char_t          patPackedGenParticles_packedGenParticles__PAT_obj_charge_[kMaxpatPackedGenParticles_packedGenParticles__PAT_obj];   //[patPackedGenParticles_packedGenParticles__PAT.obj_]
   edm::RefCoreWithIndex patPackedGenParticles_packedGenParticles__PAT_obj_mother__product_[kMaxpatPackedGenParticles_packedGenParticles__PAT_obj];
   bitset<15>      patPackedGenParticles_packedGenParticles__PAT_obj_statusFlags__flags_[kMaxpatPackedGenParticles_packedGenParticles__PAT_obj];
   Bool_t          patPackedGenParticles_packedGenParticles__PAT_present;
 //edm::Wrapper<vector<reco::GenJet> > *recoGenJets_slimmedGenJets__PAT_;
   Int_t           recoGenJets_slimmedGenJets__PAT_obj_;
   Double32_t      recoGenJets_slimmedGenJets__PAT_obj_m_state_vertex__fCoordinates_fX[kMaxrecoGenJets_slimmedGenJets__PAT_obj];   //[recoGenJets_slimmedGenJets__PAT.obj_]
   Double32_t      recoGenJets_slimmedGenJets__PAT_obj_m_state_vertex__fCoordinates_fY[kMaxrecoGenJets_slimmedGenJets__PAT_obj];   //[recoGenJets_slimmedGenJets__PAT.obj_]
   Double32_t      recoGenJets_slimmedGenJets__PAT_obj_m_state_vertex__fCoordinates_fZ[kMaxrecoGenJets_slimmedGenJets__PAT_obj];   //[recoGenJets_slimmedGenJets__PAT.obj_]
   Double32_t      recoGenJets_slimmedGenJets__PAT_obj_m_state_p4Polar__fCoordinates_fPt[kMaxrecoGenJets_slimmedGenJets__PAT_obj];   //[recoGenJets_slimmedGenJets__PAT.obj_]
   Double32_t      recoGenJets_slimmedGenJets__PAT_obj_m_state_p4Polar__fCoordinates_fEta[kMaxrecoGenJets_slimmedGenJets__PAT_obj];   //[recoGenJets_slimmedGenJets__PAT.obj_]
   Double32_t      recoGenJets_slimmedGenJets__PAT_obj_m_state_p4Polar__fCoordinates_fPhi[kMaxrecoGenJets_slimmedGenJets__PAT_obj];   //[recoGenJets_slimmedGenJets__PAT.obj_]
   Double32_t      recoGenJets_slimmedGenJets__PAT_obj_m_state_p4Polar__fCoordinates_fM[kMaxrecoGenJets_slimmedGenJets__PAT_obj];   //[recoGenJets_slimmedGenJets__PAT.obj_]
   Int_t           recoGenJets_slimmedGenJets__PAT_obj_m_state_qx3_[kMaxrecoGenJets_slimmedGenJets__PAT_obj];   //[recoGenJets_slimmedGenJets__PAT.obj_]
   Int_t           recoGenJets_slimmedGenJets__PAT_obj_m_state_pdgId_[kMaxrecoGenJets_slimmedGenJets__PAT_obj];   //[recoGenJets_slimmedGenJets__PAT.obj_]
   Int_t           recoGenJets_slimmedGenJets__PAT_obj_m_state_status_[kMaxrecoGenJets_slimmedGenJets__PAT_obj];   //[recoGenJets_slimmedGenJets__PAT.obj_]
   vector<edm::Ptr<reco::Candidate> > recoGenJets_slimmedGenJets__PAT_obj_dau[kMaxrecoGenJets_slimmedGenJets__PAT_obj];
   Float_t         recoGenJets_slimmedGenJets__PAT_obj_mJetArea[kMaxrecoGenJets_slimmedGenJets__PAT_obj];   //[recoGenJets_slimmedGenJets__PAT.obj_]
   Float_t         recoGenJets_slimmedGenJets__PAT_obj_mPileupEnergy[kMaxrecoGenJets_slimmedGenJets__PAT_obj];   //[recoGenJets_slimmedGenJets__PAT.obj_]
   Int_t           recoGenJets_slimmedGenJets__PAT_obj_mPassNumber[kMaxrecoGenJets_slimmedGenJets__PAT_obj];   //[recoGenJets_slimmedGenJets__PAT.obj_]
   Bool_t          recoGenJets_slimmedGenJets__PAT_obj_mIsWeighted[kMaxrecoGenJets_slimmedGenJets__PAT_obj];   //[recoGenJets_slimmedGenJets__PAT.obj_]
   Float_t         recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_EmEnergy[kMaxrecoGenJets_slimmedGenJets__PAT_obj];   //[recoGenJets_slimmedGenJets__PAT.obj_]
   Float_t         recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_HadEnergy[kMaxrecoGenJets_slimmedGenJets__PAT_obj];   //[recoGenJets_slimmedGenJets__PAT.obj_]
   Float_t         recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_InvisibleEnergy[kMaxrecoGenJets_slimmedGenJets__PAT_obj];   //[recoGenJets_slimmedGenJets__PAT.obj_]
   Float_t         recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_AuxiliaryEnergy[kMaxrecoGenJets_slimmedGenJets__PAT_obj];   //[recoGenJets_slimmedGenJets__PAT.obj_]
   Float_t         recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_ChargedHadronEnergy[kMaxrecoGenJets_slimmedGenJets__PAT_obj];   //[recoGenJets_slimmedGenJets__PAT.obj_]
   Float_t         recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_NeutralHadronEnergy[kMaxrecoGenJets_slimmedGenJets__PAT_obj];   //[recoGenJets_slimmedGenJets__PAT.obj_]
   Float_t         recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_ChargedEmEnergy[kMaxrecoGenJets_slimmedGenJets__PAT_obj];   //[recoGenJets_slimmedGenJets__PAT.obj_]
   Float_t         recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_NeutralEmEnergy[kMaxrecoGenJets_slimmedGenJets__PAT_obj];   //[recoGenJets_slimmedGenJets__PAT.obj_]
   Float_t         recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_MuonEnergy[kMaxrecoGenJets_slimmedGenJets__PAT_obj];   //[recoGenJets_slimmedGenJets__PAT.obj_]
   Int_t           recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_ChargedHadronMultiplicity[kMaxrecoGenJets_slimmedGenJets__PAT_obj];   //[recoGenJets_slimmedGenJets__PAT.obj_]
   Int_t           recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_NeutralHadronMultiplicity[kMaxrecoGenJets_slimmedGenJets__PAT_obj];   //[recoGenJets_slimmedGenJets__PAT.obj_]
   Int_t           recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_ChargedEmMultiplicity[kMaxrecoGenJets_slimmedGenJets__PAT_obj];   //[recoGenJets_slimmedGenJets__PAT.obj_]
   Int_t           recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_NeutralEmMultiplicity[kMaxrecoGenJets_slimmedGenJets__PAT_obj];   //[recoGenJets_slimmedGenJets__PAT.obj_]
   Int_t           recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_MuonMultiplicity[kMaxrecoGenJets_slimmedGenJets__PAT_obj];   //[recoGenJets_slimmedGenJets__PAT.obj_]
   Bool_t          recoGenJets_slimmedGenJets__PAT_present;
 //edm::Wrapper<vector<reco::GenParticle> > *recoGenParticles_prunedGenParticles__PAT_;
   Int_t           recoGenParticles_prunedGenParticles__PAT_obj_;
   Double32_t      recoGenParticles_prunedGenParticles__PAT_obj_m_state_vertex__fCoordinates_fX[kMaxrecoGenParticles_prunedGenParticles__PAT_obj];   //[recoGenParticles_prunedGenParticles__PAT.obj_]
   Double32_t      recoGenParticles_prunedGenParticles__PAT_obj_m_state_vertex__fCoordinates_fY[kMaxrecoGenParticles_prunedGenParticles__PAT_obj];   //[recoGenParticles_prunedGenParticles__PAT.obj_]
   Double32_t      recoGenParticles_prunedGenParticles__PAT_obj_m_state_vertex__fCoordinates_fZ[kMaxrecoGenParticles_prunedGenParticles__PAT_obj];   //[recoGenParticles_prunedGenParticles__PAT.obj_]
   Double32_t      recoGenParticles_prunedGenParticles__PAT_obj_m_state_p4Polar__fCoordinates_fPt[kMaxrecoGenParticles_prunedGenParticles__PAT_obj];   //[recoGenParticles_prunedGenParticles__PAT.obj_]
   Double32_t      recoGenParticles_prunedGenParticles__PAT_obj_m_state_p4Polar__fCoordinates_fEta[kMaxrecoGenParticles_prunedGenParticles__PAT_obj];   //[recoGenParticles_prunedGenParticles__PAT.obj_]
   Double32_t      recoGenParticles_prunedGenParticles__PAT_obj_m_state_p4Polar__fCoordinates_fPhi[kMaxrecoGenParticles_prunedGenParticles__PAT_obj];   //[recoGenParticles_prunedGenParticles__PAT.obj_]
   Double32_t      recoGenParticles_prunedGenParticles__PAT_obj_m_state_p4Polar__fCoordinates_fM[kMaxrecoGenParticles_prunedGenParticles__PAT_obj];   //[recoGenParticles_prunedGenParticles__PAT.obj_]
   Int_t           recoGenParticles_prunedGenParticles__PAT_obj_m_state_qx3_[kMaxrecoGenParticles_prunedGenParticles__PAT_obj];   //[recoGenParticles_prunedGenParticles__PAT.obj_]
   Int_t           recoGenParticles_prunedGenParticles__PAT_obj_m_state_pdgId_[kMaxrecoGenParticles_prunedGenParticles__PAT_obj];   //[recoGenParticles_prunedGenParticles__PAT.obj_]
   Int_t           recoGenParticles_prunedGenParticles__PAT_obj_m_state_status_[kMaxrecoGenParticles_prunedGenParticles__PAT_obj];   //[recoGenParticles_prunedGenParticles__PAT.obj_]
   edm::RefCore    recoGenParticles_prunedGenParticles__PAT_obj_dau_refVector__product_[kMaxrecoGenParticles_prunedGenParticles__PAT_obj];
   vector<unsigned int> recoGenParticles_prunedGenParticles__PAT_obj_dau_refVector__keys_[kMaxrecoGenParticles_prunedGenParticles__PAT_obj];
   edm::RefCore    recoGenParticles_prunedGenParticles__PAT_obj_mom_refVector__product_[kMaxrecoGenParticles_prunedGenParticles__PAT_obj];
   vector<unsigned int> recoGenParticles_prunedGenParticles__PAT_obj_mom_refVector__keys_[kMaxrecoGenParticles_prunedGenParticles__PAT_obj];
   Int_t           recoGenParticles_prunedGenParticles__PAT_obj_collisionId_[kMaxrecoGenParticles_prunedGenParticles__PAT_obj];   //[recoGenParticles_prunedGenParticles__PAT.obj_]
   bitset<15>      recoGenParticles_prunedGenParticles__PAT_obj_statusFlags__flags_[kMaxrecoGenParticles_prunedGenParticles__PAT_obj];
   Bool_t          recoGenParticles_prunedGenParticles__PAT_present;

   // List of branches
   TBranch        *b_EventAuxiliary;   //!
   TBranch        *b_EventProductProvenance;   //!
   TBranch        *b_EventSelections;   //!
   TBranch        *b_BranchListIndexes;   //!
   TBranch        *b_GenEventInfoProduct_generator__SIM_obj;   //!
   TBranch        *b_GenEventInfoProduct_generator__SIM_present;   //!
   TBranch        *b_LHEEventProduct_externalLHEProducer__SIM_obj;   //!
   TBranch        *b_LHEEventProduct_externalLHEProducer__SIM_present;   //!
   TBranch        *b_recoGenParticlesedmAssociation_packedPFCandidateToGenAssociation__PAT_obj;   //!
   TBranch        *b_recoGenParticlesedmAssociation_packedPFCandidateToGenAssociation__PAT_present;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_m_state_vertex__fCoordinates_fX;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_m_state_vertex__fCoordinates_fY;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_m_state_vertex__fCoordinates_fZ;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_m_state_p4Polar__fCoordinates_fPt;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_m_state_p4Polar__fCoordinates_fEta;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_m_state_p4Polar__fCoordinates_fPhi;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_m_state_p4Polar__fCoordinates_fM;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_m_state_qx3_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_m_state_pdgId_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_m_state_status_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_dau;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_mJetArea;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_mPileupEnergy;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_mPassNumber;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_mIsWeighted;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_refToOrig__core_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_refToOrig__key_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_triggerObjectMatchesEmbedded_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_efficiencyValues_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_efficiencyNames_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_genParticleRef_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_genParticleEmbedded_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_overlapLabels_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_overlapItems_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_userDataLabels_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_userDataObjects__data_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_userFloatLabels_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_userFloats_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_userIntLabels_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_userInts_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_userCandLabels_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_userCands_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_kinResolutions_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_kinResolutionLabels_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_embeddedCaloTowers_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_caloTowers__obj;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_caloTowersFwdPtr_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_embeddedPFCandidates_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_pfCandidates_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_pfCandidatesFwdPtr_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_subjetCollections_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_subjetLabels_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_genJet_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_genJetRef__refVector__product_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_genJetRef__refVector__keys_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_genJetFwdRef__ref__product_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_genJetFwdRef__backRef__product_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_bHadrons_refVector__product_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_bHadrons_refVector__keys_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_cHadrons_refVector__product_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_cHadrons_refVector__keys_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_partons_refVector__product_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_partons_refVector__keys_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_leptons_refVector__product_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_leptons_refVector__keys_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_hadronFlavour;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_partonFlavour;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_jec_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_currentJECSet_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_currentJECLevel_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_currentJECFlavor_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_pairDiscriVector_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_tagInfoLabels_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_tagInfos__data_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_tagInfosFwdPtr_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_jetCharge_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_associatedTracks__refVector__product_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_associatedTracks__refVector__keys_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_specificCalo_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_specificJPT_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_specificPF_;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_jetID__fHPD;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_jetID__fRBX;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_jetID__n90Hits;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_jetID__fSubDetector1;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_jetID__fSubDetector2;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_jetID__fSubDetector3;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_jetID__fSubDetector4;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_jetID__restrictedEMF;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_jetID__nHCALTowers;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_jetID__nECALTowers;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_jetID__approximatefHPD;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_jetID__approximatefRBX;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_jetID__hitsInN90;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_jetID__numberOfHits2RPC;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_jetID__numberOfHits3RPC;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_jetID__numberOfHitsRPC;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_jetID__fEB;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_jetID__fEE;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_jetID__fHB;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_jetID__fHE;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_jetID__fHO;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_jetID__fLong;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_jetID__fShort;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_jetID__fLS;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_obj_jetID__fHFOOT;   //!
   TBranch        *b_patJets_slimmedJetsPuppi__PAT_present;   //!
   TBranch        *b_patMuons_slimmedMuons__PAT_obj;   //!
   TBranch        *b_patMuons_slimmedMuons__PAT_present;   //!
   TBranch        *b_patPackedCandidates_packedPFCandidates__PAT_obj_;   //!
   TBranch        *b_patPackedCandidates_packedPFCandidates__PAT_obj_packedPt_;   //!
   TBranch        *b_patPackedCandidates_packedPFCandidates__PAT_obj_packedEta_;   //!
   TBranch        *b_patPackedCandidates_packedPFCandidates__PAT_obj_packedPhi_;   //!
   TBranch        *b_patPackedCandidates_packedPFCandidates__PAT_obj_packedM_;   //!
   TBranch        *b_patPackedCandidates_packedPFCandidates__PAT_obj_packedDxy_;   //!
   TBranch        *b_patPackedCandidates_packedPFCandidates__PAT_obj_packedDz_;   //!
   TBranch        *b_patPackedCandidates_packedPFCandidates__PAT_obj_packedDPhi_;   //!
   TBranch        *b_patPackedCandidates_packedPFCandidates__PAT_obj_packedDEta_;   //!
   TBranch        *b_patPackedCandidates_packedPFCandidates__PAT_obj_packedDTrkPt_;   //!
   TBranch        *b_patPackedCandidates_packedPFCandidates__PAT_obj_packedCovariance__dxydxy;   //!
   TBranch        *b_patPackedCandidates_packedPFCandidates__PAT_obj_packedCovariance__dxydz;   //!
   TBranch        *b_patPackedCandidates_packedPFCandidates__PAT_obj_packedCovariance__dzdz;   //!
   TBranch        *b_patPackedCandidates_packedPFCandidates__PAT_obj_packedCovariance__dlambdadz;   //!
   TBranch        *b_patPackedCandidates_packedPFCandidates__PAT_obj_packedCovariance__dphidxy;   //!
   TBranch        *b_patPackedCandidates_packedPFCandidates__PAT_obj_packedCovariance__dptdpt;   //!
   TBranch        *b_patPackedCandidates_packedPFCandidates__PAT_obj_packedCovariance__detadeta;   //!
   TBranch        *b_patPackedCandidates_packedPFCandidates__PAT_obj_packedCovariance__dphidphi;   //!
   TBranch        *b_patPackedCandidates_packedPFCandidates__PAT_obj_packedPuppiweight_;   //!
   TBranch        *b_patPackedCandidates_packedPFCandidates__PAT_obj_packedPuppiweightNoLepDiff_;   //!
   TBranch        *b_patPackedCandidates_packedPFCandidates__PAT_obj_rawCaloFraction_;   //!
   TBranch        *b_patPackedCandidates_packedPFCandidates__PAT_obj_rawHcalFraction_;   //!
   TBranch        *b_patPackedCandidates_packedPFCandidates__PAT_obj_caloFraction_;   //!
   TBranch        *b_patPackedCandidates_packedPFCandidates__PAT_obj_hcalFraction_;   //!
   TBranch        *b_patPackedCandidates_packedPFCandidates__PAT_obj_packedTime_;   //!
   TBranch        *b_patPackedCandidates_packedPFCandidates__PAT_obj_packedTimeError_;   //!
   TBranch        *b_patPackedCandidates_packedPFCandidates__PAT_obj_isIsolatedChargedHadron_;   //!
   TBranch        *b_patPackedCandidates_packedPFCandidates__PAT_obj_pdgId_;   //!
   TBranch        *b_patPackedCandidates_packedPFCandidates__PAT_obj_qualityFlags_;   //!
   TBranch        *b_patPackedCandidates_packedPFCandidates__PAT_obj_pvRefProd__product_;   //!
   TBranch        *b_patPackedCandidates_packedPFCandidates__PAT_obj_pvRefKey_;   //!
   TBranch        *b_patPackedCandidates_packedPFCandidates__PAT_obj_packedHits_;   //!
   TBranch        *b_patPackedCandidates_packedPFCandidates__PAT_obj_packedLayers_;   //!
   TBranch        *b_patPackedCandidates_packedPFCandidates__PAT_obj_normalizedChi2_;   //!
   TBranch        *b_patPackedCandidates_packedPFCandidates__PAT_obj_covarianceVersion_;   //!
   TBranch        *b_patPackedCandidates_packedPFCandidates__PAT_obj_covarianceSchema_;   //!
   TBranch        *b_patPackedCandidates_packedPFCandidates__PAT_obj_firstHit_;   //!
   TBranch        *b_patPackedCandidates_packedPFCandidates__PAT_obj_trkAlgoPacked_;   //!
   TBranch        *b_patPackedCandidates_packedPFCandidates__PAT_present;   //!
   TBranch        *b_patPackedGenParticles_packedGenParticles__PAT_obj_;   //!
   TBranch        *b_patPackedGenParticles_packedGenParticles__PAT_obj_packedPt_;   //!
   TBranch        *b_patPackedGenParticles_packedGenParticles__PAT_obj_packedY_;   //!
   TBranch        *b_patPackedGenParticles_packedGenParticles__PAT_obj_packedPhi_;   //!
   TBranch        *b_patPackedGenParticles_packedGenParticles__PAT_obj_packedM_;   //!
   TBranch        *b_patPackedGenParticles_packedGenParticles__PAT_obj_vertex__fCoordinates_fX;   //!
   TBranch        *b_patPackedGenParticles_packedGenParticles__PAT_obj_vertex__fCoordinates_fY;   //!
   TBranch        *b_patPackedGenParticles_packedGenParticles__PAT_obj_vertex__fCoordinates_fZ;   //!
   TBranch        *b_patPackedGenParticles_packedGenParticles__PAT_obj_dxy_;   //!
   TBranch        *b_patPackedGenParticles_packedGenParticles__PAT_obj_dz_;   //!
   TBranch        *b_patPackedGenParticles_packedGenParticles__PAT_obj_dphi_;   //!
   TBranch        *b_patPackedGenParticles_packedGenParticles__PAT_obj_pdgId_;   //!
   TBranch        *b_patPackedGenParticles_packedGenParticles__PAT_obj_charge_;   //!
   TBranch        *b_patPackedGenParticles_packedGenParticles__PAT_obj_mother__product_;   //!
   TBranch        *b_patPackedGenParticles_packedGenParticles__PAT_obj_statusFlags__flags_;   //!
   TBranch        *b_patPackedGenParticles_packedGenParticles__PAT_present;   //!
   TBranch        *b_recoGenJets_slimmedGenJets__PAT_obj_;   //!
   TBranch        *b_recoGenJets_slimmedGenJets__PAT_obj_m_state_vertex__fCoordinates_fX;   //!
   TBranch        *b_recoGenJets_slimmedGenJets__PAT_obj_m_state_vertex__fCoordinates_fY;   //!
   TBranch        *b_recoGenJets_slimmedGenJets__PAT_obj_m_state_vertex__fCoordinates_fZ;   //!
   TBranch        *b_recoGenJets_slimmedGenJets__PAT_obj_m_state_p4Polar__fCoordinates_fPt;   //!
   TBranch        *b_recoGenJets_slimmedGenJets__PAT_obj_m_state_p4Polar__fCoordinates_fEta;   //!
   TBranch        *b_recoGenJets_slimmedGenJets__PAT_obj_m_state_p4Polar__fCoordinates_fPhi;   //!
   TBranch        *b_recoGenJets_slimmedGenJets__PAT_obj_m_state_p4Polar__fCoordinates_fM;   //!
   TBranch        *b_recoGenJets_slimmedGenJets__PAT_obj_m_state_qx3_;   //!
   TBranch        *b_recoGenJets_slimmedGenJets__PAT_obj_m_state_pdgId_;   //!
   TBranch        *b_recoGenJets_slimmedGenJets__PAT_obj_m_state_status_;   //!
   TBranch        *b_recoGenJets_slimmedGenJets__PAT_obj_dau;   //!
   TBranch        *b_recoGenJets_slimmedGenJets__PAT_obj_mJetArea;   //!
   TBranch        *b_recoGenJets_slimmedGenJets__PAT_obj_mPileupEnergy;   //!
   TBranch        *b_recoGenJets_slimmedGenJets__PAT_obj_mPassNumber;   //!
   TBranch        *b_recoGenJets_slimmedGenJets__PAT_obj_mIsWeighted;   //!
   TBranch        *b_recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_EmEnergy;   //!
   TBranch        *b_recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_HadEnergy;   //!
   TBranch        *b_recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_InvisibleEnergy;   //!
   TBranch        *b_recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_AuxiliaryEnergy;   //!
   TBranch        *b_recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_ChargedHadronEnergy;   //!
   TBranch        *b_recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_NeutralHadronEnergy;   //!
   TBranch        *b_recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_ChargedEmEnergy;   //!
   TBranch        *b_recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_NeutralEmEnergy;   //!
   TBranch        *b_recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_MuonEnergy;   //!
   TBranch        *b_recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_ChargedHadronMultiplicity;   //!
   TBranch        *b_recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_NeutralHadronMultiplicity;   //!
   TBranch        *b_recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_ChargedEmMultiplicity;   //!
   TBranch        *b_recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_NeutralEmMultiplicity;   //!
   TBranch        *b_recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_MuonMultiplicity;   //!
   TBranch        *b_recoGenJets_slimmedGenJets__PAT_present;   //!
   TBranch        *b_recoGenParticles_prunedGenParticles__PAT_obj_;   //!
   TBranch        *b_recoGenParticles_prunedGenParticles__PAT_obj_m_state_vertex__fCoordinates_fX;   //!
   TBranch        *b_recoGenParticles_prunedGenParticles__PAT_obj_m_state_vertex__fCoordinates_fY;   //!
   TBranch        *b_recoGenParticles_prunedGenParticles__PAT_obj_m_state_vertex__fCoordinates_fZ;   //!
   TBranch        *b_recoGenParticles_prunedGenParticles__PAT_obj_m_state_p4Polar__fCoordinates_fPt;   //!
   TBranch        *b_recoGenParticles_prunedGenParticles__PAT_obj_m_state_p4Polar__fCoordinates_fEta;   //!
   TBranch        *b_recoGenParticles_prunedGenParticles__PAT_obj_m_state_p4Polar__fCoordinates_fPhi;   //!
   TBranch        *b_recoGenParticles_prunedGenParticles__PAT_obj_m_state_p4Polar__fCoordinates_fM;   //!
   TBranch        *b_recoGenParticles_prunedGenParticles__PAT_obj_m_state_qx3_;   //!
   TBranch        *b_recoGenParticles_prunedGenParticles__PAT_obj_m_state_pdgId_;   //!
   TBranch        *b_recoGenParticles_prunedGenParticles__PAT_obj_m_state_status_;   //!
   TBranch        *b_recoGenParticles_prunedGenParticles__PAT_obj_dau_refVector__product_;   //!
   TBranch        *b_recoGenParticles_prunedGenParticles__PAT_obj_dau_refVector__keys_;   //!
   TBranch        *b_recoGenParticles_prunedGenParticles__PAT_obj_mom_refVector__product_;   //!
   TBranch        *b_recoGenParticles_prunedGenParticles__PAT_obj_mom_refVector__keys_;   //!
   TBranch        *b_recoGenParticles_prunedGenParticles__PAT_obj_collisionId_;   //!
   TBranch        *b_recoGenParticles_prunedGenParticles__PAT_obj_statusFlags__flags_;   //!
   TBranch        *b_recoGenParticles_prunedGenParticles__PAT_present;   //!

   JetTree(TTree *tree=0);
   virtual ~JetTree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef JetTree_cxx
JetTree::JetTree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/data1/users/dndus0107/skimmed_data/TTtoLNu2Q_TuneCP5_13p6TeV_powheg-pythia8/crab_TTtoLNu2Q_TuneCP5_13p6TeV_powheg-pythia8/250610_074241/0000/skimmed_data_21.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/data1/users/dndus0107/skimmed_data/TTtoLNu2Q_TuneCP5_13p6TeV_powheg-pythia8/crab_TTtoLNu2Q_TuneCP5_13p6TeV_powheg-pythia8/250610_074241/0000/skimmed_data_21.root");
      }
      f->GetObject("Events",tree);

   }
   Init(tree);
}

JetTree::~JetTree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t JetTree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t JetTree::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void JetTree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   EventAuxiliary = 0;
   EventProductProvenance = 0;
   EventSelections = 0;
   BranchListIndexes = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("EventAuxiliary", &EventAuxiliary, &b_EventAuxiliary);
   fChain->SetBranchAddress("EventProductProvenance", &EventProductProvenance, &b_EventProductProvenance);
   fChain->SetBranchAddress("EventSelections", &EventSelections, &b_EventSelections);
   fChain->SetBranchAddress("BranchListIndexes", &BranchListIndexes, &b_BranchListIndexes);
   fChain->SetBranchAddress("GenEventInfoProduct_generator__SIM.obj", &GenEventInfoProduct_generator__SIM_obj, &b_GenEventInfoProduct_generator__SIM_obj);
   fChain->SetBranchAddress("GenEventInfoProduct_generator__SIM.present", &GenEventInfoProduct_generator__SIM_present, &b_GenEventInfoProduct_generator__SIM_present);
   fChain->SetBranchAddress("LHEEventProduct_externalLHEProducer__SIM.obj", &LHEEventProduct_externalLHEProducer__SIM_obj, &b_LHEEventProduct_externalLHEProducer__SIM_obj);
   fChain->SetBranchAddress("LHEEventProduct_externalLHEProducer__SIM.present", &LHEEventProduct_externalLHEProducer__SIM_present, &b_LHEEventProduct_externalLHEProducer__SIM_present);
   fChain->SetBranchAddress("recoGenParticlesedmAssociation_packedPFCandidateToGenAssociation__PAT.obj", &recoGenParticlesedmAssociation_packedPFCandidateToGenAssociation__PAT_obj, &b_recoGenParticlesedmAssociation_packedPFCandidateToGenAssociation__PAT_obj);
   fChain->SetBranchAddress("recoGenParticlesedmAssociation_packedPFCandidateToGenAssociation__PAT.present", &recoGenParticlesedmAssociation_packedPFCandidateToGenAssociation__PAT_present, &b_recoGenParticlesedmAssociation_packedPFCandidateToGenAssociation__PAT_present);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj", &patJets_slimmedJetsPuppi__PAT_obj_, &b_patJets_slimmedJetsPuppi__PAT_obj_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.m_state.vertex_.fCoordinates.fX", patJets_slimmedJetsPuppi__PAT_obj_m_state_vertex__fCoordinates_fX, &b_patJets_slimmedJetsPuppi__PAT_obj_m_state_vertex__fCoordinates_fX);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.m_state.vertex_.fCoordinates.fY", patJets_slimmedJetsPuppi__PAT_obj_m_state_vertex__fCoordinates_fY, &b_patJets_slimmedJetsPuppi__PAT_obj_m_state_vertex__fCoordinates_fY);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.m_state.vertex_.fCoordinates.fZ", patJets_slimmedJetsPuppi__PAT_obj_m_state_vertex__fCoordinates_fZ, &b_patJets_slimmedJetsPuppi__PAT_obj_m_state_vertex__fCoordinates_fZ);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.m_state.p4Polar_.fCoordinates.fPt", patJets_slimmedJetsPuppi__PAT_obj_m_state_p4Polar__fCoordinates_fPt, &b_patJets_slimmedJetsPuppi__PAT_obj_m_state_p4Polar__fCoordinates_fPt);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.m_state.p4Polar_.fCoordinates.fEta", patJets_slimmedJetsPuppi__PAT_obj_m_state_p4Polar__fCoordinates_fEta, &b_patJets_slimmedJetsPuppi__PAT_obj_m_state_p4Polar__fCoordinates_fEta);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.m_state.p4Polar_.fCoordinates.fPhi", patJets_slimmedJetsPuppi__PAT_obj_m_state_p4Polar__fCoordinates_fPhi, &b_patJets_slimmedJetsPuppi__PAT_obj_m_state_p4Polar__fCoordinates_fPhi);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.m_state.p4Polar_.fCoordinates.fM", patJets_slimmedJetsPuppi__PAT_obj_m_state_p4Polar__fCoordinates_fM, &b_patJets_slimmedJetsPuppi__PAT_obj_m_state_p4Polar__fCoordinates_fM);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.m_state.qx3_", patJets_slimmedJetsPuppi__PAT_obj_m_state_qx3_, &b_patJets_slimmedJetsPuppi__PAT_obj_m_state_qx3_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.m_state.pdgId_", patJets_slimmedJetsPuppi__PAT_obj_m_state_pdgId_, &b_patJets_slimmedJetsPuppi__PAT_obj_m_state_pdgId_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.m_state.status_", patJets_slimmedJetsPuppi__PAT_obj_m_state_status_, &b_patJets_slimmedJetsPuppi__PAT_obj_m_state_status_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.dau", patJets_slimmedJetsPuppi__PAT_obj_dau, &b_patJets_slimmedJetsPuppi__PAT_obj_dau);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.mJetArea", patJets_slimmedJetsPuppi__PAT_obj_mJetArea, &b_patJets_slimmedJetsPuppi__PAT_obj_mJetArea);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.mPileupEnergy", patJets_slimmedJetsPuppi__PAT_obj_mPileupEnergy, &b_patJets_slimmedJetsPuppi__PAT_obj_mPileupEnergy);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.mPassNumber", patJets_slimmedJetsPuppi__PAT_obj_mPassNumber, &b_patJets_slimmedJetsPuppi__PAT_obj_mPassNumber);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.mIsWeighted", patJets_slimmedJetsPuppi__PAT_obj_mIsWeighted, &b_patJets_slimmedJetsPuppi__PAT_obj_mIsWeighted);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.refToOrig_.core_", patJets_slimmedJetsPuppi__PAT_obj_refToOrig__core_, &b_patJets_slimmedJetsPuppi__PAT_obj_refToOrig__core_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.refToOrig_.key_", patJets_slimmedJetsPuppi__PAT_obj_refToOrig__key_, &b_patJets_slimmedJetsPuppi__PAT_obj_refToOrig__key_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.triggerObjectMatchesEmbedded_", patJets_slimmedJetsPuppi__PAT_obj_triggerObjectMatchesEmbedded_, &b_patJets_slimmedJetsPuppi__PAT_obj_triggerObjectMatchesEmbedded_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.efficiencyValues_", patJets_slimmedJetsPuppi__PAT_obj_efficiencyValues_, &b_patJets_slimmedJetsPuppi__PAT_obj_efficiencyValues_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.efficiencyNames_", patJets_slimmedJetsPuppi__PAT_obj_efficiencyNames_, &b_patJets_slimmedJetsPuppi__PAT_obj_efficiencyNames_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.genParticleRef_", patJets_slimmedJetsPuppi__PAT_obj_genParticleRef_, &b_patJets_slimmedJetsPuppi__PAT_obj_genParticleRef_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.genParticleEmbedded_", patJets_slimmedJetsPuppi__PAT_obj_genParticleEmbedded_, &b_patJets_slimmedJetsPuppi__PAT_obj_genParticleEmbedded_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.overlapLabels_", patJets_slimmedJetsPuppi__PAT_obj_overlapLabels_, &b_patJets_slimmedJetsPuppi__PAT_obj_overlapLabels_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.overlapItems_", patJets_slimmedJetsPuppi__PAT_obj_overlapItems_, &b_patJets_slimmedJetsPuppi__PAT_obj_overlapItems_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.userDataLabels_", patJets_slimmedJetsPuppi__PAT_obj_userDataLabels_, &b_patJets_slimmedJetsPuppi__PAT_obj_userDataLabels_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.userDataObjects_.data_", patJets_slimmedJetsPuppi__PAT_obj_userDataObjects__data_, &b_patJets_slimmedJetsPuppi__PAT_obj_userDataObjects__data_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.userFloatLabels_", patJets_slimmedJetsPuppi__PAT_obj_userFloatLabels_, &b_patJets_slimmedJetsPuppi__PAT_obj_userFloatLabels_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.userFloats_", patJets_slimmedJetsPuppi__PAT_obj_userFloats_, &b_patJets_slimmedJetsPuppi__PAT_obj_userFloats_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.userIntLabels_", patJets_slimmedJetsPuppi__PAT_obj_userIntLabels_, &b_patJets_slimmedJetsPuppi__PAT_obj_userIntLabels_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.userInts_", patJets_slimmedJetsPuppi__PAT_obj_userInts_, &b_patJets_slimmedJetsPuppi__PAT_obj_userInts_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.userCandLabels_", patJets_slimmedJetsPuppi__PAT_obj_userCandLabels_, &b_patJets_slimmedJetsPuppi__PAT_obj_userCandLabels_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.userCands_", patJets_slimmedJetsPuppi__PAT_obj_userCands_, &b_patJets_slimmedJetsPuppi__PAT_obj_userCands_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.kinResolutions_", patJets_slimmedJetsPuppi__PAT_obj_kinResolutions_, &b_patJets_slimmedJetsPuppi__PAT_obj_kinResolutions_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.kinResolutionLabels_", patJets_slimmedJetsPuppi__PAT_obj_kinResolutionLabels_, &b_patJets_slimmedJetsPuppi__PAT_obj_kinResolutionLabels_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.embeddedCaloTowers_", patJets_slimmedJetsPuppi__PAT_obj_embeddedCaloTowers_, &b_patJets_slimmedJetsPuppi__PAT_obj_embeddedCaloTowers_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.caloTowers_.obj", patJets_slimmedJetsPuppi__PAT_obj_caloTowers__obj, &b_patJets_slimmedJetsPuppi__PAT_obj_caloTowers__obj);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.caloTowersFwdPtr_", patJets_slimmedJetsPuppi__PAT_obj_caloTowersFwdPtr_, &b_patJets_slimmedJetsPuppi__PAT_obj_caloTowersFwdPtr_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.embeddedPFCandidates_", patJets_slimmedJetsPuppi__PAT_obj_embeddedPFCandidates_, &b_patJets_slimmedJetsPuppi__PAT_obj_embeddedPFCandidates_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.pfCandidates_", patJets_slimmedJetsPuppi__PAT_obj_pfCandidates_, &b_patJets_slimmedJetsPuppi__PAT_obj_pfCandidates_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.pfCandidatesFwdPtr_", patJets_slimmedJetsPuppi__PAT_obj_pfCandidatesFwdPtr_, &b_patJets_slimmedJetsPuppi__PAT_obj_pfCandidatesFwdPtr_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.subjetCollections_", patJets_slimmedJetsPuppi__PAT_obj_subjetCollections_, &b_patJets_slimmedJetsPuppi__PAT_obj_subjetCollections_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.subjetLabels_", patJets_slimmedJetsPuppi__PAT_obj_subjetLabels_, &b_patJets_slimmedJetsPuppi__PAT_obj_subjetLabels_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.genJet_", patJets_slimmedJetsPuppi__PAT_obj_genJet_, &b_patJets_slimmedJetsPuppi__PAT_obj_genJet_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.genJetRef_.refVector_.product_", patJets_slimmedJetsPuppi__PAT_obj_genJetRef__refVector__product_, &b_patJets_slimmedJetsPuppi__PAT_obj_genJetRef__refVector__product_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.genJetRef_.refVector_.keys_", patJets_slimmedJetsPuppi__PAT_obj_genJetRef__refVector__keys_, &b_patJets_slimmedJetsPuppi__PAT_obj_genJetRef__refVector__keys_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.genJetFwdRef_.ref_.product_", patJets_slimmedJetsPuppi__PAT_obj_genJetFwdRef__ref__product_, &b_patJets_slimmedJetsPuppi__PAT_obj_genJetFwdRef__ref__product_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.genJetFwdRef_.backRef_.product_", patJets_slimmedJetsPuppi__PAT_obj_genJetFwdRef__backRef__product_, &b_patJets_slimmedJetsPuppi__PAT_obj_genJetFwdRef__backRef__product_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.jetFlavourInfo_.m_bHadrons.refVector_.product_", patJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_bHadrons_refVector__product_, &b_patJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_bHadrons_refVector__product_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.jetFlavourInfo_.m_bHadrons.refVector_.keys_", patJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_bHadrons_refVector__keys_, &b_patJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_bHadrons_refVector__keys_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.jetFlavourInfo_.m_cHadrons.refVector_.product_", patJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_cHadrons_refVector__product_, &b_patJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_cHadrons_refVector__product_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.jetFlavourInfo_.m_cHadrons.refVector_.keys_", patJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_cHadrons_refVector__keys_, &b_patJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_cHadrons_refVector__keys_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.jetFlavourInfo_.m_partons.refVector_.product_", patJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_partons_refVector__product_, &b_patJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_partons_refVector__product_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.jetFlavourInfo_.m_partons.refVector_.keys_", patJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_partons_refVector__keys_, &b_patJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_partons_refVector__keys_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.jetFlavourInfo_.m_leptons.refVector_.product_", patJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_leptons_refVector__product_, &b_patJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_leptons_refVector__product_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.jetFlavourInfo_.m_leptons.refVector_.keys_", patJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_leptons_refVector__keys_, &b_patJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_leptons_refVector__keys_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.jetFlavourInfo_.m_hadronFlavour", patJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_hadronFlavour, &b_patJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_hadronFlavour);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.jetFlavourInfo_.m_partonFlavour", patJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_partonFlavour, &b_patJets_slimmedJetsPuppi__PAT_obj_jetFlavourInfo__m_partonFlavour);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.jec_", patJets_slimmedJetsPuppi__PAT_obj_jec_, &b_patJets_slimmedJetsPuppi__PAT_obj_jec_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.currentJECSet_", patJets_slimmedJetsPuppi__PAT_obj_currentJECSet_, &b_patJets_slimmedJetsPuppi__PAT_obj_currentJECSet_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.currentJECLevel_", patJets_slimmedJetsPuppi__PAT_obj_currentJECLevel_, &b_patJets_slimmedJetsPuppi__PAT_obj_currentJECLevel_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.currentJECFlavor_", patJets_slimmedJetsPuppi__PAT_obj_currentJECFlavor_, &b_patJets_slimmedJetsPuppi__PAT_obj_currentJECFlavor_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.pairDiscriVector_", patJets_slimmedJetsPuppi__PAT_obj_pairDiscriVector_, &b_patJets_slimmedJetsPuppi__PAT_obj_pairDiscriVector_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.tagInfoLabels_", patJets_slimmedJetsPuppi__PAT_obj_tagInfoLabels_, &b_patJets_slimmedJetsPuppi__PAT_obj_tagInfoLabels_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.tagInfos_.data_", patJets_slimmedJetsPuppi__PAT_obj_tagInfos__data_, &b_patJets_slimmedJetsPuppi__PAT_obj_tagInfos__data_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.tagInfosFwdPtr_", patJets_slimmedJetsPuppi__PAT_obj_tagInfosFwdPtr_, &b_patJets_slimmedJetsPuppi__PAT_obj_tagInfosFwdPtr_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.jetCharge_", patJets_slimmedJetsPuppi__PAT_obj_jetCharge_, &b_patJets_slimmedJetsPuppi__PAT_obj_jetCharge_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.associatedTracks_.refVector_.product_", patJets_slimmedJetsPuppi__PAT_obj_associatedTracks__refVector__product_, &b_patJets_slimmedJetsPuppi__PAT_obj_associatedTracks__refVector__product_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.associatedTracks_.refVector_.keys_", patJets_slimmedJetsPuppi__PAT_obj_associatedTracks__refVector__keys_, &b_patJets_slimmedJetsPuppi__PAT_obj_associatedTracks__refVector__keys_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.specificCalo_", patJets_slimmedJetsPuppi__PAT_obj_specificCalo_, &b_patJets_slimmedJetsPuppi__PAT_obj_specificCalo_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.specificJPT_", patJets_slimmedJetsPuppi__PAT_obj_specificJPT_, &b_patJets_slimmedJetsPuppi__PAT_obj_specificJPT_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.specificPF_", patJets_slimmedJetsPuppi__PAT_obj_specificPF_, &b_patJets_slimmedJetsPuppi__PAT_obj_specificPF_);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.jetID_.fHPD", patJets_slimmedJetsPuppi__PAT_obj_jetID__fHPD, &b_patJets_slimmedJetsPuppi__PAT_obj_jetID__fHPD);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.jetID_.fRBX", patJets_slimmedJetsPuppi__PAT_obj_jetID__fRBX, &b_patJets_slimmedJetsPuppi__PAT_obj_jetID__fRBX);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.jetID_.n90Hits", patJets_slimmedJetsPuppi__PAT_obj_jetID__n90Hits, &b_patJets_slimmedJetsPuppi__PAT_obj_jetID__n90Hits);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.jetID_.fSubDetector1", patJets_slimmedJetsPuppi__PAT_obj_jetID__fSubDetector1, &b_patJets_slimmedJetsPuppi__PAT_obj_jetID__fSubDetector1);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.jetID_.fSubDetector2", patJets_slimmedJetsPuppi__PAT_obj_jetID__fSubDetector2, &b_patJets_slimmedJetsPuppi__PAT_obj_jetID__fSubDetector2);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.jetID_.fSubDetector3", patJets_slimmedJetsPuppi__PAT_obj_jetID__fSubDetector3, &b_patJets_slimmedJetsPuppi__PAT_obj_jetID__fSubDetector3);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.jetID_.fSubDetector4", patJets_slimmedJetsPuppi__PAT_obj_jetID__fSubDetector4, &b_patJets_slimmedJetsPuppi__PAT_obj_jetID__fSubDetector4);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.jetID_.restrictedEMF", patJets_slimmedJetsPuppi__PAT_obj_jetID__restrictedEMF, &b_patJets_slimmedJetsPuppi__PAT_obj_jetID__restrictedEMF);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.jetID_.nHCALTowers", patJets_slimmedJetsPuppi__PAT_obj_jetID__nHCALTowers, &b_patJets_slimmedJetsPuppi__PAT_obj_jetID__nHCALTowers);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.jetID_.nECALTowers", patJets_slimmedJetsPuppi__PAT_obj_jetID__nECALTowers, &b_patJets_slimmedJetsPuppi__PAT_obj_jetID__nECALTowers);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.jetID_.approximatefHPD", patJets_slimmedJetsPuppi__PAT_obj_jetID__approximatefHPD, &b_patJets_slimmedJetsPuppi__PAT_obj_jetID__approximatefHPD);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.jetID_.approximatefRBX", patJets_slimmedJetsPuppi__PAT_obj_jetID__approximatefRBX, &b_patJets_slimmedJetsPuppi__PAT_obj_jetID__approximatefRBX);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.jetID_.hitsInN90", patJets_slimmedJetsPuppi__PAT_obj_jetID__hitsInN90, &b_patJets_slimmedJetsPuppi__PAT_obj_jetID__hitsInN90);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.jetID_.numberOfHits2RPC", patJets_slimmedJetsPuppi__PAT_obj_jetID__numberOfHits2RPC, &b_patJets_slimmedJetsPuppi__PAT_obj_jetID__numberOfHits2RPC);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.jetID_.numberOfHits3RPC", patJets_slimmedJetsPuppi__PAT_obj_jetID__numberOfHits3RPC, &b_patJets_slimmedJetsPuppi__PAT_obj_jetID__numberOfHits3RPC);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.jetID_.numberOfHitsRPC", patJets_slimmedJetsPuppi__PAT_obj_jetID__numberOfHitsRPC, &b_patJets_slimmedJetsPuppi__PAT_obj_jetID__numberOfHitsRPC);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.jetID_.fEB", patJets_slimmedJetsPuppi__PAT_obj_jetID__fEB, &b_patJets_slimmedJetsPuppi__PAT_obj_jetID__fEB);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.jetID_.fEE", patJets_slimmedJetsPuppi__PAT_obj_jetID__fEE, &b_patJets_slimmedJetsPuppi__PAT_obj_jetID__fEE);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.jetID_.fHB", patJets_slimmedJetsPuppi__PAT_obj_jetID__fHB, &b_patJets_slimmedJetsPuppi__PAT_obj_jetID__fHB);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.jetID_.fHE", patJets_slimmedJetsPuppi__PAT_obj_jetID__fHE, &b_patJets_slimmedJetsPuppi__PAT_obj_jetID__fHE);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.jetID_.fHO", patJets_slimmedJetsPuppi__PAT_obj_jetID__fHO, &b_patJets_slimmedJetsPuppi__PAT_obj_jetID__fHO);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.jetID_.fLong", patJets_slimmedJetsPuppi__PAT_obj_jetID__fLong, &b_patJets_slimmedJetsPuppi__PAT_obj_jetID__fLong);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.jetID_.fShort", patJets_slimmedJetsPuppi__PAT_obj_jetID__fShort, &b_patJets_slimmedJetsPuppi__PAT_obj_jetID__fShort);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.jetID_.fLS", patJets_slimmedJetsPuppi__PAT_obj_jetID__fLS, &b_patJets_slimmedJetsPuppi__PAT_obj_jetID__fLS);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.obj.jetID_.fHFOOT", patJets_slimmedJetsPuppi__PAT_obj_jetID__fHFOOT, &b_patJets_slimmedJetsPuppi__PAT_obj_jetID__fHFOOT);
   fChain->SetBranchAddress("patJets_slimmedJetsPuppi__PAT.present", &patJets_slimmedJetsPuppi__PAT_present, &b_patJets_slimmedJetsPuppi__PAT_present);
   fChain->SetBranchAddress("patMuons_slimmedMuons__PAT.obj", &patMuons_slimmedMuons__PAT_obj, &b_patMuons_slimmedMuons__PAT_obj);
   fChain->SetBranchAddress("patMuons_slimmedMuons__PAT.present", &patMuons_slimmedMuons__PAT_present, &b_patMuons_slimmedMuons__PAT_present);
   fChain->SetBranchAddress("patPackedCandidates_packedPFCandidates__PAT.obj", &patPackedCandidates_packedPFCandidates__PAT_obj_, &b_patPackedCandidates_packedPFCandidates__PAT_obj_);
   fChain->SetBranchAddress("patPackedCandidates_packedPFCandidates__PAT.obj.packedPt_", patPackedCandidates_packedPFCandidates__PAT_obj_packedPt_, &b_patPackedCandidates_packedPFCandidates__PAT_obj_packedPt_);
   fChain->SetBranchAddress("patPackedCandidates_packedPFCandidates__PAT.obj.packedEta_", patPackedCandidates_packedPFCandidates__PAT_obj_packedEta_, &b_patPackedCandidates_packedPFCandidates__PAT_obj_packedEta_);
   fChain->SetBranchAddress("patPackedCandidates_packedPFCandidates__PAT.obj.packedPhi_", patPackedCandidates_packedPFCandidates__PAT_obj_packedPhi_, &b_patPackedCandidates_packedPFCandidates__PAT_obj_packedPhi_);
   fChain->SetBranchAddress("patPackedCandidates_packedPFCandidates__PAT.obj.packedM_", patPackedCandidates_packedPFCandidates__PAT_obj_packedM_, &b_patPackedCandidates_packedPFCandidates__PAT_obj_packedM_);
   fChain->SetBranchAddress("patPackedCandidates_packedPFCandidates__PAT.obj.packedDxy_", patPackedCandidates_packedPFCandidates__PAT_obj_packedDxy_, &b_patPackedCandidates_packedPFCandidates__PAT_obj_packedDxy_);
   fChain->SetBranchAddress("patPackedCandidates_packedPFCandidates__PAT.obj.packedDz_", patPackedCandidates_packedPFCandidates__PAT_obj_packedDz_, &b_patPackedCandidates_packedPFCandidates__PAT_obj_packedDz_);
   fChain->SetBranchAddress("patPackedCandidates_packedPFCandidates__PAT.obj.packedDPhi_", patPackedCandidates_packedPFCandidates__PAT_obj_packedDPhi_, &b_patPackedCandidates_packedPFCandidates__PAT_obj_packedDPhi_);
   fChain->SetBranchAddress("patPackedCandidates_packedPFCandidates__PAT.obj.packedDEta_", patPackedCandidates_packedPFCandidates__PAT_obj_packedDEta_, &b_patPackedCandidates_packedPFCandidates__PAT_obj_packedDEta_);
   fChain->SetBranchAddress("patPackedCandidates_packedPFCandidates__PAT.obj.packedDTrkPt_", patPackedCandidates_packedPFCandidates__PAT_obj_packedDTrkPt_, &b_patPackedCandidates_packedPFCandidates__PAT_obj_packedDTrkPt_);
   fChain->SetBranchAddress("patPackedCandidates_packedPFCandidates__PAT.obj.packedCovariance_.dxydxy", patPackedCandidates_packedPFCandidates__PAT_obj_packedCovariance__dxydxy, &b_patPackedCandidates_packedPFCandidates__PAT_obj_packedCovariance__dxydxy);
   fChain->SetBranchAddress("patPackedCandidates_packedPFCandidates__PAT.obj.packedCovariance_.dxydz", patPackedCandidates_packedPFCandidates__PAT_obj_packedCovariance__dxydz, &b_patPackedCandidates_packedPFCandidates__PAT_obj_packedCovariance__dxydz);
   fChain->SetBranchAddress("patPackedCandidates_packedPFCandidates__PAT.obj.packedCovariance_.dzdz", patPackedCandidates_packedPFCandidates__PAT_obj_packedCovariance__dzdz, &b_patPackedCandidates_packedPFCandidates__PAT_obj_packedCovariance__dzdz);
   fChain->SetBranchAddress("patPackedCandidates_packedPFCandidates__PAT.obj.packedCovariance_.dlambdadz", patPackedCandidates_packedPFCandidates__PAT_obj_packedCovariance__dlambdadz, &b_patPackedCandidates_packedPFCandidates__PAT_obj_packedCovariance__dlambdadz);
   fChain->SetBranchAddress("patPackedCandidates_packedPFCandidates__PAT.obj.packedCovariance_.dphidxy", patPackedCandidates_packedPFCandidates__PAT_obj_packedCovariance__dphidxy, &b_patPackedCandidates_packedPFCandidates__PAT_obj_packedCovariance__dphidxy);
   fChain->SetBranchAddress("patPackedCandidates_packedPFCandidates__PAT.obj.packedCovariance_.dptdpt", patPackedCandidates_packedPFCandidates__PAT_obj_packedCovariance__dptdpt, &b_patPackedCandidates_packedPFCandidates__PAT_obj_packedCovariance__dptdpt);
   fChain->SetBranchAddress("patPackedCandidates_packedPFCandidates__PAT.obj.packedCovariance_.detadeta", patPackedCandidates_packedPFCandidates__PAT_obj_packedCovariance__detadeta, &b_patPackedCandidates_packedPFCandidates__PAT_obj_packedCovariance__detadeta);
   fChain->SetBranchAddress("patPackedCandidates_packedPFCandidates__PAT.obj.packedCovariance_.dphidphi", patPackedCandidates_packedPFCandidates__PAT_obj_packedCovariance__dphidphi, &b_patPackedCandidates_packedPFCandidates__PAT_obj_packedCovariance__dphidphi);
   fChain->SetBranchAddress("patPackedCandidates_packedPFCandidates__PAT.obj.packedPuppiweight_", patPackedCandidates_packedPFCandidates__PAT_obj_packedPuppiweight_, &b_patPackedCandidates_packedPFCandidates__PAT_obj_packedPuppiweight_);
   fChain->SetBranchAddress("patPackedCandidates_packedPFCandidates__PAT.obj.packedPuppiweightNoLepDiff_", patPackedCandidates_packedPFCandidates__PAT_obj_packedPuppiweightNoLepDiff_, &b_patPackedCandidates_packedPFCandidates__PAT_obj_packedPuppiweightNoLepDiff_);
   fChain->SetBranchAddress("patPackedCandidates_packedPFCandidates__PAT.obj.rawCaloFraction_", patPackedCandidates_packedPFCandidates__PAT_obj_rawCaloFraction_, &b_patPackedCandidates_packedPFCandidates__PAT_obj_rawCaloFraction_);
   fChain->SetBranchAddress("patPackedCandidates_packedPFCandidates__PAT.obj.rawHcalFraction_", patPackedCandidates_packedPFCandidates__PAT_obj_rawHcalFraction_, &b_patPackedCandidates_packedPFCandidates__PAT_obj_rawHcalFraction_);
   fChain->SetBranchAddress("patPackedCandidates_packedPFCandidates__PAT.obj.caloFraction_", patPackedCandidates_packedPFCandidates__PAT_obj_caloFraction_, &b_patPackedCandidates_packedPFCandidates__PAT_obj_caloFraction_);
   fChain->SetBranchAddress("patPackedCandidates_packedPFCandidates__PAT.obj.hcalFraction_", patPackedCandidates_packedPFCandidates__PAT_obj_hcalFraction_, &b_patPackedCandidates_packedPFCandidates__PAT_obj_hcalFraction_);
   fChain->SetBranchAddress("patPackedCandidates_packedPFCandidates__PAT.obj.packedTime_", patPackedCandidates_packedPFCandidates__PAT_obj_packedTime_, &b_patPackedCandidates_packedPFCandidates__PAT_obj_packedTime_);
   fChain->SetBranchAddress("patPackedCandidates_packedPFCandidates__PAT.obj.packedTimeError_", patPackedCandidates_packedPFCandidates__PAT_obj_packedTimeError_, &b_patPackedCandidates_packedPFCandidates__PAT_obj_packedTimeError_);
   fChain->SetBranchAddress("patPackedCandidates_packedPFCandidates__PAT.obj.isIsolatedChargedHadron_", patPackedCandidates_packedPFCandidates__PAT_obj_isIsolatedChargedHadron_, &b_patPackedCandidates_packedPFCandidates__PAT_obj_isIsolatedChargedHadron_);
   fChain->SetBranchAddress("patPackedCandidates_packedPFCandidates__PAT.obj.pdgId_", patPackedCandidates_packedPFCandidates__PAT_obj_pdgId_, &b_patPackedCandidates_packedPFCandidates__PAT_obj_pdgId_);
   fChain->SetBranchAddress("patPackedCandidates_packedPFCandidates__PAT.obj.qualityFlags_", patPackedCandidates_packedPFCandidates__PAT_obj_qualityFlags_, &b_patPackedCandidates_packedPFCandidates__PAT_obj_qualityFlags_);
   fChain->SetBranchAddress("patPackedCandidates_packedPFCandidates__PAT.obj.pvRefProd_.product_", patPackedCandidates_packedPFCandidates__PAT_obj_pvRefProd__product_, &b_patPackedCandidates_packedPFCandidates__PAT_obj_pvRefProd__product_);
   fChain->SetBranchAddress("patPackedCandidates_packedPFCandidates__PAT.obj.pvRefKey_", patPackedCandidates_packedPFCandidates__PAT_obj_pvRefKey_, &b_patPackedCandidates_packedPFCandidates__PAT_obj_pvRefKey_);
   fChain->SetBranchAddress("patPackedCandidates_packedPFCandidates__PAT.obj.packedHits_", patPackedCandidates_packedPFCandidates__PAT_obj_packedHits_, &b_patPackedCandidates_packedPFCandidates__PAT_obj_packedHits_);
   fChain->SetBranchAddress("patPackedCandidates_packedPFCandidates__PAT.obj.packedLayers_", patPackedCandidates_packedPFCandidates__PAT_obj_packedLayers_, &b_patPackedCandidates_packedPFCandidates__PAT_obj_packedLayers_);
   fChain->SetBranchAddress("patPackedCandidates_packedPFCandidates__PAT.obj.normalizedChi2_", patPackedCandidates_packedPFCandidates__PAT_obj_normalizedChi2_, &b_patPackedCandidates_packedPFCandidates__PAT_obj_normalizedChi2_);
   fChain->SetBranchAddress("patPackedCandidates_packedPFCandidates__PAT.obj.covarianceVersion_", patPackedCandidates_packedPFCandidates__PAT_obj_covarianceVersion_, &b_patPackedCandidates_packedPFCandidates__PAT_obj_covarianceVersion_);
   fChain->SetBranchAddress("patPackedCandidates_packedPFCandidates__PAT.obj.covarianceSchema_", patPackedCandidates_packedPFCandidates__PAT_obj_covarianceSchema_, &b_patPackedCandidates_packedPFCandidates__PAT_obj_covarianceSchema_);
   fChain->SetBranchAddress("patPackedCandidates_packedPFCandidates__PAT.obj.firstHit_", patPackedCandidates_packedPFCandidates__PAT_obj_firstHit_, &b_patPackedCandidates_packedPFCandidates__PAT_obj_firstHit_);
   fChain->SetBranchAddress("patPackedCandidates_packedPFCandidates__PAT.obj.trkAlgoPacked_", patPackedCandidates_packedPFCandidates__PAT_obj_trkAlgoPacked_, &b_patPackedCandidates_packedPFCandidates__PAT_obj_trkAlgoPacked_);
   fChain->SetBranchAddress("patPackedCandidates_packedPFCandidates__PAT.present", &patPackedCandidates_packedPFCandidates__PAT_present, &b_patPackedCandidates_packedPFCandidates__PAT_present);
   fChain->SetBranchAddress("patPackedGenParticles_packedGenParticles__PAT.obj", &patPackedGenParticles_packedGenParticles__PAT_obj_, &b_patPackedGenParticles_packedGenParticles__PAT_obj_);
   fChain->SetBranchAddress("patPackedGenParticles_packedGenParticles__PAT.obj.packedPt_", patPackedGenParticles_packedGenParticles__PAT_obj_packedPt_, &b_patPackedGenParticles_packedGenParticles__PAT_obj_packedPt_);
   fChain->SetBranchAddress("patPackedGenParticles_packedGenParticles__PAT.obj.packedY_", patPackedGenParticles_packedGenParticles__PAT_obj_packedY_, &b_patPackedGenParticles_packedGenParticles__PAT_obj_packedY_);
   fChain->SetBranchAddress("patPackedGenParticles_packedGenParticles__PAT.obj.packedPhi_", patPackedGenParticles_packedGenParticles__PAT_obj_packedPhi_, &b_patPackedGenParticles_packedGenParticles__PAT_obj_packedPhi_);
   fChain->SetBranchAddress("patPackedGenParticles_packedGenParticles__PAT.obj.packedM_", patPackedGenParticles_packedGenParticles__PAT_obj_packedM_, &b_patPackedGenParticles_packedGenParticles__PAT_obj_packedM_);
   fChain->SetBranchAddress("patPackedGenParticles_packedGenParticles__PAT.obj.vertex_.fCoordinates.fX", patPackedGenParticles_packedGenParticles__PAT_obj_vertex__fCoordinates_fX, &b_patPackedGenParticles_packedGenParticles__PAT_obj_vertex__fCoordinates_fX);
   fChain->SetBranchAddress("patPackedGenParticles_packedGenParticles__PAT.obj.vertex_.fCoordinates.fY", patPackedGenParticles_packedGenParticles__PAT_obj_vertex__fCoordinates_fY, &b_patPackedGenParticles_packedGenParticles__PAT_obj_vertex__fCoordinates_fY);
   fChain->SetBranchAddress("patPackedGenParticles_packedGenParticles__PAT.obj.vertex_.fCoordinates.fZ", patPackedGenParticles_packedGenParticles__PAT_obj_vertex__fCoordinates_fZ, &b_patPackedGenParticles_packedGenParticles__PAT_obj_vertex__fCoordinates_fZ);
   fChain->SetBranchAddress("patPackedGenParticles_packedGenParticles__PAT.obj.dxy_", patPackedGenParticles_packedGenParticles__PAT_obj_dxy_, &b_patPackedGenParticles_packedGenParticles__PAT_obj_dxy_);
   fChain->SetBranchAddress("patPackedGenParticles_packedGenParticles__PAT.obj.dz_", patPackedGenParticles_packedGenParticles__PAT_obj_dz_, &b_patPackedGenParticles_packedGenParticles__PAT_obj_dz_);
   fChain->SetBranchAddress("patPackedGenParticles_packedGenParticles__PAT.obj.dphi_", patPackedGenParticles_packedGenParticles__PAT_obj_dphi_, &b_patPackedGenParticles_packedGenParticles__PAT_obj_dphi_);
   fChain->SetBranchAddress("patPackedGenParticles_packedGenParticles__PAT.obj.pdgId_", patPackedGenParticles_packedGenParticles__PAT_obj_pdgId_, &b_patPackedGenParticles_packedGenParticles__PAT_obj_pdgId_);
   fChain->SetBranchAddress("patPackedGenParticles_packedGenParticles__PAT.obj.charge_", patPackedGenParticles_packedGenParticles__PAT_obj_charge_, &b_patPackedGenParticles_packedGenParticles__PAT_obj_charge_);
   fChain->SetBranchAddress("patPackedGenParticles_packedGenParticles__PAT.obj.mother_.product_", patPackedGenParticles_packedGenParticles__PAT_obj_mother__product_, &b_patPackedGenParticles_packedGenParticles__PAT_obj_mother__product_);
   fChain->SetBranchAddress("patPackedGenParticles_packedGenParticles__PAT.obj.statusFlags_.flags_", patPackedGenParticles_packedGenParticles__PAT_obj_statusFlags__flags_, &b_patPackedGenParticles_packedGenParticles__PAT_obj_statusFlags__flags_);
   fChain->SetBranchAddress("patPackedGenParticles_packedGenParticles__PAT.present", &patPackedGenParticles_packedGenParticles__PAT_present, &b_patPackedGenParticles_packedGenParticles__PAT_present);
   fChain->SetBranchAddress("recoGenJets_slimmedGenJets__PAT.obj", &recoGenJets_slimmedGenJets__PAT_obj_, &b_recoGenJets_slimmedGenJets__PAT_obj_);
   fChain->SetBranchAddress("recoGenJets_slimmedGenJets__PAT.obj.m_state.vertex_.fCoordinates.fX", recoGenJets_slimmedGenJets__PAT_obj_m_state_vertex__fCoordinates_fX, &b_recoGenJets_slimmedGenJets__PAT_obj_m_state_vertex__fCoordinates_fX);
   fChain->SetBranchAddress("recoGenJets_slimmedGenJets__PAT.obj.m_state.vertex_.fCoordinates.fY", recoGenJets_slimmedGenJets__PAT_obj_m_state_vertex__fCoordinates_fY, &b_recoGenJets_slimmedGenJets__PAT_obj_m_state_vertex__fCoordinates_fY);
   fChain->SetBranchAddress("recoGenJets_slimmedGenJets__PAT.obj.m_state.vertex_.fCoordinates.fZ", recoGenJets_slimmedGenJets__PAT_obj_m_state_vertex__fCoordinates_fZ, &b_recoGenJets_slimmedGenJets__PAT_obj_m_state_vertex__fCoordinates_fZ);
   fChain->SetBranchAddress("recoGenJets_slimmedGenJets__PAT.obj.m_state.p4Polar_.fCoordinates.fPt", recoGenJets_slimmedGenJets__PAT_obj_m_state_p4Polar__fCoordinates_fPt, &b_recoGenJets_slimmedGenJets__PAT_obj_m_state_p4Polar__fCoordinates_fPt);
   fChain->SetBranchAddress("recoGenJets_slimmedGenJets__PAT.obj.m_state.p4Polar_.fCoordinates.fEta", recoGenJets_slimmedGenJets__PAT_obj_m_state_p4Polar__fCoordinates_fEta, &b_recoGenJets_slimmedGenJets__PAT_obj_m_state_p4Polar__fCoordinates_fEta);
   fChain->SetBranchAddress("recoGenJets_slimmedGenJets__PAT.obj.m_state.p4Polar_.fCoordinates.fPhi", recoGenJets_slimmedGenJets__PAT_obj_m_state_p4Polar__fCoordinates_fPhi, &b_recoGenJets_slimmedGenJets__PAT_obj_m_state_p4Polar__fCoordinates_fPhi);
   fChain->SetBranchAddress("recoGenJets_slimmedGenJets__PAT.obj.m_state.p4Polar_.fCoordinates.fM", recoGenJets_slimmedGenJets__PAT_obj_m_state_p4Polar__fCoordinates_fM, &b_recoGenJets_slimmedGenJets__PAT_obj_m_state_p4Polar__fCoordinates_fM);
   fChain->SetBranchAddress("recoGenJets_slimmedGenJets__PAT.obj.m_state.qx3_", recoGenJets_slimmedGenJets__PAT_obj_m_state_qx3_, &b_recoGenJets_slimmedGenJets__PAT_obj_m_state_qx3_);
   fChain->SetBranchAddress("recoGenJets_slimmedGenJets__PAT.obj.m_state.pdgId_", recoGenJets_slimmedGenJets__PAT_obj_m_state_pdgId_, &b_recoGenJets_slimmedGenJets__PAT_obj_m_state_pdgId_);
   fChain->SetBranchAddress("recoGenJets_slimmedGenJets__PAT.obj.m_state.status_", recoGenJets_slimmedGenJets__PAT_obj_m_state_status_, &b_recoGenJets_slimmedGenJets__PAT_obj_m_state_status_);
   fChain->SetBranchAddress("recoGenJets_slimmedGenJets__PAT.obj.dau", recoGenJets_slimmedGenJets__PAT_obj_dau, &b_recoGenJets_slimmedGenJets__PAT_obj_dau);
   fChain->SetBranchAddress("recoGenJets_slimmedGenJets__PAT.obj.mJetArea", recoGenJets_slimmedGenJets__PAT_obj_mJetArea, &b_recoGenJets_slimmedGenJets__PAT_obj_mJetArea);
   fChain->SetBranchAddress("recoGenJets_slimmedGenJets__PAT.obj.mPileupEnergy", recoGenJets_slimmedGenJets__PAT_obj_mPileupEnergy, &b_recoGenJets_slimmedGenJets__PAT_obj_mPileupEnergy);
   fChain->SetBranchAddress("recoGenJets_slimmedGenJets__PAT.obj.mPassNumber", recoGenJets_slimmedGenJets__PAT_obj_mPassNumber, &b_recoGenJets_slimmedGenJets__PAT_obj_mPassNumber);
   fChain->SetBranchAddress("recoGenJets_slimmedGenJets__PAT.obj.mIsWeighted", recoGenJets_slimmedGenJets__PAT_obj_mIsWeighted, &b_recoGenJets_slimmedGenJets__PAT_obj_mIsWeighted);
   fChain->SetBranchAddress("recoGenJets_slimmedGenJets__PAT.obj.m_specific.m_EmEnergy", recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_EmEnergy, &b_recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_EmEnergy);
   fChain->SetBranchAddress("recoGenJets_slimmedGenJets__PAT.obj.m_specific.m_HadEnergy", recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_HadEnergy, &b_recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_HadEnergy);
   fChain->SetBranchAddress("recoGenJets_slimmedGenJets__PAT.obj.m_specific.m_InvisibleEnergy", recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_InvisibleEnergy, &b_recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_InvisibleEnergy);
   fChain->SetBranchAddress("recoGenJets_slimmedGenJets__PAT.obj.m_specific.m_AuxiliaryEnergy", recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_AuxiliaryEnergy, &b_recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_AuxiliaryEnergy);
   fChain->SetBranchAddress("recoGenJets_slimmedGenJets__PAT.obj.m_specific.m_ChargedHadronEnergy", recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_ChargedHadronEnergy, &b_recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_ChargedHadronEnergy);
   fChain->SetBranchAddress("recoGenJets_slimmedGenJets__PAT.obj.m_specific.m_NeutralHadronEnergy", recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_NeutralHadronEnergy, &b_recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_NeutralHadronEnergy);
   fChain->SetBranchAddress("recoGenJets_slimmedGenJets__PAT.obj.m_specific.m_ChargedEmEnergy", recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_ChargedEmEnergy, &b_recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_ChargedEmEnergy);
   fChain->SetBranchAddress("recoGenJets_slimmedGenJets__PAT.obj.m_specific.m_NeutralEmEnergy", recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_NeutralEmEnergy, &b_recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_NeutralEmEnergy);
   fChain->SetBranchAddress("recoGenJets_slimmedGenJets__PAT.obj.m_specific.m_MuonEnergy", recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_MuonEnergy, &b_recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_MuonEnergy);
   fChain->SetBranchAddress("recoGenJets_slimmedGenJets__PAT.obj.m_specific.m_ChargedHadronMultiplicity", recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_ChargedHadronMultiplicity, &b_recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_ChargedHadronMultiplicity);
   fChain->SetBranchAddress("recoGenJets_slimmedGenJets__PAT.obj.m_specific.m_NeutralHadronMultiplicity", recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_NeutralHadronMultiplicity, &b_recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_NeutralHadronMultiplicity);
   fChain->SetBranchAddress("recoGenJets_slimmedGenJets__PAT.obj.m_specific.m_ChargedEmMultiplicity", recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_ChargedEmMultiplicity, &b_recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_ChargedEmMultiplicity);
   fChain->SetBranchAddress("recoGenJets_slimmedGenJets__PAT.obj.m_specific.m_NeutralEmMultiplicity", recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_NeutralEmMultiplicity, &b_recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_NeutralEmMultiplicity);
   fChain->SetBranchAddress("recoGenJets_slimmedGenJets__PAT.obj.m_specific.m_MuonMultiplicity", recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_MuonMultiplicity, &b_recoGenJets_slimmedGenJets__PAT_obj_m_specific_m_MuonMultiplicity);
   fChain->SetBranchAddress("recoGenJets_slimmedGenJets__PAT.present", &recoGenJets_slimmedGenJets__PAT_present, &b_recoGenJets_slimmedGenJets__PAT_present);
   fChain->SetBranchAddress("recoGenParticles_prunedGenParticles__PAT.obj", &recoGenParticles_prunedGenParticles__PAT_obj_, &b_recoGenParticles_prunedGenParticles__PAT_obj_);
   fChain->SetBranchAddress("recoGenParticles_prunedGenParticles__PAT.obj.m_state.vertex_.fCoordinates.fX", recoGenParticles_prunedGenParticles__PAT_obj_m_state_vertex__fCoordinates_fX, &b_recoGenParticles_prunedGenParticles__PAT_obj_m_state_vertex__fCoordinates_fX);
   fChain->SetBranchAddress("recoGenParticles_prunedGenParticles__PAT.obj.m_state.vertex_.fCoordinates.fY", recoGenParticles_prunedGenParticles__PAT_obj_m_state_vertex__fCoordinates_fY, &b_recoGenParticles_prunedGenParticles__PAT_obj_m_state_vertex__fCoordinates_fY);
   fChain->SetBranchAddress("recoGenParticles_prunedGenParticles__PAT.obj.m_state.vertex_.fCoordinates.fZ", recoGenParticles_prunedGenParticles__PAT_obj_m_state_vertex__fCoordinates_fZ, &b_recoGenParticles_prunedGenParticles__PAT_obj_m_state_vertex__fCoordinates_fZ);
   fChain->SetBranchAddress("recoGenParticles_prunedGenParticles__PAT.obj.m_state.p4Polar_.fCoordinates.fPt", recoGenParticles_prunedGenParticles__PAT_obj_m_state_p4Polar__fCoordinates_fPt, &b_recoGenParticles_prunedGenParticles__PAT_obj_m_state_p4Polar__fCoordinates_fPt);
   fChain->SetBranchAddress("recoGenParticles_prunedGenParticles__PAT.obj.m_state.p4Polar_.fCoordinates.fEta", recoGenParticles_prunedGenParticles__PAT_obj_m_state_p4Polar__fCoordinates_fEta, &b_recoGenParticles_prunedGenParticles__PAT_obj_m_state_p4Polar__fCoordinates_fEta);
   fChain->SetBranchAddress("recoGenParticles_prunedGenParticles__PAT.obj.m_state.p4Polar_.fCoordinates.fPhi", recoGenParticles_prunedGenParticles__PAT_obj_m_state_p4Polar__fCoordinates_fPhi, &b_recoGenParticles_prunedGenParticles__PAT_obj_m_state_p4Polar__fCoordinates_fPhi);
   fChain->SetBranchAddress("recoGenParticles_prunedGenParticles__PAT.obj.m_state.p4Polar_.fCoordinates.fM", recoGenParticles_prunedGenParticles__PAT_obj_m_state_p4Polar__fCoordinates_fM, &b_recoGenParticles_prunedGenParticles__PAT_obj_m_state_p4Polar__fCoordinates_fM);
   fChain->SetBranchAddress("recoGenParticles_prunedGenParticles__PAT.obj.m_state.qx3_", recoGenParticles_prunedGenParticles__PAT_obj_m_state_qx3_, &b_recoGenParticles_prunedGenParticles__PAT_obj_m_state_qx3_);
   fChain->SetBranchAddress("recoGenParticles_prunedGenParticles__PAT.obj.m_state.pdgId_", recoGenParticles_prunedGenParticles__PAT_obj_m_state_pdgId_, &b_recoGenParticles_prunedGenParticles__PAT_obj_m_state_pdgId_);
   fChain->SetBranchAddress("recoGenParticles_prunedGenParticles__PAT.obj.m_state.status_", recoGenParticles_prunedGenParticles__PAT_obj_m_state_status_, &b_recoGenParticles_prunedGenParticles__PAT_obj_m_state_status_);
   fChain->SetBranchAddress("recoGenParticles_prunedGenParticles__PAT.obj.dau.refVector_.product_", recoGenParticles_prunedGenParticles__PAT_obj_dau_refVector__product_, &b_recoGenParticles_prunedGenParticles__PAT_obj_dau_refVector__product_);
   fChain->SetBranchAddress("recoGenParticles_prunedGenParticles__PAT.obj.dau.refVector_.keys_", recoGenParticles_prunedGenParticles__PAT_obj_dau_refVector__keys_, &b_recoGenParticles_prunedGenParticles__PAT_obj_dau_refVector__keys_);
   fChain->SetBranchAddress("recoGenParticles_prunedGenParticles__PAT.obj.mom.refVector_.product_", recoGenParticles_prunedGenParticles__PAT_obj_mom_refVector__product_, &b_recoGenParticles_prunedGenParticles__PAT_obj_mom_refVector__product_);
   fChain->SetBranchAddress("recoGenParticles_prunedGenParticles__PAT.obj.mom.refVector_.keys_", recoGenParticles_prunedGenParticles__PAT_obj_mom_refVector__keys_, &b_recoGenParticles_prunedGenParticles__PAT_obj_mom_refVector__keys_);
   fChain->SetBranchAddress("recoGenParticles_prunedGenParticles__PAT.obj.collisionId_", recoGenParticles_prunedGenParticles__PAT_obj_collisionId_, &b_recoGenParticles_prunedGenParticles__PAT_obj_collisionId_);
   fChain->SetBranchAddress("recoGenParticles_prunedGenParticles__PAT.obj.statusFlags_.flags_", recoGenParticles_prunedGenParticles__PAT_obj_statusFlags__flags_, &b_recoGenParticles_prunedGenParticles__PAT_obj_statusFlags__flags_);
   fChain->SetBranchAddress("recoGenParticles_prunedGenParticles__PAT.present", &recoGenParticles_prunedGenParticles__PAT_present, &b_recoGenParticles_prunedGenParticles__PAT_present);
   Notify();
}

Bool_t JetTree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void JetTree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t JetTree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef JetTree_cxx
