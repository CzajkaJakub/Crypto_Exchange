//
// Created by Jakub on 29.10.2021.
//

#include <iostream>
#include "../headers/Account.h"


void Account::showAvailableCryptos(ExchangeDatabase &database) {
    for(auto currency : database.getCryptoBase()){
        cout << currency.getName() << " value : " << currency.getValue() << " $." << endl;
    }
}
