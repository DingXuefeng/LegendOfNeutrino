/*****************************************************************
 * The class representing relation between two element
 * Author: Ding Xuefeng dingxf@ihep.ac.cn
 * History:
 *   2013.09.25 ver 1.0
 *****************************************************************/
#ifndef Point_H
#define Point_H
#include <string>
#include <cmath>
#include "Equal.h"
template<typename X,typename Y>
class Point
{
  public:
    Point(X xValue,Y yValue):x(xValue),y(yValue){};
    // getter and setter
    inline void setX(const X& xValue) { x = xValue; }
    inline void setY(const Y& yValue) { y = yValue; }
    inline const X& getX() const { return x; }
    inline const Y& getY() const { return y; }
    inline bool sameX(const X& xValue) const { return LegendOfNeutrino::Equal::equal<X>(x,xValue);}

  private:
    // private member holding the data
    X x;
    Y y;
};
/*
bool
operator==(const std::string& a, const std::string& b) {
	return false;  
}
*/
#endif
