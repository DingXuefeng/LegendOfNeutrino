/*
#include "IinputFileNamesProvider.h"
template<typename Info>
std::vector<std::string>* IinputFileNamesProvider::getInputFileNames(const Info& info,const unsigned int jobNumber) const
{
  std::vector<std::string>* inputFileNames = new std::vector<std::string>;
  for(unsigned int i=0;i<jobNumber;i++)
    inputFileNames->push_back(getInputFileName<Info>(info));
  return inputFileNames;
}
*/
