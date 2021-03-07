
#include "base.h"
#include "common/Activation.h"
#include "network/BP.h"
using namespace std;

namespace HCN
{
    namespace NetWork
    {
        BPNet::BPNet(vector<int> input)
        {

            netCnt = input.size();
            layCnt = input;
            dx.resize(netCnt);
            X.resize(netCnt);
            W.resize(netCnt);
            B.resize(netCnt);
        }

        void BPNet::build(vector<int> input)
        {
            netCnt = input.size();
            layCnt = input;
            dx.resize(netCnt);
            X.resize(netCnt);
            W.resize(netCnt);
            B.resize(netCnt);
        }
        void BPNet::init()
        {

            for (int i = 0; i < netCnt; i++)
            {
                if (i)
                    W[i] = Matrix<double>(layCnt[i], layCnt[i - 1], 2);
                X[i] = Matrix<double>(layCnt[i], 1, 2);
                dx[i] = Matrix<double>(layCnt[i], 1, 2);
                B[i] = Matrix<double>(layCnt[i], 1, 2);
            }
        }
        void BPNet::forwardPropagation(const Matrix<double> input, Matrix<double> &outputRes)
        {

            if (input.row != layCnt[0])
            {
                cout << "输入维度不相同" << endl;
                return;
            }
            X[0] = input;
            for (int t = 1; t < netCnt; t++)
            {
                X[t] = W[t] * X[t - 1];
                for (int j = 0; j < X[t].row; j++)
                {
                    X[t].a[j][0] = Sigmoid::Formula(B[t].a[j][0] + X[t].a[j][0]);
                }
            }
            outputRes = X[netCnt - 1];
        }
        void BPNet::backPropagation(const Matrix<double> output)
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
            cout << "loss : " << setprecision(10) << sum / (2 * N) << endl;
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
        void BPNet::train(vector<Matrix<double>> input, vector<Matrix<double>> output, const int trainNum)
        {
            for (int t = 0; t < trainNum; t++)
            {
                // cout << t << " "
                //      << "training" << endl;
                for (int i = 0; i < input.size(); i++)
                {
                    Matrix<double> outputRes;
                    forwardPropagation(input[i], outputRes);

                    backPropagation(output[i]);
                }
            }
        }
    }

}
