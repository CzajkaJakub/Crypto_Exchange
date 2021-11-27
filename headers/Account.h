//
// Created by Jakub on 27.11.2021.
//

#ifndef CRYPTO_EXCHANGE_ACCOUNT_H
#define CRYPTO_EXCHANGE_ACCOUNT_H

#endif //CRYPTO_EXCHANGE_ACCOUNT_H

#include <string>
#include <map>

class Account{
protected:
    string login;
    string password;
    double dollarAmount;
    map<Currency*, double> wallet;
public:
    virtual string getLogin() = 0;
    virtual string getPassword() = 0;
    virtual void addMoney(double value) = 0;
    virtual void withDrawYourMoney(double value) = 0;
    virtual double getDollarAmount() const = 0;
    virtual void changePassword(string password) = 0;
    virtual void showYourCryptoWallet() = 0;
    virtual void buyCurrency(Currency* currency) = 0;
    virtual void setDollarAmount(double value) = 0;
    virtual void addCryptoToWallet(Currency *pCurrency, double d) = 0;
    virtual void sellYourCrypto(Currency *pCurrency) = 0;
};
