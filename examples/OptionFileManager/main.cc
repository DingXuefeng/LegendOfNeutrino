#include "OptionFileManager.h"
#include <TFile.h>
#include <TTree.h>
#include <iostream>
int main()
{
  OptionFileManager* optionFileManager = new OptionFileManager;
  optionFileManager->setOptionFileName("/workfs/dyw/dingxf/JUNO/PMTradioactivity/plot/share/u_1e6_pmt_Det2_quench_splittedFirst_1.3m.txt");
  std::cout<<optionFileManager->getOption("JobName")<<std::endl;
  std::cout<<optionFileManager->getJobName()<<std::endl;
  std::cout<<optionFileManager->getOption("InputFileDirectory")<<std::endl;
  std::cout<<optionFileManager->getInputFileDirectory()<<std::endl;
  std::cout<<optionFileManager->getOption("InputFileNamePrefix")<<std::endl;
  std::cout<<optionFileManager->getOption("FileNumbers")<<std::endl;
  std::cout<<optionFileManager->getDoubleOption("ScaleFactor")<<std::endl;
  std::cout<<optionFileManager->getOption("ScaleFactor")<<std::endl;
  return 0;
}
