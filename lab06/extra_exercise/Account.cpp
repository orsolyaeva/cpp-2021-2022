//
// Created by Orsi on 10/27/2021.
//

#include "Account.h"

int Account::counter = 0;

Account::Account(double balance) : balance(balance), id(++counter) {}

void Account::deposit(double amount) {
    if(amount > 0) {
        this->balance += amount;
    }
}

bool Account::withdraw(double amount) {
    if(amount > this->balance) {
        cout << "Non-sufficient funds!" << endl;
        return false;
    }
    this->balance -= amount;
    return true;
}

int Account::getId() const {
    return this->id;
}

double Account::getBalance() const {
   return this->balance;
}

void Account::print(ostream &os) const {
    os << "Account ID: " << this->id << " ~~~ current balance: " << this->balance << " RON" << endl;
}

ostream &operator<<(ostream &os, const Account &account) {
    account.print(os);
    return os;
}




