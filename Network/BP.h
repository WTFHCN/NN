#ifndef _BP
#define _BP
#include <bits/stdc++.h>
#include "../common/Activation.h"
#include "../math/Matrix.h"

namespace HCN
{
    namespace NetWork
    {
        class BP
        {
        public:
            double BATCH_SIZE = 0.5;
            std::vector<Matrix<double>> dx, X, W, B;
            int netCnt;
            vector<int> layCnt;
            BP(){};
            BP(vector<int> input);
            void init();
            void forwardPropagation(const Matrix<double> input);
            void backPropagation(const Matrix<double> output);
            void train(vector<Matrix<double>> input, vector<Matrix<double>> output);
        };
    }
}
#endif