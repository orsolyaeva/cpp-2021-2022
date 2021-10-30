//
// Created by Orsi on 10/27/2021.
//

#include "Customer.h"

int Customer::counter = 0;

Customer::Customer(const string &firstName, const string &lastName): firstName(firstName), lastName(lastName), id(++counter) {}

const string &Customer::getFirstName() const {
    return this->firstName;
}

void Customer::setFirstName(const string &firstName) {
    this->firstName = firstName;
}

const string &Customer::getLastName() const {
    return this->lastName;
}

void Customer::setLastName(const string &lastName) {
    this->lastName = lastName;
}

Account &Customer::getAccount(int id) {
    for(auto & account : this->accounts) {
        if(account.getId() == id) {
            return (Account&)account;
        }
    }
    throw out_of_range("The given account ID not exists!\n");
}

int Customer::newAccount(double balance) {
    this->accounts.emplace_back(Account(balance));
    return this->accounts.back().getId();
}

bool Customer::deleteAccount(int id) {
    for(int i = 0; i < this->accounts.size(); i++) {
        if(this->accounts[i].getId() == id) {
            this->accounts.erase(this->accounts.begin() + i);
            return true;
        }
    }
    return false;
}

int Customer::getNumAccounts() const {
    return this->accounts.size();
}

void Customer::print(ostream &os) const {
    os << "Customer ID: " << this->id << " ~~~ Name: " << this->firstName << " " << this->lastName << endl;
    os << "Accounts: " << endl;

    if(this->accounts.empty()) {
        os << '\t' << "This costumer has no accounts yet!" << endl << endl;
        return;
    }

    for(auto account : this->accounts) {
        os << '\t' << account;
    }
    os << endl;
}

Account &Customer::operator[](int index) {
   if(index < 0 || index > this->accounts.size()) {
       throw out_of_range("The given index is out of range!\n");
   }
   return (Account&)this->accounts[index];
}

const Account &Customer::operator[](int index) const {
    if(index < 0 || index > this->accounts.size()) {
        throw out_of_range("The given index is out of range!\n");
    }
    return (Account&)this->accounts[index];
}

ostream &operator<<(ostream &os, const Customer &customer) {
    customer.print(os);
    return os;
}
