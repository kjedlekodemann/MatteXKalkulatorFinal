#include "geometriskSted.hpp"
#include <iostream>

double Pungt::distanse(const Pungt& p) const {
    return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
}
bool erPaaSirkel(Pungt p, Pungt midt, double len) {
    return std::abs(p.distanse(midt) - len) < 1e-9;
}
bool erPaaMidtnormal(Pungt p, Pungt a, Pungt b) {
    return std::abs(p.distanse(a) - p.distanse(b)) < 1e-9;
}
std::ostream& operator<<(std::ostream& os, const Pungt& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}