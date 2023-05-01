#include<iostream>
using namespace std;
void test(int a)   /* Cuando yo hago int a lo que estoy haciendo es tomar el valor de la variable que me pasan, hacerle una copia y dicho valor usarlo ahí.
Sin embargo, si yo lo que quiero es modificar el valor de a debo usar punteros.
*/
{
    a++;
    cout<<a<<endl;
}
void incremento_ptr(int *p)  // Aquí le estoy diciendo, cójame el valor de la direacción de memoria e incremente uno
{
    (*p)++;
}
void incremento_ref(int &n)  /* Con el & le estoy pidiend la referencia, es decir, aquí no le
voy a pasar un puntero, sino una variable normal
*/
{
    n++; //como es referencia no necesito la sintaxis de aritmética de punteros
}
int main()
{
    int num;
    //int *p = new int;
    int *p;
    p = new int; // Asigno la variable puntero 
    (*p) = 321;  // Le doy el valor a puntero
    cout<<"dirreccón de memeria = "<<p<<endl;
    cout<<"valor = "<<*p<<endl;  

    num = 2;
    test(num);
    cout<<num<<endl; /* Note que a pesar de que a num lo metí a la función, su valor sigue
    siendo 2, no 3 como es lo que saldría en la función
    */

    p = &num; // le digo que p es igual a la dirección de memoria donde tengo num
    num=4;
    cout<<"dirección de memoria = "<<p<<endl;
    cout<<"dirección de memoria = "<<&num<<endl;
    cout<<"valor = "<<*p<<endl;
    cout<<"valor = "<<num<<endl;
    // Note que p toma el mismo valor que num porque apuntan a la misma dirección de memoria
    

    incremento_ptr(p);
    /* Aquí también le podría pasar en lugar de p, &num y no habría problema. Si le paso num 
    solo, ahí sí errores*/
    cout<<"valor (p) = "<<*p<<endl; 
    cout<<"valor (num) = "<<num<<endl;
    /* Note que a diferencia de lo que pasaba con test, aquí estoy modificando la dirección 
    de memoria, por lo que lo que haga dentro de la función debe modificar a la variable con
    la misma dirección de memoria que estuviese afuera de la función
    A su vez, lo mismo pasará con num porque apuntan a la misma dirección de memoria
    */

    incremento_ref(num); /* se debe incrementar num afuera también ya que cogí la referencia de 
    num, no hice una copia ni nada así*/
    cout<<"valor (p) = "<<*p<<endl;
    cout<<"valor (num) = "<<num<<endl;

    delete p;
    p=nullptr;
    cout<<"dirreccón de memeria (p) = "<<p<<endl;
    
    return 0;
}