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
void BPtrain(HCN::NetWork::BPNet &test)
{
    HCN::DataHelper mnistTrainData;
    string trainImagesPath = "/Users/nacn/Desktop/BP Network/data/MNIST/raw/train-images-idx3-ubyte";
    string trainLabelsPath = "/Users/nacn/Desktop/BP Network/data/MNIST/raw/train-labels-idx1-ubyte";
    cout << "begin to prepare " << endl;
    mnistTrainData.read_Mnist(trainImagesPath, trainLabelsPath);

    // prepareData(mnistTrainData.input, mnistTrainData.output);
    cout << "prepare is OK" << endl;
    test.init();
    cout << "init is OK" << endl;
    auto start = clock();

    cout << "begin to train" << endl;

    int trainNum = 10000;
    test.Train(mnistTrainData.input, mnistTrainData.output, trainNum);
    cout << "train is OK" << endl;
    auto end = clock();
    cout << "cost :" << (double)(end - start) / CLOCKS_PER_SEC << endl;
}
void BPtest(HCN::NetWork::BPNet &test)
{
    HCN::DataHelper mnistTestData;
    string testImagesPath = "/Users/nacn/Desktop/BP Network/data/MNIST/raw/t10k-images-idx3-ubyte";
    string testLabelsPath = "/Users/nacn/Desktop/BP Network/data/MNIST/raw/t10k-labels-idx1-ubyte";

    cout << "begin to prepare " << endl;

    mnistTestData.read_Mnist(testImagesPath, testLabelsPath);
    int testNum = 40;
    auto start = clock();
    test.TestMnist(mnistTestData.input, mnistTestData.output, mnistTestData.imageRow, mnistTestData.imageCol, testNum);
    auto end = clock();
    cout << "cost :" << (double)(end - start) / CLOCKS_PER_SEC << endl;
}
void BPwork()
{
    vector<int> level = {28 * 28, 196, 49, 10};
    HCN::NetWork::BPNet test(level);
    BPtrain(test);
    BPtest(test);
    //test.test();
}
int main()
{
    BPwork();
}