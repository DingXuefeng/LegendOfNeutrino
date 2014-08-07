#include "XYcurve.h"
#include "PointWithYError.h"
#include <iostream>
int main()
{
  PointWithYError point[3]={PointWithYError("cake",13,2.3),PointWithYError("moon",1e6,3.2e3),PointWithYError(13,1,1.5)};
  XYcurve curve;
  for(unsigned int i = 0;i<3;i++)
    curve.insert(point[i]);
  //TestTool.testVector<PointWithYError>(std::cout,curve.getCurve());
  const std::vector<PointWithYError>& curveV(curve.getCurve());
  for(unsigned int i = 0;i<curveV.size();i++)
    std::cout<<i<<": ["<<curveV[i].type<<":"<<curveV[i].x<<","<<curveV[i].y<<"("<<curveV[i].yerr<<")]"<<std::endl;
  return 0;
}


