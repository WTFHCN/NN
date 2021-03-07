#include "base.h"
#include "common/DataHelper.h"
#include "math/Matrix.h"
#include "common/Activation.h"
#include "network/BP.h"

void prepareXorData(vector<HCN::Matrix<double>> &Input, vector<HCN::Matrix<double>> &Output)
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
void BPtest()
{
    vector<int> level = {28 * 28, 196, 49, 10};
    HCN::NetWork::BPNet test(level);
    HCN::DataHelper mnistTrainData;
    string trainImagesPath = "/Users/nacn/Desktop/BP Network/data/MNIST/raw/train-images-idx3-ubyte";
    string trainLabelsPath = "/Users/nacn/Desktop/BP Network/data/MNIST/raw/train-labels-idx1-ubyte";
    cout << "begin to prepare " << endl;
    mnistTrainData.read_Mnist(trainImagesPath, trainLabelsPath);

    // prepareData(mnistTrainData.input, mnistTrainData.output);
    cout << "prepare is OK" << endl;
    test.init();
    cout << "init is OK" << endl;
    cout << "begin to train" << endl;

    int trainNum = 100000;
    test.train(mnistTrainData.input, mnistTrainData.output, trainNum);
    cout << "train is OK" << endl;
    //test.test();
}
int main()
{
    BPtest();
}