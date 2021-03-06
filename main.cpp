#include <bits/stdc++.h>
#include "math/Matrix.hpp"
#include "common/Activation.h"

int main()
{
    HCN::Matrix<int> a(3, 3, 1);
    HCN::Matrix<int> b(3, 3, 1);
    auto c = a * b;
    cout << c << endl;
}