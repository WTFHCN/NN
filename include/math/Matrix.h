#ifndef Matrix_H
#define Matrix_H
#include "base.h"
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
        Matrix(){};
        Matrix(int row, int col, int e = 0);
        Matrix(vector<vector<T>> tmp);
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
    Matrix<T>::Matrix(int row, int col, int e) : row(row), col(col)
    {
        a.resize(row, vector<T>(col, 0));
        if (e == 1)
        {
            for (int i = 0; i < min(row, col); i++)
                a[i][i] = 1;
        }
        else if (e == 2)
        {
            srand(time(NULL));
            for (int i = 0; i < row; i++)
                for (int j = 0; j < col; j++)
                    a[i][j] = (rand() % 200 - 100) / 100.0;
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
        assert(col == x.row);
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
    template <class T>
    Matrix<T>::Matrix(vector<vector<T>> tmp)
    {
        row = tmp.size();
        assert(tmp.size() != 0);
        col = tmp[0].size();
        a = tmp;
    }
    template <class T>
    Matrix<T> ToMatrix(vector<vector<T>> tmp)
    {
        Matrix<T> res(tmp);
        return res;
    }

    template <class T>
    Matrix<T>::~Matrix()
    {
    }
};
#endif