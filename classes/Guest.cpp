//
// Created by Jakub on 29.10.2021.
//

#include <iostream>
#include "../headers/Guest.h"

using namespace std;

string Guest::getLogin() {
    return "Your are on guest Account! You don't gave login";
}
string Guest::getPassword() {
    return "Your are on guest Account! You don't gave password";
}

void Guest::addMoney(double value) {
    cout << "You can't add money to guest account" << endl;
}
void Guest::withDrawYourMoney(double value) {
    cout << "You can't withdraw money to guest account" << endl;
}
double Guest::getDollarAmount() const {
    return 0;
}
void Guest::changePassword(string newPassword) {
    cout << "you can't change guest's password" << endl;
}
void Guest::showYourCryptoWallet() {
    cout << "Guest don't have wallet, log in user account!" << endl;
}
void Guest::setDollarAmount(double value) {
}

void Guest::buyCurrency(Currency* currency) {
    cout << "You can't buy crypto as guest!" << endl;
}
void Guest::addCryptoToWallet(Currency *pCurrency, double amount) {
}

void Guest::sellYourCrypto(Currency *pCurrency) {
    cout << "You can't sell crypto as guest!" << endl;
}

