import FWCore.ParameterSet.Config as cms

process = cms.Process("muonJet")

# Configure the MessageLogger
process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 10000

process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(-1))

process.source = cms.Source("PoolSource",
    fileNames=cms.untracked.vstring()
)

# Enable multithreading 
process.options = cms.untracked.PSet(
    numberOfThreads = cms.untracked.uint32(1),
    numberOfStreams = cms.untracked.uint32(0),
#    TryToContinue = cms.untracked.vstring('ProductNotFound'),
)

process.TFileService = cms.Service("TFileService",
    fileName = cms.string("muonJet_test.root")
)

process.muonJet = cms.EDAnalyzer('muonJet',
    packedMuons = cms.InputTag("packedPFCandidates"),                            
    muons = cms.InputTag("slimmedMuons"),
    jets = cms.InputTag("slimmedJetsPuppi"),
    packedGenParticles = cms.InputTag("packedGenParticles"),
    genParticles = cms.InputTag("prunedGenParticles"),
    genJets = cms.InputTag("slimmedGenJets"),
    pfToGenAssoc = cms.InputTag("packedPFCandidateToGenAssociation"),
    pfToPackedGenAssoc = cms.InputTag("packedPFCandidateToGenAssociation"),
    generator = cms.InputTag("generator")
)

process.p = cms.Path(process.muonJet)  
process.options.wantSummary = True