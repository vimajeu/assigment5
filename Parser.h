//
// Created by ліна on 16.07.2026.
//

#ifndef ASSIGMENT5_PARSER_H
#define ASSIGMENT5_PARSER_H
#include <vector>

class Parser {
    std::vector<std::string> tokens;
    size_t position;
    std::string peek();
    std::string advance();
    static bool is_number(const std::string& token);
    double parse_expr();
    double parse_term();
    double parse_factor();
    double parse_function_call(const std::string& name);
public:
    Parser(std::vector<std::string> tokens);
    double parse();
};

#endif //ASSIGMENT5_PARSER_H
