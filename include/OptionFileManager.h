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
class OptionFileManager
{
  public:
    void setOptionFileName(std::string);

    // look up "option" in the option file
    std::string getOption(std::string option) const;

    // look up "option" in the option file, return a double
    double getDoubleOption(std::string option) const;

    // look up "option" in the option file, return a int
    int getIntOption(std::string option) const;

    // look up a list of "option"s in the option file
    // it will look for numbers of num before it stops
    std::vector<std::string>* getOptions(std::string option,int num=0) const;

    // look up a list of "option"s in the option file
    // it will look for numbers of num before it stops
    std::vector<int>* getIntOptions(std::string option,int num=0) const;

    // Caution: these two are to be deprecated
    // JobName
    std::string getJobName() const;
    // InputFileDirectory
    std::string getInputFileDirectory() const;

  private:
    // It will return "Not found" if it cannot find option.
    std::string _getOption(std::string option) const;

    // It will return "Not found" if it cannot find option.
    std::vector<std::string>* _getOptions(std::string option,int num=0) const;

  private:
    std::string m_optionFileName;
};
#endif
