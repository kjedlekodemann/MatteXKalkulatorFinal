#include "geometriskSted.hpp"
#include <iostream>

double Pungt::distanse(const Pungt& p) const {
    return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
} //bruker vektorregning for å finne distanse mellom punkt
bool erPaaSirkel(Pungt p, Pungt midt, double len) {
    return std::abs(p.distanse(midt) - len) < 1e-9;
} //hvis punktet p er radius r ifra midten, return true. 1e-9 er der fordi floats e rare og av og t bittelitt større eller mindre enn anslått
bool erPaaMidtnormal(Pungt p, Pungt a, Pungt b) {
    return std::abs(p.distanse(a) - p.distanse(b)) < 1e-9;
} //samme greia men her sjekker den om punktet p er like langt ifra a og b
bool erPaaLinje(Pungt a, Pungt b, Pungt p) {
    return std::abs((b.x - a.x) * (p.y - a.y) - (b.y - a.y) * (p.x - a.x)) < 1e-9;
} // samme greia men LINJE
std::ostream& operator<<(std::ostream& os, const Pungt& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
} //qol for å cout<< "Pungt" class