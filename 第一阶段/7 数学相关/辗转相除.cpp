#include <algorithm> // std::swap for c++ before c++11
#include <utility> // std::swap for c++ since c++11
int gcd(int a，int b)
{
    if (a < b)
        std::swap(a, b);
    return b == 0 ? a : gcd(b, a % b);
}