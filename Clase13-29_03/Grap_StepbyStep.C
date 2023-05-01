void Grap_StepbyStep(){
    // The number of points in the data set
    const int n_points = 10;
    // The values along X and Y axis
    double x_vals[n_points] = {1,2,3,4,5,6,7,8,9,10};
    double y_vals[n_points] = {6,12,14,20,22,24,35,45,44,53};
    // The errors on the Y axis
    double y_errs[n_points] = {5,5,4.7,4.5,4.2,5.1,2.9,4.1,4.8,5.43};
    // Instance of the graph
    auto graph = new TGraphErrors(n_points,x_vals,y_vals,nullptr,y_errs); // note que x_vals,y_vals, y y_errs son punteros, pues son arreglos y el nombre de un arreglo es un puntero a su primera coordenada
    
    graph->SetMarkerStyle(kOpenCircle);
    graph->SetMarkerColor(kBlue);
    graph->SetLineColor(kBlue); // Hago que la línea sea azul
    graph->SetTitle(";length [cm];Arb.Units"); // HAy otra forma de ponerle nombre a los títulos, que es primero trayendo el título con un get y luego poniendo el nombre con un set
    
    graph->Draw("APEL"); // Cada letra tiene un significado. A: Eje, P: Puntos, E: Error
    
    // Define a linear function
    auto f = new TF1("Linear law","[0]+x*[1]",.5,10.5); // El 0.5 y 10.5 equivale de dónde a dónde estamos graficando la línea
    // Let's make the function line nicer
    f->SetLineColor(kRed-3);
    f->SetLineStyle(2);
    // Set parameters
    f->SetParameters(-1,5); // Pone -1 e0n el primer parametro ([]) y 5 en el segundo ([1])
    f->Draw("Same");
    
    auto legend = new TLegend(.1,.7,.3,.9,"Lab. Lesson 1");
    legend->AddEntry(graph,"Exp. Points","PE");
    legend->AddEntry(f,"Th. Law","L");
    legend->Draw();
}