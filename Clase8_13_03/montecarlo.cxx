#include <random>  // Las cosas que tengan que ver con aleatoriedad en C++ van a estar en random
#include <iostream>
#include <cmath>

using namespace std;

class Integral
{
    protected:
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen; // seed the generator
    double (*fun)(double); // Función a integrar
    double a,b;
    uniform_real_distribution<double> unif;
    public:
        Integral(double (*_fun)(double),double min, double max):fun(_fun),gen(rd()),unif(min,max),a(min),b(max){  // Mi puntero a función que es fun (es un atributo que definimos arriba) le pasamos el _fun, y a y b le pasamos tanto min como max. También aquí inicializo la función uniforme (unif) para que me genere valores entre el min y el max, y a su vez, también instancio el generador con la semilla
        }

        virtual double integrar(int n){ // n es la cantidad de nuúmeros aleatorios 
            //https://es.wikipedia.org/wiki/Integraci%C3%B3n_de_Monte_Carlo#Algoritmo
            double Ef=0;
            for(int i=0;i<n;i++)
            {
              Ef+=fun(unif(gen));  
            }
            return ((b-a)/n)*Ef;
        }
};

int main()
{
    Integral inte(sin,0,2*M_PI);
    cout<<inte.integrar(100000)<<endl;
    return 0;
}
