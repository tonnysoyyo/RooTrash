{
   auto c47 = new TCanvas("c47","c47",200,10,600,400);
   double ax[]      = {0, 1, 2, 3, 4};
   double ay[]      = {0, 2, 4, 1, 3};
   double aexl[]    = {0.3, 0.3, 0.3, 0.3, 0.3};
   double aexh[]    = {0.3, 0.3, 0.3, 0.3, 0.3};
   double* aeylstat = new double[5]  {1, 0.5, 1, 0.5, 1};
   double* aeyhstat = new double[5]  {0.5, 1, 0.5, 1, 0.5};
   double* aeylsys  = new double[5]  {0.5, 0.4, 0.8, 0.3, 1.2};
   double* aeyhsys  = new double[5]  {0.6, 0.7, 0.6, 0.4, 0.8};
 
   TGraphMultiErrors* gme = new TGraphMultiErrors("gme", "TGraphMultiErrors Example", 5, ax, ay, aexl, aexh, aeylstat, aeyhstat);
   gme->AddYError(5, aeylsys, aeyhsys);
   gme->SetMarkerStyle(20);
   gme->SetLineColor(kRed);
   gme->GetAttLine(0)->SetLineColor(kRed);
   gme->GetAttLine(1)->SetLineColor(kBlue);
   gme->GetAttFill(1)->SetFillStyle(0);
 
   gme->Draw("a p s ; ; 5 s=0.5");
}