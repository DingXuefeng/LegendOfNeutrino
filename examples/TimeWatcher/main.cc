#include "TimeWatcher.h"
#include <iostream>
int main()
{
  TimeWatcher::startWatch();
  double sum;
  for(int i =0;i<10;i++)
  {
    for(int j=0;j<10;j++)
    {
      for(int k =0 ; k<10*(j+5)*(i+1)*i*i*j;k++)
      {
	TimeWatcher* x=new TimeWatcher;
	delete x;
      }
      sum+=i*1000+j;
    }
    TimeWatcher::report(std::cout,__PRETTY_FUNCTION__);
    TimeWatcher::report(std::cout,__PRETTY_FUNCTION__,__LINE__);
  }

  return 0;
}
