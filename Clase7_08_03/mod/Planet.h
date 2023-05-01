#ifndef PLANET_H
#define PLANET_H
#include<Particle.h>

class Planet:public Particle
{

    private:
        double mass;
    public:
        Planet(double pos[3], double mass):Particle(3,pos)
        {
            this->mass = mass;
        }
    
        virtual int numSatellites() = 0; // Aquí estamos definiendo dos métodos virtuales y los estamos igualando a 0, es decir, aquí no le hemos dicho al método qué es lo que debe hacer. Esto lo hacemos para que una clase que herede Planet, me implemente estos dos métodos
        // Esto se llama clase abstracta porque todavía no he definido el comportamiento de los métodos

        virtual bool hasStmosphere() = 0;

};


class Mars:public Planet
{
    public:
        Mars(double pos[3]):Planet(pos,6.4185*10e23)
        {

        }

        int numSatellites()
        {
            return 2;
        }

        virtual bool hasStmosphere()
        {
            return false;
        }

};


class Earth:public Planet
{
    public:
        Earth(double pos[3]):Planet(pos,6.4185*10e23)
        {

        }

        int numSatellites()
        {
            return 1;
        }

        bool hasStmosphere()
        {
            return true;
        }

};

#endif