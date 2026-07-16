//
// Created by ліна on 15.07.2026.
//

#include "Program.h"
#include "Tokenization.h"
#include "Calculator.h"
#include "ValuableContainer.h"
#include "Parser.h"
#include <iostream>
#include <sstream>

InputType Program::input_type(std::string input) {
    std::stringstream ss(input);
    std::string word;
    std::vector<std::string> words;
    while (ss >> word) {
        words.push_back(word);
    }
    if (words.size() >= 3 && words[0] == "var" && words[2] == "=") {
        return ValuableInput;
    }
    return ExpressionInput;
}

double Program::calculation(std::string expression) {
    Parser p(Tokenization::tokenize(expression));
    return p.parse();
}

void Program::valuable(std::string expression) {
    std::stringstream ss(expression);
    std::string word;
    std::vector<std::string> words;
    while (ss >> word) {
        words.push_back(word);
    }
    size_t eq_pos = expression.find('=');
    std::string exp = expression.substr(eq_pos + 1);

    double value = calculation(exp);
    ValuableContainer::add_valuable(words[1], value);
}

void Program::run() {
    while (true) {
        std::string input;
        std::getline(std::cin, input);
        if (input.empty()) continue;
        if (input == "exit" || input == "quit") break;

        try {
            if (input_type(input) == ValuableInput) {
                valuable(input);
            } else {
                std::cout << calculation(input) << std::endl;
            }
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
}