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

std::string Functions::pow(int a, int b) {
    return std::to_string(static_cast<int>(std::pow(a, b)));
}

std::string Functions::abs(int a) {
    return std::to_string(std::abs(a));
}

std::string Functions::max(int a, int b) {
    return std::to_string(std::max(a, b));
}

std::string Functions::min(int a, int b) {
    return std::to_string(std::min(a, b));
}

std::string Functions::calculate_function(std::string function) {
    FunctionType type = function_type(function);
    if (type == NonFunction) throw std::invalid_argument("No such function exists.");
    std::string expression = function.substr(4, function.size() - 5);
    if (type == Abs) {
        return abs(Program::calculation(expression));
    }

    size_t comma_pos = expression.find(",");
    if (comma_pos == std::string::npos) throw std::invalid_argument("Wrong argument in a function.");
    std::string a = expression.substr(0, static_cast<int>(comma_pos));
    std::string b = expression.substr(comma_pos + 1, expression.size() - comma_pos - 1);

    if (type == Pow) {
        return pow(Program::calculation(a), Program::calculation(b));
    }
    if (type == Max) {
        return max(Program::calculation(a), Program::calculation(b));
    }
    return min(Program::calculation(a), Program::calculation(b));
}