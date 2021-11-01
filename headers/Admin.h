//
// Created by Jakub on 29.10.2021.
//

#ifndef CRYPTO_EXCHANGE_ADMIN_H
#define CRYPTO_EXCHANGE_ADMIN_H


#include "Account.h"

class Admin:
        public Account{
public:
    static void addNewCurrencyToDatabase(ExchangeDatabase& database);
    static void deleteTheCurrency(ExchangeDatabase& database);
};


#endif //CRYPTO_EXCHANGE_ADMIN_H
