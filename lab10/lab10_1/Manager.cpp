//
// Created by Orsi on 11/20/2021.
//

#include "Manager.h"

const string Manager::Manager_Department = "manager";

Manager::Manager(const string &firstname, const string &lastname, int birthdate, const string &department) : Employee(
        firstname, lastname, birthdate, department) {}

void Manager::addEmployee(Employee *emp) {
    this->employees.emplace_back(emp);
}

//void Manager::deleteEmployee(Employee *emp) {
//    this->employees.erase(std::remove(this->employees.begin(), this->employees.end(), emp), this->employees.end());
//}

int Manager::getNumberEmployees() {
    return this->employees.size();
}

void Manager::print(ostream &os) {
    os << "Manager " << this->id << " " << this->firstname << " " << this->lastname;
    os << " employees: " << endl;
    for(auto emp : this->employees) {
        os << "\t Employee ";
        emp->print(os);
        os << endl;
    }
    os << endl;
}

void Manager::deleteEmployee(int id) {
    this->employees.erase(std::remove_if(this->employees.begin(), this->employees.end(), [id](Employee *emp) {
        return emp->getId() == id;
    }), this->employees.end());
}
