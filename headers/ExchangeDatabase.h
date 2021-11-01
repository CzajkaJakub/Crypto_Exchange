//
// Created by Jakub on 29.10.2021.
//

#ifndef CRYPTO_EXCHANGE_EXCHANGEDATABASE_H
#define CRYPTO_EXCHANGE_EXCHANGEDATABASE_H

#include <string>
#include <vector>
#include "Currency.h"

using namespace std;

class ExchangeDatabase {

private:
    string adminLogin = "admin";
    string adminPassword = "admin";
    int numbersOfCryptoInBase;
    vector<Currency> cryptoBase;

public:
    ExchangeDatabase();
    string getAdminLogin();
    string getAdminPassword();
    vector<Currency> getCryptoBase();
    int getNumberOfCryptoInBase() const;
    void addCurrency(const Currency& currency);
    void removeCurrency(int position);
};


#endif //CRYPTO_EXCHANGE_EXCHANGEDATABASE_H
