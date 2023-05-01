void format_line(TAttLine* line,int col,int sty){ // Función de estilo
    line->SetLineWidth(1.0); line->SetLineColor(col);
    line->SetLineStyle(sty);}
/*
double the_gausppar(double* vars, double* pars){
    return pars[0]*TMath::Gaus(vars[0],pars[1],pars[2])+
        pars[3]+pars[4]*vars[0]+pars[5]*vars[0]*vars[0];}
*/
double the_gauscub(double* vars, double* pars){
    return pars[0]*TMath::Gaus(vars[0],pars[1],pars[2])+
        pars[3]+pars[4]*vars[0]+pars[5]*vars[0]*vars[0]+pars[6]*vars[0]*vars[0]*vars[0];}

void myGraphVFinal(){

    gStyle->SetOptTitle(0); gStyle->SetOptStat(0);
    gStyle->SetOptFit(1111); gStyle->SetStatBorderSize(0);
    // Open the input file containing the TTree
    TFile* infile = TFile::Open("reducetree_Bujk_AOD_3_best1.root");

    // Get the TTree from the input file
    TTree* tree = (TTree*)infile->Get("butree");
    
    // Set the branch
    double B_mass;
    tree->SetBranchAddress("B_mass", &B_mass);

    // Create a Histogram
    int num_bins = 100;
    float min_value = 5;
    float max_value = 5.6;
    auto hist = new TH1F("Histogram", "Histogram Title", num_bins, min_value, max_value);

    // Fill the Hitogram with the values from the TTree branches
    // tree->GetEntries(): 770929
    for (int i = 0; i < tree->GetEntries(); ++i) {
        tree->GetEntry(i); // Output: 132
        hist->Fill(B_mass);
        //cout << "Entries: " << h->GetEntries() << endl;
        //cout << "B_mass value: " << B_mass << endl;
    }

    // Create a canvas and draw the TGraph

    TCanvas* canvas = new TCanvas("canvas", "Graph", 800, 600);

    //hist->Draw();
    // Customize histogram appearance
    hist->SetLineColor(kBlack);
    hist->SetLineWidth(2);
    hist->GetXaxis()->SetNdivisions(5, 5, 0);
    hist->GetXaxis()->SetRangeUser(5.0, 5.6);

    hist->SetMinimum(1e2); // The minimum value should be greater than zero
    hist->SetMaximum(1e5); 
    

    canvas->SetLogy(true);
    /*
    auto parabola = new TF1("parabola","[0]+[1]*x+[2]*x**2",0,20);
    format_line(parabola,kBlack,0);
    */

    auto cubic = new TF1("cubic","[0]+[1]*x+[2]*x**2+[3]*x**3",0,20);
    format_line(cubic,kBlack,0);

    auto gaussian = new TF1("gaussian","[0]*TMath::Gaus(x,[1],[2])",0,20);
    format_line(gaussian,kRed,0);

    auto gauscub = new TF1("gausppar",the_gauscub,5.0,5.6,7);// El 6 es el número de parámetros

    format_line(gauscub,kBlue,0);
    gauscub->SetParNames("Norm","Mean","Sigma","a","b","c","d"); // Nombramos los parámetros

    gauscub->SetParameter(0,1e2);
    gauscub->SetParameter(1,5.3);
    int npar=gauscub->GetNpar();
    for (int ipar=2;ipar<npar;++ipar) gauscub->SetParameter(ipar,1);
    
    hist->Fit(gauscub, "R");
    gauscub->DrawClone("Same");

    // Given the parameters to the gaussian and parabola functions
    for (int ipar=0;ipar<3;ipar++){
        gaussian->SetParameter(ipar,gauscub->GetParameter(ipar));
        cubic->SetParameter(ipar,gauscub->GetParameter(ipar+3));
    }

    hist->DrawClone("PE");
    cubic->DrawClone("Same");
    gaussian->DrawClone("Same");
    
    canvas->SaveAs("histogram.png");

    // Close the input file
    //infile->Close();
}