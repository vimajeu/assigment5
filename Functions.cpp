//
// Created by ліна on 15.07.2026.
//

#include "Functions.h"
#include <iostream>
#include <string>
#include <cmath>

std::string Functions::pow(double a, double b) {
    return std::to_string(std::pow(a, b));
}

std::string Functions::abs(double a) {
    return std::to_string(std::abs(a));
}

std::string Functions::max(double a, double b) {
    return std::to_string(std::max(a, b));
}

std::string Functions::min(double a, double b) {
    return std::to_string(std::min(a, b));
}

std::string Functions::calculate_function(std::string name, std::vector<double> args) {
    if (name == "abs") {
        return abs(args[0]);
    }
    if (name == "pow") {
        return pow(args[0], args[1]);
    }
    if (name == "max") {
        return max(args[0], args[1]);
    }
    return min(args[0], args[1]);
}