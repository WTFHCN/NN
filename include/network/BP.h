#ifndef _BP
#define _BP
#include "base.h"
#include "common/Activation.h"
#include "math/Matrix.h"

namespace HCN
{
    namespace NetWork
    {
        class BPNet
        {
        public:
            double BATCH_SIZE = 1;
            std::vector<Matrix<double>> dx, X, W, B;
            int netCnt;
            vector<int> layCnt;
            BPNet(){};
            BPNet(vector<int> input);
            void build(vector<int> input);
            void init();
            void forwardPropagation(const Matrix<double> input);
            void backPropagation(const Matrix<double> output);
            void train(vector<Matrix<double>> input, vector<Matrix<double>> output);
        };

    }
}
#endif