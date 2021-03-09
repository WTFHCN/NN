import torch
import torch.nn as nn
import torch.utils.data as Data
import torchvision      # 数据库模块
import matplotlib.pyplot as plt

train_data = torchvision.datasets.MNIST(
    root='./data',    # 保存或者提取位置
    train=True,  # this is training data
    transform=torchvision.transforms.ToTensor(),    # 转换 PIL.Image or numpy.ndarray 成
                                                    # torch.FloatTensor (C x H x W), 训练的时候 normalize 成 [0.0, 1.0] 区间
    download=False,          # 没下载就下载, 下载了就不用再下了
)

print(train_data.train_data.size())
print(train_data.train_labels.size())
for i in range(0, 10):
    plt.imshow(train_data.train_data[i].numpy(), cmap='gray')
    plt.show()
