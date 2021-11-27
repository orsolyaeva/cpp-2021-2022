//
// Created by Orsi on 11/20/2021.
//

#ifndef LAB10_1_MANAGER_H
#define LAB10_1_MANAGER_H

#include "Employee.h"
#include <vector>
#include <algorithm>

class Manager: public Employee {
private:
    vector<Employee*> employees;
public:
    static const string Manager_Department;
    Manager(const string &firstname, const string &lastname, int birthdate, const string &department);
    void addEmployee(Employee* emp);
    void deleteEmployee(int id);
    int getNumberEmployees();
    void print(ostream& os);
};


#endif //LAB10_1_MANAGER_H
