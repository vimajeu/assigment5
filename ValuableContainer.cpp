//
// Created by ліна on 15.07.2026.
//

#include "ValuableContainer.h"
#include <string>

std::unordered_map<std::string, double> ValuableContainer::dictionary;

void ValuableContainer::add_valuable(const std::string& name, double value) {
    if (dictionary.find(name) != dictionary.end()) {
        throw std::invalid_argument("Variable '" + name + "' is already defined and cannot be reassigned.");
    }
    dictionary[name] = value;
}

double ValuableContainer::get_valuable(const std::string& name) {
    auto it = dictionary.find(name);
    if (it == dictionary.end()) throw std::invalid_argument("No such variable: " + name);
    return it->second;
}