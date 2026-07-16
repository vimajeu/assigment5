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

double Parser::parse_factor() {
    std::string token = peek();

    if (is_number(token)) {
        advance();
        return std::stod(token);
    }

    if (token == "(") {
        advance();
        double value = parse_expr();
        if (peek() != ")") throw std::invalid_argument("Expected ')'");
        advance();
        return value;
    }

    if (token.empty()) {
        throw std::invalid_argument("Unexpected end of expression");
    }

    std::string name = advance();
    if (peek() == "(") {
        return parse_function_call(name);
    }
    return ValuableContainer::get_valuable(name);
}

double Parser::parse_function_call(const std::string& name) {
    advance();
    std::vector<double> args;
    if (peek() != ")") {
        args.push_back(parse_expr());
        while (peek() == ",") {
            advance();
            args.push_back(parse_expr());
        }
    }
    if (peek() != ")") throw std::invalid_argument("Expected ')'");
    advance();

    return Functions::calculate_function(name, args);
}

double Parser::parse_term() {
    double result = parse_factor();
    while (peek() == "*" || peek() == "/") {
        std::string op = advance();
        double rhs = parse_factor();
        result = (op == "*") ? result * rhs : result / rhs;
    }
    return result;
}

double Parser::parse_expr() {
    double result = parse_term();
    while (peek() == "+" || peek() == "-") {
        std::string op = advance();
        double rhs = parse_term();
        result = (op == "+") ? result + rhs : result - rhs;
    }
    return result;
}

double Parser::parse() {
    double result = parse_expr();
    if (position != tokens.size()) {
        throw std::invalid_argument("Unexpected token: " + peek());
    }
    return result;
}
