// Importamos la librería
#include "Factura.h"

// Desarrollamos el contructor, que funcionará con el método establecer();
Factura::Factura(){
    establecer();
}

void Factura::establecer(){
  //Establece la informacion del articulo desde la consola
  cout << "INFORMACION ARTICULO" << endl;
  
  cout << "Ingrese numero de pieza: "; cin >> numPieza;
  
  cout << "Ingrese descripcion: ";
  cin.ignore();
  getline (cin, descripcion);
  
  cout << "Ingrese cantidad: "; cin >> cantidad;
  if(cantidad < 0){
    cantidad = 0;
  }
  
  cout << "Ingrese precio: "; cin >> precio;
  if(precio < 0){
    precio = 0;
  }
}

void Factura::obtener(){
  unsigned int opcion{0};
  cout << "¿Que informacion desea obtener? \n 1. Numero de pieza \n 2. Descripcion \n 3. Cantidad \n 4. Precio" << endl;
  cout << "Ingrese opcion: "; cin >> opcion;
  
  switch(opcion){
  case 1:
    cout << "Numero de pieza: " << numPieza << endl;
    break;
  case 2:
    cout << "Descripcion: " << descripcion << endl;
    break;
  case 3:
    cout << "Cantidad: " << cantidad << endl;
    break;
  case 4:
    cout << "Precio: " << precio << endl;
    break;
  }
}

void Factura::obtenerMontoFactura(){
  cout << "********************************" << endl;
  cout << "FACTURA" << endl;
  cout << "********************************" << endl;
  cout << "Articulo: \nRef. " << numPieza << "\t Desc. " << descripcion << endl;
  cout << "Precio total: $ " << cantidad*precio << endl; 
}