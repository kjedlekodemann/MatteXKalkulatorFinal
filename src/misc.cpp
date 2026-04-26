#include <iostream>
#include <vector>

void clearTerminal() {
#ifdef _WIN32
    std::cout << "\x1B[2J\x1B[H";
#else
    std::cout << "\x1B[2J\x1B[H";
#endif
}

template <typename T>
void printVector(const std::vector<T>& v, const std::string& name = "vec") {
    std::cout << name << " = [ ";
    for (const auto& x : v) {
        std::cout << x << " ";
    }
    std::cout << "]\n";
}