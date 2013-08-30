#include "DybStyle.h"
#include <TCanvas.h>
#include <TH1F.h>
#include <TF1.h>
#include <iostream>
int main()
{
  std::cout<<"Testing DybStyle..."<<std::endl;
  TCanvas c("c","canvas",800,600);
  TH1F* h = new TH1F("h","my histogram",5,-10,10);
  TF1* ff = new TF1("ff","gaus(0)+gaus(3)",-5,5);
  ff->SetParameters(1,2,0.6,4,0.7);
  h->FillRandom("ff",10000);
  h->Draw();
  c.Print("pic1.png");
  DybStyle::set();
  h->Draw();
  c.Print("pic2.png");
  return 0;
}
