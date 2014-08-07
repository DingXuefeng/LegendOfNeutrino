#include "OptionFileManager.h"
#include "Converter.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
void OptionFileManager::setOptionFileName(std::string optionFileName)
{
  m_optionFileName=optionFileName;
}

std::string OptionFileManager::getOptionFileName() const
{
  return m_optionFileName;
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
  return Converter::stringToDouble(_getOption(option));
}

int OptionFileManager::getIntOption(std::string option) const
{
  return Converter::stringToInt(_getOption(option));
}

std::string OptionFileManager::_getOption(std::string option) const
{
  std::vector<std::string> tmp;
  return getOptionList<std::string>(option,tmp,1).front();
  //return tmp.front();
}
