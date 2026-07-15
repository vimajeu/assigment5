//
// Created by ліна on 08.07.2026.
//

#include "Tokenization.h"
#include "Functions.h"
#include "ValuableContainer.h"
#include <sstream>

bool Tokenization::is_numeric(std::string& text) {
    return std::all_of(text.begin(), text.end(), isdigit);
}

TokenType Tokenization::token_type(std::string& token) {
    std::vector<std::string> operators = {"+", "-", "*", "/"};
    if (is_numeric(token)) return Number;
    if (token.find("(") != std::string::npos) return Function;
    if (std::find(operators.begin(), operators.end(), token) != operators.end()) return Operator;
    return Valuable;
}

std::vector<std::string> Tokenization::tokenize(std::string& input) {
    std::stringstream ss(input);
    std::string word;
    std::vector<std::string> words;
    while (ss << word) {
        words.push_back(word);
    }

    return words;
}

std::vector<std::string> Tokenization::nonnumeric_replacer(std::vector<std::string> tokens) {
    for (int i = 0; i < tokens.size(); i++) {
        TokenType type = token_type(tokens[i]);
        if (type == Function) {
            tokens[i] = Functions::calculate_function(tokens[i]);
        }
        else if (type == Valuable) {
            tokens[i] = ValuableContainer::get_valuable(tokens[i]);
        }
    }
}
