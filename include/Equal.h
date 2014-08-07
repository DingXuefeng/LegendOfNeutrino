/*****************************************************************
 * Equal class
 * Author: Ding Xuefeng dingxf@ihep.ac.cn
 * History:
 *   2013.09.25 ver 1.0
 *****************************************************************/
#ifndef Equal_H
#define Equal_H
#include <cmath>
namespace LegendOfNeutrino
{
  namespace Equal
  {
    template<typename X>
      bool equal(const X& a,const X& b)
      {
	return a==b;
      }
    template<>
      bool equal<float>(const float& a,const float& b)
      {
	return fabs(a-b)<1e-5;
      }
    template<>
      bool equal<double>(const double& a,const double& b)
      {
	return fabs(a-b)<1e-10;
      }
  }
}
#endif
