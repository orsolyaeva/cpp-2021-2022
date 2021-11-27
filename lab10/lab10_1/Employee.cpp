//
// Created by Orsi on 11/20/2021.
//

#include "Employee.h"

int Employee::counter = 0;

Employee::Employee(const string &firstname, const string &lastname, int birthdate, const string &department) : Person(
        firstname, lastname, birthdate), department(department), id(++counter) {}

void Employee::print(ostream &os) const{
    os << this->id << " ";
    Person::print(os);
    os << " " << this->department;
}

int Employee::getId() const {
    return id;
}

const string &Employee::getDepartment() const {
    return department;
}
