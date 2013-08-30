#ifndef DybStyle_H
#define DybStyle_H
#include "TStyle.h"
/*//////////////////////
    m_dybStyle->cd();
    gROOT->ForceStyle();
    gStyle->ls();
*///////////////////////
class DybStyle : public TStyle{
  private:
    DybStyle();
  public:
    ~DybStyle(){if(m_dybStyle) delete m_dybStyle;}
    static TStyle* get();
    static void set();
  private:
    static TStyle* m_dybStyle;
};
#endif

