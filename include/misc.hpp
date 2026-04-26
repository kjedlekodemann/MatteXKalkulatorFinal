#pragma once
#include <iostream>
#include <vector>

void clearTerminal();
template <typename T>
void printVector(const std::vector<T>& v, const std::string& name = "vec");