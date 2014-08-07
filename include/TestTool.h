/******************************************
 * class that test all kinds of TObjects
 * Author: Ding Xuefeng dingxf@ihep.ac.cn
 * History:
 *   2013.08.22 ver 1.0
 *****************************************/
#ifndef TestTool_H
#define TestTool_H
#include <iostream>
class TTree;
class TH1;
class TH2;
class TestTool
{
  public:
    // show the name,entries,and the name of the first branch
    // if level>0, show all the branch names
    static void testTTree(std::ostream& output,TTree*,int level=0);

    // show the name,Mean,RMS
    // if level>0, show each bin content
    static void testTH1(std::ostream& output,TH1*,int level = 0);

    // find the bin x
    static double watchTH1(TH1*,double x);
    static void watchTH1(std::ostream& output,TH1*,double x);

    // provide with one test histogram
    // nbins: 5  xlow: 0.5 xup: 5.5
    // Fill: 0.1x2 1x3 3x1 4x2
    static TH1* getTestTH1();
    static void testTH2(std::ostream& output,TH2*,int level = 0);
    static TH2* getTestTH2();
};
#endif
