#include <iostream>

using namespace std;

//int *integer;
int n = 0;

int incremento_ptr(int &p, int n)
{
    //int result = (*p)+n;
    return p+n;
}

int main()
{
    int *integer;
    integer = new int;
    (*integer) = 0;
    cout << "Ingrese un valor: ";
    cin >> *integer;
    cout << "Qué cantidad lo desea aumentar: ";
    cin >> n;
    int result = incremento_ptr(*integer, n);
    cout << "El resultado final es:" << result << endl;
    cout << "Puntero:" << (*integer) << endl;
    return 0;
}