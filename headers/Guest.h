//
// Created by Jakub on 03.12.2021.
//

#ifndef CRYPTO_EXCHANGE_GUEST_H
#define CRYPTO_EXCHANGE_GUEST_H


#include <string>

#include "Currency.h"
#include "Account.h"


class Guest: public Account {
public:
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


#endif //CRYPTO_EXCHANGE_GUEST_H
