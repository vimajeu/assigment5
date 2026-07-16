//
// Created by ліна on 15.07.2026.
//

#ifndef ASSIGMENT5_FUNCTIONS_H
#define ASSIGMENT5_FUNCTIONS_H
#include <string>
#include <vector>

class Functions {
    static double pow(double a, double b);
    static double abs(double a);
    static double max(double a, double b);
    static double min(double a, double b);
public:
    static double calculate_function(const std::string& name, std::vector<double> args);
};

#endif //ASSIGMENT5_FUNCTIONS_H
