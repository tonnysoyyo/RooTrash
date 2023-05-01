#include<iostream>
#include<cmath>

using namespace std;

double fun(int* y,int* x, int n)
{   
    for(int i=0;i<n;i++){
        y[i] = x[i];
    }
}

double suma_rienmann(double (*fun)(int*,int*,int), int*y, int* x, int a, int b, int n)
{
    double delta_x = (b-a)/n;
    int tam = sizeof(x) / sizeof(x[0]);
    fun(y,x,n);
    
    if(tam == n){
        double res=0;
        for (int i = 0;i<n;i++){
            res += y[i]*delta_x;
        }
        return res;
    }
    else{
        cout << "Tienes un error con tu n" << endl;
    }
}

int main()
{
    int a = 0;
    int b = 1;
    int n = 1000;
}