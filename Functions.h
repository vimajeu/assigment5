//
// Created by ліна on 15.07.2026.
//

#ifndef ASSIGMENT5_FUNCTIONS_H
#define ASSIGMENT5_FUNCTIONS_H
#include <string>

enum FunctionType {
    Pow,
    Abs,
    Max,
    Min,
    NonFunction
};

class Functions {
    FunctionType function_type(std::string function);
    std::string pow(int a, int b);
    std::string abs(int a);
    std::string max(int a, int b);
    std::string min(int a, int b);
public:
    static std::string calculate_function(std::string function);
};

#endif //ASSIGMENT5_FUNCTIONS_H
