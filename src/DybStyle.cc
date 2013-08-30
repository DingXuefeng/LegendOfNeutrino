#include "DybStyle.h"
#include "TStyle.h"
#include "TROOT.h"
#include "Rtypes.h"
TStyle* DybStyle::m_dybStyle = NULL;
DybStyle::DybStyle(){}

TStyle* DybStyle::get(){
  if(!m_dybStyle){
    m_dybStyle = new  TStyle("m_dybStyle", "Daya Bay Style");

    //set the background color to white
    Int_t icol=0;
    //m_dybStyle->SetFillColor(icol); 
    m_dybStyle->SetFrameFillColor(icol);
    m_dybStyle->SetCanvasColor(icol);
    m_dybStyle->SetPadColor(icol);
    m_dybStyle->SetStatColor(icol);
    m_dybStyle->SetTitleFillColor(icol);
    //m_dybStyle->SetLegendFillColor(icol); //Only available for ROOT version >= 5.30
    //For ROOR version < 5.30
    //TStyle has no global setting for Lengend FillColor 
    //Set the FillColor for the Legend to White whenever you create it. legend->SetFillColor(0)

    //dont put a colored frame around the plots
    m_dybStyle->SetFrameBorderMode(0);
    m_dybStyle->SetCanvasBorderMode(0);
    m_dybStyle->SetPadBorderMode(0);
    m_dybStyle->SetLegendBorderSize(0);

    //use the primary color palette
    m_dybStyle->SetPalette(1);

    //set the default line color for a histogram to be black
    m_dybStyle->SetHistLineColor(kBlack);

    //set the default line color for a fit function to be blue
    m_dybStyle->SetFuncColor(kBlue);

    //make the axis labels black
    m_dybStyle->SetLabelColor(kBlack,"xyz");

    //set the default title color to be black
    m_dybStyle->SetTitleColor(kBlack);
     
    //set the margins, give some additional space on the Left/Bottom where axis labels go
    m_dybStyle->SetPadTopMargin(0.05);
    m_dybStyle->SetPadBottomMargin(0.12);
    m_dybStyle->SetPadRightMargin(0.05); //set larger for Draw("colz")
    m_dybStyle->SetPadLeftMargin(0.13);

    //set axis label and title text sizes
    Int_t font=132; //bold (4), high precision (2), root default 62
    Double_t tsize=0.05; //should be set between 0.04-0.06, is in units of "% of pad"
    m_dybStyle->SetLabelFont(font,"xyz"); 
    m_dybStyle->SetLabelSize(tsize,"xyz");
    m_dybStyle->SetLabelOffset(0.01,"xyz");
    m_dybStyle->SetTitleFont(font,"xyz");
    m_dybStyle->SetTitleSize(tsize,"xyz");
    //offset the title of y and z axis a bit. The optimal tile offset relies on the number of label digits.
    //The default 1.1 is proper for 3 or 4 digits.
    m_dybStyle->SetTitleOffset(1.1,"yz"); 
    m_dybStyle->SetTitleOffset(1.0,"x");
    m_dybStyle->SetTitleBorderSize(0);
    m_dybStyle->SetStatFont(font);
    m_dybStyle->SetStatFontSize(tsize);
    m_dybStyle->SetStatBorderSize(1);
    m_dybStyle->SetStatX(0.98);
    m_dybStyle->SetStatY(0.98);
    m_dybStyle->SetTextFont(font);

    //set line widths
    m_dybStyle->SetFuncWidth(2);
    m_dybStyle->SetHistLineWidth(2);

    //turn off xy grids
    m_dybStyle->SetPadGridX(0);
    m_dybStyle->SetPadGridY(0);

    //set the tick marks on top and right of plots 
    //m_dybStyle->SetPadTickX(1);
    //m_dybStyle->SetPadTickY(1);
    // tick marks only on left and bottom
    m_dybStyle->SetPadTickX(0);
    m_dybStyle->SetPadTickY(0);

    m_dybStyle->SetOptTitle(0); //no tile shown
    //m_dybStyle->SetOptStat(111); //standard stat info
    m_dybStyle->SetOptStat(0); //number of entries only
    m_dybStyle->SetOptFit(1111);  //standard fit info
    //m_dybStyle->SetOptFit(0);       //no fit info

    //marker settings
    m_dybStyle->SetMarkerStyle(20);
    m_dybStyle->SetMarkerSize(0.8);
    m_dybStyle->SetLineWidth(2); 

    m_dybStyle->SetEndErrorSize(0); //no error caps
  }
  return m_dybStyle;
}

void DybStyle::set()
{
  DybStyle::get()->cd();
  gROOT->ForceStyle();
}

