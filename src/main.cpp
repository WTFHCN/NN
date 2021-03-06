#include "base.h"

#include "math/Matrix.h"
#include "common/Activation.h"
#include "network/BP.h"

void prepareData(vector<HCN::Matrix<double>> &Input, vector<HCN::Matrix<double>> &Output)
{
    vector<vector<vector<double>>> input(4);
    vector<vector<vector<double>>> output(4);
    input[0] = {{1}, {0}};
    input[1] = {{0}, {1}};
    input[2] = {{0}, {0}};
    input[3] = {{1}, {1}};

    output[0] = {{1}};
    output[1] = {{1}};
    output[2] = {{0}};
    output[3] = {{0}};
    for (int i = 0; i < 4; i++)
    {
        Input[i] = HCN::ToMatrix(input[i]);
        Output[i] = HCN::ToMatrix(output[i]);
    }
}
int main()
{
    HCN::Matrix<double> a(3, 3, 2);

    vector<int> level = {2, 2, 1};
    HCN::NetWork::BPNet test(level);

    vector<HCN::Matrix<double>> Input(4);
    vector<HCN::Matrix<double>> Output(4);
    prepareData(Input, Output);
    cout << "prepare is OK" << endl;
    test.init();
    cout << "init is OK" << endl;
    cout << "begin to train" << endl;
    test.train(Input, Output);
}