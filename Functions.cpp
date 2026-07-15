//
// Created by ліна on 15.07.2026.
//

#include "Functions.h"
#include <iostream>
#include <string>
#include <cmath>
#include "Tokenization.h"
#include "Program.h"

FunctionType Functions::function_type(std::string function) {
    if (function.substr(0, 4) == "pow(" && function.back() == ')') return Pow;
    if (function.substr(0, 4) == "abs(" && function.back() == ')') return Abs;
    if (function.substr(0, 4) == "max(" && function.back() == ')') return Max;
    if (function.substr(0, 4) == "min(" && function.back() == ')') return Min;
    return NonFunction;
}

int Functions::pow(int a, int b) {
    return static_cast<int>(std::pow(a, b));
}

int Functions::abs(int a) {
    return std::abs(a);
}

int Functions::max(int a, int b) {
    return std::max(a, b);
}

int Functions::min(int a, int b) {
    return std::min(a, b);
}

int Functions::calculate_function(std::string function) {
    FunctionType type = function_type(function);
    if (type == NonFunction) throw std::invalid_argument("No such function exists.");
    if (type == Abs) {
        std::string expression = function.substr(4, function.size() - 5);
        Program::calculation(function);
    }
}
