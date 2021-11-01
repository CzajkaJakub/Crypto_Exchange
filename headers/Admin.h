//
// Created by Jakub on 29.10.2021.
//

#ifndef CRYPTO_EXCHANGE_ADMIN_H
#define CRYPTO_EXCHANGE_ADMIN_H


#include "ExchangeDatabase.h"

class Admin{
public:
    static void addNewCurrencyToDatabase(ExchangeDatabase& database);
    static void deleteTheCurrency(ExchangeDatabase& database);
    static void showAvailableCryptos(ExchangeDatabase &database);
    static void showAllAccountsInDatabase(ExchangeDatabase &database);
};


#endif //CRYPTO_EXCHANGE_ADMIN_H
