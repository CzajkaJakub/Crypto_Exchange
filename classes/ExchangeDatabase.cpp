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

string ExchangeDatabase::getAdminLogin() {
    return adminLogin;
}

string ExchangeDatabase::getAdminPassword() {
    return adminPassword;
}

int ExchangeDatabase::getNumberOfCryptoInBase() const {
    return numbersOfCryptoInBase;
}

vector<Currency> ExchangeDatabase::getCryptoBase() {
    return cryptoBase;
}

void ExchangeDatabase::addCurrency(const Currency& currency) {
    cryptoBase.push_back(currency);
    numbersOfCryptoInBase++;
}

void ExchangeDatabase::removeCurrency(int position) {
    cryptoBase.erase(cryptoBase.begin()+position);
    numbersOfCryptoInBase --;
}

bool ExchangeDatabase::checkAvailabilityOfLogin(const string& login) {
    for(User account : accounts){
        if(account.getLogin() == login){
            cout << "An account exist with this login, try the other one" << endl;
            return false;
        }
    }
    return true;
}

void ExchangeDatabase::addAccount(User user) {
    accounts.push_back(user);
}

bool ExchangeDatabase::checkDataToAccount(const string& login, const string& password) {
    for(User account : accounts){
        if(account.getLogin() == login && account.getPassword() == password){
            return true;
        }
    }
    cout << "Incorrect data, try again!" << endl;
    return false;
}

User ExchangeDatabase::getUser(const string& login) {
    for(User account : accounts){
        if(account.getLogin() == login){
            return account;
        }
    }
}

void ExchangeDatabase::updateData(User user) {
    int pos = 0;
    for(User account : accounts){
        if(account.getLogin() == user.getLogin()){
            accounts.erase(accounts.begin()+pos);
            accounts.push_back(user);
            return;
        }else{
            pos++;
        }
    }
}

vector<User> ExchangeDatabase::getAccounts() {
    return accounts;
}


