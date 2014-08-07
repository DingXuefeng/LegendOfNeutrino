#include "TestTool.h"
#include <TTree.h>
#include <TH1.h>
#include <TH1F.h>
#include <TH2.h>
#include <TH2F.h>
#include <TF2.h>
#include <TBranch.h>
#include <iostream>
void TestTool::testTTree(std::ostream& test,TTree* tree,int level)
{
  if(!tree)
  {
    test<<"tested tree does not exist!"<<std::endl;
    return;
  }
  test<<"TTree name ["<<(tree->GetName())<<"]\n"<<
    "Entries: "<<(tree->GetEntries())<<std::endl;
  if(level==0)
    test<<"Frist branch name ["<<
      std::string(((TBranch*)(tree->GetListOfBranches()->First()))->GetName())
      <<"]"<<std::endl;
  else
  {
    TIter next(tree->GetListOfBranches());
    TBranch* branch;
    while((branch = (TBranch*)(next())))
      test<<"["<<
	std::string(branch->GetName())
	<<"]"<<std::endl;
  }
}

void TestTool::testTH1(std::ostream& test,TH1* h,int level)
{
  if(!h)
  {
    test<<"tested histogram does not exist!"<<std::endl;
    return;
  }
  test<<"TH1 name ["<<(h->GetName())<<"] "<<
    "Mean(RMS): "<<(h->GetMean())<<"("<<(h->GetRMS())<<")"<<std::endl;
  if(level>0)
    for(int bin = 0;bin<=h->GetNbinsX()+1;bin++)
      test<<"["<<bin<<"] "<<h->GetBinContent(bin)<<std::endl;
}

double TestTool::watchTH1(TH1* h,double x)
{
  return h->GetBinContent(h->FindBin(x));
}

void TestTool::watchTH1(std::ostream& test,TH1* h,double x)
{
  test<<watchTH1(h,x)<<std::endl;
}

TH1* TestTool::getTestTH1()
{
  TH1F* testHistogram = new TH1F("testTH1","test histogram",5,0.5,5.5);
  testHistogram->Fill(0.1);
  testHistogram->Fill(0.1);
  testHistogram->Fill(1);
  testHistogram->Fill(1);
  testHistogram->Fill(1);
  testHistogram->Fill(3);
  testHistogram->Fill(4);
  testHistogram->Fill(4);
  return testHistogram;
}

void TestTool::testTH2(std::ostream& test,TH2* h,int level)
{
  if(!h)
  {
    test<<"tested histogram does not exist!"<<std::endl;
    return;
  }
  test<<"TH2 name ["<<(h->GetName())<<"] "<<
    "CorrelationFactor(Covariance): "<<
      h->GetCorrelationFactor()<<"("<<h->GetCovariance()<<")"<<std::endl;;
}

TH2* TestTool::getTestTH2()
{
  TH2F* testHistogram = new TH2F("testTH2","test histogram",100,-10,10,100,-10,10);
  TF2* f2 = new TF2("f2","sin(1/(x^2+y^2))*(x^2+y^2)",-10,10,-10,10);
  testHistogram->FillRandom("f2",100000);
  delete f2;
  return testHistogram;
}
