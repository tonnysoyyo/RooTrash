#include<iostream>
#include<cmath>

using namespace std;

class Particle {
private:
    double *position;
    int dim;
protected:
    // La función copy a continuación es para hacer la copia de la información de los punteros.
    void copy(double *posI, double *posO, int dim){ //se podría usar  std::memcpy
        for(int i=0; i<dim; i++){
            posO[i] = posI[i];
        }
    }    
public:
    Particle(int dim, double *position) {
        this->dim = dim;
        this->position = new double[dim];
        copy(position,this->position,dim);
        /* Si yo en lugar de hacer esto:

        this->position = new double[dim];
        copy(position,this->position,dim);
        
        hago this->position = position;
        voy a tener un problema pues el puntero de mi clase va a quedar con la dirección de memoria de un puntero afuera, por lo que me quedo sin control del objeto, ya que si modifican el de afuera o lo borran, el posición de adentro que invalido. Además, cuanod se llame el destructor, una cosa que puede pasar, ya que tienen la misma dirección de memoria es que me elimine el puntero de afuera.
        */
    }

    Particle(const Particle &p){ // Aquí cree otro constructor, pero en este caso p es un escalar objeto, por eso, por ejemplo, para acceder a la posición y la dimensión usamos el . y no la ->
       dim = p.dim;
       position=new double[dim];
       copy(p.position, position,dim);
    }

    ~Particle(){
        delete[] position;
    }
    
    void print(){
        for(int i=0;i<dim;i++){
        cout<<position[i]<<" ";
        }
        cout<<endl;
    }

    int getDim(){
        return dim;
    }
    // A diferencia de Pisition, yo no puedo crear un metodo que sea setDim, ya que es un atributo que se mantiene fijo a lo largo de la clase, y si cambio la dimensíón me toca crear un arreglo nuevo y de dónde voy a obtener la información de la posición de un arreglo con nueva dimensión

    double getPosition(int i){
        if(i>dim) // Con este if chequeo que el usuario no se vaya a pasar con la dimensión de la posición
        {
            cout<<"ERROR: se trata de acceder a una posición mayor que la dimensión"<<endl;
            exit(1); //salida de error
        }
        return position[i]; // Al hacer este método nótese que estoy protegiendo el puntero, ya que no le brindo el puntero al usuario en ningún momento
    }
    void setPosition(int i, double value){
        if(i>dim)
        {
            cout<<"ERROR: se trata de acceder a una posición mayor que la dimensión"<<endl;
            exit(1); //salida de error
        }
        position[i]=value; // Con esto estoy cambiando el valor en alguna posición deseada por el usuario
    }

    double distance(Particle p)
    {
        if(dim != p.getDim()) // chequeamos que las direcciones sean iguales
        {
            cout<<"ERROR:no se puede calcular la distancia entre dos partículas de diferente dimensión"<<endl;
            exit(1); //salida de error
        }
        double sum = 0;
        for(int i=0;i<dim;i++)
        {
            sum+=(position[i]+p.getPosition(i))*(position[i]+p.getPosition(i));
        }
        return sqrt(sum);
    }

    double distance(Particle *p) // Polimorfismo -> métodos que se llaman igual, pero reciben argumentos diferentes
    {
        if(dim != p->getDim())
        {
            cout<<"ERROR:no se puede calcular la distancia entre dos partículas de diferente dimensión"<<endl;
            exit(1); //salida de error
        }
        double sum = 0;
        for(int i=0;i<dim;i++)
        {
            sum+=(position[i]+p->getPosition(i))*(position[i]+p->getPosition(i));
        }
        return sqrt(sum);        
    }
    // En este último método hay un error ya que hay que chequear que el puntero p no sea vacío
    // Respecto a estos dos últimos métodos donde se ve el polimorfismo, la clase va a saber cuál método usar por la naturaleza del objeto que le pasemos como argumento, ya que si es puntero usa el último y si es escalar usa el otro.
    /* Otro detalle importante, es que me pude haber ahorrado líneas de código escribiendo estos dos métodos uno en términos del otro y viceversa. Así:
    
    double distance(Particle p)
    {
        return distance(&p);
    }

    double distance(Particle *p)
    {
        if(dim != p->getDim())
        {
            cout<<"ERROR:no se puede calcular la distancia entre dos partículas de diferente dimensión"<<endl;
            exit(1); //salida de error
        }
        double sum = 0;
        for(int i=0;i<dim;i++)
        {
            sum+=(position[i]+p->getPosition(i))*(position[i]+p->getPosition(i));
        }
        return sqrt(sum);        
    }

    Con lo anterior, note que estoy volviendo el p que entre en el primer método, un puntero mediante el & y así lo puedo meter en el segundo método

    Si al contrario, lo que queremos es hacer que el segundo método quede en función del primero, el segundo debe estar escrito así:
    
    double distance(Particle *p)
    {
        return distance(*(p));        
    }

    */
};

int main()
{   
    // Aqui son escalares
    double pos1[]={0,0};
    double pos2[]={1,1};
    Particle p1(2,pos1);
    Particle p2(2,pos2);
    p1.print();
    p2.print();
    cout<<"la distancia entre p1 y p2 es "<<p1.distance(p2)<<endl;
    //OJO A ESTO
    //p1=p2; // aún no sobrecargamos operadores, comportamiento indefinido o error de compilación
    //p1.print();
    //p2.print();
    // Si corremos las tres últimas líneas de código va a salir un double free corruption, interpretamos en clase que era porque igualamos los dos punteros con la misma dirección de memoria y al llamar el destructor está borrando dos veces la misma dirección.

    // Aquí son punteros
    auto pp1=new Particle(2,pos1); /* auto es una palabra clave del lenguaje que me permite definir variables en el momento de instanciación y asignación. Aquí lo que está interpretanod es que como estoy creando una nueva partícula el pp1 es partícula también, es decir, en este caso reemplaza el Particle y sería sin el auto así:
    Particle *pp1=new Particle(2,pos1);
    */
    auto pp2=new Particle(2,pos2);
    pp1->print(); //nótese que cuando es puntero los métodos se llaman con el operador ->
    pp2->print();
    cout<<"la distancia entre pp1 y pp2 es "<<pp1->distance(*pp2)<<endl; //podemos pasar el valor del puntero por que tenemos copy contructor, si lo comentamos no funciona
    cout<<"la distancia entre pp1 y pp2 es "<<pp1->distance(pp2)<<endl; //este lo podemos usar, pasando el puntero directamente por que tenemos sobrecargado el método distance (polimosfismo)

    //Este caso ya lo estudiamos
    pp1=pp2; // ¿qué pasa aquí? -> Al hacer esto no va a salir ningún error pero va a haber una dirección de memoria de una partícula que se va a perder y no vamos a poder recuperarla
    pp2->print();

    Particle p3(p2); //copy constructor
    p3.print();
    p2.print();
    delete pp1;
    //delete pp2; //arriba asigne pp2 a pp1, no se puede hacer una libraciṕn doble, saldría un double free corruption
    return 0;
}