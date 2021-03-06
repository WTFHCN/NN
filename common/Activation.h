#include <bits/stdc++.h>

namespace HCN
{
    namespace Sigmoid
    {
        template <typename T>
        T Formula(T x)
        {
            return 1.00 / (1 + exp(-x));
        }
        template <typename T>
        T Derivative_X(T x)
        {
            return Formula(x) * (1 - Formula(x));
        }
        template <typename T>
        T Derivative_Y(T y)
        {
            return y * (1 - y);
        }
    }
    namespace Tanh
    {
        template <typename T>
        T Formula(T x)
        {
            return (exp(x) - exp(-x)) / (exp(x) + exp(-x));
        }
        template <typename T>
        T Derivative_X(T x)
        {
            return 1 - Formula(x) * Formula(x);
        }
        template <typename T>
        T Derivative_Y(T y)
        {
            return 1 - y * y;
        }
    }
    namespace Relu
    {
        template <typename T>
        T Formula(T x)
        {
            return max((T)0, x);
        }
        template <typename T>
        T Derivative_X(T x)
        {
            assert(x != 0);
            return x > 0 ? 1 : 0;
        }
        template <typename T>
        T Derivative_Y(T y)
        {
            return y > 0 ? 1 : 0;
        }
    }
}