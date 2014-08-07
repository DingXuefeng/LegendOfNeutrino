#include "TTreeAnalyzer.h"
#include "TimeWatcher.h"
#include "TestTool.h"
#include <TFile.h>
#include <TTree.h>
#include <TH1.h>
#include <TChain.h>
#include <iostream>
int main()
{
  TimeWatcher::startWatch();
  TimeWatcher::report(std::cout,__PRETTY_FUNCTION__,__LINE__);
  std::cout<<"Testing TTreeAnalyzer::getAccumulatedDistribution(TH1*).."<<std::endl;
  TH1* testHistogram = TestTool::getTestTH1();
  TestTool::testTH1(std::cout,testHistogram,1);
  TimeWatcher::report(std::cout,__PRETTY_FUNCTION__,__LINE__);
  TH1* accumulatedHistogram;
  accumulatedHistogram = TTreeAnalyzer::getAccumulatedDistribution(testHistogram);
  TestTool::testTH1(std::cout,accumulatedHistogram,1);
  TimeWatcher::report(std::cout,__PRETTY_FUNCTION__,__LINE__);
  std::cout<<"Testing TTreeAnalyzer::getDistribution(TTree*,std::string,TCut).."
    <<std::endl;
  TFile testFile("/publicfs/dyb/data/userdata/dingxf/JUNO/PMTradioactivity/Det2/u_1e6_pmt_Det2_quench_splittedFirst_1.3m/u_100000_0.root");
  TTree* tree = (TTree*)(testFile.Get("evt"));
  TestTool::testTTree(std::cout,tree,1);
  TimeWatcher::report(std::cout,__PRETTY_FUNCTION__,__LINE__);
  TestTool::testTH1(std::cout,TTreeAnalyzer::getDistribution(tree,"totalPE","edep_pos_z>0"));
  TimeWatcher::report(std::cout,__PRETTY_FUNCTION__,__LINE__);
  TestTool::testTH1(std::cout,TTreeAnalyzer::getDistribution(tree,"totalPE","edep_pos_z>0","(1000,0,1000)"));
  TimeWatcher::report(std::cout,__PRETTY_FUNCTION__,__LINE__);
  std::cout<<"Testing TTreeAnalyzer::getAccumulatedDistribution(TTree*,std::string,TCut).."
    <<std::endl;
  TimeWatcher::report(std::cout,__PRETTY_FUNCTION__,__LINE__);
  TestTool::testTH1(std::cout,TTreeAnalyzer::getAccumulatedDistribution(tree,"totalPE","edep_pos_z>0"));
  TimeWatcher::report(std::cout,__PRETTY_FUNCTION__,__LINE__);
  TestTool::testTH1(std::cout,TTreeAnalyzer::getAccumulatedDistribution(tree,"totalPE","edep_pos_z>0","(100,0,100)"));
  TimeWatcher::report(std::cout,__PRETTY_FUNCTION__,__LINE__);
  TestTool::testTH1(std::cout,TTreeAnalyzer::getAccumulatedDistribution(tree,
	"sqrt(edep_pos_x^2+edep_pos_y^2+edep_pos_z^2)",
	"quenchededep_total>0.7","","new"),1);
  TimeWatcher::report(std::cout,__PRETTY_FUNCTION__,__LINE__);
  TestTool::testTH1(std::cout,TTreeAnalyzer::getRelation(tree,"totalPE","sqrt(edep_pos_x^2+edep_pos_y^2+edep_pos_z^2)","edep_pos_z>0"),1);
  TimeWatcher::report(std::cout,__PRETTY_FUNCTION__,__LINE__);
  TestTool::testTTree(std::cout,TTreeAnalyzer::getTTree("/publicfs/dyb/data/userdata/dingxf/JUNO/PMTradioactivity/Det2/u_1e6_pmt_Det2_quench_splittedFirst_1.3m","evt",10),1);
  TimeWatcher::report(std::cout,__PRETTY_FUNCTION__,__LINE__);
  return 0;
}
