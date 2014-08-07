#include "PointWithYError.h"
#include <iostream>
void PointWithYError::setType(std::string typer)
{
  type = typer;
}
void PointWithYError::toPercent()
{
  y*=100;
  yerr*=100;
}
void PointWithYError::show(std::ostream& out) const
{
  out<<"[type] x:y[yerr] ["<<type<<"] "<<x<<":"<<y<<"["<<yerr<<"]"<<std::endl;
}

