/******************************************
 * The grabber class
 * It helps you grab a histogram from a root
 * file.
 * Author: Ding Xuefeng dingxf@ihep.ac.cn
 * History:
 *   2013.08.22 ver 1.0
 *****************************************/
#ifndef IhitogramGrabber_H
#define IhitogramGrabber_H
#include <string>
class TH1;
class TFile;
class IhitogramGrabber
{
  public:
    virtual ~IhitogramGrabber(){};
    //grab a histogram from a root file
    virtual TH1* getEnergySpectrum(TFile*) const;
    //get the name of the root file
    //it's used to name the grabbed histogram
    virtual std::string getSplittedFileName(TFile*) const;
  protected:
    virtual TH1* getEnergySpectrum_(TFile*) const = 0;
};
#endif
