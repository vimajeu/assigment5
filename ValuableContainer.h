//
// Created by ліна on 15.07.2026.
//

#ifndef ASSIGMENT5_VALUABLECONTAINER_H
#define ASSIGMENT5_VALUABLECONTAINER_H
#include <unordered_map>

class ValuableContainer {
    static std::unordered_map<std::string, double> dictionary;
public:
    static void add_valuable(const std::string& name, double value);
    static double get_valuable(const std::string& name);
};

#endif //ASSIGMENT5_VALUABLECONTAINER_H
