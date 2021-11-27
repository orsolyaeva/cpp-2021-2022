//
// Created by Orsi on 11/20/2021.
//

#include "Person.h"

Person::Person(const string &firstname, const string &lastname, int birthdate) : firstname(firstname),
                                                                                 lastname(lastname),
                                                                                 birthdate(birthdate) {}

void Person::print(ostream &os) const {
    os << this->firstname << " " << this->lastname;
//       "\nBirthdate: " << this->birthdate << endl;
}

ostream& operator<<(ostream &os, const Person &person) {
    person.print(os);
    return os;
}