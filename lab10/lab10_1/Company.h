//
// Created by Orsi on 11/25/2021.
//

#ifndef LAB10_1_COMPANY_H
#define LAB10_1_COMPANY_H

#include "Manager.h"
#include <fstream>
#include <sstream>

class Company {
private:
    vector<Employee*> employees;
public:
    void addEmployee(Employee *employee);
    void deleteEmployee(int id);
    void assignEmployeeToManager(Employee* employee, Manager* manager);
    void removeEmployeeFromManager(Employee* employee, Manager* manager);
    void listEmployees() const;
    void listManagers() const;
};

void readEmployeesFromFile(const string& filename, vector<Employee*>& employees, vector<Manager*>& managers);

#endif //LAB10_1_COMPANY_H
