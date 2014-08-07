/*****************************************************************
 * The option file manager class
 * Author: Ding Xuefeng dingxf@ihep.ac.cn
 * History:
 *   2013.08.22 ver 1.1
 *   2013.08.27 ver 1.2 
 *    Tiny modification and move it into LengendOfNeutrino library
 *****************************************************************/
#ifndef OptionFileManager_H
#define OptionFileManager_H
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
class OptionFileManager
{
  public:
    void setOptionFileName(std::string);
    std::string getOptionFileName() const;

    // look up "option" in the option file
    std::string getOption(std::string option) const;

    // look up "option" in the option file, return a double
    double getDoubleOption(std::string option) const;

    // look up "option" in the option file, return a int
    int getIntOption(std::string option) const;

    // it will look up for a list of something.
    // the list begins with 
    // <option> begin
    // end with 
    // <option> end
    template<typename T>
    const std::vector<T>& getOptionList(std::string option,std::vector<T>& inputList,int num=-1) const;

    // Caution: these two are to be deprecated
    // JobName
    std::string getJobName() const;
    // InputFileDirectory
    std::string getInputFileDirectory() const;

  private:
    // It will return "Not found" if it cannot find option.
    std::string _getOption(std::string option) const;

  private:
    std::string m_optionFileName;
};

template<typename T>
const std::vector<T>& OptionFileManager::getOptionList(std::string option,std::vector<T>& inputList,int num) const
{
  if(num==-1) 
    num = getIntOption(option+"_num");
  const int originNum(num);
  std::ifstream inputfile;
  if(m_optionFileName.size()==0)
  {
    std::cerr<<"[OptionFileManager::_getOptions(\""<<option<<"\","<<num<<")]"<<std::endl;
    std::cerr<<"Fatal! call getOptions before setting option file!"<<std::endl;
    throw -1;
  }
  inputfile.open(m_optionFileName.c_str());
  if(!inputfile.is_open())
  {
    std::cerr<<"[OptionFileManager::_getOptions(\""<<option<<"\","<<num<<")]"<<std::endl;
    std::cerr<<"Error! Option file ["<<m_optionFileName<<"] not found."<<std::endl;
    throw -1;
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
    std::string optionType;
    lines>>optionType;
    if(optionType.compare(option)==0)
    {
      num--;
      lines.ignore(256,' ');
      char optionContent[256];
      lines.get(optionContent,256);
      inputList.push_back(T(optionContent));
      if(num==0)
	break;
    }
  }
  inputfile.close();
  if(num==originNum)
  {
    std::cout<<"Warning! ["<<option<<"] not found in ["<<m_optionFileName<<"]."<<std::endl;
    inputList.push_back(T("Not found"));
    return inputList;
  }
  else if(num>0)
  {
    std::cout<<"Warning! only "<<originNum-num<<"["<<option<<"] are found in ["<<m_optionFileName<<"]."<<std::endl;
    return inputList;
  }
  return inputList;
}

#endif
