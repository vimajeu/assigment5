//
// Created by ліна on 15.07.2026.
//

#include "ValuableContainer.h"
#include <string>

void ValuableContainer::add_valuable(std::string name, double value) {
    dictionary[name] = value;
}

double ValuableContainer::get_valuable(std::string name) {
    auto pointer = dictionary.find(name);
    if (pointer == dictionary.end()) throw std::invalid_argument("No such variable.");
    return pointer->second;
}
