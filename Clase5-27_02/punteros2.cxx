#include<iostream>
using namespace std;

void llenar(int *p,int n, int valor){
    /* Si declaro una variable acá, solo es válida acá, en su ámbito de ejecución, luego muere.
    La variable no la podré usar en el main por ejemplo. Lo mismo pasaría si declaro un 
    puntero estático, luego de acá se libera y muere.
    Si yo declaro un puntero dinámico dentro de la función y no lo elimino, entonces cada vez 
    que yo llame a la función estoy gastando una cantidad de memoria absurda y super 
    ineficiente. */
    for(int i=0;i<n;i++){
        p[i]=valor;
    }
}
void print(int *p,int n){
    cout<<"[";
    for(int i=0;i<n;i++){
        cout<<p[i]<<" ";
    } 
    cout<<"]"<<endl;
}
void sumar(int *suma, int *v1, int *v2,int n){
    for(int i=0;i<n;i++){
        suma[i] = v1[i]+v2[i];
    }
}
int main(){ // Tanto p1, como p2, como p3 son arreglos, solo que p2 es estático, y p1 y p3 son dinámicos
    unsigned int num=10;  // El unsigned es porque no puede ser negativo.
    int *p1 = new int[num]; /* creo un arreglo de 10 enteros. Se duce que aloje los elementos
    dinámicamente porque yo no sé qué valor tendrá num, puede ser 100, 10 o 1, y en cualquiera
    de los casos voy a poder alojar los elementos pues estoy poniendo la variable num ahí */
    int p2[] = {1,1,1,1,1,1,1,1,1,1}; // 10 enteros con asignación estática e inicializado 
                                      // con valores en 1, no necesita usarse delete, se borra solo
    /* esta es la forma de inicializar p2, realmente es un *, ya que es un puntero, pero esta
    es la sintaxis de inicialización */
    int *p3 = new int[num];

    // p1, p2 y p3 son arreglos, solo que p1 y p3 son dinámicos y p2 es estático

    llenar(p1,num,2); // Al hacer esto voy a obtener una salida así: [2 2 2 2 2 2 2 2 2 2 ]
    print(p1,num);
    //llenar(p2,num,2); //está inicializado
    print(p2,num);
    sumar(p3,p1,p2,num);
    print(p3,num);

    delete[] p1;  // El [] es porque es un arreglo. Ésta es la sintaxis.
    /* delete[] p2; // no es necesario cuando es estática, ya que el compilador los elimina 
    automáticamente. Si yo trato de borrar p2, me va a salir un error. */
    delete[] p3;
    
    /*
    El p2 no es necesario borrarlo ya que fue inicializado estaticamente, estos el complilador
    los elimina solos
    Si yo lo intentase borrar me saldrá un error.

    Si yo creo un puntero dinámico dentro de una función y no lo elimino, cada que yo llame
    la función estoy almacenando memoria en un puntero de manera innecesaria que nunca se 
    elimina. En cambio, si el puntero hubiese sido declarado estáticamente este se elimina una 
    vez finalice la funcion.

    Buscar qué es el stack y qué es el heap
    */
    return 0;
}