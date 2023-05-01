{
auto h1 =new TH1F("h1","Signal Histo",50,0,10);
TRandom3 rndgen;
for (int imeas=0;imeas<4000;imeas++){
h1->Fill(rndgen.Gaus(5,.5));
}
h1->Fit("gaus","","",4.5,6.);
h1->Fit("expo","+","",2.,4);
//h1->Fit("gaus","V");
//h1->Fit("gaus","L N 0");
auto result = h1->Fit("gaus","L S"); // Con esta parte del código estoy imprimiendo la información. Ndf (number degrees free) es el número de grados de libertad
result->Print("V");
}