void prueba()
{
    // Create histogram
    int num_bins = 5;
    float min_value = 0;
    float max_value = 100;
    TH1F* hist = new TH1F("hist", "Histogram Title", num_bins, min_value, max_value);

    // Fill histogram
    hist->Fill(10);
    hist->Fill(20);
    hist->Fill(30);
    hist->Fill(40);
    hist->Fill(50);
    hist->Fill(60);
    hist->Fill(70);
    hist->Fill(80);
    hist->Fill(85);
    hist->Fill(90);

    // Draw histogram
    TCanvas* canvas = new TCanvas("canvas", "Canvas Title", 800, 600);
    hist->Draw();

    // Customize histogram appearance
    hist->SetLineColor(kRed);
    hist->SetLineWidth(2);
    hist->SetFillColor(kBlue);

    // Save histogram to file
    canvas->SaveAs("histogram.png");
}