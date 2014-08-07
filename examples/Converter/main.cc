#include "Converter.h"
#include <iostream>
int main()
{
  std::cout<<"Testing Converter::doubleToString()..."<<std::endl;
  std::cout<<Converter::doubleToString(0)<<std::endl;
  std::cout<<Converter::doubleToString(3.722883)<<std::endl;
  std::cout<<Converter::doubleToString(3.722883,3)<<std::endl;
  std::cout<<Converter::doubleToString(3.722883e-20,3)<<std::endl;
  std::cout<<Converter::doubleToString(3.722883e-20,3,true)<<std::endl;
  std::cout<<Converter::doubleToString(1000000000)<<std::endl;
  std::cout<<"Testing Converter::intToString()..."<<std::endl;
  std::cout<<Converter::intToString(-1)<<std::endl;
  std::cout<<Converter::intToString(1000000000)<<std::endl;
  std::cout<<"Testing Converter::stringToDouble()..."<<std::endl;
  std::cout<<Converter::stringToDouble("1+3*2.5^2")<<std::endl;
  std::cout<<Converter::stringToDouble("1000000000000")<<std::endl;
  std::cout<<"Testing Converter::stringToInt()..."<<std::endl;
  std::cout<<Converter::stringToInt("1+sqrt(3)*sin(37)*2.5^2")<<std::endl;
  std::cout<<Converter::stringToInt("100000")<<std::endl;
  return 0;
}
