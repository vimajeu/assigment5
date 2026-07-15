//
// Created by ліна on 15.07.2026.
//

#ifndef ASSIGMENT5_CALCULATOR_H
#define ASSIGMENT5_CALCULATOR_H
#include <vector>

class Calculator {
    std::vector<std::string> high_priority = {"*", "/"};
    std::vector<std::string> low_priority = {"+", "-"};
public:
    double calculating(std::vector<std::string> tokens);
};

#endif //ASSIGMENT5_CALCULATOR_H
