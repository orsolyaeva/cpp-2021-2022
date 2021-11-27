//
// Created by Orsi on 11/25/2021.
//

#include "Company.h"

void Company::addEmployee(Employee *employee) {
    this->employees.emplace_back(employee);
}

void Company::deleteEmployee(int id) {
    this->employees.erase(remove_if(this->employees.begin(), this->employees.end(), [id](Employee *emp) {
        return emp->getId() == id;
    }), this->employees.end());
}

void Company::assignEmployeeToManager(Employee *employee, Manager *manager) {
    manager->addEmployee(employee);
}

void Company::removeEmployeeFromManager(Employee* employee, Manager* manager) {
    manager->deleteEmployee(employee->getId());
}

void Company::listEmployees() const {
    for(auto& emp : this->employees) {
        cout << *emp << endl;
    }
}

void Company::listManagers() const {
    for(auto& emp : this->employees) {
        if(instanceof<Manager>(emp)) {
            Manager * m = dynamic_cast<Manager*>(emp);
            m->print(std::cout);
        }
    }
}

void readEmployeesFromFile(const string& filename, vector<Employee*>& employees, vector<Manager*>& managers) {
    fstream fin(filename);
    if(!fin) {
        exit(1);
    }

    vector<string> row;
    string line, temp, word;
    int nr_employees = 7;

    while(getline(fin, line)) {
        row.clear();
        stringstream s(line);
        while(getline(s, word, ',')) {
            row.emplace_back(word);
        }

        if(nr_employees) {
            employees.emplace_back(new Employee(row[0], row[1], stoi(row[2]), row[3]));
            nr_employees--;
        } else {
            managers.emplace_back(new Manager(row[0], row[1], stoi(row[2]), row[3]));
        }
    }
}
