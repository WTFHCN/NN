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
            dx.resize(netCnt);
            X.resize(netCnt);
            W.resize(netCnt);
            B.resize(netCnt);
        }
        void BP::init()
        {

            for (int i = 0; i < netCnt; i++)
            {
                if (i)
                    W[i] = Matrix<double>(layCnt[i], layCnt[i - 1], 2);
                X[i] = Matrix<double>(layCnt[i], 1, 2);
                dx[i] = Matrix<double>(layCnt[i], 1, 2);
            }
        }
        void BP::forwardPropagation(const Matrix<double> input)
        {

            if (input.row != layCnt[0])
            {
                cout << "输入维度不相同" << endl;
                return;
            }
            X[netCnt - 1] = input;
            for (int t = 1; t < netCnt; t++)
            {
                X[t] = W[t] * X[t - 1];
                for (int j = 0; j < X[t].row; j++)
                    X[t].a[j][0] = Sigmoid::Derivative_Y(B[t].a[j][0] + X[t].a[j][0]);
            }
        }
        void BP::backPropagation(const Matrix<double> output)
        {
            if (output.row != layCnt.back())
            {
                cout << "输出维度不相同" << endl;
                return;
            }
            int N = layCnt.back();
            double sum = 0;
            for (int i = 0; i < dx.back().row; i++)
                sum += (X.back().a[i][0] - output.a[i][0]) * (X.back().a[i][0] - output.a[i][0]);
            cout << "loss : " << sum / (2 * N) << endl;
            for (int i = 0; i < dx.back().row; i++)
                dx[netCnt - 1].a[i][0] = 2 * (X.back().a[i][0] - output.a[i][0]);
            for (int t = netCnt - 1; t; t--)
            {
                for (int i = 0; i < dx[t].row; i++)
                {
                    dx[t].a[i][0] *= Sigmoid::Derivative_Y(X[t].a[i][0]);
                    B[t].a[i][0] -= BATCH_SIZE * dx[t].a[i][0];
                }
                // dx[t - 1] = dx[t].val * w[t].rev();
                for (int i = 0; i < W[t].col; i++)
                {
                    dx[t - 1].a[i][0] = 0;
                    for (int j = 0; j < W[t].row; j++)
                        dx[t - 1].a[i][0] += dx[t].a[j][0] * W[t].a[j][i];
                }
                for (int i = 0; i < W[t].row; i++)
                    for (int j = 0; j < W[t].col; j++)
                        W[t].a[i][j] -= BATCH_SIZE * dx[t].a[i][0] * X[t - 1].a[j][0];
            }
        }
        void BP::train(vector<Matrix<double>> input, vector<Matrix<double>> output)
        {
            for (int i = 0; i < input.size(); i++)
            {
                forwardPropagation(input[i]);
                backPropagation(output[i]);
            }
        }
    }

}