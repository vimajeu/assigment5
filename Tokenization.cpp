//
// Created by ліна on 08.07.2026.
//

#include "Tokenization.h"
#include "Functions.h"

std::vector<std::string> Tokenization::tokenize(std::string& input) {
    std::vector<std::string> result;
    std::string operators = "+-*/(),";
    std::string buffer = "";
    for (char c : input) {
        if (operators.find(c) != std::string::npos){
            if (!buffer.empty()) result.push_back(buffer);
            result.push_back(std::string(1, c));
            buffer = "";
        }
        else if (c == ' '){
            if (!buffer.empty()) result.push_back(buffer);
            buffer = "";
        }
        else {
            buffer += c;
        }
    }
    if (!buffer.empty()) result.push_back(buffer);
    return result;
}