#include <iostream>

using namespace std;

class Tiempo{
    private:
        int hora, min, seg;
    public:
        Tiempo(int,int,int);
        Tiempo(long int);
        void mostrarTiempo();
};

Tiempo::Tiempo(int _hora, int _min, int _seg){
    this->hora = _hora;
    this->min = _min;
    this->seg = _seg;
}

Tiempo::Tiempo(long int _seg){

    this->seg = _seg%60;

    long int min_ = _seg/60;
    this->min = (min_)%60;

    this->hora = min_/60;
}

void Tiempo::mostrarTiempo(){
    cout << "Horas: " << hora << " Minutos: " << min << " Segundos: " << seg << endl;
}

int main(){

    Tiempo time1(1,24,54);
    Tiempo time2(67004);

    time1.mostrarTiempo();
    time2.mostrarTiempo();
    
    return 0;
}