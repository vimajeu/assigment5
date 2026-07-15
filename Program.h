//
// Created by ліна on 15.07.2026.
//

#ifndef ASSIGMENT5_PROGRAM_H
#define ASSIGMENT5_PROGRAM_H
#include <string>

enum InputType {
    Valuable,
    Expression
};

class Program {
    std::string input;
public:
    void get_input();
    InputType input_type();
    static int calculation(std::string expression);
    void run();
};

#endif //ASSIGMENT5_PROGRAM_H
