{
   auto c46 = new TCanvas("c46","c46",500,500);
   auto grP1 = new TGraphPolar();
   grP1->SetTitle("TGraphPolar example");
 
   grP1->SetPoint(0, (1*TMath::Pi())/4., 0.05);
   grP1->SetPoint(1, (2*TMath::Pi())/4., 0.10);
   grP1->SetPoint(2, (3*TMath::Pi())/4., 0.15);
   grP1->SetPoint(3, (4*TMath::Pi())/4., 0.20);
   grP1->SetPoint(4, (5*TMath::Pi())/4., 0.25);
   grP1->SetPoint(5, (6*TMath::Pi())/4., 0.30);
   grP1->SetPoint(6, (7*TMath::Pi())/4., 0.35);
   grP1->SetPoint(7, (8*TMath::Pi())/4., 0.40);
 
   grP1->SetMarkerStyle(20);
   grP1->SetMarkerSize(1.);
   grP1->SetMarkerColor(4);
   grP1->SetLineColor(4);
   grP1->Draw("ALP");
 
   // Update, otherwise GetPolargram returns 0
   c46->Update();
   grP1->GetPolargram()->SetToRadian();
}