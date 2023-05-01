{
const Int_t n = 20; // sin el const saldría un error. De esta forma, siempre va a ser necesario poner el tamaño de los arreglos constantes.
Double_t x[n], y[n];
for (Int_t i=0; i<n; i++) {
x[i] = i*0.1;
y[i] = 10*sin(x[i]+0.2);
}
auto gr1 = new TGraph (n, x, y); // número de puntos, puntos en x, puntos en y
auto c1 = new TCanvas("c1","Graph Draw Options",200,10,600,400);
// draw the graph with axis, contineous line, and put a * at each point
gr1->Draw("AC*");

auto gr2 = new TGraph (n, x, y);
gr2->SetFillColor(40);
gr2->Draw("AB");

auto gr3 = new TGraph (n, x, y);
gr2->SetFillColor(45);
gr2->Draw("AF");
}