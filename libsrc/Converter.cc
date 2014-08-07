#include "Converter.h"
#include <TFormula.h>
#include <iomanip>
#include <sstream>
std::string Converter::doubleToString(double x,int precision,bool scientifiStyle)
{
  std::stringstream xs;
  if(scientifiStyle)
    xs<<std::scientific;
  else
    xs<<std::fixed;
  xs<<std::setprecision(precision)<<x;
  return xs.str();
};
std::string Converter::intToString(int x)
{
  return doubleToString(x,0);
};
double Converter::stringToDouble(std::string formula)
{
  TFormula myf("myf",formula.c_str());
  return myf.Eval(0);
}
int Converter::stringToInt(std::string formula)
{
  return (int)(stringToDouble(formula));
}
