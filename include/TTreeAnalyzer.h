/*****************************************************************
 * The TTree analyzer class
 * Author: Ding Xuefeng dingxf@ihep.ac.cn
 * History:
 *   2013.08.27 ver 1.2 
 *   2013.09.26 ver 1.3
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
    // use this method to get the tree from the specific directory
    // it will add all the files in one directory
    // use numberCheck to makesure that you get the right number of root files
    static TTree* getTTree(TString directoryName,TString treeName,int numberCheck=-1);
    // This method give a histogram telling you how the event number
    // increase as the variable increases under specified cut
    // use it like this:
    //   treeAnalyzer->getAccumulatedDistribution(tree,variable,cut,fixbin,name);
    static TH1* getAccumulatedDistribution(TTree*,std::string,TCut cut="",std::string fixBin="",std::string name="accumulatedDistribution");
    // if you already has the distribution, then use this:
    static TH1* getAccumulatedDistribution(TH1*);

    // This method give the distribution of the variable increases under 
    // specified cut
    // use it like this:
    //   treeAnalyzer->getDistribution(tree,variable,cut,fixbin,name);
    static TH1* getDistribution(TTree*,std::string,TCut cut="",std::string fixBin="",std::string name="distribution");
    // This method give the relationship between two variables under
    // specified cut
    // use it like this:
    //   treeAnalyzer->getRelation(tree,variable1,variable2,cut,name);
    static TH1* getRelation(TTree*,std::string,std::string,TCut cut="",std::string name="distribution");
};
#endif
