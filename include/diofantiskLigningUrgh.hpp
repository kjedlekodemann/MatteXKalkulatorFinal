#include <iostream>
#include <cmath>
#include "euklid.hpp"

struct Linje {
    long long x0, y0, dx, dy;  // k*dx,k*dy
};
Linje diofantiskLinje(long long a, long long b, long long c);
std::ostream& operator<<(std::ostream& os, const Linje& l);