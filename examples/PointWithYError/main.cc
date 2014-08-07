#include "PointWithYError.h"
#include "DybStyle.h"
#include <TCanvas.h>
#include <TH1F.h>
#include <TLegend.h>
#include <iostream>
int main()
{
  PointWithYError point1(0.7,0.032,0.000037);
  point1.setType("U238");
  point1.show(std::cout);
  point1.toPercent();
  point1.show(std::cout);
  PointWithYError point2("Th232",0.7,0.032,0.000037);
  point2.show(std::cout);
  PointWithYError point[3] = 
  {PointWithYError("U(ppb)",34.91,1.3),PointWithYError("Th(ppb)",85.12,7.6),PointWithYError("K(ppm)",22.45,0.9)};
  DybStyle::set();
  TCanvas* c =new TCanvas;
  c->SetGridx();
  c->SetGridy();
  TH1F* h = new TH1F("newPMT","Glass used by new PMT(x0.1)",3,0,3);
  for(int i = 0;i<3;i++)
    h->Fill(point[i].type.c_str(),point[i].y);
  h->Draw("e");
  h->GetYaxis()->SetTitle("PMT radioactivity");
  h->GetYaxis()->SetTitleOffset(1.3);
  h->GetYaxis()->SetLabelOffset(0.02);
  h->GetYaxis()->SetLabelSize(0.05);
  h->GetYaxis()->SetTitleSize(0.05);
  h->GetYaxis()->SetTitleOffset(1.16);
  h->GetYaxis()->CenterTitle(true);
  h->GetXaxis()->SetLabelSize(0.08);
  TLegend *leg = new TLegend(0.2112069,0.5233051,0.5301724,0.75,NULL,"brNDC");
  leg->SetTextSize(0.04237288);
  leg->AddEntry(h,"Glass used by new PMT now(x0.1)","lp");
  leg->Draw();
  leg->SetFillColor(0);
  leg->SetFillStyle(0);
  c->Print("stringHistograms.png");
  return 0;
}
