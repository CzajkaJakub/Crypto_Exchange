#include <iostream>
#include "headers/ExchangeDatabase.h"
#include "headers/Admin.h"

void adminUser(ExchangeDatabase& database);

int logIntoServerAsAdmin(ExchangeDatabase database);

string callLogin();

string callPassword();

void createCurrencies(ExchangeDatabase &database);

using namespace std;

int main() {
    ExchangeDatabase exchangeDatabase;
    createCurrencies(exchangeDatabase);

    char response;
    int programIsOpen = 1;

    while(programIsOpen){

        cout << "\nChoose a type of user: \n"
                "U - user\n"
                "A - admin\n"
                "Q - quit the program" << endl;

        cin >> response;
        fflush(stdin);

        switch (tolower(response)) {
            case 'u' :
                //userMenu(exchangeDatabase); TODO
                break;
            case 'a' :
                adminUser(exchangeDatabase); break;
            case 'q' : programIsOpen = 0; break;
            default: cout << "Wrong data! Try again" << endl;
        }
    }
}

void adminUser(ExchangeDatabase& database) {

    char response;
    int logged;

    logged = logIntoServerAsAdmin(database);

    while(logged == 1){
        cout << "\nChoose an action as admin: \n"
                "A - Add new crypto to the database\n"
                "S - Show all currencies in database\n"
                "D - Delete a currency\n"
                "N - Show number of currencies in a database\n"
                "Q - Log out\n" << endl;

        cin >> response;
        fflush(stdin);

        switch (tolower(response)) {
            case 'a' :
                Admin::addNewCurrencyToDatabase(database); break;
            case 's' :
                Admin::showAvailableCryptos(database); break;
            case 'd' :
                Admin::deleteTheCurrency(database); break;
            case 'n' :
                cout << "\nNumber od currencies in a database : " << database.getNumberOfCryptoInBase() << endl;
                break;
            case 'q' : logged = 0; break;
            default: cout << "Wrong data! Try again" << endl;
        }
    }
}

void createCurrencies(ExchangeDatabase& database) {                  // currency's values was taken from binance exchange 1.11.2021
    Currency bitcoin = Currency("Bitcoin", 62195.39);
    Currency ethereum = Currency("Ethereum", 4343.19);
    Currency bnb = Currency("Bnb", 538.42);
    Currency cardano = Currency("Cardano", 1.99);
    Currency solana = Currency("Solana", 206.07);
    Currency xrp = Currency("XRP", 1.10);
    Currency polkadot = Currency("Polkadot", 45.00);
    Currency avalanche = Currency("Avalanche", 63.64);
    Currency dogeCoin = Currency("Doge Coin", 0.274611);
    Currency terra = Currency("Terra", 43.15);

    database.addCurrency(bitcoin);
    database.addCurrency(ethereum);
    database.addCurrency(bnb);
    database.addCurrency(cardano);
    database.addCurrency(solana);
    database.addCurrency(xrp);
    database.addCurrency(avalanche);
    database.addCurrency(dogeCoin);
    database.addCurrency(polkadot);
    database.addCurrency(terra);
}

int logIntoServerAsAdmin(ExchangeDatabase database) {
    string login = callLogin();
    string password = callPassword();

    if(login == database.getAdminLogin() && password == database.getAdminPassword()){
        return 1;
    }else{
        cout << "Wrong data!" << endl;
        return 0;
    }
}

string callPassword() {
    cout << "Type admin password" << endl;
    string password;
    cin >> password;
    return password;
}

string callLogin() {
    cout << "Type admin login" << endl;
    string login;
    cin >> login;
    return login;
}




