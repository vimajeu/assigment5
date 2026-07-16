//
// Created by ліна on 15.07.2026.
//

#ifndef ASSIGMENT5_FUNCTIONS_H
#define ASSIGMENT5_FUNCTIONS_H
#include <string>
#include <vector>

class Functions {
    static std::string pow(double a, double b);
    static std::string abs(double a);
    static std::string max(double a, double b);
    static std::string min(double a, double b);
public:
    static std::string calculate_function(std::string name, std::vector<double> args);
};

#endif //ASSIGMENT5_FUNCTIONS_H
