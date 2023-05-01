#include<Planet.h>

int main()
{
    double pos[]={1,1,1};
    //Planet  p(pos,0); esto no se puede porque la clase es virtual pura -> Lo que debemos hacer es heredar esta clase para poder implementar los métodos virtuales
    Earth e(pos);
    cout<<"num lunas = "<<e.numSatellites()<<endl;
    return 0;
}