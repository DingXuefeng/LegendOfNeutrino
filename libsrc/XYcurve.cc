#include "XYcurve.h"
#include "PointWithYError.h"
#include <vector>
void XYcurve::insert(const PointWithYError& point)
{
  curve.push_back(PointWithYError(point));
}

const std::vector<PointWithYError>& XYcurve::getCurve() const
{
  return curve;
}
