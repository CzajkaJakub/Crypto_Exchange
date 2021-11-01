//
// Created by Jakub on 29.10.2021.
//

#ifndef CRYPTO_EXCHANGE_USER_H
#define CRYPTO_EXCHANGE_USER_H


#include <string>

using namespace std;

class User{
private:
    string login;
    string password;
    double dollarAmount;
public:
    User(string login, string password);
    string getLogin();
    string getPassword();
    double getDollarAmount();
    void addMoney(double value);
    void withDrawYourMoney(double value);
    void changePassword(string password);
};


#endif //CRYPTO_EXCHANGE_USER_H
