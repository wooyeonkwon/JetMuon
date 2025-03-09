import FWCore.ParameterSet.Config as cms

process = cms.Process("skimFilter")

# Configure the MessageLogger
process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 10000

process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(-1))

process.source = cms.Source("PoolSource",
    fileNames=cms.untracked.vstring()
)
# MC truth matching for muons
process.muonMCMatch = cms.EDProducer("MCMatcher",
    src         = cms.InputTag("slimmedMuons"),       # reco muons
    matched     = cms.InputTag("prunedGenParticles"),  # gen particles
    mcPdgId     = cms.vint32(13),             # Muon PDG ID
    checkCharge = cms.bool(True),             # Check charge match
    maxDeltaR   = cms.double(0.3),            # ΔR threshold
    maxDPtRel   = cms.double(0.5),            # Relative pT difference
    resolveAmbiguities = cms.bool(True),      # One-to-one matching
    resolveByMatchQuality = cms.bool(True),   # Match by ΔR
    mcStatus    = cms.vint32(1)               # Match only stable particles
)

# Skim filter
process.skimFilter = cms.EDFilter('skimFilter',
    triggerResults=cms.InputTag("TriggerResults", "", "HLT"),
    HLT_IsoMu24_v=cms.string("HLT_IsoMu24_v"),
    HLT_Ele32_WPTight_Gsf_v=cms.string("HLT_Ele32_WPTight_Gsf_v"),
    muons = cms.InputTag("slimmedMuons"),
    electrons = cms.InputTag("slimmedElectrons")
)

# Path configuration
process.p = cms.Path(
    process.skimFilter +          # Trigger filter
    process.muonMCMatch  # MC truth matching
)

# Output module to store matched information
process.out = cms.OutputModule("PoolOutputModule",
    fileName=cms.untracked.string('file:skimmed_data.root'),
    SelectEvents=cms.untracked.PSet(
        SelectEvents=cms.vstring('p')
    ),
    outputCommands=cms.untracked.vstring(
        'drop *',
        'keep patMuons_slimmedMuons__*',         # Store all reco muons
        'keep patJets_slimmedJetsPuppi__PAT*',   # Store MC matching results
        'keep edmEventAuxiliary_*_*_*',
        # Keep gen-level particles
        'keep recoGenParticles_prunedGenParticles__PAT*',
        'keep recoGenJets_slimmedGenJets__PAT*', 
        'keep genWeights_genWeight__*',
        'keep recoGenParticlesedmAssociation_muonMCMatch__skim*',
        'keep GenEventInfoProduct_generator__*'
    )
)

process.e = cms.EndPath(process.out)

process.options.wantSummary = True