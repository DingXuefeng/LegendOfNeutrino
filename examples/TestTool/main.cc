#include "TestTool.h"
#include <TFile.h>
#include <TTree.h>
#include <TH1.h>
#include <TChain.h>
#include <iostream>
int main()
{
  TFile testFile("/publicfs/dyb/data/userdata/dingxf/JUNO/PMTradioactivity/Det2/u_1e6_pmt_Det2_quench_splittedFirst_1.3m/u_100000_0.root");
  TTree* tree = (TTree*)(testFile.Get("evt"));
  TestTool::testTTree(std::cout,tree,1);

  TChain* chain = new TChain("evt");
  chain->Add("/publicfs/dyb/data/userdata/dingxf/JUNO/PMTradioactivity/Det2/u_1e6_pmt_Det2_quench_splittedFirst_1.3m/u_100000_0.root");
  chain->Add("/publicfs/dyb/data/userdata/dingxf/JUNO/PMTradioactivity/Det2/u_1e6_pmt_Det2_quench_splittedFirst_1.3m/u_100000_1.root");
  TestTool::testTTree(std::cout,chain);

  TH1* testHistogram = TestTool::getTestTH1();
  TestTool::testTH1(std::cout,testHistogram,1);
  TestTool::testTH2(std::cout,TestTool::getTestTH2());
  return 0;
}
