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
    Number
};

class Tokenization {
    TokenType token_type(std::string& token);
    std::vector<std::string> tokenize(std::string& input);
    std::vector<std::string> nonnumeric_replacer(std::vector<std::string> tokens);

public:
    bool is_numeric(std::string& text);
    std::vector<std::string> get_expression();
};

#endif //ASSIGMENT5_TOKENIZATION_H
