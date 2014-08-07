#include "EnergySpectrum.h"
#include <TF1.h>
#include <TString.h>
#include <RooMath.h>
#include <TMath.h>
#include <cmath>
TF1* EnergySpectrum::Co60(TString name,bool doubleGauss)
{
  if(doubleGauss)
    return Co60_doubleGauss(name);
  else
    return Co60_gaussCrystalball(name);
}

TF1* EnergySpectrum::Co60_doubleGauss(TString name)
{
  static TF1* co60_doubleGauss = new TF1("",_doubleGauss);
  co60_doubleGauss->SetName(name);
  return co60_doubleGauss;
}

TF1* EnergySpectrum::Co60_gaussCrystalball(TString name)
{
  TF1* co60_gaussCrystalball(_Co60_gaussCrystalball());
  co60_gaussCrystalball->SetName(name);
  return co60_gaussCrystalball;
}

TF1* EnergySpectrum::_Co60_gaussCrystalball()
{
  TF1* gaussCB = new TF1("",_gaussCrystalball,0,4,8);
  gaussCB->SetParNames(
      "Gauss_N",
      "Gauss_mean",
      "Gauss_sigma",
      "CB_N",
      "CB_mean",
      "CB_sigma",
      "CB_alpha",
      "CB_n"
      );
  return gaussCB;
}

double EnergySpectrum::_doubleGauss(double *x,double *par)
{
  throw -1;
  return 0;
}

double EnergySpectrum::_gaussCrystalball(double* x,double* par)
{
  const double xx = x[0];
  const double Gauss_N = par[0];
  const double Gauss_mean = par[1];
  const double Gauss_sigma = par[2];

  const double CB_N = par[3];
  const double CB_mean = par[4];
  const double CB_sigma = par[5];
  const double CB_alpha = par[6];
  const double CB_n = par[7];

  // for crystalball
  double crystalball = 0;
  double t = (xx-CB_mean)/CB_sigma;
  if(CB_alpha<0) t = -t;
  const double absAlpha = fabs(CB_alpha);
  const double absAlpha2exp = exp(-0.5*absAlpha*absAlpha);

  if ( t >= -absAlpha)
  {
    crystalball = exp(-0.5*t*t);
  }
  else
  {
    const double A = TMath::Power(CB_n/absAlpha, CB_n)*absAlpha2exp;
    const double B = CB_n/absAlpha - absAlpha;
    crystalball = A/TMath::Power(B-t,CB_n);
  }

  // crystalball norm
  //const double C = CB_n/absAlpha/(CB_n-1)*absAlpha2exp;
  //static const double rootpiby2 = sqrt(atan2(0.0,-1.0)/2.0);
  //const double D = rootpiby2*(1+RooMath::erf(absAlpha*sqrt(0.5)));
  //const double crystalballNorm = 1/(CB_sigma*(C+D));

  // for gauss
  double gauss = 0;
  const double arg = xx-Gauss_mean;
  gauss = exp(-0.5*arg*arg/(Gauss_sigma*Gauss_sigma));

  // gauss norm
  //static const double root2pi = sqrt(atan2(0.0,-1.0)*2.0);
  //const double gaussNorm = 1/(Gauss_sigma*root2pi);

  //return CB_N*crystalballNorm*crystalball+Gauss_N*gaussNorm*gauss;
  return CB_N*crystalball+Gauss_N*gauss;
}
