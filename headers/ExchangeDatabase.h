//
// Created by Jakub on 29.10.2021.
//

#ifndef CRYPTO_EXCHANGE_EXCHANGEDATABASE_H
#define CRYPTO_EXCHANGE_EXCHANGEDATABASE_H

#include <string>
#include <vector>
#include "Currency.h"
#include "User.h"


using namespace std;

class ExchangeDatabase {

private:
    string adminLogin = "admin";
    string adminPassword = "admin";
    int numbersOfCryptoInBase;
    vector<Currency> cryptoBase;
    vector<User> accounts;

public:
    ExchangeDatabase();
    string getAdminLogin();
    string getAdminPassword();
    vector<Currency> getCryptoBase();
    int getNumberOfCryptoInBase() const;
    void addCurrency(const Currency& currency);
    void removeCurrency(int position);
    bool checkAvailabilityOfLogin(const string& login);
    void addAccount(User user);
    bool checkDataToAccount(const string& login, const string& password);
    User getUser(const string& login);
    void updateData(User user);
    vector<User> getAccounts();
};


#endif //CRYPTO_EXCHANGE_EXCHANGEDATABASE_H
