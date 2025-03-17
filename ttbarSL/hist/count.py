import ROOT
from ROOT import RDataFrame
ROOT.EnableThreadSafety()
ROOT.EnableImplicitMT(48)

rdf = ROOT.RDataFrame("Events", "/home/dndus0107/JetMuon/run/ttbarSLJetMuon_skim/mc/Run3Summer23BPixNanoAODv12/TTtoLNu2Q_TuneCP5_13p6TeV_powheg-pythia8/NANOAODSIM/130X_mcRun3_2023_realistic_postBPix_v2-v3/ttbarSL_ttbarSLJetMuonSkim.root")

rdf2 = rdf.Define("nJet_positive", "return std::count_if(Jet_muEF.begin(), Jet_muEF.end(), [](double jet) { return jet > 0; });")

result = rdf2.Sum("nJet_positive")

print("Total jets with Jet_muEF > 0:", result.GetValue())
