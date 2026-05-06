#include <cmath>
#include <vector>
#include "diofantiskLigningUrgh.hpp"
#include "euklid.hpp"
#include <iostream>

int euklid(int a, int b) {
    if (b == 0) return a;
    return abs(euklid(b, a % b));
} //bruker recursion for å finne sfd, hvis b = 0, så er a sfd, ellers tar den euklid() igjen med b og resten mellom a%b

omvEuklid omvendtEuklid(long long a, long long b) {
    if (b == 0) return {a, 1, 0};

    omvEuklid r = omvendtEuklid(b, a % b); //rest lolol

    long long x = r.y; //long long er større datatype, kan bli større tall
    long long y = r.x - (a / b) * r.y;

    return {r.gcd, x, y}; // returner sfd,  x verdi og  y verdi
}

std::ostream& operator<<(std::ostream& os, const omvEuklid& r) {
    os << "gcd=" << r.gcd << std::endl << ", x=" << r.x << std::endl << ", y=" << r.y;
    return os;
} //qol for å cout<< struct "omvEuklid"