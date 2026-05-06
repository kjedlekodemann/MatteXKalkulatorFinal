#include <iostream>
#include <cmath>
#include "euklid.hpp"



struct Linje {
    long long x0, y0, dx, dy;  // k*dx,k*dy
};

Linje diofantiskLinje(long long a, long long b, long long c) {
    omvEuklid base = omvendtEuklid(a, b);

    if (c % base.gcd != 0) {
        std::cout << "Error: Ingen Løsning, c%base.gcd!=0";
        return {0, 0, 0, 0}; // ingen løsning, return bascially bare null
    }

    long long k = c / base.gcd; //finner det summen må ganges med, hvis sfd = 1, k=c

    long long x0 = base.x * k; //ganger
    long long y0 = base.y * k; //ganger igjen

    long long dx = b / base.gcd; //forskjell i x for hver verdi
    long long dy = -a / base.gcd; // same for y

    return {x0, y0, dx, dy}; //return alt :DDDDDDDDDD
}

std::ostream& operator<<(std::ostream& os, const Linje& l) {
    os << "x0=" << l.x0 << std::endl << "y0=" << l.y0 << std::endl << "dx=" << l.dx << std::endl << "dy=" << l.dy; //qol for å returne Linje
    return os;
}