
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
from root_tool import Histo1D_def


ROOT.gStyle.SetOptStat(0)
ROOT.gROOT.SetBatch(True) # don't show pop-up (can cause seg fault with multi-thread)
ROOT.EnableThreadSafety()
ROOT.EnableImplicitMT(255) # activate multi-thread and set a number of threads

data_entry_numbers = []
log_lock = threading.Lock()
profile_lock = threading.Lock()
canvas_lock = threading.Lock()

##############################
# Set user define parameters #
##############################

# directory, tree, branch name and histogram parameters setting
DIR_NAMES = [[]]   # set directory of the root file, if no directory : []
TREE_NAMES = ["JetTree"]    # set tree path of the root file, you can use multiple trees.
BRANCHES = [ # see details at Profile1D_def in the module interface/root_tool.py
    {"output": "gen_Jet_EnergyFraction_eta", "name": "Jet_eta", "title" : "", "bins": 60, "xmin": -3.0, "xmax": 3.0, "xtitle": "Jet_eta", "ytitle": "energy fraction", "condition": None},
#    {"output": "gen_Jet_EnergyFraction_pt", "name": "Jet_pt", "title" : "", "bins": 270, "xmin": 30.0, "xmax": 300.0, "xtitle": "Jet_pt", "ytitle": "energy fraction", "condition": None},
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

def filter(df):
    df = df.Filter(f"""(Jet_btagPNetB < 0.05)""")
    return df

def draw_profile(root_rdf, tree_name, branch, output_dir="."):
    #root_rdf = filter(root_rdf)  # Apply the filter
    h_chHadEF = ROOT.TH1D("hist1", branch["title"], branch["bins"], branch["xmin"], branch["xmax"])
    h_photonEF = ROOT.TH1D("hist2", branch["title"], branch["bins"], branch["xmin"], branch["xmax"])
    h_neuHadEF = ROOT.TH1D("hist3", branch["title"], branch["bins"], branch["xmin"], branch["xmax"])
    h_eleEF = ROOT.TH1D("hist4", branch["title"], branch["bins"], branch["xmin"], branch["xmax"])
    h_muEF = ROOT.TH1D("hist5", branch["title"], branch["bins"], branch["xmin"], branch["xmax"])
    bin_width = (branch["xmax"] - branch["xmin"]) / branch["bins"]
    for i in range(branch["bins"]):
        
        eta_min = branch["xmin"] + i * bin_width
        eta_max = branch["xmin"] + (i + 1) * bin_width
        df_bin = root_rdf.Filter(f"""(Jet_eta >= {eta_min}) && (Jet_eta < {eta_max})""")

        
        nJets = df_bin.Count().GetValue()
        if nJets == 0:
            continue

        avg_chHadEF = df_bin.Mean("Jet_chHadEF").GetValue()
        avg_photonEF = df_bin.Mean("Jet_photonEF").GetValue()
        avg_neuHadEF = df_bin.Mean("Jet_neuHadEF").GetValue()
        avg_eleEF = df_bin.Mean("Jet_eleEF").GetValue()
        avg_muEF = df_bin.Mean("Jet_muEF").GetValue()

        h_chHadEF.SetBinContent(i+1, avg_chHadEF)
        h_photonEF.SetBinContent(i+1, avg_photonEF)
        h_neuHadEF.SetBinContent(i+1, avg_neuHadEF)
        h_eleEF.SetBinContent(i+1, avg_eleEF)
        h_muEF.SetBinContent(i+1, avg_muEF)

    h_chHadEF.SetFillColor(ROOT.kRed+1)
    h_photonEF.SetFillColor(ROOT.kBlue+1)
    h_neuHadEF.SetFillColor(ROOT.kGreen+1)
    h_eleEF.SetFillColor(ROOT.kOrange+1)
    h_muEF.SetFillColor(ROOT.kMagenta+1)

    hist = ROOT.THStack("hs", "")
    hist.Add(h_chHadEF)
    hist.Add(h_photonEF)
    hist.Add(h_neuHadEF)
    hist.Add(h_muEF)
    hist.Add(h_eleEF)


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
        hist.Draw("HIST")
        print("test2")
        hist.GetXaxis().SetTitle(branch["xtitle"])
        hist.GetXaxis().SetTitleSize(0.06)
        hist.GetYaxis().SetTitle(branch["ytitle"])
        hist.GetYaxis().SetTitleSize(0.06)
        hist.SetMaximum(1.4)
        pad1.Modified()
        pad1.Update()
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
        
        legend = ROOT.TLegend(0.5, 0.7, 0.9, 0.9)
        legend.SetNColumns(2)
        legend.AddEntry(h_eleEF, "Electron", "f")
        legend.AddEntry(h_muEF, "Muon", "f")
        legend.AddEntry(h_neuHadEF, "Neutral Hadron", "f")
        legend.AddEntry(h_photonEF, "Photon", "f")
        legend.AddEntry(h_chHadEF, "Charged Hadron", "f")
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
