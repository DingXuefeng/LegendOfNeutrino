/*****************************************************************
 * This is a data class. It will hold points describing curve of 
 * y(x).
 * Now I use vector.
 * Author: Ding Xuefeng dingxf@ihep.ac.cn
 * History:
 *   2013.09.24 ver 1.0
 *****************************************************************/
#ifndef XYcurve_H
#define XYcurve_H
#include "PointWithYError.h"
#include <vector>
class XYcurve
{
  public:
    // use this method to insert a point into the curve
    // I copied the data, so you don't have to worry about whether 
    // point is destroyed when I use the curve
    void insert(const PointWithYError& point);
    const std::vector<PointWithYError>& getCurve() const;
  private:
    std::vector<PointWithYError> curve;
};
#endif
