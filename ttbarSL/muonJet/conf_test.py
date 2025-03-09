import FWCore.ParameterSet.Config as cms
import os

process = cms.Process("muonJet")
# Configure the MessageLogger
process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 10 # Report every 10000 events
process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(-1))
#directory_path = '/data1/users/dndus0107/AnalysisResults/Muon/crab_Run2022D-27Jun2023-v2/241231_153948/1000/'
#file_list = os.listdir(directory_path)
#file_paths = [f'file://{directory_path}{filename}' for filename in file_list]
file_paths = ['file:///home/dndus0107/JetMuon/CMSSW_14_2_2/src/ttbarSL/skimFilter/skimmed_data.root']
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(*file_paths)
)

# Enable multithreading 
process.options = cms.untracked.PSet(
    numberOfThreads = cms.untracked.uint32(1),
    numberOfStreams = cms.untracked.uint32(0),
)
process.TFileService = cms.Service("TFileService",
    fileName = cms.string("muonJet_test.root")
)

process.muonJet = cms.EDAnalyzer('muonJet',
    muons = cms.InputTag("muons")
)

process.p = cms.Path(process.muonJet)  
process.options.wantSummary = True
