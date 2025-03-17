
#############################################
# Description:                              #
#     draw simple histogram with RdataFrame #
#############################################
import ROOT
from ROOT import RDataFrame
import sys
import os
import gc
import threading
import json
from root_tool import *
ROOT.gStyle.SetOptStat(0)
ROOT.gROOT.SetBatch(True) # don't show pop-up (can cause seg fault with multi-thread)
ROOT.EnableThreadSafety()
ROOT.EnableImplicitMT(48) # activate multi-thread and set a number of threads

data_entry_numbers = []
log_lock = threading.Lock()
canvas_lock = threading.Lock()


#######################
# Set user parameters #
#######################

if len(sys.argv) == 3:
    mode = int(sys.argv[1])
    json_path = sys.argv[2]
    if not isinstance(mode, int) or mode < 0 or mode > 5:
        print("warning: mode must be integer 0 to 5.")
        sys.exit(1)
    if not os.path.exists(json_path):
        print(f"Error: {json_path} does not exist.")
        sys.exit(1)

else:
    print("Usage: script.py <mode> <json_path>")
    sys.exit(1)


with open(json_path, 'r') as f:
    data = json.load(f).get(str(mode))
    input_path = data.get("input_path")
    output_path = data.get("output_path")
    json_config = data.get("json_config")
    if not os.path.exists(output_path): 
            os.makedirs(output_path)

try:
    with open(json_config, "r") as config_file:
        config = json.load(config_file)
except Exception as e:
    print("Error reading json:", e)
    sys.exit(1)

DIR_NAMES = config.get("DIR_NAMES", [])
TREE_NAMES = config.get("TREE_NAMES", ["Events"])
BRANCHES = config.get("BRANCHES", [])

######################################################################################
# helper functions                                                                   #
# log_corrupted_entry(event_number)                                                  #
#     Logs the corrupted event number to a file                                      #
#     parameters:                                                                    #
#         event_number (int) : Corrupted event, which can't be read a entry          #
#                                                                                    #
# draw_histogram                                                                     #
#    parameters:                                                                     #
#        root_rdf (RDataFrame): RDataFrame of root                                   #
#        tree_name (str): current tree                                               #
#        branch (dict): branch info with (bins, xmin, xmax, xtitle, ytitle...)       #
#        output_dir (str): histogram output directory                                #
# ####################################################################################



def log_corrupted_entry(event_number):
    with log_lock:
        with open("corrupted_entries.log", "a") as log_file:
            log_file.write(f"Corrupted event: {event_number}\n")


def draw_histogram(root_rdf, tree_name, branch, output_dir="."):

    #hist_root = Histo1D_def_weight(root_rdf, branch)
    hist_root = Histo1D_def(root_rdf, branch)
    # draw and decorate canvas
    with canvas_lock: # deactivate multi-thread
        canvas = ROOT.TCanvas("canvas", "", 800, 600)
        canvas.SetLeftMargin(0.15)
        canvas.SetBottomMargin(0.15)
        canvas.SetLogx(branch['xscalelog'])
        canvas.SetLogy(branch['yscalelog'])

        hist_root.SetMarkerStyle(20)
        hist_root.SetMarkerColor(ROOT.kBlack)
        hist_root.SetLineColor(ROOT.kBlack)
        hist_root.SetOption("HIST")
        hist_root.Draw()
        entries = int(hist_root.Integral())
        latex = ROOT.TLatex()
        latex.SetNDC()
        latex.SetTextSize(0.035)
        latex.SetTextFont(62)  # bold font for "CMS"
        latex.SetTextAlign(12)
        latex.DrawLatex(0.15, 0.92, "CMS")
        latex.SetTextFont(42)  # normal font
        latex.DrawLatex(0.21, 0.92, "#it{In Progress}")
#        latex.DrawLatex(0.70, 0.91, "#sqrt{s} = 13.6 TeV, L = 7.6 /fb")
        latex.SetTextAlign(32)
        latex.DrawLatex(0.9, 0.92, "#sqrt{s} = 13.6 TeV")
        #latex.DrawLatex(0.9, 0.88, f"Total entries : {entries}")
        hist_root.GetXaxis().SetTitle(branch['xtitle'])
        hist_root.GetXaxis().SetTitleSize(0.06)
        hist_root.GetYaxis().SetTitle(branch['ytitle'])
        hist_root.GetYaxis().SetTitleSize(0.06)

        canvas.SaveAs(f"{output_dir}/{branch['output']}.png")
        del canvas


##########################################################################
# main function : Open Data and MC file and call draw_histogram function #
#     Parameters:                                                        #
#         filename (str): inputfile.root file directory                  #
#         output_dir (str): histogram output directory                   #
##########################################################################

def main(filename, output_dir="."):

    root_file = None
    gc.collect()

    root_file, root_dir = load_file(filename, DIR_NAMES)

    for tree_name in TREE_NAMES:
        root_tree = root_dir.Get(tree_name)
        if not root_tree:
            print(f"Tree '{tree_name}' not found in data directory '{DIR_NAMES}'!")
            continue

        root_rdf = ROOT.RDataFrame(root_tree)

        for branch in BRANCHES:
            condition_str = branch.get("condition", "")
            if "[i]" in condition_str:
                branch["condition"] = lambda i, cond_str=condition_str: cond_str
            else:
                branch["condition"] = condition_str
            print(f"Draw '{branch}' in '{tree_name}'")
            try:
                draw_histogram(root_rdf, tree_name, branch, output_dir)
                        
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


main(input_path, output_path)