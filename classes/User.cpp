//
// Created by Jakub on 29.10.2021.
//

#include <iostream>
#include "../headers/User.h"

using namespace std;

User::User(string login, string password) {
    this -> login = std::move(login);
    this -> password = std::move(password);
    this -> dollarAmount = 0;
}
string User::getLogin() {
    return login;
}
string User::getPassword() {
    return password;
}
void User::addMoney(double value) {
    dollarAmount += value;
}
void User::withDrawYourMoney(double value) {
    if(dollarAmount >= value){
        dollarAmount -= value;
    }else{
        cout << "Not enough money to withdraw" << endl;
    }
}
double User::getDollarAmount() const {
    return dollarAmount;
}
void User::changePassword(string newPassword) {
    this->password = newPassword;
}
void User::showYourCryptoWallet() {
    cout << "Your wallet: " << endl;
    for(auto crypto : wallet){
        cout << crypto.first->getName() << " : " << crypto.second << endl;
    }
}
void User::setDollarAmount(double value) {
    this->dollarAmount = value;
}
void User::buyCurrency(Currency* currency) {
    double count;
    double value;
    if(currency != nullptr){
       cout << "How much : " << currency->getName() << ", for : " << currency->getValue() << "$ would you like to buy" << endl;
       cin >> count;
       value = count * currency->getValue();
       if(this->getDollarAmount() >= value){
           cout << "you have bought " << count << " " << currency->getName() << " for : " << value << "$" << endl;
           this->setDollarAmount(this->getDollarAmount() - value);
           this->addCryptoToWallet(currency, count);
       }else{
           cout << "You don't have enough money to buy this currency" << endl;
       }
   }else{
       cout << "Wrong data entered!" << endl;
   }
}
void User::addCryptoToWallet(Currency *pCurrency, double amount) {
    for(auto crypto : wallet){
        if(crypto.first->getName() == pCurrency->getName()){
            wallet[crypto.first] = crypto.second + amount;
            return;
        }
    }
    wallet[pCurrency] = amount;
}
void User::sellYourCrypto(Currency *pCurrency) {
    double count;
    double value;
    if(pCurrency != nullptr){
        cout << "How much : " << pCurrency->getName() << ", for : " << pCurrency->getValue() << "$ would you like to sell" << endl;
        cin >> count;
        value = count * pCurrency->getValue();
        if(this->wallet[pCurrency] >= count){
            this->addMoney(value);
            this->wallet[pCurrency] -= count;
        }else{
            cout << "You don't have enough crypto" << endl;
        }
    }else{
        cout << "Wrong data entered!" << endl;
    }
}





