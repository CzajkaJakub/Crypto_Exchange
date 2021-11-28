#include <iostream>
#include "headers/ExchangeDatabase.h"
#include "headers/Admin.h"

string callLogin();
string callPassword();
void adminUser(ExchangeDatabase* database);
void createCurrencies(ExchangeDatabase* database);
void userMenu(ExchangeDatabase* database);
void createAnAccount(ExchangeDatabase* database);
void logInIntoService(ExchangeDatabase* database);
void createAnAdminAccount(ExchangeDatabase *pDatabase);
using namespace std;

int main() {
    ExchangeDatabase exchangeDatabase;
    ExchangeDatabase* databasePointer = &exchangeDatabase;
    createCurrencies(databasePointer);
    createAnAdminAccount(databasePointer);

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
                userMenu(databasePointer); break;
            case 'a' :
                adminUser(databasePointer); break;
            case 'q' : programIsOpen = 0; break;
            default: cout << "Wrong data! Try again" << endl;
        }
    }
}
void createCurrencies(ExchangeDatabase* database) {                  // currency's values was taken from binance exchange 1.11.2021
    auto *bitcoin = new Currency("Bitcoin", 62195.39);
    auto *ethereum = new Currency("Ethereum", 4343.19);
    auto *bnb = new Currency("Bnb", 538.42);
    auto *cardano = new Currency("Cardano", 1.99);
    auto *solana = new Currency("Solana", 206.07);
    auto *xrp = new Currency("XRP", 1.10);
    auto *polkadot = new Currency("Polkadot", 45.00);
    auto *avalanche = new Currency("Avalanche", 63.64);
    auto *dogeCoin = new Currency("Doge Coin", 0.274611);
    auto *terra = new Currency("Terra", 43.15);

    database->addCurrency(bitcoin);
    database->addCurrency(ethereum);
    database->addCurrency(bnb);
    database->addCurrency(cardano);
    database->addCurrency(solana);
    database->addCurrency(xrp);
    database->addCurrency(avalanche);
    database->addCurrency(dogeCoin);
    database->addCurrency(polkadot);
    database->addCurrency(terra);
}
void createAnAdminAccount(ExchangeDatabase* database) {
    string adminLogin = "admin";
    string adminPassword = "admin";
    auto *admin = new Admin(adminLogin, adminPassword);
    database->addAccount(admin);
}
void userMenu(ExchangeDatabase* database) {

    int loggingPanel = 1;
    char response;

    while(loggingPanel){
        cout << "\nChoose an action: \n"
                "L - Login\n"
                "C - Create an account\n"
                "Q - Quit the logging panel" << endl;

        cin >> response;
        fflush(stdin);

        switch (tolower(response)) {
            case 'l' : logInIntoService(database); break;
            case 'c' : createAnAccount(database); break;
            case 'q' : loggingPanel = 0; break;
            default: cout << "Wrong data! Try again" << endl;
        }
    }
}
void logInIntoService(ExchangeDatabase* database) {
    string login;
    string password;
    int logged;
    char response;
    string newPassword;

    cout << "Type your login" << endl;
    getline(cin, login);
    cout << "Type your password" << endl;
    getline(cin, password);

    if(database->checkDataToAccount(login, password)){
        User* user = database->getUser(login);
        cout << "Welcome again " << user->getLogin() << endl;
        logged = 1;
        double value;

        while(logged == 1){
            cout << "\nChoose an action as user: \n"
                    "A - Add money to your account\n"
                    "W - Withdraw your money\n"
                    "S - Show your dollar amount\n"
                    "C - Change your password\n"
                    "Y - show your crypto wallet\n"
                    "B - buy currency\n"
                    "P - Sell your crypto\n"
                    "Q - Log out\n" << endl;

            cin >> response;
            fflush(stdin);

            switch (tolower(response)) {
                case 'a' :
                    cout << "Type amount to add: " << endl;
                    cin >> value;
                    user->addMoney(value); break;
                case 'w' :
                    cout << "Type amount to withdraw: " << endl;
                    cin >> value;
                    user->withDrawYourMoney(value); break;
                case 's' :
                    cout << "your money : " << user->getDollarAmount() << endl; break;
                case 'c' :
                    cout << "Type your new password: " << endl;
                    cin >> newPassword;
                    user->changePassword(newPassword);
                    break;
                case 'y' :
                    user->showYourCryptoWallet(); break;
                case 'b':
                    user->buyCurrency(database->getCurrency()); break;
                case 'q' :
                    logged = 0;
                    break;
                case 'p' : user->sellYourCrypto(database->getCurrency());
                    break;
                default:
                    cout << "Wrong data! Try again" << endl;
            }
        }
    }
}
void createAnAccount(ExchangeDatabase* database) {
    string login;
    string password;

    cout << "Creating account, please type your login" << endl;
    getline(cin, login);

    if(database->checkAvailabilityOfLogin(login)){
        cout << "Type your password" << endl;
        getline(cin, password);
        User *user = new User(login, password);
        database->addAccount(user);
        cout << "Account was created" << endl;
        return;
    }
}
void adminUser(ExchangeDatabase* database) {

    char response;
    int logged;

    string login = callLogin();
    string password = callPassword();
    if(login == "admin") {
        while (database->checkDataToAccount(login, password)) {
            User *admin = database->getUser(login);
            cout << "Welcome again " << admin->getLogin() << endl;
            logged = 1;
            double value;
            string newPassword;

            while (logged == 1) {
                cout << "\nChoose an action as admin: \n"
                        "A - Add new crypto to the database\n"
                        "S - Show all currencies in database\n"
                        "D - Delete a currency\n"
                        "N - Show number of currencies in a database\n"
                        "K - Show all accounts in database\n"
                        "Y - show your crypto wallet\n"
                        "O - Add money to your account\n"
                        "W - Withdraw your money\n"
                        "L - Show your dollar amount\n"
                        "C - change your password\n"
                        "B - buy currency\n"
                        "P - Sell your crypto\n"
                        "Q - Log out\n" << endl;

                cin >> response;
                fflush(stdin);

                switch (tolower(response)) {
                    case 'a' :
                        Admin::addNewCurrencyToDatabase(database);
                        break;
                    case 's' :
                        Admin::showAvailableCryptos(database);
                        break;
                    case 'd' :
                        Admin::deleteTheCurrency(database);
                        break;
                    case 'n' :
                        cout << "\nNumber od currencies in a database : " << database->getNumberOfCryptoInBase()
                             << endl;
                        break;
                    case 'k' :
                        Admin::showAllAccountsInDatabase(database);
                        break;
                    case 'y' :
                        admin->showYourCryptoWallet();
                        break;
                    case 'o' :
                        cout << "Type amount to add: " << endl;
                        cin >> value;
                        admin->addMoney(value);
                        break;
                    case 'w' :
                        cout << "Type amount to withdraw: " << endl;
                        cin >> value;
                        admin->withDrawYourMoney(value);
                        break;
                    case 'l' :
                        cout << "your money : " << admin->getDollarAmount() << endl;
                        break;
                    case 'c' :
                        cout << "Type your new password: " << endl;
                        cin >> newPassword;
                        admin->changePassword(newPassword);
                        break;
                    case 'b':
                        admin->buyCurrency(database->getCurrency());
                        break;
                    case 'p' :
                        admin->sellYourCrypto(database->getCurrency());
                        break;
                    case 'q' :
                        logged = 0;
                        break;
                    default:
                        cout << "Wrong data! Try again" << endl;
                }
            }
            return;
        }
    }else{
        cout << "Wrong data" << endl;
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




