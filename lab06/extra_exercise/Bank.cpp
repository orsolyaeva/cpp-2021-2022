//
// Created by Orsi on 10/27/2021.
//

#include "Bank.h"

Bank::Bank(const string &name) : name(name) {}

int Bank::newCustomer(const string &firstName, const string &lastName) {
    this->customers.emplace_back(Customer(firstName, lastName));
    return this->customers.back().getId();
}

bool Bank::deleteCustomer(int id) {
    for(int i = 0; i < this->customers.size(); i++) {
        if(this->customers[i].getId() == id) {
            this->customers.erase(this->customers.begin() + i);
            return true;
        }
    }
    return false;
}

Customer &Bank::getCustomer(int id) {
    for(auto & customer : this->customers) {
        if(customer.getId() == id) {
            return (Customer&)customer;
        }
    }
    throw out_of_range("The given account ID not exists!\n");
}

void Bank::printCustomers(ostream &os) const {
    for(auto& customer : this->customers) {
        os << "Customer ID: " << customer.getId() << " ~~~ Name: " << customer.getFirstName() << " " << customer.getLastName() << endl;
    }
    os << endl;
}

void Bank::printCustomersAndAccounts(ostream &os) const {
    os << "Name: " << this->name << endl;
    for(auto & customer : this->customers) {
        os << customer;
    }
    os << endl;
}

vector<int> Bank::loadCustomers(const string &filename) {
    ifstream fin(filename);
    if(!fin) {
        cout << "File not found!" << endl;
        return {};
    }
    vector<int> result;
    string firstname, lastname;
    while(fin >> firstname >> lastname) {
        result.emplace_back(newCustomer(firstname, lastname));
    }
    return result;
}

