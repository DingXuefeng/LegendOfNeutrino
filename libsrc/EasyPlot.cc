#include "EasyPlot.h"
#include "PointWithYError.h"
#include "DybStyle.h"
#include <TCanvas.h>
#include <TH1.h>
#include <TLegend.h>
#include <map>
#include <vector>
#include <string>
TCanvas* EasyPlot::drawHistogramsMapType(std::map<std::string,TH1*>* hMapType,std::string canvasName,std::string Xtitle,std::string Ytitle,double bottomleft_x,double bottomleft_y,double topright_x,double topright_y,bool whetherLogy)
{
  TCanvas* canvas = new TCanvas(canvasName.c_str(),canvasName.c_str(),800,600);
  if(whetherLogy)
    canvas->SetLogy();
  std::map<std::string,TH1*>::iterator hMapTypeit = hMapType->begin();
  hMapTypeit->second->Draw("e");
  hMapTypeit->second->GetXaxis()->SetTitle(Xtitle.c_str());
  hMapTypeit->second->GetXaxis()->SetTitleOffset(1.1);
  hMapTypeit->second->GetXaxis()->CenterTitle(true);
  //hMapTypeit->second->GetYaxis()->SetRangeUser(getHistogramsMapYMin<std::string>(hMapType)*0.9,getHistogramsMapYMax<std::string>(hMapType)*1.1);
  // don't set y minimum if you want logy
  if(!whetherLogy)
    hMapTypeit->second->SetMinimum(getHistogramsMapYMin<std::string>(hMapType)*0.9);
  hMapTypeit->second->SetMaximum(getHistogramsMapYMax<std::string>(hMapType)*1.1);
  hMapTypeit->second->GetYaxis()->SetTitle(Ytitle.c_str());
  hMapTypeit->second->GetYaxis()->SetTitleOffset(1.2);
  hMapTypeit->second->GetYaxis()->CenterTitle(true);
  hMapTypeit->second->SetLineWidth(2);
  int style(1);
  hMapTypeit->second->SetLineColor(1);
  hMapTypeit->second->SetLineStyle(1);
  hMapTypeit->second->SetMarkerStyle(20);
  hMapTypeit->second->SetMarkerColor(1);
  while((++hMapTypeit)!=hMapType->end())
  {
    hMapTypeit->second->Draw("esame");
    hMapTypeit->second->SetLineWidth(2);
    hMapTypeit->second->SetLineColor(style);
    hMapTypeit->second->SetLineStyle(style);
    hMapTypeit->second->SetMarkerStyle(20);
    hMapTypeit->second->SetMarkerColor(style);
    style++;
  }
  TLegend *leg = new TLegend(bottomleft_x,bottomleft_y,topright_x,topright_y,NULL,"brNDC");
  for(std::map<std::string,TH1*>::iterator hMapTypeit = hMapType->begin();
      hMapTypeit != hMapType->end(); hMapTypeit++)
    leg->AddEntry(hMapTypeit->second,hMapTypeit->second->GetTitle(),"lp");
  leg->Draw();
  leg->SetFillStyle(0);
  canvas->Print((canvasName+".png").c_str());
  canvas->Modified();
  canvas->cd();
  return canvas;
};

TCanvas* EasyPlot::drawHistogramWithNamedBinsFromNamedItemVector(std::vector<PointWithYError>* pointVector,std::string canvasName,std::string Xtitle,std::string Ytitle,bool whetherLogy)
{
  return drawHistogramWithNamedBins(fromPointVectorToTH1(pointVector),canvasName,Xtitle,Ytitle,whetherLogy);
};
TCanvas* EasyPlot::drawHistogramWithNamedBins(TH1* h,std::string canvasName,std::string Xtitle,std::string Ytitle,bool whetherLogy)
{
  DybStyle::set();
  TCanvas* canvas = new TCanvas(canvasName.c_str(),canvasName.c_str(),800,600);
  if(whetherLogy)
    canvas->SetLogy();
  h->Draw("e");
  h->SetLineWidth(2);
  h->SetLineColor(kBlack);
  h->SetMarkerStyle(20);
  h->SetMarkerColor(kBlack);
  h->GetXaxis()->SetLabelSize(0.07);
  h->GetXaxis()->SetTitle(Xtitle.c_str());
  h->GetXaxis()->CenterTitle(true);
  h->GetYaxis()->SetLabelOffset(0.02);
  h->GetYaxis()->SetLabelSize(0.05);
  h->GetYaxis()->SetTitle(Ytitle.c_str());
  h->GetYaxis()->CenterTitle(true);
  canvas->Print((canvasName+".png").c_str());
  return canvas;
}

TH1* EasyPlot::fromPointVectorToTH1(std::vector<PointWithYError>* pointVector,std::string histogramName,std::string histogramTitle)
{
  TH1F* h = new TH1F(histogramName.c_str(),histogramTitle.c_str(),pointVector->size(),0,pointVector->size());
  unsigned int bins(1);
  for(std::vector<PointWithYError>::iterator pointVectorit = pointVector->begin();
      pointVectorit != pointVector->end(); pointVectorit++)
  {
    h->Fill(pointVectorit->type.c_str(),pointVectorit->y);
    h->SetBinError(bins++,pointVectorit->yerr);
  }
  return h;
}

