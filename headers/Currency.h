//
// Created by Jakub on 01.11.2021.
//

#ifndef CRYPTO_EXCHANGE_CURRENCY_H
#define CRYPTO_EXCHANGE_CURRENCY_H

#include <string>

using namespace std;

class Currency {

private:
    string name;
    double value;
public:
    Currency(string name, double value);
    double getValue() const;
    string getName();
};


#endif //CRYPTO_EXCHANGE_CURRENCY_H
