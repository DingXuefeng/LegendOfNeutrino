#include "TTreeAnalyzer.h"
#include <TH1.h>
#include <TH2.h>
#include <TH1F.h>
#include <TProfile.h>
#include <TROOT.h>
#include <TCut.h>
#include <TTree.h>
#include <TChain.h>
#include <TSystem.h>
#include <TString.h>
#include <string>
#include <iostream>
#include <sstream>
#include <ctime>
#include <iostream>
#include <stdexcept>
#include <cassert>
TTree* TTreeAnalyzer::getTTree(TString directoryName,TString treeName,int numberCheck)
{
  std::cerr<<"[TTreeAnalyzer::getTTree]\n"
    <<"Warning: I have add all the files in ["<<directoryName<<"]\n"
    <<"Check them below:"<<std::endl;
  TChain* tree = new TChain(treeName);
  void *dirp = gSystem->OpenDirectory(directoryName);
  int fileNumbers(0);
  try
  {
    if (!dirp) throw std::runtime_error("No such directory.");
    char *direntry;
    Long_t id, size,flags,modtime;
    //loop on all entries of this directory
    while ((direntry=(char*)(gSystem->GetDirEntry(dirp)))) 
    {
      TString afile = Form("%s/%s",(const char*)(directoryName),direntry);
      gSystem->GetPathInfo(afile,&id,&size,&flags,&modtime);
      if (strstr(direntry,".root"))
      {
	tree->Add(afile);
	std::cerr<<"[INFO] add file["<<afile<<"]"<<std::endl;
	fileNumbers++;
      }
    }
    gSystem->FreeDirectory(dirp);
  }
  catch(const std::runtime_error& err)
  {
    std::cerr<<"[TTreeAnalyzer::getTTree]\n"
      <<"Cannot find the directory["<<directoryName<<"]."<<std::endl;
    gSystem->FreeDirectory(dirp);
    throw err;
  }
  assert(tree->GetEntries()!=0);
  assert((fileNumbers==numberCheck)||(numberCheck==-1));
  return tree;
}

TH1* TTreeAnalyzer::getAccumulatedDistribution(TTree* tree,std::string variable,TCut cut,std::string fixBin,std::string name)
{
  if(!tree)
  {
    std::cout<<"empty tree!"<<std::endl;
    return NULL;
  }
  return getAccumulatedDistribution(getDistribution(tree,variable,cut,fixBin,name));
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

TH1* TTreeAnalyzer::getDistribution(TTree* tree,std::string variable,TCut cut,std::string fixBin,std::string name)
{
  if(!tree)
  {
    std::cout<<"empty tree!"<<std::endl;
    return NULL;
  }
  std::stringstream hash;
  hash<<"_"<<clock();
  name += hash.str();
  //tree->Draw((variable+">>"+name+"_distribution(1000,0,1000)").c_str(),cut);
  tree->Draw((variable+">>"+name+"_distribution"+fixBin).c_str(),cut);
  std::cout<<(variable+">>"+name+"_distribution"+fixBin)<<std::endl;
  TH1F* h1=(TH1F*)gDirectory->Get((name+"_distribution").c_str());
  h1->SetDirectory(0);
  return h1;
}

TH1* TTreeAnalyzer::getRelation(TTree* tree,std::string variable,std::string variable2,TCut cut,std::string name)
{
  TH1* tmp = ((TH2*)(getDistribution(tree,"("+variable+"):("+variable2+")",cut,"",name)))->ProfileX();
  //return tmp;
  Double_t* bins = new Double_t[tmp->GetNbinsX()+1];
  for(int i=0;i<tmp->GetNbinsX();i++)
    bins[i]=tmp->GetBinLowEdge(i+1);
  bins[tmp->GetNbinsX()]=tmp->GetBinLowEdge(tmp->GetNbinsX())+tmp->GetBinWidth(tmp->GetNbinsX());
  TH1* tmp2 = new TH1F((std::string(tmp->GetName())+"_TH1").c_str(),tmp->GetTitle(),tmp->GetNbinsX(),bins);
  for(int i = 0;i<tmp->GetNbinsX();i++)
  {
    tmp2->SetBinContent(i,tmp->GetBinContent(i));
    tmp2->SetBinError(i,tmp->GetBinError(i));
  }
  return tmp2;
}
