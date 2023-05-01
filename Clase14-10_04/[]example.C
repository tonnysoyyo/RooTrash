{
   auto c43 = new TCanvas("c43","c43",200,10,600,400);
   c43->DrawFrame(0., -0.5, 6., 2);
 
   double x[5]    = {1, 2, 3, 4, 5};
   double zero[5] = {0, 0, 0, 0, 0};
 
   // data set (1) with stat and sys errors
   double py1[5]      = {1.2, 1.15, 1.19, 0.9, 1.4};
   double ey_stat1[5] = {0.2, 0.18, 0.17, 0.2, 0.4};
   double ey_sys1[5]  = {0.5, 0.71, 0.76, 0.5, 0.45};
 
   // data set (2) with stat and sys errors
   double y2[5]       = {0.25, 0.18, 0.29, 0.2, 0.21};
   double ey_stat2[5] = {0.2, 0.18, 0.17, 0.2, 0.4};
   double ey_sys2[5]  = {0.63, 0.19, 0.7, 0.2, 0.7};
 
   // Now draw data set (1)
 
   // We first have to draw it only with the stat errors
   auto graph1 = new TGraphErrors(5, x, py1, zero, ey_stat1);
   graph1->SetMarkerStyle(20);
   graph1->Draw("P");
 
   // Now we have to somehow depict the sys errors
 
   auto graph1_sys = new TGraphErrors(5, x, py1, zero, ey_sys1);
   graph1_sys->Draw("[]");
 
   // Now draw data set (2)
 
   // We first have to draw it only with the stat errors
   auto graph2 = new TGraphErrors(5, x, y2, zero, ey_stat2);
   graph2->SetMarkerStyle(24);
   graph2->Draw("P");
 
   // Now we have to somehow depict the sys errors
 
   auto graph2_sys = new TGraphErrors(5, x, y2, zero, ey_sys2);
   graph2_sys->Draw("[]");
}