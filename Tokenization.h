//
// Created by ліна on 08.07.2026.
//

#ifndef ASSIGMENT5_TOKENIZATION_H
#define ASSIGMENT5_TOKENIZATION_H
#include <vector>

enum TokenType {
    Valuable,
    Function,
    Operator,
    Number,
    NonToken
};

class Tokenization {
    static TokenType token_type(std::string& token);
    static std::vector<std::string> tokenize(std::string& input);
    static std::vector<std::string> nonnumeric_replacer(std::vector<std::string> tokens);

public:
    static bool is_numeric(std::string& text);
    static std::vector<std::string> get_expression(std::string text);
};

#endif //ASSIGMENT5_TOKENIZATION_H
