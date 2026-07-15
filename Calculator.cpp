//
// Created by ліна on 15.07.2026.
//

#include "Calculator.h"
#include <algorithm>
#include <iterator>

double Calculator::calculating(std::vector<std::string> tokens) {
    auto high_pointer = std::find_first_of(
            tokens.begin(), tokens.end(),
            high_priority.begin(), high_priority.end());
    while (high_pointer != tokens.end()) {
        size_t position = std::distance(tokens.begin(), high_pointer);
        char op = tokens[position][0];
        double a = std::stod(tokens[position - 1]);
        double b = std::stod(tokens[position + 1]);
        double result = 0;
        switch (op) {
            case '*':
                result = a * b;
                break;
            case '/':
                result = a / b;
                break;
            default:
                throw std::invalid_argument("Unknown operator");
        }
        auto new_pointer = tokens.erase(tokens.begin() + position - 1, tokens.begin() + position + 1);
        tokens.insert(new_pointer, std::to_string(result));
        high_pointer = std::find_first_of(
            tokens.begin(), tokens.end(),
            high_priority.begin(), high_priority.end());
    }

    auto low_pointer = std::find_first_of(
            tokens.begin(), tokens.end(),
            low_priority.begin(), low_priority.end());
    while (low_pointer != tokens.end()) {
        size_t position = std::distance(tokens.begin(), low_pointer);
        char op = tokens[position][0];
        double a = std::stod(tokens[position - 1]);
        double b = std::stod(tokens[position + 1]);
        double result = 0;
        switch (op) {
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            default:
                throw std::invalid_argument("Unknown operator");
        }
        auto new_pointer = tokens.erase(tokens.begin() + position - 1, tokens.begin() + position + 1);
        tokens.insert(new_pointer, std::to_string(result));
        low_pointer = std::find_first_of(
            tokens.begin(), tokens.end(),
            low_priority.begin(), low_priority.end());
    }
    return std::stod(tokens[0]);
}
