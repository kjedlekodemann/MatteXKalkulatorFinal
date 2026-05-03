#include "trekant.hpp"
#include "geometriskSted.hpp"

void Trekant::settSider() {
    ab = a.distanse(b);
    bc = b.distanse(c);
    ca = c.distanse(a);
}