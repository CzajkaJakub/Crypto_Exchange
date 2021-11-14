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
    vector<Currency*> getCryptoBase();
    int getNumberOfCryptoInBase() const;
    void addCurrency(Currency* currency);
    void removeCurrency(int position);
    bool checkAvailabilityOfLogin(const string& login);
    void addAccount(User* user);
    bool checkDataToAccount(const string& login, const string& password);
    Currency* getCurrency();
    User* getUser(const string& login);
    vector<User*> getAccounts();
};


#endif //CRYPTO_EXCHANGE_EXCHANGEDATABASE_H
