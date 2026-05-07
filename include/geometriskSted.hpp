#pragma once
#include <iostream>
#include <cmath>

struct Pungt {
    double x,y;

    double distanse(const Pungt& p) const;
}; //Pungt er en struct der en Pungt har en x verdi, y verdi og kan bruke metoden (funksjonen) distanse
bool erPaaSirkel(Pungt p, Pungt midt, double len);
bool erPaaMidtnormal(Pungt p, Pungt a, Pungt b);
bool erPaaLinje(Pungt a, Pungt b, Pungt p);
std::ostream& operator<<(std::ostream& os, const Pungt& p);