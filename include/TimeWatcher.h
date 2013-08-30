/******************************************
 * class that watch how fast program runs
 * Author: Ding Xuefeng dingxf@ihep.ac.cn
 * History:
 *   2013.08.22 ver 1.0
 *****************************************/
#ifndef TimeWatcher_H
#define TimeWatcher_H
#include <ctime>
#include <iostream>
class TimeWatcher
{
  public:
    inline static void startWatch()
    {
      watch = clock();
    }
    inline static void report(std::ostream& test,const char info[])
    {
      test<<((double(clock()-watch))/CLOCKS_PER_SEC)<<" s ["<<
	info<<"]"<<std::endl;
    }
    inline static void report(std::ostream& test,const char info[],const int line)
    {
      test<<((double(clock()-watch))/CLOCKS_PER_SEC)<<" s ["<<
	info<<"] "<<line<<"L"<<std::endl;
    }
  private:
    static clock_t watch;
};
clock_t TimeWatcher::watch = 0L;
#endif
