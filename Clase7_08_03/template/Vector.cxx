#include <cmath>
#include <iostream>

using namespace std;

class Vector {
private:
    double* data;
    int size;

public:
    // Constuctores
    Vector(int n) : size(n) {
        data = new double[n];
        for (int i = 0; i < size; i++) {
            data[i] = 0.0;
        }
    }

    Vector(const Vector& v) : size(v.size) {
        data = new double[size];
        for (int i = 0; i < size; i++) {
            data[i] = v.data[i];
        }
    }

    // Destructor
    ~Vector() {
        delete[] data;
    }

    int getSize() const {
        return size;
    }

    double get(int i) const {
        return data[i];
    }

    void set(int i, double x) {
        data[i] = x;
    }

    // Método para calcularle la norma al vector
    double norm() const {
        double sum = 0.0;
        for (int i = 0; i < size; i++) {
            sum += data[i] * data[i];
        }
        return std::sqrt(sum);
    }

    Vector& operator=(const Vector& v) { // Está el & porque tengo que retornar la dirección de memoria del objeto que sobrecargué, puesto lo que yo retorne no es un nuevo vector, sino que es lo mismo con los nuevos cambios aplicados, por eso también es que el retorno es el *this
        if (this != &v) {  // Con este if lo ue hago es no igualar dos cosas que son lo mismo
            if (size != v.size) { // Aquí chequeo si son del mismo tamaño y si no lo son creo un nuevo data con el tamaño del otro
                delete[] data;
                size = v.size;
                data = new double[size];
            }
            for (int i = 0; i < size; i++) {
                data[i] = v.data[i];
            }
        }
        return *this;
    }

    Vector operator+(const Vector& v) const { // Aquí hubiese faltado verificar tamaño y demás
        Vector w(size); // Cree un nuevo arreglo que seŕa el que voy a retornar, porque no puedo modificar ni mi objeto de mi clase ni el que me pasen.
        for (int i = 0; i < size; i++) {
            w.data[i] = data[i] + v.data[i];
        }
        return w;
    }

    Vector operator-(const Vector& v) const {
        Vector w(size);
        for (int i = 0; i < size; i++) {
            w.data[i] = data[i] - v.data[i];
        }
        return w;
    }
    // En el =,+ y -, hay un const, esto es debido al prototipo que requiere la sobrecarga del operador, lo que quiere decir es que no puedo modificar nada que esté en mi clase ni ningún objeto que me pasen, por lo que yo solo accedo a ellos, no los modifico

    //Vector& operator+=(const Vector& other) { //¿cómo podría definir este?
    //return *this;
    //}

    double& operator[](int i){ // Aquí lo que quiero es definir el operador [] para que cuando yo le meta una posición me arroje el valor de dicha posición; por eso es double, porque me va a retornar este tipo de objeto y la i es int porque lo que le voy a ingresar va a ser un entero
        return data[i];
    }
    /* Si el operator[] no tiene el & va a salir un error en caso de que en el main queramos hacer cosas como:
    v3[0] = 0.1;
    cout<<v3[0]<<endl;
    Es decir, aquí estoy reasignando 0.1 a la posición 0, pero si no está el & saldrá un error dado que no estaré accediendo a la dirección de memoria y si bien sobrecargué el operador y si solo está el
    cout<<v3[0]<<endl;
    no habrá problema (dado que no hay ninguna reasignación), no habré sobrecargué de la manera correcta. */

};

int main()
{

    Vector v1(2);
    Vector v2(2);
    v1.set(0,2);
    v1.set(1,2);
    
    v2.set(0,1);
    v2.set(1,1);

    auto v3=v1+v2;
    cout<<v3.get(0)<<"  "<<v3.get(1)<<endl;
    v3=v1-v2;
    cout<<v3.get(0)<<"  "<<v3.get(1)<<endl;
    v3=v2;
    cout<<v3.get(0)<<"  "<<v3.get(1)<<endl;

    return 0;
}