const double rootpiby2 = sqrt(atan2(0.0,-1.0)/2.0);
const double root2pi = sqrt(atan2(0.0,-1.0)*2.0);
double _gaussCrystalball(double* x,double* par)
{
  const double xx = x[0];
  const double Gauss_N = par[0];
  const double Gauss_mean = par[1];
  const double Gauss_sigma = par[2];

  const double CB_N = par[3];
  const double CB_mean = par[4];
  const double CB_sigma = par[5];
  const double CB_alpha = par[6];
  const double CB_n = par[7];

  // for crystalball
  double crystalball = 0;
  double t = (xx-CB_mean)/CB_sigma;
  if(CB_alpha<0) t = -t;
  const double absAlpha = fabs(CB_alpha);
  const double absAlpha2exp = exp(-0.5*absAlpha*absAlpha);

  if ( t >= -absAlpha)
  {
    crystalball = exp(-0.5*t*t);
  }
  else
  {
    const double A = TMath::Power(CB_n/absAlpha, CB_n)*absAlpha2exp;
    const double B = CB_n/absAlpha - absAlpha;
    crystalball = A/TMath::Power(B-t,CB_n);
  }

  // crystalball norm
  const double C = CB_n/absAlpha/(CB_n-1)*absAlpha2exp;
  const double D = rootpiby2*(1+RooMath::erf(absAlpha*sqrt(0.5)));
  const double crystalballNorm = 1/(CB_sigma*(C+D));

  // for gauss
  double gauss = 0;
  const double arg = xx-Gauss_mean;
  gauss = exp(-0.5*arg*arg/(Gauss_sigma*Gauss_sigma));

  // gauss norm
  const double gaussNorm = 1/(Gauss_sigma*root2pi);

  return CB_N*crystalball+Gauss_N*gauss;
  //return Gauss_N*gaussNorm*gauss;
  //return CB_N*crystalballNorm*crystalball;
}
void draw()
{
  TF1* f = new TF1("f",_gaussCrystalball,0,5,8);
  f->SetParameters(39,1.42,0.22,172,2.506,0.14,0.64,1.7);
  f->SetNpx(500);
  f->Draw();
}
