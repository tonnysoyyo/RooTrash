#include<iostream>
#include <limits>       // std::numeric_limits
using namespace std;

void print(int *p,int n){
    cout<<"[";
    for(int i=0;i<n;i++){
        cout<<p[i]<<" ";
    } 
    cout<<"]"<<endl;
}
/*
void llenar_matriz(int **m,int n,int m, int valor){
    for(int i=0;i<n;i++){
        for(int j=0;)
    }
}
*/
int main(){
    int *p;   
    //caso 1 segfault, la posicioón 100 del vertor p no existe
    //cout<<p[100]<<endl;

    // caso 2 liberar p sin haber sido asignado
    //delete p;

    p=new int[2]; // Creo un arreglo de dos elementos
    p[0] = 1;
    p[1] = 1;
    int *t=p;
    print(p,2);
    print(t,2);
    cout<<p<<endl<<t<<endl;
    delete p;
    //delete t; // ¿qué va a pasar?
    /* Pasaría ese error de doble eliminación (double free), pues ya elimine la dirección de 
    memoria al eliminar p. 
    Si por ejemplo lo que hacemos es primero definir *t = p+1 y eliminar t y luego p, me va a
    salir un error pues el compilador detecta cuál es la dirección de memoria original, y debo
    es eliminar dicha dirección. */

    //para este ejemplo vamos a asignar mas memoria de la disponible
    // Para esto lo que le pido es al computador el entero más grande que tenga
    //unsigned long int max = std::numeric_limits<unsigned long int>::max();
    //unsigned  int max = std::numeric_limits<unsigned int>::max();
    
    unsigned  int max = 5;
    cout<<max<<endl;
    int **m;
    m=new int*[max];
    for(auto i=0;i<max;i++){
        m[i]=new int[max];  //ojo al correr este código te va  a bloquear el pc
    }
    return 0;
}