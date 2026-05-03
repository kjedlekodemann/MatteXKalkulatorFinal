#pragma once
#include <iostream>
#include <cmath>

struct Pungt {
    double x,y;

    double distanse(const Pungt& p) const;
};
bool erPaaSirkel(Pungt p, Pungt midt, double len);
std::ostream& operator<<(std::ostream& os, const Pungt& p);