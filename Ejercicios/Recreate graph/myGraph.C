void myGraph(){
    // Open the input file containing the TTree
    TFile* infile = TFile::Open("reducetree_Bujk_AOD_3_best1.root");

    // Get the TTree from the input file
    TTree* tree = (TTree*)infile->Get("butree");

    // Create a TGraph from the TTree
    auto graph = new TGraph(tree->GetEntries());

    double B_mass;
    tree->SetBranchAddress("B_mass", &B_mass);

    TH1F* h = new TH1F("h", "Histogram of B_mass", 100, 5, 5.6);
    
    // Fill the TGraph with the values from the TTree branches
    for (int i = 0; i < tree->GetEntries(); ++i) {
        tree->GetEntry(i);
        double B_mass_val;
        tree->SetBranchAddress("B_mass", &B_mass_val);
        h->Fill(B_mass);
        graph->SetPoint(i, B_mass_val, i);
        //cout << B_mass_val << " " << i << endl;
    }

    //double xMin = 5.0;
    //double xMax = 6;
    //graph->GetXaxis()->SetRange(xMin, xMax);

    // Create a canvas and draw the TGraph
    TCanvas* canvas = new TCanvas("canvas", "Graph Example");
    graph->Draw("AP");
    h->Draw("Same");
    // Close the input file
    infile->Close();

    return 0;
}