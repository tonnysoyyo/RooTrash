#include "Parcial.h"

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