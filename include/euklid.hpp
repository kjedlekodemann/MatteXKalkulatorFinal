#pragma once
#include <vector>
#include <iostream>
#include <cmath>

int euklid(int a, int b);
struct omvEuklid {
    long long gcd;
    long long x;
    long long y;
};
omvEuklid omvendtEuklid(long long a, long long b);
std::ostream& operator<<(std::ostream& os, const omvEuklid& r); //helt irrelevant, bare for enklere cout statements kan lowk fjernes