#include <vector>
#include <cmath>
    //empty line
bool sjekkPrim(int a) {
    if (a<2) {return false;}
    int maksRot = std::floor(sqrt(a));
    int temp = 2;
    while (temp<=maksRot) {
        if (a%temp==0) {
            return false;
        } else {
            temp++;
        }
    }
    return true;
} //incrementer tall opp til rota, og hvis noen av de er kongruente med null mod(input), returnerer false. hvis loopen avsluttes ved at
  //temp>=maksrot så returnerer den true

std::vector<int> primtallsFaktorisering(int i) {
    int a = i;
    int temp = 2;
    std::vector<int> returnVect;

    while (a > 1) { //for hver gang tallet kan deles på variabelen a, tillegges a i vektoren og fortsetter til det opprinnelige produktet er et primtall
        if (a % temp == 0) {
            returnVect.push_back(temp);
            a /= temp;
        } else {
            temp++;
        }
    }

    return returnVect;
}