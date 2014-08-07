/*****************************************************************
 * The converter class
 * Author: Ding Xuefeng dingxf@ihep.ac.cn
 * History:
 *   2013.09.05 ver 1.0
 *****************************************************************/
#ifndef Converter_H
#define Converter_H
#include <string>
class Converter
{
  public:
    // This method convert double to string.
    // it allows precision for 1, and fiexed type
    static std::string doubleToString(double,int precision = 1,bool scientifiStyle=false);
    static std::string intToString(int);
    // This method convert string to double
    static double stringToDouble(std::string);
    // This method convert string to int
    static int stringToInt(std::string);
};
#endif
