/*****************************************************************
 * The plot class
 * Author: Ding Xuefeng dingxf@ihep.ac.cn
 * History:
 *   2013.09.26 ver 1.0
 *****************************************************************/
#ifndef Plot_H
#define Plot_H
#include "OptionFileManager.h"
#include <TString.h>
#include <iostream>
#include <vector>
//enum DrawType
//{
//  HistogramWithNamedBins,
//  Histogram,
//  HistogramsMapType
//};
class Plot
{
  public:
    // it will read option file, get everything and generate png
    void draw(const std::string& optionFileName);
    // it will print help info
    static void help();
    void show() const;
    class singleJob;
  private:
    void readOption();
  private:
    OptionFileManager optionFileManager;
  private:
    //enum DrawType drawType;
    std::string drawType;
    std::vector<singleJob> inputList;
    TString xTitle;
    TString yTitle;
    double scaleBinx;
    float legendLBx;
    float legendLBy;
    float legendRTx;
    float legendRTy;
    float leftMargin;
    float rightMargin;
    float topMargin;
    float bottomMargin;
    TString pngName;
    float rangeLow;
    float rangeUp;
  public:
    class singleJob
    {
      public:
	singleJob(TString inputString)
	{
	  std::stringstream inputss;
	  inputss<<inputString;
	  inputss>>inputFileName>>histogramName>>lineColor>>lineStyle>>markerStyle;
	  legend=inputss.str().substr(inputss.tellg()).substr(1);
	}
      public:
	TString inputFileName;
	TString histogramName;
	int lineColor;
	int lineStyle;
	int markerStyle;
	TString legend;
      public:
	friend std::ostream& operator<< (std::ostream& output, const singleJob& r)
	{
	  TString outputInfo;
	  outputInfo += "inputFileName:[";
	  outputInfo += r.inputFileName;
	  outputInfo += "] ";
	  outputInfo += "histogramName:[";
	  outputInfo += r.histogramName;
	  outputInfo += "] ";
	  outputInfo += "lineColor:[";
	  outputInfo += r.lineColor;
	  outputInfo += "] ";
	  outputInfo += "lineStyle:[";
	  outputInfo += r.lineStyle;
	  outputInfo += "] ";
	  outputInfo += "markerStyle:[";
	  outputInfo += r.markerStyle;
	  outputInfo += "] ";
	  outputInfo += "legend:[";
	  outputInfo += r.legend;
	  outputInfo += "]";
	  output<<outputInfo;
	  return output;
	}
    };
};
#endif
