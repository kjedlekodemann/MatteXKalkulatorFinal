#include <iostream>
#include <vector>

void clearTerminal() {
#ifdef _WIN32
    std::cout << "\x1B[2J\x1B[H";
#else
    std::cout << "\x1B[2J\x1B[H";
#endif
}
void printVector(const std::vector<int>& v) {
    std::cout << " = [ ";
    for (const auto& x : v) {
        std::cout << x << " ";
    }
    std::cout << "]\n";
}