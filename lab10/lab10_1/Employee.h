//
// Created by Orsi on 11/20/2021.
//

#ifndef LAB10_1_EMPLOYEE_H
#define LAB10_1_EMPLOYEE_H

#include "Person.h"

class Employee : public Person {
protected:
    int id;
    string department;
    static int counter;
public:
    Employee(const string &firstname, const string &lastname, int birthdate, const string &department);
    virtual void print(ostream& os) const;

    int getId() const;
    const string &getDepartment() const;
};
#endif //LAB10_1_EMPLOYEE_H
