#define JetTree_cxx
#include "JetTree.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void JetTree::Loop()
{
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   for (Long64_t jentry = 0; jentry < nentries; ++jentry) {
      fChain->GetEntry(jentry);

      std::cout << "Event " << jentry << ": tagInfoLabels = [ ";
      for (const auto& label : *patJets_slimmedJetsPuppi__PAT_obj_tagInfoLabels_) {
         std::cout << label << " ";
      }
      std::cout << "]" << std::endl;

   }
}