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
            std::vector<Matrix<double>> e;
            vector<int> layCnt;
            BP(vector<int> input);
            void init();
            void forwardPropagation();
            void backPropagation();
            void train();
        };
    }
}