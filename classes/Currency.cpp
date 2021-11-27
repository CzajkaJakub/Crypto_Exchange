//
// Created by Jakub on 01.11.2021.
//

#include "../headers/Currency.h"


Currency::Currency(string name, double value) {
    this->name = std::move(name);
    this->value = value;
}

double Currency::getValue() const {
    return value;
}

string Currency::getName() {
    return name;
}

