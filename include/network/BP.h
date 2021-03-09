#ifndef _BP
#define _BP
#include "base.h"
#include "common/Activation.h"
#include "math/Matrix.h"

namespace HCN
{
    namespace NetWork
    {
        //double LOSS_EPS = 1e-8;
        class BPNet
        {
        public:
            double BATCH_SIZE = 0.7;
            std::vector<Matrix<double>> dx, X, W, B;
            int netCnt;
            vector<int> layCnt;
            BPNet(){};
            BPNet(vector<int> input);
            void build(vector<int> input);
            void init();
            void TestMnist(vector<Matrix<double>> input, vector<Matrix<double>> output, int imageCow, int imageCol, const int testNum);
            void forwardPropagation(const Matrix<double> input, Matrix<double> &outputRes);
            void backPropagation(const Matrix<double> output);
            void Train(vector<Matrix<double>> input, vector<Matrix<double>> output, const int trainNum);
            void Save(string Path);
            void Load(string Path);
            int TestImage(string Path);
        };
    }
}
#endif