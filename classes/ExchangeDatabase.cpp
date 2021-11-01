//
// Created by Jakub on 29.10.2021.
//

#include "../headers/ExchangeDatabase.h"
#include <string>

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


