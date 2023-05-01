#ifndef STAR_H
#define STAR_H
#include<Particle.h>

class Star:public Particle  // Note que estoy heredando Particle de manera publica
{

    private:
        double mass;
        string name;
        double temp;

    public:
        Star(double pos[3], double mass,  double temp, string name):Particle(3,pos) // Note que aquí pongo un 3 como dimensión en Particle porque voy a trabajar en R3, pero puedo poner el número que yo desease
        {
            this->mass = mass;
            this->name = name; 
        }

        double getMass(){
            return mass;
        }
        string getName(){
            return name;
        }
        double getTemp(){
            return temp;
        }
};

#endif