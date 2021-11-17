//
// Created by Jakub on 29.10.2021.
//

#include "../headers/ExchangeDatabase.h"
#include <string>
#include <iostream>

using namespace std;

ExchangeDatabase::ExchangeDatabase() {
    numbersOfCryptoInBase = 0;
}
void ExchangeDatabase::addCurrency(Currency* currency) {
    cryptoBase.push_back(currency);
    numbersOfCryptoInBase++;
}
void ExchangeDatabase::addAccount(User* user) {
    accounts.push_back(user);
}
bool ExchangeDatabase::checkAvailabilityOfLogin(const string& login) {
    for(User* account : accounts){
        if(account->getLogin() == login){
            cout << "An account exist with this login, try the other one" << endl;
            return false;
        }
    }
    return true;
}
bool ExchangeDatabase::checkDataToAccount(const string& login, const string& password) {
    for(User* account : accounts){
        if(account->getLogin() == login && account->getPassword() == password){
            return true;
        }
    }
    cout << "Incorrect data, try again!" << endl;
    return false;
}
User* ExchangeDatabase::getUser(const string& login) {
    for(User* account : accounts){
        if(account->getLogin() == login){
            return account;
        }
    }
}
Currency* ExchangeDatabase::getCurrency() {

    Currency *cur = nullptr;
    cout << "Type a currency to buy" << endl;
    string currency;
    getline(cin, currency);

    for(auto crypto : cryptoBase){
        if(crypto->getName() == currency){
            return crypto;
        }
    }
    return cur;
}
void ExchangeDatabase::removeCurrency(int position) {
    cryptoBase.erase(cryptoBase.begin()+position);
    numbersOfCryptoInBase --;
}
int ExchangeDatabase::getNumberOfCryptoInBase() const {
    return numbersOfCryptoInBase;
}

vector<Currency*> ExchangeDatabase::getCryptoBase() {
    return cryptoBase;
}

vector<User*> ExchangeDatabase::getAccounts() {
    return accounts;
}


