/*****************************************************************
 * The TTree analyzer class
 * Author: Ding Xuefeng dingxf@ihep.ac.cn
 * History:
 *   2013.08.27 ver 1.2 
 *   2013.09.26 ver 1.3
 *****************************************************************/
#ifndef EnergySpectrum_H
#define EnergySpectrum_H
#include <TString.h>
#include <TF1.h>
class EnergySpectrum
{
  public:
    // this method will provide with you a TF1. you are responsible to set the initial conditions
    // if set double gause true, it use double gause, otherwise gauss + crystallball
    static TF1* Co60(TString name="Co60_energySpectrum",bool doubleGauss=false);
  private:
    static TF1* Co60_doubleGauss(TString name);
    static TF1* Co60_gaussCrystalball(TString name);
    static TF1* _Co60_gaussCrystalball();
    static double _doubleGauss(double *x,double* par);
    static double _gaussCrystalball(double *x,double* par);
};
#endif
