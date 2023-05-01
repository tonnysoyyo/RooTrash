#include <iostream>

using namespace std;
//Aqui se inicia a definir la clase template
template <class T> class Matrix {
    private:
        T *matrix; //Se define como privado el puntero dinamico que va a almacenar los valores cual lista plana, no se va usar doble puntero.
        int n,m;
        int size;

    public:
        
        Matrix(int n, int m);

        Matrix(const Matrix& v);

        ~Matrix();

        void setValue(int ns, int ms, T value);

        T getValue(int ng, int mg);

        int getN() const;
        int getM() const;

        void print(bool t = false);

        // Sobrecargamos los operadores: =,+,-,+=,-=

        Matrix<T>& operator=(const Matrix<T>& v);

        Matrix<T> operator+(const Matrix<T>& v) const;
        
        Matrix<T> operator-(const Matrix<T>& v) const;

        Matrix<T>& operator+=(const Matrix<T>& v);

        Matrix<T>& operator-=(const Matrix<T>& v);
    
};


template <class T> Matrix<T>::Matrix(int n, int m) : size(n*m) {
    this->n = n;
    this->m = m;
    matrix = new T[n*m];
    for (int i = 0; i < size; i++) {
        matrix[i] = 0.0;
    }
}

template <class T> Matrix<T>::Matrix(const Matrix& v) : size(v.n * v.m) {
    matrix = new T[size];
    for (int i = 0; i < size; i++) {
        matrix[i] = v.matrix[i];
    }
}

template <class T> Matrix<T>::~Matrix(){
    delete[] matrix;
}

template <class T> void Matrix<T>::setValue(int ns, int ms, T value) {
    matrix[(ns*m) + ms] = value;
}

template <class T> T Matrix<T>::getValue(int ng, int mg) {
    return matrix[(ng*m) + mg];
}

template <class T> int Matrix<T>::getN() const {
    return n;
}

template <class T> int Matrix<T>::getM() const {
    return m;
}

template <class T> void Matrix<T>::print(bool t) {
    if (t == false){
        for (int i = 0; i < n ; i++) {

            for (int j = 0; j < m; j++) {
        
                cout <<" "<< matrix[(i*m)+j] <<" ";
            }
            cout<< endl;
        }
    }
    else {
        for (int j = 0; j < m ; j++) {

            for (int i = 0; i < n; i++) {
        
                cout <<" "<< matrix[(i*m)+j] <<" ";
            }
            cout<< endl;
        }
    }
}

template <class T> Matrix<T>& Matrix<T>::operator=(const Matrix<T>& v) {
    if (this != &v) {
        if (this->getN() == v.getN() && this->getM() == v.getM()) {
            delete[] matrix;
            size = v.size;
            matrix = new T[size];
            for (int i = 0; i < size; i++) {
                matrix[i] = v.matrix[i];
            }
            this->n = v.n;
            this->m = v.m;
        }
        else{
            cout << "No tienen la misma dirección mi rey" << endl;
            exit(1);
        }
    }
    return *this;
}

template <class T> Matrix<T> Matrix<T>::operator+(const Matrix<T>& v) const {
    Matrix w(this->getN(),this->getM());
    for (int i = 0; i < size; i++) {
        w.matrix[i] = matrix[i] + v.matrix[i];
    }
    return w;
}

template <class T> Matrix<T> Matrix<T>::operator-(const Matrix<T>& v) const {
    Matrix w(this->getN(),this->getM());
    for (int i = 0; i < size; i++) {
        w.matrix[i] = matrix[i] - v.matrix[i];
    }
    return w;
}

template <class T> Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& v) {
    if (this != &v) {
        if (this->getN() == v.getN() && this->getM() == v.getM()) {
            for (int i = 0; i < size; i++) {
                matrix[i] += v.matrix[i];
            }
        }
        else{
            cout << "No tienen la misma dirección mi rey" << endl;
            exit(1);
        }
    }
    return *this;
}

template <class T> Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& v) {
    if (this != &v) {
        if (this->getN() == v.getN() && this->getM() == v.getM()) {
            for (int i = 0; i < size; i++) {
                matrix[i] -= v.matrix[i];
            }
        }
        else{
            cout << "No tienen la misma dirección mi rey" << endl;
            exit(1);
        }
    }
    return *this;
}

int main() {
    Matrix<int> intMatrix(4, 3);
    intMatrix.setValue(0, 0, 1);
    intMatrix.setValue(0, 1, 2);
    intMatrix.setValue(1, 0, 3);
    intMatrix.setValue(1, 1, 4);
    cout << "Matriz 1" << endl;
    intMatrix.print();
    //cout<<intMatrix.getValue(1,1)<<endl;
    //cout<<intMatrix.getN()<<endl;
    //cout<<intMatrix.getM()<<endl;

    Matrix<int> intMatrix2(4, 3);
    intMatrix2.setValue(0, 0, 5);
    intMatrix2.setValue(0, 1, 6);
    intMatrix2.setValue(1, 0, 7);
    intMatrix2.setValue(1, 1, 8);
    cout << "Matriz 2" << endl;
    intMatrix2.print();

    //cout << "Comparación" << endl;
    //intMatrix = intMatrix2;
    //intMatrix.print();
    //intMatrix2.print();
    cout << "Suma" << endl;
    auto intMatrix3 = intMatrix + intMatrix2;
    intMatrix3.print();

    cout << "Resta" << endl;
    auto intMatrix4 = intMatrix - intMatrix2;
    intMatrix4.print();
/*
    cout << "Suma +=" << endl;
    intMatrix4+=intMatrix2;
    intMatrix4.print();
*/
    cout << "Resta -=" << endl;
    intMatrix4-=intMatrix2;
    intMatrix4.print();

    cout << "Transpuesta" << endl;
    bool t = true;
    intMatrix4.print(t);

    return 0;
}