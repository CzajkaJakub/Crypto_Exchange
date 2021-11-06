//
// Created by Jakub on 29.10.2021.
//

#include <iostream>
#include "../headers/Admin.h"



void Admin::deleteTheCurrency(ExchangeDatabase* database) {
    int posInVector = 0;

    string name;
    cout << "\nType a name a currency to delete it from the base" << endl;
    cin >> name;

    for(Currency* currency : database->getCryptoBase()){
        if(currency->getName() == name){
            cout << "Your have deleted a currency : " << currency->getName() << " value : " << currency->getValue() << " $." << endl;
            database->removeCurrency(posInVector);
            return;
        }else{
            posInVector++;
        }
    }

    cout << "Currency you typed doesn't exist in a database" << endl;

}

void Admin::addNewCurrencyToDatabase(ExchangeDatabase* database) {

    string name;
    cout << "Type a name of currency" << endl;
    getline(cin, name);

    double value;
    cout << "Type a value of a currency in dollars." << endl;
    cin >> value;

    for(Currency* cryptoName : database->getCryptoBase()){
        if(cryptoName->getName() == name){
            cout << "Crypto exist in a database, you can't add it again ! " << endl;
            return;
        }
    }

    // currency added to a database
    database->addCurrency(new Currency(name, value));
    printf("Currency added to the database : %s, value : %.2lf $.\n", name.c_str(), value);
}


void Admin::showAvailableCryptos(ExchangeDatabase* database) {
    for(auto currency : database->getCryptoBase()){
        cout << currency->getName() << " value : " << currency->getValue() << " $." << endl;
    }
}

void Admin::showAllAccountsInDatabase(ExchangeDatabase* database) {
    for(User* account : database->getAccounts()){
        cout << "Login: " << account->getLogin() << " Password: "<< account->getPassword() << " Amount: " << account->getDollarAmount()<<endl;
    }
}






