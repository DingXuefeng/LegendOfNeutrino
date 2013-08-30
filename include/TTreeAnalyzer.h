/*****************************************************************
 * The TTree analyzer class
 * Author: Ding Xuefeng dingxf@ihep.ac.cn
 * History:
 *   2013.08.27 ver 1.2 
 *****************************************************************/
#ifndef TTreeAnalyzer_H
#define TTreeAnalyzer_H
#include <TCut.h>
#include <string>
class TH1;
class TTree;
class TTreeAnalyzer
{
  public:
    // This method give a histogram telling you how the event number
    // increase as the varible increases under specified cut
    // use it like this:
    //   treeAnalyzer->getAccumulatedDistribution(tree,varible,cut,name);
    static TH1* getAccumulatedDistribution(TTree*,std::string,TCut cut="",std::string name="accumulatedDistribution");
    // if you already has the distribution, then use this:
    static TH1* getAccumulatedDistribution(TH1*);

    // This method give the distribution of the varible increases under 
    // specified cut
    // use it like this:
    //   treeAnalyzer->getDistribution(tree,varible,cut,name);
    static TH1* getDistribution(TTree*,std::string,TCut cut="",std::string name="distribution");
};
#endif
