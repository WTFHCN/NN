#include "base.h"
#include "common/DataHelper.h"
#include "math/Matrix.h"
#include "common/Activation.h"
#include "network/BP.h"
using namespace std;

DEFINE_int32(testNum, 0, "test num");
DEFINE_int32(trainNum, 0, "train num");
DEFINE_string(modelSavePath, "model/BPTest", "modelSavePath");
DEFINE_string(modelLoadPath, "model/BPTest", "modelSavePath");

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
void BPtrain(HCN::NetWork::BPNet &test, int trainNum)
{
    HCN::DataHelper mnistTrainData;
    string trainImagesPath = "/Users/nacn/Desktop/BP Network/data/MNIST/raw/train-images-idx3-ubyte";
    string trainLabelsPath = "/Users/nacn/Desktop/BP Network/data/MNIST/raw/train-labels-idx1-ubyte";
    LOG(INFO) << "begin to prepare " << endl;
    mnistTrainData.read_Mnist(trainImagesPath, trainLabelsPath);

    // prepareData(mnistTrainData.input, mnistTrainData.output);
    LOG(INFO) << "prepare is OK" << endl;

    LOG(INFO) << "init is OK" << endl;
    auto start = clock();

    LOG(INFO) << "begin to train" << endl;

    test.Train(mnistTrainData.input, mnistTrainData.output, trainNum);
    LOG(INFO) << "train is OK" << endl;
    auto end = clock();
    LOG(INFO) << "cost :" << (double)(end - start) / CLOCKS_PER_SEC << endl;
}
void BPtest(HCN::NetWork::BPNet &test, int testNum)
{
    HCN::DataHelper mnistTestData;
    string testImagesPath = "/Users/nacn/Desktop/BP Network/data/MNIST/raw/t10k-images-idx3-ubyte";
    string testLabelsPath = "/Users/nacn/Desktop/BP Network/data/MNIST/raw/t10k-labels-idx1-ubyte";

    LOG(INFO) << "begin to prepare " << endl;

    mnistTestData.read_Mnist(testImagesPath, testLabelsPath);

    auto start = clock();
    test.TestMnist(mnistTestData.input, mnistTestData.output, mnistTestData.imageRow, mnistTestData.imageCol, testNum);
    auto end = clock();
    LOG(INFO) << "cost :" << (double)(end - start) / CLOCKS_PER_SEC << endl;
}
void BPwork()
{
    vector<int> level = {28 * 28, 196, 49, 10};
    HCN::NetWork::BPNet test(level);
    test.init();

    test.Load(FLAGS_modelLoadPath);
    BPtrain(test, FLAGS_trainNum);

    BPtest(test, FLAGS_testNum);

    test.Save(FLAGS_modelLoadPath);
    test.TestImage("../1.txt");

    //test.test();
}
// extern "C"
// {
//     int Forpy();
// }
// int Forpy()
// {
//     vector<int> level = {28 * 28, 196, 49, 10};
//     HCN::NetWork::BPNet test(level);
//     test.init();
//     test.Load(FLAGS_modelLoadPath);
//     return test.TestImage("../1.txt");
// }

int main(int argc, char **argv)
{
    gflags::ParseCommandLineFlags(&argc, &argv, true);
    google::InitGoogleLogging(argv[0]);
    FLAGS_log_dir = "./log";
    BPwork();
}
