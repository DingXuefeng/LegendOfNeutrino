#include "Plot.h"
#include "Converter.h"
#include "DybStyle.h"
#include <TCanvas.h>
#include <TLegend.h>
#include <TFile.h>
#include <TH1.h>
#include <iostream>
#include <vector>
#include <cassert>
void Plot::draw(const std::string& optionFileName)
{
  optionFileManager.setOptionFileName(optionFileName);
  readOption();
  show();
  DybStyle::set();
  TCanvas* canvas = new TCanvas(pngName,pngName,800,600);
  canvas->SetLeftMargin(leftMargin);
  canvas->SetRightMargin(rightMargin);
  canvas->SetTopMargin(topMargin);
  canvas->SetBottomMargin(bottomMargin);
  TLegend *leg = new TLegend(legendLBx,legendLBy,legendRTx,legendRTy,NULL,"brNDC");
  for(std::vector<singleJob>::const_iterator inputListit = inputList.begin();
      inputListit != inputList.end(); inputListit++)
  {
    TFile* f = new TFile(inputListit->inputFileName);
    TH1* h=(TH1*)(f->Get(inputListit->histogramName));
    assert(h!=NULL);
    h->SetDirectory(0);
    f->Close();
    delete f;
    //h->Scale(1/(h->GetBinContent(h->FindBin(scaleBinx))));
    //h->Scale(scale);
    if(inputListit == inputList.begin())
    {
      h->GetYaxis()->SetRangeUser(rangeLow,rangeUp);
      h->GetXaxis()->SetTitle(xTitle);
      h->GetXaxis()->CenterTitle(true);
      h->GetYaxis()->SetTitle("Enrgy [MeV]");
      h->GetYaxis()->CenterTitle(true);
      h->Draw("e");
    }
    else
      h->Draw("esame");
    h->SetLineColor(inputListit->lineColor);
    h->SetLineStyle(inputListit->lineStyle);
    h->SetMarkerColor(inputListit->lineColor);
    h->SetMarkerStyle(inputListit->markerStyle);
    leg->AddEntry(h,inputListit->legend,"lp");
  }
  leg->Draw();
  leg->SetFillStyle(0);
  canvas->Modified();
  canvas->cd();
  canvas->Print(pngName);
}

void Plot::readOption() 
{
  drawType = optionFileManager.getOption("DrawType");
  optionFileManager.getOptionList<Plot::singleJob>("InputList",inputList);
  //scaleBinx = optionFileManager.getIntOption("ScaleBinx");
  rangeLow = optionFileManager.getDoubleOption("RangeLow");
  rangeUp = optionFileManager.getDoubleOption("RangeUp");
  xTitle = optionFileManager.getOption("Xtitle");
  yTitle = optionFileManager.getOption("Ytitle");
  legendLBx = optionFileManager.getDoubleOption("LegendLBx");
  legendLBy = optionFileManager.getDoubleOption("LegendLBy");
  legendRTx = optionFileManager.getDoubleOption("LegendRTx");
  legendRTy = optionFileManager.getDoubleOption("LegendRTy");
  leftMargin = optionFileManager.getDoubleOption("LeftMargin");
  rightMargin = optionFileManager.getDoubleOption("RightMargin");
  topMargin = optionFileManager.getDoubleOption("TopMargin");
  bottomMargin = optionFileManager.getDoubleOption("BottomMargin");
  pngName = optionFileManager.getOption("PNGname");
}

void Plot::show() const
{
  TString info;
  std::cout<<"drawType: "<<drawType<<std::endl;
  for(std::vector<singleJob>::const_iterator inputListit = inputList.begin();
      inputListit != inputList.end(); inputListit++)
    std::cout<<(*inputListit)<<std::endl;
  info += "scaleBinx: ";
  info += Converter::doubleToString(scaleBinx);
  info += "\nrangeLow: ";
  info += Converter::doubleToString(rangeLow);
  info += "\nrangeUp: ";
  info += Converter::doubleToString(rangeUp);
  info += "\nxTitle: ";
  info += xTitle;
  info += "\nyTitle: ";
  info += yTitle;
  info += "\n(legendLBx,legendLBy,legendRTx,legendRTy): (";
  info += Converter::doubleToString(legendLBx);
  info += ",";
  info += Converter::doubleToString(legendLBy);
  info += ",";
  info += Converter::doubleToString(legendRTx);
  info += ",";
  info += Converter::doubleToString(legendRTy);
  info += ")\n(leftMargin,rightMargin,topMargin,bottomMargin): (";
  info += Converter::doubleToString(leftMargin);
  info += ",";
  info += Converter::doubleToString(rightMargin);
  info += ",";
  info += Converter::doubleToString(topMargin);
  info += ",";
  info += Converter::doubleToString(bottomMargin);
  info += ")\n pngName: ";
  info += pngName;
  std::cout<<info<<std::endl;


}

void Plot::help()
{
  TString helpinfo;
  helpinfo += "[Plot::help]\n";
  helpinfo += "The format for optionfile should be <Key> <Value>. eg:\n";
  helpinfo += "DrawType HistogramWithNamedBins\n";
  helpinfo += "In your option file, you should give:\n";;
  helpinfo += "1) draw type [key]: DrawType\n";;
  helpinfo += "[Value]: HistogramWithNamedBins it will draw a histogram with named bins\n";
  helpinfo += "[Value]: Histogram it will draw a histogram\n";
  helpinfo += "[Value]: HistogramsMapType it will draw several histograms mapped to different types.\n";
  helpinfo += "2) input list [key]: InputList\n";
  helpinfo += "example:\n";
  helpinfo += "InputList begin\n";
  helpinfo += "test1.root totalPE23 1 1 1 Tyvek 1.0m\n";
  helpinfo += "test12.root totalPE213 2 2 2 Tyvek 2.0m\n";
  helpinfo += "test2.root totalPE21 3 3 3 None\n";
  helpinfo += "InputList end\n";
  helpinfo += "totalPE23 is the name of histograms\n";
  helpinfo += "here 1 1 1 represent LineColor, LineStyle, MarkerStyle. MarkerColor are the same with LineColor.\n";
  helpinfo += "3) x title [key]: Xtitle\n";
  helpinfo += "example:\n";
  helpinfo += "Xtitle #frac{s [m]}{v [m/s]";
  helpinfo += "4) y title [key]: Ytitle\n";
  //helpinfo += "5) scalebinx [key]: ScaleBinx\n";
  helpinfo += "6) Legend corner x of left bottom [key]: LegendLBx\n";
  helpinfo += "7) Legend corner y of left bottom [key]: LegendLBy\n";
  helpinfo += "8) Legend corner x of right top [key]: LegendRTx\n";
  helpinfo += "9) Legend corner y of right top [key]: LegendRTy\n";
  helpinfo += "10) left canvas margin [key]: LeftMargin\n";
  helpinfo += "11) right canvas margin [key]: RightMargin\n";
  helpinfo += "12) top canvas margin [key]: TopMargin\n";
  helpinfo += "13) bottom canvas margin [key]: BottomMargin\n";
  helpinfo += "14) generated png name [key]: PNGname\n";
  helpinfo += "15) rangeLow [key]: RangeLow\n";
  helpinfo += "16) rangeUp [key]: RangeUp\n";
  std::cout<<helpinfo<<std::endl;
}

int main(int argc,char* argv[])
{
  if(argc==1)
    Plot::help();
  else
  {
    Plot plot;
    plot.draw(argv[1]);
  }
  return 0;
}
