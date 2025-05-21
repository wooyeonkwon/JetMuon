
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
import numpy as np

ROOT.gStyle.SetOptStat(0)
ROOT.gROOT.SetBatch(True) # don't show pop-up (can cause seg fault with multi-thread)
ROOT.EnableThreadSafety()
ROOT.EnableImplicitMT(240) # activate multi-thread and set a number of threads

data_entry_numbers = []
log_lock = threading.Lock()
canvas_lock = threading.Lock()

##############################
# Set user define parameters #
##############################
# directory, tree, branch name and histogram parameters setting
DIR_NAMES = []   # set TDirectory of the root file ["data","mc" ], if no directory : []
TREE_NAMES = ["Events"]               # set tree path of the root file, you must use same Treename for data and mc.
BG_BRANCHES = [                            # see details at Histo1D_def in the module root_tool.py
    {"output": "Muon_looseId", "name": "Muon_pt", "weight":"genWeight", "xsection":96.9,  "bins": 185, "xmin": 15.0, "xmax": 200.0, "title": "", "xtitle": "", "ytitle": "Events", "condition": "Muon_looseId[i] == 1"},
    {"output": "Muon_mediumId", "name": "Muon_pt", "weight":"genWeight", "xsection":96.9,  "bins": 185, "xmin": 15.0, "xmax": 200.0, "title": "", "xtitle": "", "ytitle": "Events", "condition": "Muon_mediumId[i] == 1"},
    {"output": "Muon_tightId", "name": "Muon_pt", "weight":"genWeight", "xsection":96.9,  "bins": 185, "xmin": 15.0, "xmax": 200.0, "title": "", "xtitle": "", "ytitle": "Events", "condition": "Muon_tightId[i] == 1"},
    {"output": "Muon_softId", "name": "Muon_pt", "weight":"genWeight", "xsection":96.9,  "bins": 185, "xmin": 15.0, "xmax": 200.0, "title": "", "xtitle": "", "ytitle": "Events", "condition": "Muon_softId[i] == 1"},
    {"output": "Muon_mvaMuID_WP_medium", "name": "Muon_pt", "weight":"genWeight", "xsection":96.9,  "bins": 185, "xmin": 15.0, "xmax": 200.0, "title": "", "xtitle": "", "ytitle": "Events", "condition": "Muon_mvaMuID_WP[i] >= 1"},
    {"output": "Muon_mvaMuID_WP_tight", "name": "Muon_pt", "weight":"genWeight", "xsection":96.9,  "bins": 185, "xmin": 15.0, "xmax": 200.0, "title": "", "xtitle": "", "ytitle": "Events", "condition": "Muon_mvaMuID_WP[i] == 2"},
]
SIG_BRANCHES = [                            # see details at Histo1D_def in the module root_tool.py
    {"output": "Muon_looseId", "name": "Muon_pt", "weight":"genWeight", "xsection":0.000012, "bins": 185, "xmin": 15.0, "xmax": 200.0, "title": "", "xtitle": "", "ytitle": "Events", "condition": "Muon_looseId[i] == 1"},    
    {"output": "Muon_mediumId", "name": "Muon_pt", "weight":"genWeight", "xsection":0.000012, "bins": 185, "xmin": 15.0, "xmax": 200.0, "title": "", "xtitle": "", "ytitle": "Events", "condition": "Muon_mediumId[i] ==1"},    
    {"output": "Muon_tightId", "name": "Muon_pt", "weight":"genWeight", "xsection":0.000012, "bins": 185, "xmin": 15.0, "xmax": 200.0, "title": "", "xtitle": "", "ytitle": "Events", "condition": "Muon_tightId[i] == 1"},    
    {"output": "Muon_softId", "name": "Muon_pt", "weight":"genWeight", "xsection":0.000012, "bins": 185, "xmin": 15.0, "xmax": 200.0, "title": "", "xtitle": "", "ytitle": "Events", "condition": "Muon_softId[i] == 1"},    
    {"output": "Muon_mvaMuID_WP_medium", "name": "Muon_pt", "weight":"genWeight", "xsection":0.000012, "bins": 185, "xmin": 15.0, "xmax": 200.0, "title": "", "xtitle": "", "ytitle": "Events", "condition": "Muon_mvaMuID_WP[i] >= 1"},
    {"output": "Muon_mvaMuID_WP_tight", "name": "Muon_pt", "weight":"genWeight", "xsection":0.000012, "bins": 185, "xmin": 15.0, "xmax": 200.0, "title": "", "xtitle": "", "ytitle": "Events", "condition": "Muon_mvaMuID_WP[i] == 2"},        
]
# Define the muon isolation categories
ISO_BRANCHES = [{"label": "pfIsoId[1]", "condition": "Muon_pfIsoId[i] >= 1" },
                {"label": "pfIsoId[2]", "condition": "Muon_pfIsoId[i] >= 2" },
                {"label": "pfIsoId[3]", "condition": "Muon_pfIsoId[i] >= 3" },
                {"label": "pfIsoId[4]", "condition": "Muon_pfIsoId[i] >= 4" },
                {"label": "pfIsoId[5]", "condition": "Muon_pfIsoId[i] >= 5" },
                {"label": "pfIsoId[6]", "condition": "Muon_pfIsoId[i] == 6" },
                {"label": "tkIsoId[1]", "condition": "Muon_tkIsoId[i] >= 1" },
                {"label": "tkIsoId[2]", "condition": "Muon_tkIsoId[i] == 2" },
                {"label": "miniIsoId[1]", "condition": "Muon_miniIsoId[i] >= 1" },
                {"label": "miniIsoId[2]", "condition": "Muon_miniIsoId[i] >= 2" },
                {"label": "miniIsoId[3]", "condition": "Muon_miniIsoId[i] >= 3" },
                {"label": "miniIsoId[4]", "condition": "Muon_miniIsoId[i] >= 4" },
                {"label": "multiIsoId", "condition": "Muon_multiIsoId[i] >= 1"},
                ]

# final_survie_event (data) = data_lumi * mc_cross_section * mc_triggerEff * mc_selectionEff
# final_survie_event (mc) = mc_events * mc_selectionEff * mc_triggerEff * matchingEff / gen_weight
# final_survie_event (data) = nom_factor * final_survie_event (mc) 
# data_lumi * mc_cross_section * data_triggerEff / mc_events_total * mc_triggerEff * matchingEff
###################################################################################
# Usage of this code                                                              #
# python3 script.py <path/to/data.root> <path/to/mc.root> [path/to/output/folder] #
###################################################################################

if len(sys.argv) > 2:
    sig_path = sys.argv[1]
    bg_path = sys.argv[2]
    try:
        output_path = sys.argv[3]
        if not os.path.exists(output_path): 
            os.makedirs(output_path)
    except IndexError:
        output_path = "."
else:
    print("Usage: script.py <signal_path> <background_path> [output_path]")
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
                    if (Jet_pt.size() < 4) return false;
                    int nbjets = 0; 
                    for (size_t i = 0; i < Jet_pt.size(); ++i) {{
                        if ((Jet_pt[i] > 25) && (std::fabs(Jet_eta[i]) < 2.5) && (Jet_jetId[i] == 6) && (Jet_btagPNetB[i] > 0.1917)) nbjets++;
                    }}
                    if (nbjets > 3) return true;
                    else{{
                        return false;
                    }} 
                    """)
    return rdf

def goodMuon(rdf, muon_id, muon_iso):
    rdf = rdf.Define("Muon_isGood",f"""
                   std::vector<bool> good_muons;
                    for (size_t i = 0; i < Muon_pt.size(); ++i) {{
                        if((Muon_pt[i] > 15) && (std::fabs(Muon_eta[i]) < 2.4) && ({muon_id}) && ({muon_iso}) && (std::fabs(Muon_dxy[i]) < 0.05) && (std::fabs(Muon_dz[i]) < 0.1)) good_muons.push_back(true);
                        else good_muons.push_back(false);
                    }}
                    return good_muons;

                    """)
    return rdf

def nGoodMuon(rdf):
    rdf = rdf.Define("nGoodMuons", f"""
                    int nMuons = 0;
                    for (size_t i = 0; i < Muon_pt.size(); ++i) {{
                        if (Muon_isGood[i] == true){{
                            nMuons++;
                            }}
                        }}
                    return nMuons;
                    """)

    return rdf

def same_sign_muon_filter(rdf):
    rdf = rdf.Filter(f"""
                    if (nGoodMuons < 2) return false;
                    if (nGoodMuons >= 3) return true;
                    for (size_t i = 0; i < Muon_charge.size(); ++i) {{
                        if (!(Muon_isGood[i])) continue;
                        for (size_t j = i + 1; j < Muon_charge.size(); ++j) {{
                            if (!(Muon_isGood[j])) continue;
                            if (Muon_charge[i] * Muon_charge[j] > 0) {{
                                return true;
                            }} 
                        }}
                    }}
                    return false;
                    """)

    return rdf

def opposite_sign_muon_filter(rdf):
    rdf = rdf.Filter(f"""
                    if (!(nGoodMuons == 2)) return false;
                    for (size_t i = 0; i < Muon_charge.size(); ++i) {{
                        if (!(Muon_isGood[i])) continue;
                        for (size_t j = i + 1; j < Muon_charge.size(); ++j) {{
                            if (!(Muon_isGood[j])) continue;
                            if (Muon_charge[i] * Muon_charge[j] < 0) {{
                                return true;
                            }} 
                        }}
                    }}
                    return false;
                    """)


def draw_histogram(sig_rdf_org, bg_rdf_org, tree_name, sig_branch, bg_branch, norm_weight, output_dir="."):


    # Define the histogram for signal and background x-axis bins with ISO_BRANCHES label

    hist_sig = ROOT.TH1D("hist_sig","",len(ISO_BRANCHES),0.5,len(ISO_BRANCHES)+0.5)
    hist_bg = ROOT.TH1D("hist_bg","",len(ISO_BRANCHES),0.5,len(ISO_BRANCHES)+0.5)
    significanceHist = ROOT.TH1D("significanceHist","",len(ISO_BRANCHES),0.5,len(ISO_BRANCHES)+0.5)

    for i, iso_branch in enumerate(ISO_BRANCHES):
        sig_rdf = sig_rdf_org
        bg_rdf = bg_rdf_org

        sig_rdf = goodMuon(sig_rdf,sig_branch['condition'],iso_branch['condition'])
        sig_rdf = nGoodMuon(sig_rdf)
        sig_rdf = same_sign_muon_filter(sig_rdf)    
        bg_rdf = goodMuon(bg_rdf,bg_branch['condition'],iso_branch['condition'])
        bg_rdf = nGoodMuon(bg_rdf)
        bg_rdf = same_sign_muon_filter(bg_rdf)
        
        sig_events = sig_rdf.Count().GetValue()
        bg_events = int(norm_weight * bg_rdf.Count().GetValue())

        significance = sig_events / (np.sqrt(bg_events))
        hist_sig.SetBinContent(i+1,sig_events)
        hist_bg.SetBinContent(i+1,bg_events)
        significanceHist.SetBinContent(i+1,significance)
        significanceHist.GetXaxis().SetBinLabel(i+1,iso_branch['label'])


    # draw and decorate canvas
    with canvas_lock: # deactivate multi-thread
        canvas = ROOT.TCanvas("canvas", "", 800, 800)
        canvas.SetLeftMargin(0.15)
        canvas.SetBottomMargin(0.15)
        hist_sig.SetLineColor(ROOT.kBlack)
        hist_bg.SetLineColor(ROOT.kBlue)
        
        # pad1
        pad1 = ROOT.TPad("pad1", "pad1", 0, 0.3, 1, 1.0)
        pad1.SetLeftMargin(0.15)
        pad1.SetBottomMargin(0)
        pad1.Draw()
        pad1.SetLogy(True)
        pad1.cd()
        hist_bg.GetYaxis().SetTitle(sig_branch['ytitle'])
        hist_bg.GetYaxis().SetTitleSize(0.06)
        ymax = 10 * max(hist_bg.GetMaximum(),hist_sig.GetMaximum())
        hist_bg.GetYaxis().SetRangeUser(1, ymax)
        hist_bg.Draw("HIST")
        hist_sig.Draw("HIST Same")

        
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
        
        legend = ROOT.TLegend(0.8, 0.8, 0.9, 0.9)
        legend.AddEntry(hist_sig, "ttHH", "f")
        legend.AddEntry(hist_bg, "ttbar", "f")
        legend.Draw()
        
        # pad2
        canvas.cd()
        pad2 = ROOT.TPad("pad2", "pad2", 0, 0.05, 1, 0.3)
        pad2.SetLeftMargin(0.15)
        pad2.SetTopMargin(0)
        pad2.SetBottomMargin(0.2)
        pad2.Draw()
        pad2.cd()
        

        significanceHist.GetYaxis().SetTitle("significance")

        significanceHist.GetYaxis().SetNdivisions(505)
        significanceHist.GetYaxis().SetTitleSize(20)
        significanceHist.GetYaxis().SetTitleFont(43)
        significanceHist.GetYaxis().SetTitleOffset(1.55)
        significanceHist.GetYaxis().SetLabelFont(43)
        significanceHist.GetYaxis().SetLabelSize(15)
        significanceHist.GetXaxis().SetTitle(sig_branch['xtitle'])
        significanceHist.GetXaxis().SetTitleSize(20)
        significanceHist.GetXaxis().SetTitleFont(43)
        significanceHist.GetXaxis().SetLabelFont(43)
        significanceHist.GetXaxis().SetLabelSize(15)
        significanceHist.Draw("HIST")
        significanceHist.GetYaxis().SetRangeUser(0.9 * significanceHist.GetMinimum(), 1.1 * significanceHist.GetMaximum())
        
        canvas.SaveAs(f"{output_dir}/{sig_branch['output']}.png")
        del canvas


##########################################################################
# main function : Open Data and MC file and call draw_histogram function #
#     Parameters:                                                        #
#         data_filename (str): data.root file directory                  #
#         mc_filename (str): mc.root file directory                      #
#         output_dir (str): histogram output directory                   #
##########################################################################

def main(sig_filename, bg_filename, output_dir="."):

    sig_file = None
    bg_file = None
    gc.collect()

    sig_file, sig_dir = load_file(sig_filename, DIR_NAMES)
    bg_file, bg_dir = load_file(bg_filename, DIR_NAMES)

    for tree_name in TREE_NAMES:
        sig_tree = sig_dir.Get(tree_name)
        bg_tree = bg_dir.Get(tree_name)
        if not sig_tree:
            print(f"Tree '{tree_name}' not found in data directory '{DIR_NAMES}'!")
            continue

        if not bg_tree:
            print(f"Tree '{tree_name}' not found in MC directory '{DIR_NAMES}'!")
            continue

        sig_rdf = ROOT.RDataFrame(sig_tree)
        bg_rdf = ROOT.RDataFrame(bg_tree)
        
        sig_events_org = 99998 #SL 99998, DL 99998
        bg_events_org = 48203000 #SL 152797000, DL 48203000

        sig_rdf_org = rdf_filter_jet(sig_rdf)
        bg_rdf_org = rdf_filter_jet(bg_rdf)


        for bg_branch, sig_branch in zip(BG_BRANCHES, SIG_BRANCHES):
            print(f"Draw '{bg_branch}' in '{tree_name}'")
            print(f"Draw '{sig_branch}' in '{tree_name}'")
            try:
                sig_lumi = sig_events_org / sig_branch["xsection"]
                bg_norm_weight = sig_lumi * bg_branch["xsection"] / bg_events_org
                draw_histogram(sig_rdf_org, bg_rdf_org, tree_name, sig_branch, bg_branch, bg_norm_weight, output_dir)
                        
            except Exception as e:
                # Check for specific error and log the problematic entry
                print(f"Error initializing RDataFrame for tree '{tree_name}': {str(e)}")
                for entry in sig_tree:
                    try:
                        event_number = getattr(entry, "eventNumber", None)
                        if event_number:
                            data_entry_numbers.append(event_number)
                    except:
                        log_corrupted_entry(event_number)
                        continue
                continue

    sig_file.Close()
    bg_file.Close()

main(sig_path, bg_path, output_path)