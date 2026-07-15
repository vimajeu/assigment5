//
// Created by ліна on 15.07.2026.
//

#include "Program.h"
#include <iostream>
#include <sstream>

void Program::get_input() {
    std::getline(std::cin, input);
}

InputType Program::input_type() {
    std::stringstream ss(input);
    std::string word;
    std::vector<std::string> words;
    while (ss << word) {
        words.push_back(word);
    }

    if (words[0] == "var" && words[2] == "=") {
        return Valuable;
    }
    return Expression;
}

double Program::calculation(std::string expression) {
}

void Program::add_valuable(std::string expression) {

}

void Program::run() {
    get_input();
    calculation();
}
