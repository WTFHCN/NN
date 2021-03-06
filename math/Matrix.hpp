// #ifndef Matrix_H
// #define Matrix_H
#include <bits/stdc++.h>
using namespace std;
namespace HCN
{
    template <class T>
    class Matrix
    {
    private:
        /* data */
    public:
        std::vector<std::vector<T>> a;
        int row, col;
        Matrix(int row, int col, int e = 0, int rd = 0);
        //Matrix<T> rev();
        Matrix<T> operator+(const Matrix<T> &x);
        Matrix<T> operator-(const Matrix<T> &x);
        Matrix<T> operator*(const Matrix<T> &x);
        Matrix<T> operator!();
        // Matrix<T> operator*(const Matrix<T> &x);
        friend ostream &operator<<(ostream &out, const Matrix<T> &res)
        {
            for (int i = 0; i < res.row; i++)
            {
                for (int j = 0; j < res.col; j++)
                {
                    out << res.a[i][j] << " ";
                }
                out << endl;
            }
            return out;
        }
        // void DeBug();
        ~Matrix();
    };

    template <class T>
    Matrix<T>::Matrix(int row, int col, int e, int rd) : row(row), col(col)
    {
        a.resize(row, vector<T>(col, 0));
        if (e)
        {
            for (int i = 0; i < min(row, col); i++)
                a[i][i] = 1;
        }
        if (rd)
        {
            srand(time(NULL));
            for (int i = 0; i < row; i++)
                for (int j = 0; j < col; j++)
                    a[i][j] = rand();
        }
    }
    // template <class T>
    // Matrix<T> Matrix<T>::rev()
    // {
    //     Matrix<T> res(col, row);
    //     for (int i = 0; i < row; i++)
    //     {
    //         for (int j = 0; j < col; j++)
    //             res.a[i][j] = a[j][i];
    //     }
    //     return res;
    // }
    template <class T>
    Matrix<T> Matrix<T>::operator*(const Matrix<T> &x)
    {
        Matrix<T> res(row, x.col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < x.col; j++)
            {
                for (int k = 0; k < col; k++)
                {
                    res.a[i][j] = res.a[i][j] + a[i][k] * x.a[k][j];
                }
            }
        }
        return res;
    }
    template <class T>
    Matrix<T> Matrix<T>::operator+(const Matrix<T> &x)
    {
        Matrix<T> res(row, col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                res.a[i][j] = a[i][j] + x.a[i][j];
            }
        }
        return res;
    }
    template <class T>
    Matrix<T> Matrix<T>::operator-(const Matrix<T> &x)
    {
        Matrix<T> res(row, col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                res.a[i][j] = a[i][j] - x.a[i][j];
            }
        }
        return res;
    }
    template <class T>
    Matrix<T> Matrix<T>::operator!()
    {
        Matrix<T> res(col, row);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                res.a[i][j] = a[j][i];
            }
        }
        return res;
    }
    // template <class T>
    // void Matrix<T>::DeBug()
    // {
    //     for (int i = 0; i < row; i++)
    //     {
    //         for (int j = 0; j < col; j++)
    //         {
    //             cout << a[i][j] << " ";
    //         }
    //         cout << endl;
    //     }
    // }

    template <class T>
    Matrix<T>::~Matrix()
    {
    }
};
// #endif