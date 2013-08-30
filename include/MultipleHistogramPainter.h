/*****************************************************************
 * The multiple histogram painter
 * Use optionFileManager to read options from a txt file.
 * Author: Ding Xuefeng dingxf@ihep.ac.cn
 * History:
 *   2013.08.27 ver 1.0
 *****************************************************************/
#ifndef MultipleHistogramPainter_H
#define MultipleHistogramPainter_H
#include <string>
class OptionFileManager;
class MultipleHistogramPainter
{
  public:
    // set the option file name
    void setOptionFile(std::string);
    // read the option file and draw
    // In the option, you should tell:
    //  * How many histograms are there
    //    option: "HistogramNumbers"
    //  * Where is the histogram for the specified histograms
    //    option: "InputFileDirectory" and "InputFileName" "HistogramName"
    //    you should specify the histogram id first, say:
    //      InputFileDirectory 2 /publicfs/dyb/data/userdata/dingxf/JUNO/PMTradioactivity/Det2/u_1e6_pmt_Det2_quench_splittedFirst_1.3m
    //    if there are two layers, you should calculate the id.
    //    id starts from 0.
    //  * Interpretation for the histograms
    //    option: "Legend"
    //  * Color, Style
    //    option: "Color" "Style"
    //  * draw option
    //    option: "DrawOption"
    TCanvas* draw() const;

  private:
    OptionFileManager* optionFileManager;
};
#endif
