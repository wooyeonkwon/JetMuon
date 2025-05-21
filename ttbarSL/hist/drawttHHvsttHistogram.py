
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
from root_tool import Histo1D_def_weight

ROOT.gStyle.SetOptStat(0)
ROOT.gROOT.SetBatch(True) # don't show pop-up (can cause seg fault with multi-thread)
ROOT.EnableThreadSafety()
ROOT.EnableImplicitMT(56) # activate multi-thread and set a number of threads

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
    {"output": "Muon_mvaTight_miniIsoTight_pt", "name": "Muon_pt", "weight":"genWeight", "xsection":404.0,  "bins": 185, "xmin": 15.0, "xmax": 200.0, "title": "", "xtitle": "pt (GeV)", "ytitle": "Muon Multiplicity", "condition": lambda i: "Muon_isGood[i]"},


]
SIG_BRANCHES = [                            # see details at Histo1D_def in the module root_tool.py
    {"output": "Muon_mvaTight_miniIsoTight_pt", "name": "Muon_pt", "weight":"genWeight", "xsection":0.0000618, "bins": 185, "xmin": 15.0, "xmax": 200.0, "title": "", "xtitle": "pt (GeV)", "ytitle": "Muon Multiplicity", "condition": lambda i: "Muon_isGood[i]"},    
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

def goodMuon(rdf):
    rdf = rdf.Define("Muon_isGood",f"""
                   std::vector<bool> good_muons;
                    for (size_t i = 0; i < Muon_pt.size(); ++i) {{
                        if((Muon_pt[i] > 15) && (std::fabs(Muon_eta[i]) < 2.4) && (Muon_mvaMuID_WP[i] >= 2) && (Muon_miniIsoId[i] > 2) && (std::fabs(Muon_dxy[i]) < 0.05) && (std::fabs(Muon_dz[i]) < 0.1)) good_muons.push_back(true);
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
                    if (nGoodMuons > 3) return true;
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


def draw_histogram(sig_rdf, bg_rdf, tree_name, branch, gen_branch, norm_weight, output_dir="."):
    
    hist_sig = Histo1D_def_weight(sig_rdf, branch, 1)
    hist_bg = Histo1D_def_weight(bg_rdf, gen_branch, norm_weight)

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
        hist_sig.SetLineColor(ROOT.kBlack)
        #hist_gen.SetFillColor(ROOT.kBlue)
        hist_bg.SetLineColor(ROOT.kBlue)
        
        # pad1
        pad1 = ROOT.TPad("pad1", "pad1", 0, 0.3, 1, 1.0)
        pad1.SetLeftMargin(0.15)
        pad1.SetBottomMargin(0)
        pad1.Draw()
        pad1.SetLogy(True)
        pad1.cd()
        hist_bg.GetYaxis().SetTitle(branch['ytitle'])
        hist_bg.GetYaxis().SetTitleSize(0.06)
        ymax = 10 * max(hist_bg.GetMaximum(),hist_sig.GetMaximum())
        hist_bg.GetYaxis().SetRangeUser(1, ymax)
        hist_bg.Draw("HIST")
        hist_sig.Draw("HIST Same")
        bg_entries = int(hist_bg.Integral())
        sig_entries = int(hist_sig.Integral())
        print(f"ttHH_entries : {sig_entries}, ttbar_entries: {bg_entries}")

        sig_events = sig_rdf.Count().GetValue()
        bg_events = int(norm_weight * bg_rdf.Count().GetValue())
        print(f"ttHH_events : {sig_events}, ttbar_events: {bg_events}")
        
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
        
        legend = ROOT.TLegend(0.7, 0.7, 0.9, 0.9)
        legend.AddEntry(hist_sig.GetValue(), "ttHHMuon", "f")
        legend.AddEntry(hist_bg.GetValue(), "ttbarMuon", "f")
        legend.Draw()
        
        # pad2
        canvas.cd()
        pad2 = ROOT.TPad("pad2", "pad2", 0, 0.05, 1, 0.3)
        pad2.SetLeftMargin(0.15)
        pad2.SetTopMargin(0)
        pad2.SetBottomMargin(0.2)
        pad2.Draw()
        pad2.cd()
        
        ratioHist = hist_sig.Clone("ratioHist")
        ratioHist.Divide(hist_bg.GetValue())
        ratioHist.SetTitle("")
        ratioHist.GetYaxis().SetTitle("ttHH / ttbar")

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
        ratioHist.GetYaxis().SetRangeUser(0.9 * ratioHist.GetMinimum(), 1.1 * ratioHist.GetMaximum())

        
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
        
        sig_events_org = sig_rdf.Count().GetValue()
        bg_events_org = bg_rdf.Count().GetValue()


        sig_rdf = rdf_filter_jet(sig_rdf)
        sig_rdf = goodMuon(sig_rdf)
        sig_rdf = nGoodMuon(sig_rdf)
        sig_rdf = same_sign_muon_filter(sig_rdf)

        bg_rdf = rdf_filter_jet(bg_rdf)
        bg_rdf = goodMuon(bg_rdf)
        bg_rdf = nGoodMuon(bg_rdf)
        bg_rdf = same_sign_muon_filter(bg_rdf)

        for bg_branch, sig_branch in zip(BG_BRANCHES, SIG_BRANCHES):
            print(f"Draw '{bg_branch}' in '{tree_name}'")
            print(f"Draw '{sig_branch}' in '{tree_name}'")
            try:
                sig_lumi = sig_events_org / sig_branch["xsection"]
                bg_norm_weight = sig_lumi * bg_branch["xsection"] / bg_events_org
                draw_histogram(sig_rdf, bg_rdf, tree_name, sig_branch, bg_branch, bg_norm_weight, output_dir)
                        
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