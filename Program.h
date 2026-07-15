//
// Created by ліна on 15.07.2026.
//

#ifndef ASSIGMENT5_PROGRAM_H
#define ASSIGMENT5_PROGRAM_H
#include <string>

enum InputType {
    ValuableInput,
    ExpressionInput
};

class Program {
public:
    InputType input_type(std::string input);
    static double calculation(std::string expression);
    static void valuable(std::string expression);
    void run();
};

#endif //ASSIGMENT5_PROGRAM_H
