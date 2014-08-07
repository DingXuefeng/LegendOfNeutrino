/*****************************************************************
 * The easy plot class
 * Author: Ding Xuefeng dingxf@ihep.ac.cn
 * History:
 *   2013.09.08 ver 1.0
 *****************************************************************/
#ifndef EasyPlot_H
#define EasyPlot_H
#include "PointWithYError.h"
#include <map>
#include <vector>
#include <string>
#include <TH1.h>
class TCanvas;
class EasyPlot
{
  public:
    // this method will draw several histograms for different types on one canvas
    // the legend for each histograms come from the name of the histogram
    static TCanvas* drawHistogramsMapType(std::map<std::string,TH1*>* hMapType,std::string canvasName="hMapType",std::string Xtitle="X [unit]",std::string Ytitle="Y [unit]",double bottomleft_x=0.4,double bottomleft_y=0.6,double topright_x=0.95,double topright_y=0.95,bool whetherLogy=false);
    // // this method will draw several graph with errors for different types on one canvas
    // static TCanvas* drawTGraphErrorsMapType(std::map<std::string,TGraphErrors*>* grMapType,std::string canvasName,std::string Xtitle,std::string Ytitle);
    // this method will draw one histograms, and each bin represent one type
    static TCanvas* drawHistogramWithNamedBinsFromNamedItemVector(std::vector<PointWithYError>* pointMapType,std::string canvasName,std::string Xtitle="",std::string Ytitle="",bool whetherLogy=false);
    // this method can generate a TH1 for the vector
    static TH1* fromPointVectorToTH1(std::vector<PointWithYError>* pointVector,std::string histogramName="histograms",std::string histogramTitle="Demo histograms");
  protected:
    // this mehod will get min y of the map
    template<typename Type>
    static double getHistogramsMapYMin(std::map<Type,TH1*>* hMap);
    // this mehod will get max y of the map
    template<typename Type>
    static double getHistogramsMapYMax(std::map<Type,TH1*>* hMap);
    // this is the concrete mothod that do the drawing
    static TCanvas* drawHistogramWithNamedBins(TH1* pointMapType,std::string canvasName,std::string Xtitle,std::string Ytitle,bool whetherLogy=false);
};

template<typename Type>
double EasyPlot::getHistogramsMapYMin(std::map<Type,TH1*>* hMap)
{
  double min(1e100);
  for(std::map<std::string,TH1*>::iterator hMapit = hMap->begin();
      hMapit != hMap->end(); hMapit++)
  {
    double localMin(hMapit->second->GetBinContent(hMapit->second->GetMinimumBin()));
    min=(min<localMin)?min:localMin;
  }
  return min;
}
template<typename Type>
double EasyPlot::getHistogramsMapYMax(std::map<Type,TH1*>* hMap)
{
  double max(0);
  for(std::map<std::string,TH1*>::iterator hMapit = hMap->begin();
      hMapit != hMap->end(); hMapit++)
  {
    double localMax(hMapit->second->GetBinContent(hMapit->second->GetMaximumBin()));
    max=(max>localMax)?max:localMax;
  }
  return max;
}
#endif
