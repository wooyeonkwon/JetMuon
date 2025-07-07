
#####################################################
# Description:                                      #
#     draw data and mc comparision histogram.       #
#     draw both data and mc histogram in same pad 1 #
#     draw data/mc ratio in pad 2                   #
#####################################################
import ROOT
from ROOT import RDataFrame
import sys
import os
import gc
import threading
from root_tool import load_file
from root_tool import Histo1D_def
from root_tool import Profile1D_filtery_def

ROOT.gStyle.SetOptStat(0)
ROOT.gROOT.SetBatch(True) # don't show pop-up (can cause seg fault with multi-thread)
ROOT.EnableThreadSafety()
ROOT.EnableImplicitMT(54) # activate multi-thread and set a number of threads

data_entry_numbers = []
log_lock = threading.Lock()
canvas_lock = threading.Lock()

##############################
# Set user define parameters #
##############################
# directory, tree, branch name and histogram parameters setting
DIR_NAMES = ["muonJet"]   # set TDirectory of the root file ["data","mc" ], if no directory : []
TREE_NAMES = ["Events"]               # set tree path of the root file, you must use same Treename for data and mc.
GEN_BRANCHES = [                            # see details at Histo1D_def in the module root_tool.py
#    {"output": "Jet_Eta_hist", "name": "GenJet_eta", "bins": 60, "xmin": -3.0, "xmax": 3.0, "title": "", "xtitle": "Jet Multiplicity", "ytitle": "Jets", "condition": lambda i: "((Jet_overlap[GenJet_jetIdx[i]] == 0) && (GenJet_jetIdx[i] > -1) && (Jet_ID[GenJet_jetIdx[i]] > 0) && (Jet_pt[GenJet_jetIdx[i]] > 30) && (!((Jet_pt[GenJet_jetIdx[i]] < 50) && (std::fabs(Jet_eta[GenJet_jetIdx[i]]) > 2.5) && (std::fabs(Jet_eta[GenJet_jetIdx[i]]) < 3.0))))"},
#    {"output": "Jet_Multiplicity_hist", "name": "nGenJet", "bins": 25, "xmin": 0.0, "xmax": 25.0, "title": "", "xtitle": "Jet Multiplicity", "ytitle": "Events", "condition": None},
#    {"output": "Jet_muonMultiplicity_hist", "name": "GenJet_muonMultiplicity", "bins": 10, "xmin": 0.0, "xmax": 10.0, "title": "", "xtitle": "Muon multiplicity in each Jet", "ytitle": "Jets", "condition": lambda i: "((Jet_overlap[GenJet_jetIdx[i]] == 0) && (GenJet_jetIdx[i] > -1) && (Jet_ID[GenJet_jetIdx[i]] > 0) && (Jet_pt[GenJet_jetIdx[i]] > 30) && (!((Jet_pt[GenJet_jetIdx[i]] < 50) && (std::fabs(Jet_eta[GenJet_jetIdx[i]]) > 2.5) && (std::fabs(Jet_eta[GenJet_jetIdx[i]]) < 3.0))))"},
#    {"output": "Jet_muon_pt_hist", "name": "PackedGenPart_pt_jet", "bins": 200, "xmin": 0.0, "xmax": 200.0, "title": "", "xtitle": "Muon pt (GeV)", "ytitle": "Muons (/1GeV)", "condition": lambda i: "((Jet_overlap[GenJet_jetIdx[i]] == 0) && (PackedGenPart_pt_jet[i] > 0))"},
    {"output": "Jet_muonMultiplicity", "name": "GenJet_eta", "ymean": "GenJet_muonMultiplicity","bins": 60, "xmin": -3.0, "xmax": 3.0, "title": "", "xtitle": "Jet_eta", "ytitle": "mean muon multiplicity of jet", "condition": lambda i: "((Jet_overlap[GenJet_jetIdx[i]] == 0) &&(GenJet_jetIdx[i] > -1) && (Jet_ID[GenJet_jetIdx[i]] > 0) && (Jet_pt[GenJet_jetIdx[i]] > 30) && (!((Jet_pt[GenJet_jetIdx[i]] < 50) && (std::fabs(Jet_eta[GenJet_jetIdx[i]]) > 2.5) && (std::fabs(Jet_eta[GenJet_jetIdx[i]]) < 3.0))))"},
    {"output": "Jet_muonMultiplicity_01", "name": "GenJet_eta", "ymean": "GenJet_muonMultiplicity","bins": 60, "xmin": -3.0, "xmax": 3.0, "title": "", "xtitle": "Jet_eta", "ytitle": "mean muon multiplicity of jet", "condition": lambda i: "(Jet_overlap[GenJet_jetIdx[i]] == 0) &&(GenJet_muonMultiplicity[i] < 2) && (GenJet_muonMultiplicity[i] > -1) && ((GenJet_jetIdx[i] > -1) && (Jet_ID[GenJet_jetIdx[i]] > 0) && (Jet_pt[GenJet_jetIdx[i]] > 30) && (!((Jet_pt[GenJet_jetIdx[i]] < 50) && (std::fabs(Jet_eta[GenJet_jetIdx[i]]) > 2.5) && (std::fabs(Jet_eta[GenJet_jetIdx[i]]) < 3.0))))"},
    {"output": "Jet_muonMultiplicity_mul", "name": "GenJet_eta", "ymean": "GenJet_muonMultiplicity","bins": 60, "xmin": -3.0, "xmax": 3.0, "title": "", "xtitle": "Jet_eta", "ytitle": "mean muon multiplicity of jet", "condition": lambda i: "(GenJet_muonMultiplicity[i] > 1) && ((GenJet_jetIdx[i] > -1) && (Jet_ID[GenJet_jetIdx[i]] > 0) && (Jet_pt[GenJet_jetIdx[i]] > 30) && (!((Jet_pt[GenJet_jetIdx[i]] < 50) && (std::fabs(Jet_eta[GenJet_jetIdx[i]]) > 2.5) && (std::fabs(Jet_eta[GenJet_jetIdx[i]]) < 3.0))))"},
    {"output": "Jet_muEF", "name": "GenJet_eta", "ymean": "GenJet_muEF", "bins": 60, "xmin": -3.0, "xmax": 3.0, "title": "", "xtitle": "Jet_eta", "ytitle": "mean muon energy fraction of jet", "condition": lambda i: "((Jet_overlap[GenJet_jetIdx[i]] == 0) &&(GenJet_jetIdx[i] > -1) && (Jet_ID[GenJet_jetIdx[i]] > 0) && (Jet_pt[GenJet_jetIdx[i]] > 30) && (!((Jet_pt[GenJet_jetIdx[i]] < 50) && (std::fabs(Jet_eta[GenJet_jetIdx[i]]) > 2.5) && (std::fabs(Jet_eta[GenJet_jetIdx[i]]) < 3.0))))"},
    {"output": "Jet_muEF_1", "name": "GenJet_eta", "ymean": "GenJet_muEF", "bins": 60, "xmin": -3.0, "xmax": 3.0, "title": "", "xtitle": "Jet_eta", "ytitle": "mean muon energy fraction of jet", "condition": lambda i: "((Jet_overlap[GenJet_jetIdx[i]] == 0) &&(GenJet_jetIdx[i] > -1) && (Jet_ID[GenJet_jetIdx[i]] > 0) && (Jet_pt[GenJet_jetIdx[i]] > 30) && (!((Jet_pt[GenJet_jetIdx[i]] < 50) && (std::fabs(Jet_eta[GenJet_jetIdx[i]]) > 2.5) && (std::fabs(Jet_eta[GenJet_jetIdx[i]]) < 3.0)))) && (GenJet_muonMultiplicity[i] == 1) && (GenJet_muonMultiplicity[i] > -1)"},
    {"output": "Jet_muEF_01", "name": "GenJet_eta", "ymean": "GenJet_muEF", "bins": 60, "xmin": -3.0, "xmax": 3.0, "title": "", "xtitle": "Jet_eta", "ytitle": "mean muon energy fraction of jet", "condition": lambda i: "((Jet_overlap[GenJet_jetIdx[i]] == 0) &&(GenJet_jetIdx[i] > -1) && (Jet_ID[GenJet_jetIdx[i]] > 0) && (Jet_pt[GenJet_jetIdx[i]] > 30) && (!((Jet_pt[GenJet_jetIdx[i]] < 50) && (std::fabs(Jet_eta[GenJet_jetIdx[i]]) > 2.5) && (std::fabs(Jet_eta[GenJet_jetIdx[i]]) < 3.0)))) && (GenJet_muonMultiplicity[i] < 2) && (GenJet_muonMultiplicity[i] > -1) && (Jet_pt[GenJet_jetIdx[i]] > 15) && (std::fabs(Jet_eta[GenJet_jetIdx[i]]) <= 5.0)"},
#    {"output": "Jet_muEF_mul", "name": "GenJet_eta", "ymean": "GenJet_muEF", "bins": 60, "xmin": -3.0, "xmax": 3.0, "title": "", "xtitle": "Jet_eta", "ytitle": "mean muon energy fraction of jet", "condition": lambda i: "((GenJet_jetIdx[i] > -1) && (Jet_ID[GenJet_jetIdx[i]] > 0) && (Jet_pt[GenJet_jetIdx[i]] > 30) && (!((Jet_pt[GenJet_jetIdx[i]] < 50) && (std::fabs(Jet_eta[GenJet_jetIdx[i]]) > 2.5) && (std::fabs(Jet_eta[GenJet_jetIdx[i]]) < 3.0)))) && GenJet_muEF[i] > 0 && (GenJet_muonMultiplicity[i] > 1) && (Jet_pt[GenJet_jetIdx[i]] > 15) && (std::fabs(Jet_eta[GenJet_jetIdx[i]]) <= 5.0)"},
#    {"output": "Muon_JetMuon_eta", "name": "GenMuon_JetMuon_eta", "bins": 60, "xmin": -3.0, "xmax": 3.0, "title": "", "xtitle": "eta", "ytitle": "Jets", "condition": lambda i: "(Jet_overlap[GenJet_jetIdx[i]] == 0)"},

]
BRANCHES = [                            # see details at Histo1D_def in the module root_tool.py
#    {"output": "Jet_Eta_hist", "name": "Jet_eta", "bins": 60, "xmin": -3.0, "xmax": 3.0, "title": "", "xtitle": "Jet Multiplicity", "ytitle": "Jets", "condition": lambda i: "((Jet_overlap[i] == 0) && (Jet_genJetIdx[i] > -1) && (Jet_ID[i] > 0) && (Jet_pt[i] > 30) && (!((Jet_pt[i] < 50) && (std::fabs(Jet_eta[i]) > 2.5) && (std::fabs(Jet_eta[i]) < 3.0))))"},
#    {"output": "Jet_Multiplicity_hist", "name": "nJet", "bins": 25, "xmin": 0.0, "xmax": 25.0, "title": "", "xtitle": "Jet Multiplicity", "ytitle": "Events", "condition": None},
#    {"output": "Jet_muonMultiplicity_hist", "name": "Jet_globalMuonMultiplicity", "bins": 10, "xmin": 0.0, "xmax": 10.0, "title": "", "xtitle": "Muon multiplicity in each Jet", "ytitle": "Jets", "condition": lambda i: "((Jet_overlap[i] == 0) && (Jet_genJetIdx[i] > -1) && (Jet_ID[i] > 0) && (Jet_pt[i] > 30) && (!((Jet_pt[i] < 50) && (std::fabs(Jet_eta[i]) > 2.5) && (std::fabs(Jet_eta[i]) < 3.0))))"},    
#    {"output": "Jet_muon_pt_hist", "name": "PackedMuon_pt_jet", "bins": 200, "xmin": 0.0, "xmax": 200.0, "title": "", "xtitle": "Muon pt (GeV)", "ytitle": "Muons (/1GeV)", "condition": lambda i: "((Jet_overlap[i] == 0) && (PackedMuon_pt_jet[i] > 0))"},    
    {"output": "Jet_muonMultiplicity", "name": "Jet_eta", "ymean": "Jet_globalMuonMultiplicity", "bins": 60, "xmin": -3.0, "xmax": 3.0, "title": "", "xtitle": "Jet_eta", "ytitle": "mean muon multiplicity of jet", "condition": lambda i: "((Jet_overlap[i] == 0) &&(Jet_genJetIdx[i] > -1) && (Jet_ID[i] > 0) && (Jet_pt[i] > 30) && (!((Jet_pt[i] < 50) && (std::fabs(Jet_eta[i]) > 2.5) && (std::fabs(Jet_eta[i]) < 3.0))))"},
    {"output": "Jet_muonMultiplicity_01", "name": "Jet_eta", "ymean": "Jet_globalMuonMultiplicity", "bins": 60, "xmin": -3.0, "xmax": 3.0, "title": "", "xtitle": "Jet_eta", "ytitle": "mean muon multiplicity of jet", "condition": lambda i: "(Jet_overlap[i] == 0) &&(Jet_muonMultiplicity[i] < 2) && (Jet_muonMultiplicity[i] > -1) && ((Jet_genJetIdx[i] > -1) && (Jet_ID[i] > 0) && (Jet_pt[i] > 30) && (!((Jet_pt[i] < 50) && (std::fabs(Jet_eta[i]) > 2.5) && (std::fabs(Jet_eta[i]) < 3.0))))"},
    {"output": "Jet_muonMultiplicity_mul", "name": "Jet_eta", "ymean": "Jet_globalMuonMultiplicity", "bins": 60, "xmin": -3.0, "xmax": 3.0, "title": "", "xtitle": "Jet_eta", "ytitle": "mean muon multiplicity of jet", "condition": lambda i: "(Jet_muonMultiplicity[i] > 1) && ((Jet_genJetIdx[i] > -1) && (Jet_ID[i] > 0) && (Jet_pt[i] > 30) && (!((Jet_pt[i] < 50) && (std::fabs(Jet_eta[i]) > 2.5) && (std::fabs(Jet_eta[i]) < 3.0))))"},
    {"output": "Jet_muEF", "name": "Jet_eta", "ymean": "Jet_globalmuEF", "bins": 60, "xmin": -3.0, "xmax": 3.0, "title": "", "xtitle": "Jet_eta", "ytitle": "mean muon energy fraction of jet", "condition": lambda i: "((Jet_overlap[i] == 0) &&(Jet_genJetIdx[i] > -1) && (Jet_ID[i] > 0) && (Jet_pt[i] > 30) && (!((Jet_pt[i] < 50) && (std::fabs(Jet_eta[i]) > 2.5) && (std::fabs(Jet_eta[i]) < 3.0))))"},
    {"output": "Jet_muEF_1", "name": "Jet_eta", "ymean": "Jet_globalmuEF", "bins": 60, "xmin": -3.0, "xmax": 3.0, "title": "", "xtitle": "Jet_eta", "ytitle": "mean muon energy fraction of jet", "condition": lambda i: "(Jet_overlap[i] == 0) &&(Jet_muonMultiplicity[i] == 1) && (Jet_muonMultiplicity[i] > -1) && ((Jet_genJetIdx[i] > -1) && (Jet_ID[i] > 0) && (Jet_pt[i] > 30) && (!((Jet_pt[i] < 50) && (std::fabs(Jet_eta[i]) > 2.5) && (std::fabs(Jet_eta[i]) < 3.0))))"},
    {"output": "Jet_muEF_01", "name": "Jet_eta", "ymean": "Jet_globalmuEF", "bins": 60, "xmin": -3.0, "xmax": 3.0, "title": "", "xtitle": "Jet_eta", "ytitle": "mean muon energy fraction of jet", "condition": lambda i: "(Jet_overlap[i] == 0) &&(Jet_muonMultiplicity[i] < 2) && (Jet_muonMultiplicity[i] > -1) && ((Jet_genJetIdx[i] > -1) && ((Jet_genJetIdx[i] > -1) && (Jet_ID[i] > 0) && (Jet_pt[i] > 30) && (!((Jet_pt[i] < 50) && (std::fabs(Jet_eta[i]) > 2.5) && (std::fabs(Jet_eta[i]) < 3.0)))))"},
#    {"output": "Jet_muEF_mul", "name": "Jet_eta", "ymean": "Jet_globalmuEF", "bins": 60, "xmin": -3.0, "xmax": 3.0, "title": "", "xtitle": "Jet_eta", "ytitle": "mean muon energy fraction of jet", "condition": lambda i: "(Jet_muonMultiplicity[i] > 1) && ((Jet_genJetIdx[i] > -1) && (Jet_ID[i] > 0) && (Jet_pt[i] > 30) && (!((Jet_pt[i] < 50) && (std::fabs(Jet_eta[i]) > 2.5) && (std::fabs(Jet_eta[i]) < 3.0))))"},
#    {"output": "Muon_JetMuon_eta", "name": "MatchedMuon_JetMuon_eta", "bins": 60, "xmin": -3.0, "xmax": 3.0, "title": "", "xtitle": "eta", "ytitle": "Jets", "condition": lambda i: "(Jet_overlap[i] == 0)"},    

]

# final_survie_event (data) = data_lumi * mc_cross_section * mc_triggerEff * mc_selectionEff
# final_survie_event (mc) = mc_events * mc_selectionEff * mc_triggerEff * matchingEff / gen_weight
# final_survie_event (data) = nom_factor * final_survie_event (mc) 
# data_lumi * mc_cross_section * data_triggerEff / mc_events_total * mc_triggerEff * matchingEff
###################################################################################
# Usage of this code                                                              #
# python3 script.py <path/to/data.root> <path/to/mc.root> [path/to/output/folder] #
###################################################################################

if len(sys.argv) > 1:
    mc_path = sys.argv[1]
    try:
        output_path = sys.argv[2]
        if not os.path.exists(output_path): 
            os.makedirs(output_path)
    except IndexError:
        output_path = "."
else:
    print("Usage: script.py <mc_path> [output_path]")
    sys.exit(1)

######################################################################################
# helper functions                                                                   #
# log_corrupted_entry(event_number)                                                  #
#     Logs the corrupted event number to a file                                      #
#     parameters:                                                                    #
#         event_number (int) : Corrupted event, which can't be read a entry          #
#                                                                                    #
# draw_histogram                                                                     #
#    draw histogram with data and mc                                                 #
#    parameters:                                                                     #
#        data_rdf (RDataFrame): RDataFrame of data                                   #
#        mc_rdf (RDataFrame): RDataFrame of MC                                       #
#        tree_name (str): current tree                                               #
#        branch (dict): branch info with (bins, xmin, xmax, xtitle, ytitle)          #
#        output_dir (str): histogram output directory                                #
# ####################################################################################
def log_corrupted_entry(event_number): 
    with log_lock: 
        with open("corrupted_entries.log", "a") as log_file: 
            log_file.write(f"Corrupted event: {event_number}\n")

def rdf_filter_jet(rdf):
    rdf = rdf.Filter(f"""
                    for (size_t i = 0; i < Jet_pt.size(); ++i) {{
                        if (!(Jet_ID[i] > 0) || (Jet_pt[i] < 30) || (std::fabs(Jet_eta[i]) > 2.4)) continue;
                        return true;
                    }}
                    return false;
                    """)
    return rdf

def nJet(rdf):
    rdf = rdf.Define("nJet",
                    f"""
                    int n = 0;
                    for (size_t i = 0; i < Jet_pt.size(); ++i) {{
                        if (Jet_overlap[i] == 1) continue;
                        if (!(Jet_ID[i] > 0)) continue;
                        if (!(Jet_pt[i] > 30)) continue;
                        if (std::fabs(Jet_eta[i]) > 2.5 && std::fabs(Jet_eta[i]) < 3.0){{
                            if (!(Jet_pt[i] > 50)) continue;
                        }}
                        n++;
                    }}
                    return n;
                    """)
    
    rdf = rdf.Define("nGenJet",
                    f"""
                    int m = 0;
                    for (size_t i = 0; i < GenJet_pt.size(); ++i) {{
                        if (Jet_overlap[GenJet_jetIdx[i]] == 1) continue;
                        if (!(GenJet_pt[i] > 30)) continue;
                        if (std::fabs(GenJet_eta[i]) > 2.5 && std::fabs(GenJet_eta[i]) < 3.0){{
                            if (!(GenJet_pt[i] > 50)) continue;
                        }}
                        m++;
                    }}
                    return m;
                    """)
    return rdf

def nMuon(rdf):
##if (Muon_genPartIdx[PackedMuon_muonIdx[Jet_packedMuonIdx[i][j]]] > -1) 
    rdf = rdf.Define("MatchedMuon_JetMuon_eta",
                    f"""
                    std::vector<double> filtered;
                    for (size_t i = 0; i < Jet_packedMuonIdx.size(); ++i) {{
                        if (!(Jet_genJetIdx[i] > -1)) continue;
                        if (!(Jet_ID[i] > 0)) continue;
                        if (!(Jet_pt[i] > 30)) continue;
                        if (std::fabs(Jet_eta[i]) > 2.5 && std::fabs(Jet_eta[i]) < 3.0){{
                            if (!(Jet_pt[i] > 50)) continue;
                        }}
                        for (size_t j = 0; j < Jet_packedMuonIdx[i].size(); ++j) {{
                            if ((Muon_genPartIdx[PackedMuon_muonIdx[Jet_packedMuonIdx[i][j]]] > -1) && (Jet_packedMuonIdx[i][j] > -1)){{
                                filtered.push_back(PackedMuon_eta[Jet_packedMuonIdx[i][j]]);
                            }}
                        }}
                    }}
                    return filtered;
                    """)

    rdf = rdf.Define("GenMuon_JetMuon_eta",
                    f"""
                    std::vector<double> filtered;
                    for (size_t i = 0; i < GenJet_packedGenMuonIdx.size(); ++i) {{
                        if (!(GenJet_jetIdx[i] > -1)) continue;
                        if (!(Jet_ID[GenJet_jetIdx[i]] > 0)) continue;
                        if (!(Jet_pt[GenJet_jetIdx[i]] > 30)) continue;
                        if (std::fabs(Jet_eta[GenJet_jetIdx[i]]) > 2.5 && std::fabs(Jet_eta[GenJet_jetIdx[i]]) < 3.0){{
                            if (!(Jet_pt[GenJet_jetIdx[i]] > 50)) continue;
                        }}
                        for (size_t j = 0; j < GenJet_packedGenMuonIdx[i].size(); ++j) {{
                            if (GenJet_packedGenMuonIdx[i][j] > -1) {{
                            filtered.push_back(PackedGenPart_eta[GenJet_packedGenMuonIdx[i][j]]);                            
                            }}
                        }}
                    }}
                    return filtered;
                    """)    



    rdf = rdf.Define("Jet_globalMuonMultiplicity",
                    f"""
                    std::vector<int> filtered;
                    for (size_t i = 0; i < Jet_packedMuonIdx.size(); ++i) {{
                        int n = 0; 
                        for (size_t j = 0; j < Jet_packedMuonIdx[i].size(); ++j) {{
                            if((Jet_packedMuonIdx[i][j] > -1) && (Muon_isSoftMuon[PackedMuon_muonIdx[Jet_packedMuonIdx[i][j]]])) n++;
                        }}
                        filtered.push_back(n);
                    }}
                    return filtered;
                    """)

    rdf = rdf.Define("Jet_globalmuEF",
                    f"""
                    std::vector<double> filtered;
                    for (size_t i = 0; i < Jet_packedMuonIdx.size(); ++i) {{
                        double muEF = 0;
                        double nomuEF = 0;
                        for (size_t j = 0; j < Jet_packedMuonIdx[i].size(); ++j) {{
                            if((Jet_packedMuonIdx[i][j] > -1) && (Muon_isSoftMuon[PackedMuon_muonIdx[Jet_packedMuonIdx[i][j]]])) muEF = muEF + PackedMuon_energy[Jet_packedMuonIdx[i][j]];
                            else if((Jet_packedMuonIdx[i][j] > -1)) nomuEF = nomuEF + PackedMuon_energy[Jet_packedMuonIdx[i][j]];
                        }}
                        filtered.push_back(muEF/(Jet_energy[i] - nomuEF));
                    }}
                    return filtered;
                    """)
    return rdf

def rdf_filter(rdf):
    rdf = rdf.Define("PackedMuon_pt_jet",
                    f"""
                    std::vector<double> filtered;
                    for (size_t i = 0; i < Jet_packedMuonIdx.size(); ++i) {{
                        if (!(Jet_genJetIdx[i] > -1)) continue;
                        if (!(Jet_ID[i] > 0)) continue;
                        if (!(Jet_pt[i] > 30)) continue;
                        if (std::fabs(Jet_eta[i]) > 2.5 && std::fabs(Jet_eta[i]) < 3.0){{
                            if (!(Jet_pt[i] > 50)) continue;
                        }}
                        for (size_t j = 0; j < Jet_packedMuonIdx[i].size(); ++j) {{
                            if((Jet_packedMuonIdx[i][j] > -1) && (Muon_isSoftMuon[PackedMuon_muonIdx[Jet_packedMuonIdx[i][j]]])) {{
                                filtered.push_back(PackedMuon_pt[Jet_packedMuonIdx[i][j]]);
                                }}
                        }}
                    }}
                    return filtered;
                    """)
    
    rdf = rdf.Define("PackedGenPart_pt_jet",
                f"""
                std::vector<double> filtered;
                for (size_t i = 0; i < GenJet_packedGenMuonIdx.size(); ++i) {{
                    if (!(GenJet_jetIdx[i] > -1)) continue;
                    if (!(Jet_ID[GenJet_jetIdx[i]] > 0)) continue;
                    if (!(Jet_pt[GenJet_jetIdx[i]] > 30)) continue;
                    if (std::fabs(Jet_eta[GenJet_jetIdx[i]]) > 2.5 && std::fabs(Jet_eta[GenJet_jetIdx[i]]) < 3.0){{
                        if (!(Jet_pt[GenJet_jetIdx[i]] > 50)) continue;
                    }}
                    for (size_t j = 0; j < GenJet_packedGenMuonIdx[i].size(); ++j) {{
                        if(GenJet_packedGenMuonIdx[i][j] > -1) {{
                            filtered.push_back(PackedGenPart_pt[GenJet_packedGenMuonIdx[i][j]]);
                            }}
                    }}
                }}
                return filtered;
                """)
    return rdf

def draw_histogram(mc_rdf, tree_name, gen_branch, branch, output_dir="."):


    hist_gen = Profile1D_filtery_def(mc_rdf, gen_branch)
    hist_reco = Profile1D_filtery_def(mc_rdf, branch)
    #hist_gen = Histo1D_def(mc_rdf, gen_branch)
    #hist_reco = Histo1D_def(mc_rdf, branch)

    # Bin uncertainty calculate
#    for bin_idx in range(1, hist_gen.GetNbinsX() + 1):
#        bin_stat_unc = hist_gen.GetBinError(bin_idx)
#        hist_gen.SetBinError(bin_idx, bin_stat_unc)

    # draw and decorate canvas
    with canvas_lock: # deactivate multi-thread
        canvas = ROOT.TCanvas("canvas", "", 800, 800)
        canvas.SetLeftMargin(0.15)
        canvas.SetBottomMargin(0.15)
        #hist_reco.SetMarkerStyle(20)
        #hist_reco.SetMarkerColor(ROOT.kBlack)
        hist_reco.SetLineColor(ROOT.kBlack)
        #hist_gen.SetFillColor(ROOT.kBlue)
        hist_gen.SetLineColor(ROOT.kBlue)
        
        # pad1
        pad1 = ROOT.TPad("pad1", "pad1", 0, 0.3, 1, 1.0)
        pad1.SetLeftMargin(0.15)
        pad1.SetBottomMargin(0)
        pad1.Draw()
        #pad1.SetLogy(True)
        pad1.cd()
        hist_gen.GetYaxis().SetTitle(branch['ytitle'])
        hist_gen.GetYaxis().SetTitleSize(0.06)
        ymax = 1.4 * max(hist_gen.GetMaximum(),hist_reco.GetMaximum()) #1.4 or 16
        hist_gen.GetYaxis().SetRangeUser(0, ymax)
        hist_gen.Draw("HIST")
        hist_reco.Draw("HIST Same")
        gen_entries = int(hist_gen.Integral())
        reco_entries = int(hist_reco.Integral())
        print(f"gen_entries : {gen_entries}, reco_etnries: {reco_entries}")
        
        latex = ROOT.TLatex()
        latex.SetNDC()
        latex.SetTextSize(0.035)
        latex.SetTextFont(62)  # bold font for "CMS"
        latex.SetTextAlign(12)
        latex.DrawLatex(0.20, 0.92, "CMS")
        latex.SetTextFont(42)  # normal font
        latex.DrawLatex(0.25, 0.92, "#it{In Progress}")
        latex.SetTextAlign(32)
        latex.DrawLatex(0.9, 0.92, "#sqrt{s} = 13.6 TeV")
        
        legend = ROOT.TLegend(0.7, 0.7, 0.9, 0.9)
        legend.AddEntry(hist_reco.GetValue(), "Reco", "f")
        legend.AddEntry(hist_gen.GetValue(), "Gen", "f")
        legend.Draw()
        
        # pad2
        canvas.cd()
        pad2 = ROOT.TPad("pad2", "pad2", 0, 0.05, 1, 0.3)
        pad2.SetLeftMargin(0.15)
        pad2.SetTopMargin(0)
        pad2.SetBottomMargin(0.2)
        pad2.Draw()
        pad2.cd()
        
        ratioHist = hist_reco.Clone("ratioHist")
        ratioHist.Divide(hist_gen.GetValue())
        ratioHist.SetTitle("")
        ratioHist.GetYaxis().SetTitle("recoJet / genJet")

        ratioHist.GetYaxis().SetRangeUser(0.9 * ratioHist.GetMinimum(), 1.1 * ratioHist.GetMaximum())
        #ratioHist.GetYaxis().SetRangeUser(0.0,2.0)
        ratioHist.GetYaxis().SetNdivisions(505)
        ratioHist.GetYaxis().SetTitleSize(20)
        ratioHist.GetYaxis().SetTitleFont(43)
        ratioHist.GetYaxis().SetTitleOffset(1.55)
        ratioHist.GetYaxis().SetLabelFont(43)
        ratioHist.GetYaxis().SetLabelSize(15)
        ratioHist.GetXaxis().SetTitle(branch['xtitle'])
        ratioHist.GetXaxis().SetTitleSize(20)
        ratioHist.GetXaxis().SetTitleFont(43)
        ratioHist.GetXaxis().SetLabelFont(43)
        ratioHist.GetXaxis().SetLabelSize(15)
        ratioHist.Draw("HIST")

        
        line = ROOT.TLine(branch['xmin'], 1, branch['xmax'], 1)
        line.SetLineColor(ROOT.kRed)
        line.SetLineStyle(2)
        line.Draw()
        
        canvas.SaveAs(f"{output_dir}/{branch['output']}.png")
        del canvas


##########################################################################
# main function : Open Data and MC file and call draw_histogram function #
#     Parameters:                                                        #
#         data_filename (str): data.root file directory                  #
#         mc_filename (str): mc.root file directory                      #
#         output_dir (str): histogram output directory                   #
##########################################################################

def main(mc_filename, output_dir="."):

    mc_file = None
    gc.collect()

    mc_file, mc_dir = load_file(mc_filename, DIR_NAMES[0])

    for tree_name in TREE_NAMES:
        mc_tree = mc_dir.Get(tree_name)

        if not mc_tree:
            print(f"Tree '{tree_name}' not found in MC directory '{DIR_NAMES}'!")
            continue

        mc_rdf = ROOT.RDataFrame(mc_tree)
        mc_rdf = rdf_filter_jet(mc_rdf)
        mc_rdf = nJet(mc_rdf)
        mc_rdf = nMuon(mc_rdf)
        mc_rdf = rdf_filter(mc_rdf)

        for gen_branch, branch in zip(GEN_BRANCHES, BRANCHES):
            print(f"Draw '{gen_branch}' in '{tree_name}'")
            print(f"Draw '{branch}' in '{tree_name}'")

            try:
                draw_histogram(mc_rdf, tree_name, gen_branch, branch, output_dir)
                        
            except Exception as e:
                # Check for specific error and log the problematic entry
                print(f"Error initializing RDataFrame for tree '{tree_name}': {str(e)}")
                for entry in mc_tree:
                    try:
                        event_number = getattr(entry, "eventNumber", None)
                        if event_number:
                            data_entry_numbers.append(event_number)
                    except:
                        log_corrupted_entry(event_number)
                        continue
                continue

    mc_file.Close()

main(mc_path, output_path)
