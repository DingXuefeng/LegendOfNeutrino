#include "EasyPlot.h"
#include "Converter.h"
#include "PointWithYError.h"
#include <TH1F.h>
#include <map>
int main()
{
  /******************************************
   * Job 1
   * Draw a histogram with named bins
   * ****************************************/
  PointWithYError points[3]={PointWithYError("U(ppb)",34.91,3.4),PointWithYError("Th(ppb)",85.12,8.7),PointWithYError("K(ppm)",22.45,2.1)};
  std::vector<PointWithYError>* pointsVector = new std::vector<PointWithYError>(points,points+3);
  EasyPlot::drawHistogramWithNamedBinsFromNamedItemVector(pointsVector,"radio_activity");

  /******************************************
   * Job 2
   * Draw histograms of different types
   * ****************************************/
  std::map<std::string,TH1*>* hMapType = new std::map<std::string,TH1*>;
  for(unsigned int eventNumber = 1000;eventNumber<=3000;eventNumber+=1000)
  {
    (*hMapType)[Converter::intToString(eventNumber)]=new TH1F(("h"+Converter::intToString(eventNumber)).c_str(),Converter::intToString(eventNumber).c_str(),100,-10,10);
    (*hMapType)[Converter::intToString(eventNumber)]->FillRandom("gaus",eventNumber);
  }
  EasyPlot::drawHistogramsMapType(hMapType,
      				  "EventNumberMap", // canvas name
				  "Radius [m]", // x title
				  "Entries", //y title
				  0.6,0.6,0.95,0.95, // coordinates of corner of legend
				  true // whether log y
				  );
}
