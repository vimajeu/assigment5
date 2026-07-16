//
// Created by ліна on 16.07.2026.
//

#include "Parser.h"
#include "ValuableContainer.h"
#include "Functions.h"

Parser::Parser(std::vector<std::string> tokens) : tokens(std::move(tokens)), position(0){}

std::string Parser::peek() {
    if (position >= tokens.size()) return "";
    return tokens[position];
}

std::string Parser::peek_next() {
    if (position + 1 >= tokens.size()) return "";
    return tokens[position + 1];
}
std::string Parser::advance() {
    std::string token = peek();
    position++;
    return token;
}

bool Parser::is_number(const std::string& token) {
    if (token.empty()) return false;
    int i = 0;
    if (token[0] == '-') {
        if (token.size() == 1) return false;
        i += 1;
    }
    bool seen_dot = false;
    for (i; i < token.size(); i++) {
        if (token[i] == '.') {
            if (seen_dot) return false;
            seen_dot = true;
        } else if (!isdigit(token[i])) {
            return false;
        }
    }
    return true;
}

std::string Parser::parse_exp() {
    std::string operators = "+-*/(),";
    std::string token = peek();
    if (is_number(token) || operators.find(token) != std::string::npos) {
        advance();
        return token;
    }
    std::string name = advance();
    if (peek() == "(") {
        return parse_function_call(name);
    }
    return ValuableContainer::get_valuable(name);
}

std::string Parser::parse_function_call(const std::string& name) {
    advance();
    std::vector<double> args;
    if (peek() != ")") {
        args.push_back(std::stod(parse_exp()));
        if (peek() == ",") {
            advance();
            args.push_back(std::stod(parse_exp()));
        }
    }
    if (peek() != ")") throw std::invalid_argument("Expected ')'");
    advance();

    return Functions::calculate_function(name, args);
}

std::vector<std::string> Parser::parse() {
    for (int i = 0; i < tokens.size(); i++) {
        tokens[i] = parse_exp();
    }
    return tokens;
}
