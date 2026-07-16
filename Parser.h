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
    std::string peek_next();
    std::string advance();
    static bool is_number(const std::string& token);
    std::string parse_exp();
    std::string parse_function_call(const std::string& name);
public:
    Parser(std::vector<std::string> tokens);
    std::vector<std::string> parse();
};

#endif //ASSIGMENT5_PARSER_H
