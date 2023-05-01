#include<iostream>
#include<string>  // Esta es una clase que me permite usar cadenas de caracteres sin tener que preocuparme por el puntero

using namespace std;

string mensaje="mensaje global";  // mensaje es un objeto de la clase string

class Saludo
{
    private:
    string mensaje;
    
    public:
    Saludo(string mensaje)
    {
        this->mensaje = mensaje;
        cout<<"Constructor llamado"<<endl;
    }

    ~Saludo(){
        cout<<"Destructor llamado"<<endl;
    }

    void saludar()
    {
        cout<<::mensaje<<endl;  // Los 4 puntos hacen referencia a que está por fuera de la clase
        cout<<mensaje<<endl;
        // Note que con lo anterior estoy accediendo al mensaje global primero y al mensaje instanciado en la clase en segundo lugar
    }
};

int main()
{
    Saludo s("hola clase"); // Aquí estoy instanciando la clase
    s.saludar();
    // cout<<s.mensaje<<endl; // mensaje es privado, no puedo acceder desde aquí al atributo, sólo a lo público, por lo cual saldría un error. Si es protected también saldría un error, ya que protected es private básicamente a no ser que herede la clase, ahí sería ya un atributo público.
    return 0;

}