#ifndef PointWithYError_H
#define PointWithYError_H
#include <iostream>
#include <string>
class PointWithYError
{
  public:
    PointWithYError(){};
    PointWithYError(double xr,double yr,double yerrr):x(xr),y(yr),yerr(yerrr){};
    PointWithYError(std::string typer,double yr,double yerrr):type(typer),y(yr),yerr(yerrr){};
    PointWithYError(std::string typer,double xr,double yr,double yerrr):type(typer),x(xr),y(yr),yerr(yerrr){};
  public:
    void toPercent();
    void setType(std::string);
    void show(std::ostream& out) const;
  public:
    std::string type;
    double x;
    double y;
    double yerr;
};
#endif
