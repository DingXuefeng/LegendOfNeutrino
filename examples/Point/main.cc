#include "Point.h"
#include <iostream>
int main()
{
  std::cout << (std::string("hello") == std::string("hello")) << std::endl;
  Point<std::string,double> energyResolution(std::string("No cover"),3.0);
  std::cout<<energyResolution.sameX("No cover")<<std::endl;;
  Point<float,double> energyResolution1(1.0,3.0);
  std::cout<<energyResolution1.sameX(0.99999999999999999)<<std::endl;;
  std::cout<<energyResolution1.sameX(0.999999)<<std::endl;;
  std::cout<<energyResolution1.sameX(0.9999)<<std::endl;;
  Point<double,double> energyResolution2(1.0,3.0);
  std::cout<<energyResolution2.sameX(0.99999999999999999)<<std::endl;;
  std::cout<<energyResolution2.sameX(0.999999)<<std::endl;;
  std::cout<<energyResolution2.sameX(0.9999)<<std::endl;;
  return 0;
}
