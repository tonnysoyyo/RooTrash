{
   auto c47 = new TCanvas("c47","c47",200,10,600,400);
   c47->Divide(1,2);
   const Int_t n = 20;
   Double_t x[n], y[n];
   for (Int_t i=0;i<n;i++) {
      x[i] = i*0.1;
      y[i] = 10*sin(x[i]+0.2)-6;
   }
   auto gr = new TGraph(n,x,y);
   gr->SetFillColor(38);
   gr->SetTitle(" ");
   c47->cd(1); gr->Draw("AB");
   c47->cd(2); gr->Draw("AB1");
}