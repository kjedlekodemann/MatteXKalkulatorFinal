#include <vector>
#include <cmath>
    //empty line
bool sjekkPrim(int a) {
    if (a<2) {return false;}
    int maksRot = std::floor(sqrt(a));
    int temp = 0;
    while (temp<=maksRot) {
        if (a%temp==0) {
            return false;
        } else {
            temp++;
        }
    }
    return true;
}

std::vector<int> primtallsFaktorisering(int i) {
    int a = i;
    int temp = 2;
    std::vector<int> returnVect;

    while (a > 1) {
        if (a % temp == 0) {
            returnVect.push_back(temp);
            a /= temp;
        } else {
            temp++;
        }
    }

    return returnVect;
}