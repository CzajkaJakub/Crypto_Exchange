//
// Created by Jakub on 29.10.2021.
//

#ifndef CRYPTO_EXCHANGE_USER_H
#define CRYPTO_EXCHANGE_USER_H


#include <string>
#include <map>
#include "Currency.h"

using namespace std;

class User{
private:
    string login;
    string password;
    double dollarAmount;
    map<Currency*, double> wallet;
public:
    User(string login, string password);
    string getLogin();
    string getPassword();

    void setDollarAmount(double value);
    double getDollarAmount();
    void addMoney(double value);

    void withDrawYourMoney(double value);
    void changePassword(string password);
    void buyCurrency(Currency* currency);
    void addCryptoToWallet(Currency *pCurrency, double d);
    void showYourCryptoWallet();

    void sellYourCrypto(Currency *pCurrency);
};

#endif //CRYPTO_EXCHANGE_USER_H
