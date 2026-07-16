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
public:
    static std::vector<std::string> tokenize(std::string& input);
};

#endif //ASSIGMENT5_TOKENIZATION_H
