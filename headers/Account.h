//
// Created by Jakub on 29.10.2021.
//

#ifndef CRYPTO_EXCHANGE_ACCOUNT_H
#define CRYPTO_EXCHANGE_ACCOUNT_H

#include <string>
#include "ExchangeDatabase.h"

using namespace std;

class Account {
public:
    static void showAvailableCryptos(ExchangeDatabase& database);
};


#endif //CRYPTO_EXCHANGE_ACCOUNT_H
