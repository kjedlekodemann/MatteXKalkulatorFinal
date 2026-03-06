#include <iostream>

int maxPrim(int i) {
    int temp = 0;
    while ((temp*temp)<i) {
        temp++;
    }
    return temp;
}