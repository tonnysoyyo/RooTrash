#include <iostream>
#include <cmath>
//#include "TMath.h"
//#include <TH1.h>
//#include <TF1.h>
//#include "TCanvas.h"

// define a function with 3 parameters
Double_t myGf(Double_t *x,Double_t *par) {
  Double_t arg = 0;
  if (par[2]!=0) arg = (x[0] - par[1])/par[2];
  Double_t mygval = par[0]*TMath::Exp(-0.5*arg*arg);
  return mygval; 
}

void myGaussFit() {
  gStyle->SetOptFit(1111);

  // created canvas
  auto myc1 = new TCanvas("myc1","myc1",600,600);
  
  //Defin a histogram
  TH1F *myh1 = new TH1F("myh1","myh1",100,-3,3);
  myh1->FillRandom("gaus",10000);
  // always the same histo, why??????
  //TRandom3 myr;
  //myr.SetSeed();
  //for(int i=0; i<10000; i++){ myh1->Fill(myr.Gaus()); }
  //myh1->Draw("APE");

  //TF1 *myfit = new TF1("myfit","gaus");
  //TF1 myfit("myfit","gaus");
  auto myfit = new TF1("myfit","[0]*TMath::Gaus(x,[1],[2])");
  
  // Create a TF1 object using the function defined above.
  // The last three parameters specify: minX, maxX, and number of parameters for the function.
  //TF1 *myfit = new TF1("myfit",myGf,-3,3,3);
  // set the parameters to the mean and RMS of the histogram
  //myfit->SetParameters(500,myh1->GetMean(),myh1->GetRMS());
  myfit->SetParameters(4005000,500,500); /* Con estos valores y descomentando la línea:
  auto myfit = new TF1("myfit","[0]*TMath::Gaus(x,[1],[2])");
  Y comentando
  TF1 *myfit = new TF1("myfit","gaus");
  Lo que voy a lograr es arruinar el fitteo, ya que los parametros iniciales son muy malos. Antes funcionaba muy bien ya que al hacer myh1->FillRandom("gaus",10000); y luego TF1 *myfit = new TF1("myfit","gaus"); lo que hago es generar una gaussiana random, la cual está centrada en 0, y al fittearla, la busco en 0. Por lo que lo que se está haciendo es que una gaussiana se busca a sí misma.
  */
  // give the parameters meaningful names
  myfit->SetParNames ("Constant","Mean","Sigma");
 
  // call TH1::Fit with the name of the TF1 object
  myh1->Fit("myfit");
  //f1->Draw("same");

  myc1->Print("plots/myfirstc.png");  
  
}



