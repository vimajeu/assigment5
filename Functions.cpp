//
// Created by ліна on 15.07.2026.
//

#include "Functions.h"
#include <iostream>
#include <string>
#include <cmath>

double Functions::pow(double a, double b) {
    return std::pow(a, b);
}
double Functions::abs(double a) {
    return std::abs(a);
}
double Functions::max(double a, double b) {
    return std::max(a, b);
}
double Functions::min(double a, double b) {
    return std::min(a, b);
}

double Functions::calculate_function(const std::string& name, std::vector<double> args) {
    if (name == "abs") return abs(args[0]);
    if (name == "pow") return pow(args[0], args[1]);
    if (name == "max") return max(args[0], args[1]);
    if (name == "min") return min(args[0], args[1]);
    throw std::invalid_argument("Unknown function: " + name);
}