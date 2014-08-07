#include "OptionFileManager.h"
#include <TFile.h>
#include <TTree.h>
#include <iostream>
#include <string>
#include <vector>
class DemoClass
{
  public:
    DemoClass(std::string nameV):name(nameV){};
    std::string name;
};
void show(std::vector<DemoClass> V)
{
  for(unsigned int i = 0;i<V.size();i++)
    std::cout<<"["<<i<<"] "<<V[i].name<<std::endl;
}
int main()
{
  OptionFileManager* optionFileManager = new OptionFileManager;
  optionFileManager->setOptionFileName("u_1e6_pmt_Det2_quench_splittedFirst_1.3m.txt");
  std::cout<<optionFileManager->getOption("JobName")<<std::endl;
  std::cout<<optionFileManager->getJobName()<<std::endl;
  std::cout<<optionFileManager->getOption("InputFileDirectory")<<std::endl;
  std::cout<<optionFileManager->getInputFileDirectory()<<std::endl;
  std::cout<<optionFileManager->getOption("InputFileNamePrefix")<<std::endl;
  std::cout<<optionFileManager->getOption("FileNumbers")<<std::endl;
  std::cout<<optionFileManager->getDoubleOption("ScaleFactor")<<std::endl;
  std::cout<<optionFileManager->getOption("ScaleFactor")<<std::endl;
  std::cout<<optionFileManager->getOptionFileName()<<std::endl;

  // usage of getOptionList
  std::vector<DemoClass> Vdemo1;
  std::vector<DemoClass> Vdemo2;
  optionFileManager->getOptionList<DemoClass>("Name",Vdemo1);
  optionFileManager->getOptionList<DemoClass>("SName",Vdemo2,3);

  show(Vdemo1);
  show(Vdemo2);
  return 0;
}
