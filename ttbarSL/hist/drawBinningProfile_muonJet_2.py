
###################################################################
# Description:                                                    #
#     draw comparision profile                                    #
#     draw value of mean of y per x bin                           #
#     if you use CONDITIONS dictionary, draw these in same canvas #
###################################################################
import ROOT
from ROOT import RDataFrame
import sys
import os
import gc
import threading
from root_tool import load_file
from root_tool import Profile1D_filtery_def
from root_tool import Profile2D_filtery_def

ROOT.gStyle.SetOptStat(0)
ROOT.gROOT.SetBatch(True) # don't show pop-up (can cause seg fault with multi-thread)
ROOT.EnableThreadSafety()
ROOT.EnableImplicitMT(48) # activate multi-thread and set a number of threads

data_entry_numbers = []
log_lock = threading.Lock()
profile_lock = threading.Lock()
canvas_lock = threading.Lock()

##############################
# Set user define parameters #
##############################

# directory, tree, branch name and histogram parameters setting
DIR_NAMES = ["muonJet"]   # set directory of the root file, if no directory : []
TREE_NAMES = ["Events"]    # set tree path of the root file, you can use multiple trees.
#CONDITIONS = [
#    {
#        "Jet_softMuonEff": {"condition": lambda i: "MatchedMuon_isSoftMuon[i] > -1", "ymean": "MatchedMuon_isSoftMuon", "color": ROOT.kBlack, "marker": 4},
#        "GenJet_muEF": {"condition": lambda i: "GenJet_muEF[i] > -1", "ymean": "GenJet_muEF", "color": ROOT.kRed, "marker": 8},
#    },
#    {
#        "Jet_muEF": {"condition": lambda i: "Jet_muEF[i] > 0", "ymean": "Jet_muEF", "color": ROOT.kBlack, "marker": 4},
#        "GenJet_muEF": {"condition": lambda i: "GenJet_muEF[i] > 0", "ymean": "GenJet_muEF", "color": ROOT.kRed, "marker": 8},
#    }
#]
BRANCHES = [ # see details at Profile1D_def in the module interface/root_tool.py
    {"output": "Jet_softMuonEff", "name": "MatchedMuon_Jeteta", "ymean" : "MatchedMuon_isSoftMuon", "title" : "", "bins": 60, "xmin": -3.0, "xmax": 3.0, "xtitle": "JetEta", "ytitle": "Efficiency", "condition": lambda i: "MatchedMuon_isSoftMuon[i] > -1"},
    {"output": "jet_softMuonFR", "name": "UnMatchedMuon_Jeteta", "ymean" : "UnMatchedMuon_isSoftMuon", "title" : "", "bins": 60, "xmin": -3.0, "xmax": 3.0, "xtitle": "JetEta", "ytitle": "Fake rate", "condition": lambda i: "UnMatchedMuon_isSoftMuon[i] > -1"},
#    {"output": "Jet_softMuonEff_2D", "xname": "MatchedMuon_Jeteta","yname": "MatchedMuon_pt", "ymean" : "MatchedMuon_isSoftMuon", "title" : "", "xbins": 60, "xmin": -3.0, "xmax": 3.0, "ybins": 200, "ymin": 0.0, "ymax": 200.0, "xtitle": "JetEta", "ytitle": "Efficiency", "condition": lambda i: "MatchedMuon_isSoftMuon[i] > -1"},
#    {"output": "jet_softMuonFR_2D", "xname": "UnMatchedMuon_Jeteta","yname": "UnMatchedMuon_pt", "ymean" : "UnMatchedMuon_isSoftMuon", "title" : "", "xbins": 60, "xmin": -3.0, "xmax": 3.0, "ybins": 200, "ymin": 0.0, "ymax": 200.0, "xtitle": "JetEta", "ytitle": "Fake rate", "condition": lambda i: "UnMatchedMuon_isSoftMuon[i] > -1"},

]

################################################################
# Usage of this code                                           #
# python3 script.py <path/to/data.root> [path/to/output/folder]#
################################################################

if len(sys.argv) > 1:
    root_path = sys.argv[1]
    try:
        output_path = sys.argv[2]
        if not os.path.exists(output_path): 
            os.makedirs(output_path)
    except IndexError:
        output_path = "."
else:
    print("Usage: script.py <root_path> [output_path]")
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
#        root_rdf (RDataFrame): RDataFrame of data                                   #
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
                        if (!(Jet_ID[i] > 1) || (Jet_pt[i] < 30) || (std::fabs(Jet_eta[i]) > 2.4)) continue;
                        return true;
                    }}
                    return false;
                    """)
    return rdf

def rdf_define(rdf):

    rdf = rdf.Define("Jet_isIdIdx", 
                    f"""
                    std::vector<int> filtered;
                    for (size_t i = 0; i < Jet_ID.size(); ++i) {{
                        if (!(Jet_genJetIdx[i] > -1) || !(Jet_ID[i] > 1)) continue;
                        filtered.push_back(i);
                    }}
                    return filtered;              
                    """)

    rdf = rdf.Define("MatchedMuon_isSoftMuon",
                    f"""
                    std::vector<int> filtered;
                    for (size_t i = 0; i < GenJet_jetIdx.size(); ++i) {{
                        if (!(GenJet_jetIdx[i] > -1)) continue;
                        if (!(Jet_pt[GenJet_jetIdx[i]] > 30)) continue;
                        if (std::fabs(Jet_eta[GenJet_jetIdx[i]]) > 2.5 && std::fabs(Jet_eta[GenJet_jetIdx[i]]) < 3.0){{
                            if (!(Jet_pt[GenJet_jetIdx[i]] > 50)) continue;
                        }}
                        if (!(Jet_ID[GenJet_jetIdx[i]] > 0)) continue;

                        for (size_t j = 0; j < Jet_packedMuonIdx[GenJet_jetIdx[i]].size(); ++j ){{
                            if(Jet_packedMuonIdx[GenJet_jetIdx[i]][j] > -1){{
                                if (PackedMuon_muonIdx[Jet_packedMuonIdx[GenJet_jetIdx[i]][j]] > -1){{
                                    if (Muon_genPartIdx[PackedMuon_muonIdx[Jet_packedMuonIdx[GenJet_jetIdx[i]][j]]] > -1){{
                                        filtered.push_back(Muon_isSoftMuon[PackedMuon_muonIdx[Jet_packedMuonIdx[GenJet_jetIdx[i]][j]]]);
                                    }}
                                    else {{
                                        filtered.push_back(0);
                                    }}                                
                                }}

                            }}
                        }}
                    }}
                    return filtered;
                    """)
    
    rdf = rdf.Define("UnMatchedMuon_isSoftMuon",
                    f"""
                    std::vector<int> filtered;
                    for (size_t i = 0; i < Jet_isIdIdx.size(); ++i) {{
                        if (!(GenJet_jetIdx[i] > -1)) continue;
                        if (!(Jet_pt[GenJet_jetIdx[i]] > 30)) continue;
                        if (std::fabs(Jet_eta[GenJet_jetIdx[i]]) > 2.5 && std::fabs(Jet_eta[GenJet_jetIdx[i]]) < 3.0){{
                            if (!(Jet_pt[GenJet_jetIdx[i]] > 50)) continue;
                        }}      
                        for (size_t j = 0; j < Jet_packedMuonIdx[Jet_isIdIdx[i]].size(); ++j ){{
                            if(Jet_packedMuonIdx[Jet_isIdIdx[i]][j] > -1){{
                                if (PackedMuon_muonIdx[Jet_packedMuonIdx[Jet_isIdIdx[i]][j]] > -1){{
                                    if (Muon_genPartIdx[PackedMuon_muonIdx[Jet_packedMuonIdx[Jet_isIdIdx[i]][j]]] < 0){{
                                        filtered.push_back(Muon_isSoftMuon[PackedMuon_muonIdx[Jet_packedMuonIdx[Jet_isIdIdx[i]][j]]]);
                                    }}                                
                                }}
                            }}
                        }}
                    }}
                    return filtered;
                    """)
        
    rdf = rdf.Define("MatchedMuon_Jeteta",
                    f"""
                    std::vector<double> filtered;
                    for (size_t i = 0; i < GenJet_jetIdx.size(); ++i) {{
                        if (!(GenJet_jetIdx[i] > -1)) continue;
                        if (!(Jet_pt[GenJet_jetIdx[i]] > 30)) continue;
                        if (std::fabs(Jet_eta[GenJet_jetIdx[i]]) > 2.5 && std::fabs(Jet_eta[GenJet_jetIdx[i]]) < 3.0){{
                            if (!(Jet_pt[GenJet_jetIdx[i]] > 50)) continue;
                        }}
                        if (!(Jet_ID[GenJet_jetIdx[i]] > 0)) continue;

                        for (size_t j = 0; j < Jet_packedMuonIdx[GenJet_jetIdx[i]].size(); ++j ){{
                            if(Jet_packedMuonIdx[GenJet_jetIdx[i]][j] > -1){{
                                if (PackedMuon_muonIdx[Jet_packedMuonIdx[GenJet_jetIdx[i]][j]] > -1){{
                                    filtered.push_back(Jet_eta[GenJet_jetIdx[i]]);                           
                                }}
                            }}
                        }}
                    }}
                    return filtered;
                    """)
    
    
    

    rdf = rdf.Define("MatchedMuon_pt",
                    f"""
                    std::vector<double> filtered;
                    for (size_t i = 0; i < Jet_isIdIdx.size(); ++i) {{
                        if (!(Jet_genJetIdx[i] > -1)) continue;
                        if (!(Jet_pt[GenJet_jetIdx[i]] > 30)) continue;
                        if (std::fabs(Jet_eta[GenJet_jetIdx[i]]) > 2.5 && std::fabs(Jet_eta[GenJet_jetIdx[i]]) < 3.0){{
                            if (!(Jet_pt[GenJet_jetIdx[i]] > 50)) continue;
                        }}      
                        for (size_t j = 0; j < Jet_packedMuonIdx[Jet_isIdIdx[i]].size(); ++j ){{
                            if(Jet_packedMuonIdx[Jet_isIdIdx[i]][j] > -1){{
                                filtered.push_back(Jet_pt[GenJet_jetIdx[i]]);
                            }}
                        }}
                    }}
                    return filtered;
                    """)
        
    rdf = rdf.Define("UnMatchedMuon_Jeteta",
                    f"""
                    std::vector<double> filtered;
                    for (size_t i = 0; i < Jet_isIdIdx.size(); ++i) {{
                        if (!(GenJet_jetIdx[i] > -1)) continue;
                        if (!(Jet_pt[GenJet_jetIdx[i]] > 30)) continue;
                        if (std::fabs(Jet_eta[GenJet_jetIdx[i]]) > 2.5 && std::fabs(Jet_eta[GenJet_jetIdx[i]]) < 3.0){{
                            if (!(Jet_pt[GenJet_jetIdx[i]] > 50)) continue;
                        }}      
                        for (size_t j = 0; j < Jet_packedMuonIdx[Jet_isIdIdx[i]].size(); ++j ){{
                            if(Jet_packedMuonIdx[Jet_isIdIdx[i]][j] > -1){{
                                if (PackedMuon_muonIdx[Jet_packedMuonIdx[Jet_isIdIdx[i]][j]] > -1){{
                                    if (Muon_genPartIdx[PackedMuon_muonIdx[Jet_packedMuonIdx[Jet_isIdIdx[i]][j]]] < 0){{
                                        filtered.push_back(Jet_eta[GenJet_jetIdx[i]]);
                                    }}                                
                                }}
                            }}
                        }}
                    }}
                    return filtered;
                    """)
    

    
    rdf = rdf.Define("UnMatchedMuon_pt",
                    f"""
                    std::vector<double> filtered;
                    for (size_t i = 0; i < Jet_isIdIdx.size(); ++i) {{
                        if (!(GenJet_jetIdx[i] > -1)) continue;
                        if (!(Jet_pt[GenJet_jetIdx[i]] > 30)) continue;
                        if (std::fabs(Jet_eta[GenJet_jetIdx[i]]) > 2.5 && std::fabs(Jet_eta[GenJet_jetIdx[i]]) < 3.0){{
                            if (!(Jet_pt[GenJet_jetIdx[i]] > 50)) continue;
                        }}      
                        for (size_t j = 0; j < Jet_packedMuonIdx[Jet_isIdIdx[i]].size(); ++j ){{
                            if(Jet_packedMuonIdx[Jet_isIdIdx[i]][j] > -1){{
                                if (Muon_genPartIdx[PackedMuon_muonIdx[Jet_packedMuonIdx[Jet_isIdIdx[i]][j]]] < 0){{
                                    filtered.push_back(Jet_pt[GenJet_jetIdx[i]]);
                                }}
                            }}
                        }}
                    }}
                    return filtered;
                    """)    
    return rdf

def draw_profile(root_rdf, tree_name, branch, output_dir="."):


    hist = Profile1D_filtery_def(root_rdf, branch)
    # draw and decorate canvas
    with canvas_lock: # deactivate multi-thread
        
        canvas = ROOT.TCanvas("canvas", "", 800, 800)
        canvas.SetLeftMargin(0.15)
        canvas.SetBottomMargin(0.15)
        #hist.SetLineColor(ROOT.kBlue)
        
        # pad1
        pad1 = ROOT.TPad("pad1", "pad1", 0, 0, 1, 1.0)
        pad1.SetLeftMargin(0.15)
        pad1.SetBottomMargin(0.15)
        pad1.Draw()
        pad1.cd()
        print("test")
        hist.GetXaxis().SetTitle(branch['xtitle'])
        hist.GetXaxis().SetTitleSize(0.06)
        hist.GetYaxis().SetTitle(branch['ytitle'])
        hist.GetYaxis().SetTitleSize(0.06)
        hist.GetYaxis().SetRangeUser(0, 1.2*hist.GetMaximum())
        hist.Draw("HIST")
        print("test2")
        latex = ROOT.TLatex()
        latex.SetNDC()
        latex.SetTextSize(0.035)
        latex.SetTextFont(62)  # bold font for "CMS"
        latex.SetTextAlign(12)
        latex.DrawLatex(0.10, 0.92, "CMS")
        latex.SetTextFont(42)  # normal font
        latex.DrawLatex(0.17, 0.92, "#it{In Progress}")
        latex.SetTextAlign(32)
        latex.DrawLatex(0.9, 0.92, "#sqrt{s} = 13.6 TeV")
        
        legend = ROOT.TLegend(0.9, 0.8, 0.9, 0.9)
        legend.AddEntry(hist.GetValue(), "jetsoftmuon", "f")
        legend.Draw()
    
        
        canvas.SaveAs(f"{output_dir}/{branch['output']}.png")
        del canvas



##########################################################################
# main function : Open Data and MC file and call draw_histogram function #
#     Parameters:                                                        #
#         filename (str): data.root file directory                       #
#         output_dir (str): histogram output directory                   #
##########################################################################

def main(filename,output_dir="."):

    root_file = None
    gc.collect()

    root_file, root_dir = load_file(filename, DIR_NAMES[0])

    for tree_name in TREE_NAMES:
        root_tree = root_dir.Get(tree_name)
        if not root_tree:
            print(f"Tree '{tree_name}' not found in data directory '{DIR_NAMES}'!")
            continue

        root_rdf = ROOT.RDataFrame(root_tree)
        root_rdf = rdf_filter_jet(root_rdf)
        root_rdf = rdf_define(root_rdf)
        
        for branch in BRANCHES:
            print(f"Draw '{branch}' in '{tree_name}'")
            try:
                #condition = CONDITIONS[i]
                draw_profile(root_rdf, tree_name, branch, output_dir)
                        
            except Exception as e:
                # Check for specific error and log the problematic entry
                print(f"Error initializing RDataFrame for tree '{tree_name}': {str(e)}")
                for entry in root_tree:
                    try:
                        event_number = getattr(entry, "eventNumber", None)
                        if event_number:
                            data_entry_numbers.append(event_number)
                    except:
                        log_corrupted_entry(event_number)
                        continue
                continue
            
    root_file.Close()

main(root_path, output_path)
