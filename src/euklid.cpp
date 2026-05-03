#include <cmath>
#include <vector>
#include "diofantiskLigningUrgh.hpp"
#include "euklid.hpp"
#include <iostream>

int euklid(int a, int b) {
    if (b == 0) return a;
    return abs(euklid(b, a % b));
}

omvEuklid omvendtEuklid(long long a, long long b) {
    if (b == 0) return {a, 1, 0};

    omvEuklid r = omvendtEuklid(b, a % b);

    long long x = r.y;
    long long y = r.x - (a / b) * r.y;

    return {r.gcd, x, y};
}

std::ostream& operator<<(std::ostream& os, const omvEuklid& r) {
    os << "gcd=" << r.gcd << std::endl << ", x=" << r.x << std::endl << ", y=" << r.y;
    return os;
}