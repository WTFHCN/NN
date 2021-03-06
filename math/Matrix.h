#ifndef Matrix_H
#define Matrix_H
#include <bits/stdc++.h>

namespace HCN
{
    template <class T>
    class Matrix
    {
    private:
        /* data */
        std::vector<std::vector<T>> a;

    public:
        int row, col;
        Matrix(int row, int col, int e = 0);
        Matrix<T> operator+(const Matrix<T> &x);
        Matrix<T> operator-(const Matrix<T> &x);
        Matrix<T> operator*(const Matrix<T> &x);
        Matrix<T> operator!();
        // Matrix<T> operator*(const Matrix<T> &x);
        //friend ostream &operator<<(ostream &, const Matrix<T> &);
        ~Matrix();
    };
};
#endif