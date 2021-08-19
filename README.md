# BPNetwork
一个简单的全连接神经网络

## 需要环境
### C++
+ glog
+ gflags
### Python
+ matplotlib
+ PIL
+ ctypes

## 下载数据
手写数字官方自己下载
## 搭建
```bash
mkdir build
mkdir log
cd build
cmake ..
make 
cd ..
```
## 使用
```bash
./build/BP_Demo --testNum 100000 --trainNum 1000000 --batchSize 0.1 
```
## 可视化展示
```bash
python show.py
```
