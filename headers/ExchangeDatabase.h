//
// Created by Jakub on 29.10.2021.
//

#ifndef CRYPTO_EXCHANGE_EXCHANGEDATABASE_H
#define CRYPTO_EXCHANGE_EXCHANGEDATABASE_H

#include <string>
#include <vector>
#include "User.h"


using namespace std;

class ExchangeDatabase {

private:
    int numbersOfCryptoInBase;
    vector<Currency*> cryptoBase;
    vector<User*> accounts;
public:
    ExchangeDatabase();
    void addCurrency(Currency* currency);
    void addAccount(User* user);
    bool checkAvailabilityOfLogin(const string& login);
    bool checkDataToAccount(const string& login, const string& password);
    User* getUser(const string& login);
    Currency* getCurrency();
    void removeCurrency(int position);
    int getNumberOfCryptoInBase() const;
    vector<User*> getAccounts();
    vector<Currency*> getCryptoBase();
};


#endif //CRYPTO_EXCHANGE_EXCHANGEDATABASE_H
