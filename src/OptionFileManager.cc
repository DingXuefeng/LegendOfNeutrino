#include "OptionFileManager.h"
#include "TFormula.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
void OptionFileManager::setOptionFileName(std::string optionFileName)
{
  m_optionFileName=optionFileName;
}

std::string OptionFileManager::getJobName() const
{
  std::cout<<"Warning: this method is to be deprecated.\n"<<
    "Please use getOption(\"JobName\")"<<std::endl;
  return _getOption("JobName");
}

std::string OptionFileManager::getInputFileDirectory() const
{
  std::cout<<"Warning: this method is to be deprecated.\n"<<
    "Please use getOption(\"InputFileDirectory\")"<<std::endl;
  return _getOption("InputFileDirectory");
}

std::string OptionFileManager::getOption(std::string option) const
{
  return _getOption(option);
}

double OptionFileManager::getDoubleOption(std::string option) const
{
  TFormula myf("myf",(_getOption(option)).c_str());
  return myf.Eval(0);
}

int OptionFileManager::getIntOption(std::string option) const
{
  TFormula myf("myf",(_getOption(option)).c_str());
  return int(myf.Eval(0));
}

std::vector<std::string>* OptionFileManager::getOptions(std::string option,int num) const
{
  return _getOptions(option,num);
}

std::vector<int>* OptionFileManager::getIntOptions(std::string option,int num) const
{
  std::vector<std::string>* options = _getOptions(option,num);
  std::vector<int>* intOptions = new std::vector<int>;
  for(std::vector<std::string>::iterator optionsit = options->begin();
      optionsit != options->end(); optionsit++)
  {
    TFormula myf("myf",(*optionsit).c_str());
    intOptions->push_back(int(myf.Eval(0)));
  }
  delete options;
  return intOptions;
}

std::string OptionFileManager::_getOption(std::string option) const
{
  return (_getOptions(option))->front();
}

std::vector<std::string>* OptionFileManager::_getOptions(std::string option,int num) const
{
  int originNum(num);
  std::vector<std::string>* options = new std::vector<std::string>;
  std::ifstream inputfile;
  inputfile.open(m_optionFileName.c_str());
  if(!inputfile.is_open())
  {
    std::cout<<"Warning! File ["<<m_optionFileName<<"] not found."<<std::endl;
    options->push_back("Not found");
    return options;
  }
  char line[200];
  while(!inputfile.eof())
  {
    //std::getline(inputfile,line);
    inputfile.getline(line,200);
    //if the line begins with # we ignore this line
    if(line[0]=='#')
      continue;
    std::stringstream lines;
    lines<<line;
    std::string optionType,optionContent;
    lines>>optionType>>optionContent;
    if(optionType.compare(option)==0)
    {
      num--;
      options->push_back(optionContent);
      if(num==0)
	break;
    }
  }
  inputfile.close();
  if(num==originNum)
  {
    std::cout<<"Warning! ["<<option<<"] not found in ["<<m_optionFileName<<"]."<<std::endl;
    options->push_back("Not found");
    return options;
  }
  else if(num>0)
  {
    std::cout<<"Warning! only "<<originNum-num<<"["<<option<<"] are found in ["<<m_optionFileName<<"]."<<std::endl;
    return options;
  }
  return options;
}

