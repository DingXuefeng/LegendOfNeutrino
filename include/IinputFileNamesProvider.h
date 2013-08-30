/******************************************
 * class that provide with input file names
 * Author: Ding Xuefeng dingxf@ihep.ac.cn
 * History:
 *   2013.08.27 ver 1.0
 *****************************************/
#ifndef IinputFileNamesProvider_H
#define IinputFileNamesProvider_H
#include <vector>
#include <string>
class IinputFileNamesProvider
{
  public:
    virtual ~IinputFileNamesProvider(){};
    // This method will return a vector containing all the
    // names of the input files of one job.
    virtual std::vector<std::string>* getInputFileNames() const = 0;
};
#endif
