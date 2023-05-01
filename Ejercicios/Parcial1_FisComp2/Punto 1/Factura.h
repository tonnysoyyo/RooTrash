// Importamos las librerías
#include <iostream>
#include <string>

using namespace std;

// Llamamos la clase
class Factura{

    // Establecemos los atributos de la clase
    private:
    string numPieza{""}, descripcion{""};
    int cantidad{0};
    float precio{0};

    // Establecemos el contructor y los métodos
    public:
    Factura();
    void establecer();
    void obtener();
    void obtenerMontoFactura();

};