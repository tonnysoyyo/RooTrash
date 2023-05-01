#include<iostream>
using namespace std;

void print(int *p,int n){
    cout<<"[";
    for(int i=0;i<n;i++){
        cout<<p[i]<<" ";
    } 
    cout<<"]"<<endl;
}
void suma(int *sum,int *v1, int *v2, int n){
    for(int i=0;i<n;i++)
    {
        *(sum + i) = *(v1 + i) + *(v2 + i);
    }
}
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int* p = arr; // p apunta al primer elemento de arr
    cout<<*(p + 2)<<endl; /* Le estoy diciendo al puntero que me de el valor de la dirección
    de memoria movida dos veces a la derecha. En este caso, arroja 3 */
    cout<<p<<endl;
    cout<<p+2<<endl;
    /* Esto último me arrojo: 0x7ffe53ef7320 y 0x7ffe53ef7328, lo cual tiene sentido, ya que
    el entero tiene 4 bytes, y se me desplazó a la derecha 2 enteros, es decir, sumó 8 bytes 
    en total */

    int* q = p + 2; // q apunta al tercer elemento de arr (p + 2)
    int* r = q - 1; // r apunta al segundo elemento de arr (q - 1)
    cout<<q[0]<<endl;
    cout<<r[0]<<endl;
    cout<<*(p + 4)<<endl;
    q = p;
    int *s=new int[5];
    suma(s,p,q,5);
    print(s,5);
    delete s;
    return 0;
}