#pragma once
#include <iostream>
#include <random>
#include <complex>
#include <exception>
using namespace std;

namespace M {
    template<typename T>
    class Matrix {
    private:
        int _rows;
        int _cols;
        T** _data;
    public:
        Matrix() {
            _rows = 1;
            _cols = 1;
            _data = (T**) new T * [_rows];
            _data[0] = (T*)new T[_cols];
            _data[0][0] = 0;
        }

        Matrix(T rows, T cols) {
            _rows = rows;
            _cols = cols;
            _data = (T**) new T * [_rows];
            for (int i = 0; i < _rows; i++) {
                _data[i] = (T*)new T[_cols];
            }
            for (int i = 0; i < _rows; i++) {
                for (int j = 0; j < _cols; j++)
                    _data[i][j] = 0;
            }
        }

        Matrix(int rows, int cols, T data[], int size) {
            _rows = rows;
            _cols = cols;
            _data = (T**) new T * [_rows];
            for (int i = 0; i < _rows; i++) {
                _data[i] = (T*)new T[_cols];
            }
            int k = 0;
            for (int i = 0; i < _rows; i++) {
                for (int j = 0; j < _cols; j++)
                    if (k < size) {
                        _data[i][j] = data[k];
                        k++;
                    }
                    else {
                        _data[i][j] = 0;
                    }
            }
        }

        int get_rows() {
            return _rows;
        }
        int get_cols() {
            return _cols;
        }

        Matrix(const Matrix& a) {
            _rows = a._rows;
            _cols = a._cols;
            _data = (T**) new T * [_rows];
            for (int i = 0; i < _rows; i++) {
                _data[i] = (T*)new T[_cols];
            }
            for (int i = 0; i < _rows; i++) {
                for (int j = 0; j < _cols; j++)
                    _data[i][j] = a._data[i][j];
            }

        }
        T& trace() {
            if (_cols != _rows) {
                throw("Matrix must be quadratic");
            }
            else {
                T trace = 0;
                for (int i = 0; i < _rows; ++i) {
                    trace += _data[i][i];
                }
                return trace;
            }
        }
        T& operator()(const int r_ind, const int c_ind)const {
            return _data[r_ind][c_ind];
        };
        Matrix operator=(const Matrix& a)
        {
            if (_rows > 0)
            {
                for (int i = 0; i < _rows; i++)
                    delete[] _data[i];
            }

            if (_cols > 0)
            {
                delete[] _data;
            }

            _rows = a._rows;
            _cols = a._cols;

            _data = (T**) new T * [_rows];
            for (int i = 0; i < _rows; i++)
                _data[i] = (T*) new T[_cols];

            for (int i = 0; i < _rows; i++)
                for (int j = 0; j < _cols; j++)
                    _data[i][j] = a._data[i][j];
            return *this;
        }

        Matrix& operator+=(const Matrix& a) {

            if (_cols != a._cols || _rows != a._rows) {
                throw ("Sizes of matrix doesnt equal");
            }
            else {
                for (int i = 0; i < _rows; i++)
                    for (int j = 0; j < _cols; j++)
                        _data[i][j] += a._data[i][j];

            }
            return *this;
        }
        Matrix& operator-=(const Matrix& a) {

            if (_cols != a._cols || _rows != a._rows) {
                throw ("Sizes of matrix doesnt equal");
            }
            else {
                for (int i = 0; i < _rows; i++)
                    for (int j = 0; j < _cols; j++)
                        _data[i][j] -= a._data[i][j];

                return *this;
            }
            
        }
       
        friend Matrix operator +(Matrix& a, const Matrix& b) {

            if (a._cols != b._cols || a._rows != b._rows) {
                throw ("Sizes of matrix doesnt equal");
            }
            else {
                Matrix c(a);
                c += b;
                return c;
            }
        }

        friend Matrix operator -(Matrix& a, const Matrix& b) {

            if (a._cols != b._cols || a._rows != b._rows) {
                throw ("Sizes of matrix doesnt equal");
            }
            else {
                Matrix c(a);
                c -= b;
                return c;
            }
        }

         friend Matrix operator *(Matrix&a, T num) {
             Matrix b(a);
            for (int i = 0; i < b._rows; i++)
                for (int j = 0; j < b._cols; j++)
                   b._data[i][j] = b._data[i][j] * num;
            return b;   
         }

         friend Matrix operator /(Matrix& a, T num) {
             if (num == 0) {
                 throw("Division by zero");
             }
             else {
                 Matrix b(a);
                 for (int i = 0; i < b._rows; i++)
                     for (int j = 0; j < b._cols; j++)
                         b._data[i][j] = b._data[i][j] / num;
                 return b;
             }
         }

         friend Matrix operator *(Matrix& a, const Matrix& b) {
             if (a._cols != b._rows) {
                 throw("incorrect matrix");
             }
             else {
                 Matrix c(a._rows, b._cols);

                 for (int i = 0; i < a._rows; ++i)
                 {
                     for (int j = 0; j < b._cols; ++j)
                     {
                         c(i, j) = 0;
                         for (int k = 0; k < a._cols; ++k) {
                             c(i, j) += a(i, k) * b(k, j);
                         }
                     }  
                 } 
                 return c;
             }  
         }

         
        ~Matrix()
        {
            if (_rows > 0)
            {
                for (int i = 0; i < _rows; i++)
                    delete[] _data[i];
            }
            if (_cols > 0)
            {
                delete[] _data;
            }
        }
        

        void fill() {
            for (int i = 0; i < _rows; i++)
            {
                for (int j = 0; j < _cols; j++) {
                    cout << "element[" << i + 1 << "][" << j + 1 << "] is " << endl;
                    cin >> _data[i][j];
                }
            }
        }
        /*void print() {
            for (int i = 0; i < _rows; ++i)
            {
                cout << endl;
                for (int j = 0; j < _cols; ++j)
                {
                    std::cout << _data[i][j] << " \t";
                }
                cout << endl;
            }
        }*/
    }; 
    template<typename T> 
    ostream& operator<<(ostream& stream, Matrix<T>& a) {
        for (int i = 0; i < a.get_rows(); ++i)
        {
            cout << endl;
            for (int j = 0; j < a.get_cols(); ++j)
            {
                std::cout << a(i,j) << " \t";
            }
            cout << endl;
        }
        return stream;
    }
}