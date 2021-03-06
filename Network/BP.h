#include <bits/stdc++.h>
#include "../common/Activation.h"
#include "../math/Matrix.hpp"

namespace HCN
{
    namespace NetWork
    {
        class BP
        {
        public:
            double BATCH_SIZE = 0.5;
            std::vector<Matrix<double>> D, X, W;
            int netCnt;
            vector<int> layCnt;
            BP(vector<int> input);
            void init();
            void forwardPropagation();
            void backPropagation();
            void train();
        };
    }
}