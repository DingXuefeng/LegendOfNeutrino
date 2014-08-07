/******************************************
 * class that provide with input file names
 * Author: Ding Xuefeng dingxf@ihep.ac.cn
 * History:
 *   2013.08.27 ver 1.0
 *****************************************/
#define IinputFileNamesProvider_H
#ifndef IinputFileNamesProvider_H
#define IinputFileNamesProvider_H
#include <vector>
#include <string>
template<typename Type,typename Info>
class IinputFileNamesProvider
{
  public:
    virtual ~IinputFileNamesProvider(){};
    std::map<Type,std::vector<std::string>*>* getInputFileNamesMapType(std::map<Type,const Info&>*) const;
#ifndef TEST
  protected:
#else
  public:
#endif
    // This method will provide with name vectors.
    std::vector<std::string>* getInputFileNames(const Info& info,const unsigned int jobNumber) const;
    // This is the concrete method that return one file name
    std::vector<std::string>* getInputFileName(const Info& info) const;
};
#endif
