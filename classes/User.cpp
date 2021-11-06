//
// Created by Jakub on 29.10.2021.
//

#include <iostream>
#include "../headers/User.h"

using namespace std;

User::User(string login, string password) {
    this -> login = login;
    this -> password = password;
    this -> dollarAmount = 0;
}

string User::getLogin() {
    return login;
}

string User::getPassword() {
    return password;
}

double User::getDollarAmount() {
    return dollarAmount;
}

void User::withDrawYourMoney(double value) {
    if(dollarAmount >= value){
        dollarAmount -= value;
    }else{
        cout << "Not enough money to withdraw" << endl;
    }
}

void User::addMoney(double value) {
    dollarAmount += value;
}

void User::changePassword(string password) {
    this->password = password;
}


