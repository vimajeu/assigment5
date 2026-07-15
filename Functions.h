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
    int pow(int a, int b);
    int abs(int a);
    int max(int a, int b);
    int min(int a, int b);
public:
    int calculate_function(std::string function);
};

#endif //ASSIGMENT5_FUNCTIONS_H
