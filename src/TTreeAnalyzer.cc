#include "TTreeAnalyzer.h"
#include "TH1.h"
#include "TH1F.h"
#include <TROOT.h>
#include <TCut.h>
#include <TTree.h>
#include <string>
#include <iostream>
#include <sstream>
#include <ctime>
TH1* TTreeAnalyzer::getAccumulatedDistribution(TTree* tree,std::string variable,TCut cut,std::string name)
{
  if(!tree)
  {
    std::cout<<"empty tree!"<<std::endl;
    return NULL;
  }
  return getAccumulatedDistribution(getDistribution(tree,variable,cut,name));
}

TH1* TTreeAnalyzer::getAccumulatedDistribution(TH1* distribution)
{
  if(!distribution)
  {
    std::cout<<"empty histogram!"<<std::endl;
    return NULL;
  }
  TH1F* accumulatedDistribution = new TH1F(
      (distribution->GetName()+std::string("_accumulated")).c_str(),
      (distribution->GetName()+std::string("_accumulated")).c_str(),
      distribution->GetNbinsX(),
      distribution->GetXaxis()->GetBinLowEdge(1),
      distribution->GetXaxis()->GetBinLowEdge(
	distribution->GetNbinsX()));
  double eventNumber(0);
  for(int bin = distribution->GetNbinsX()+1;bin>0;bin--)
  {
    eventNumber+=distribution->GetBinContent(bin);
    accumulatedDistribution->SetBinContent(bin,eventNumber);
  }
  return accumulatedDistribution;
}

TH1* TTreeAnalyzer::getDistribution(TTree* tree,std::string variable,TCut cut,std::string name)
{
  if(!tree)
  {
    std::cout<<"empty tree!"<<std::endl;
    return NULL;
  }
  std::stringstream hash;
  hash<<"_"<<clock();
  name += hash.str();
  tree->Draw((variable+">>"+name+"_distribution(1000,0,1000)").c_str(),cut);
  TH1F* h1=(TH1F*)gDirectory->Get((name+"_distribution").c_str());
  return h1;
}
