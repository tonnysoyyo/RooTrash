
void MyFirtsTgraph(){
  //TGraphErrors *myTgr = new TGraphErrors("ExampleData.txt");
  //auto myTgr = new TGraphErrors("ExampleData.txt");
  //myTgr->Draw("AP");
  //std::cout<< "here"  << std::endl;
  
  TGraphErrors myTgr2("ExampleData.txt"); // Este constructor lee un archivo txt
  myTgr2.Draw("AP");

}
// Este código cuando lo corremos en root no sale nada, daría descomentando la 3 y 5 línea y comentando la 8 y 9 línea, pues si vamos a usar un macro con el nombre de una función debemos usar punteros. Si deseamos usar las líneas 8 y 9 lo que debemos hacer es quitar la parte de void MyFirtsTgraph() antes del {. Volver a preguntar la explicación de esto