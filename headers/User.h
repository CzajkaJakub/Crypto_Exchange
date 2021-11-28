//
// Created by Jakub on 29.10.2021.
//

#ifndef CRYPTO_EXCHANGE_USER_H
#define CRYPTO_EXCHANGE_USER_H


#include <string>
#include <map>
#include "Currency.h"
#include "Account.h"



using namespace std;

class User: public Account{
public:
    User(string login, string password);
    string getLogin() override;
    string getPassword() override;
    void addMoney(double value) override;
    void withDrawYourMoney(double value) override;
    double getDollarAmount() const override;
    void changePassword(string newPassword) override;
    void showYourCryptoWallet() override;
    void buyCurrency(Currency* currency) override;
    void setDollarAmount(double value) override;
    void addCryptoToWallet(Currency *pCurrency, double amount) override;
    void sellYourCrypto(Currency *pCurrency) override;
};

#endif //CRYPTO_EXCHANGE_USER_H
