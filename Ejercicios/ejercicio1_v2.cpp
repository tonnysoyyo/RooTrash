#include <iostream>

using namespace std;

int main()
{
    int n;
    int value;
    int *ptr = &value;

    cout << "Ingrese un valor: ";
    cin >> value;
    cout << "Qué cantidad lo desea aumentar: ";
    cin >> n;

    *ptr+=n;

    //cout << "El resultado final es:" << result << endl;
    cout << "Puntero:" << (*ptr) << endl;
    cout << "Valor:" << value << endl;
    return 0;
}