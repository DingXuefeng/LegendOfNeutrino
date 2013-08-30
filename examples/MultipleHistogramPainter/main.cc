#include "MultipleHistogramPainter.h"
#include <TCanvas.h>
#include <iostream>
int main()
{
  TCanvas* c;
  MultipleHistogramPainter* multipleHistogramPainter = new MultipleHistogramPainter;
  std::cout<<"Testing MultipleHistogramPainter::setOptionFile..."<<std::endl;
  multipleHistogramPainter->setOptionFile("share/u_1e6_pmt_Det2_quench_splittedFirst_1.3m_radius_distribution_under_energyCut.txt");
  std::cout<<"Testing MultipleHistogramPainter::draw..."<<std::endl;
  c = multipleHistogramPainter->draw();
  c->Print("test.png");
  return 0;
}
