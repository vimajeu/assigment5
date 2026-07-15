//
// Created by ліна on 15.07.2026.
//

#include "Program.h"
#include "Tokenization.h"
#include "Calculator.h"
#include "ValuableContainer.h"
#include <iostream>
#include <sstream>

InputType Program::input_type(std::string input) {
    std::stringstream ss(input);
    std::string word;
    std::vector<std::string> words;
    while (ss << word) {
        words.push_back(word);
    }

    if (words[0] == "var" && words[2] == "=") {
        return ValuableInput;
    }
    return ExpressionInput;
}

double Program::calculation(std::string expression) {
    return Calculator::calculating(Tokenization::get_expression(expression));
}

void Program::valuable(std::string expression) {
    std::stringstream ss(expression);
    std::string word;
    std::vector<std::string> words;
    while (ss << word) {
        words.push_back(word);
    }
    std::string exp = expression.substr(7);
    double value = Calculator::calculating(Tokenization::get_expression(exp));
    ValuableContainer::add_valuable(words[1], value);
}

void Program::run() {
    while (true) {
        std::string input;
        std::getline(std::cin, input);
        if (input_type(input) == ValuableInput) {
            std::cout << calculation(input) << std::endl;
        }
        else {
            valuable(input);
        }
    }
}
