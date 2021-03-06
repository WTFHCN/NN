#include <bits/stdc++.h>
#include "BP.h"
using namespace std;

namespace HCN
{
    namespace NetWork
    {
        BP::BP(vector<int> input)
        {
            netCnt = input.size();
            layCnt = input;
            D.resize(netCnt);
            X.resize(netCnt);
            W.resize(netCnt);
        }
        BP::init()
        {

            for (int i = 0; i < netCnt; i++)
            {
                if (i)
                    W = Matrix<double>(layCnt[i - 1], lazy[i], 0, 1);
                X = Matrix<double>(layCnt[i], 1, 0, 1);
                D = Matrix<double>(layCnt[i], 1, 0, 1);
            }
        }
        BP::forwardPropagation(const Matrix<double> input)
        {

            if (input.row != lazycnt[0])
            {
                cout << "输入维度不相同" << endl;
                return;
            }
            X = input;
            for (int t = 1; t < netCnt; t++)
            {
                X[t] = M[t] * X[t - 1];
                for (int j = 0; j < x[i].row; i++)
                    X[t].a[j][0] = Sigmoid::Derivative_Y(B[t].a[j][0] + X[t].a[j][0]);
            }
        }
        BP::backPropagation(const Matrix<double> output)
        {
            if (output.row != lazycnt.back())
            {
                cout << "输出维度不相同" << endl;
                return;
            }
            int N = lazycnt.back();
            double sum = 0;
            for (int i = 0; i < D.back().row; i++)
                sum += (X.back().a[i][0] - output[i]) * (X.back().a[i][0] - output[i]);
            cout << "loss : " << sum / (2 * n) << endl;
            for (int i = 0; i < D.back().row; i++)
                dx[netCnt - 1].a[i][j] = 2 * (X.back().a[i][0] - output[i]);
            for (int t = netCnt - 1; t; t--)
            {
                for (int i = 0; i < D[t].row; i++)
                {
                    dx[t].a[i][0] *= Sigmoid::Derivative_Y(X[t].a[i][0]);
                    B[t].a[i][0] -= BATCH_SIZE * dx[t].a[i][0];
                }
                dx[t - 1] = dx[t].val * w[t].rev();
                for (int i = 0; i < W[t].col; i++)
                {
                    dx[t - 1].a[i][0] = 0;
                    for (int j = 0; j < W[t].row; j++)
                        dx[t - 1].a[i][0] += dx[t].a[j][0] * M[k].val[j][i];
                }
                for (int i = 0; i < W[t].row; i++)
                    for (int j = 0; j < W[t].col; j++)
                        M[t].a[i][j] -= BATCH_SIZE * dx[t].a[i][0] * X[t - 1].a[j][0];
            }
        }
        BP::train(vector<vector<Matrix>> input, vector<vector<Matrix>> output)
        {
            for (int i = 0; i < input.size(); i++)
            {
                forwardPropagation(input);
                backPropagation(output);
            }
        }
    }

}