#include "Company.h"

int main() {
    Company company;
    vector<Employee*> employees;
    vector<Manager*> managers;

    readEmployeesFromFile("employees.txt", employees, managers);

    for(auto& emp : employees) {
        company.addEmployee(emp);
    }

    for(auto& man : managers) {
        company.addEmployee(man);
    }

    cout << "All employees of the company: " << endl;
    company.listEmployees();

    for(auto& manager : managers) {
        for(auto& emp : employees) {
            if(manager->getDepartment() == emp->getDepartment()) {
                manager->addEmployee(emp);
            }
        }
    }

    cout << endl << "Managers of the company: " << endl;
    company.listManagers();

    company.removeEmployeeFromManager(employees[0], managers[1]);
    company.assignEmployeeToManager(employees[0], managers[0]);

    cout << endl << endl << "Bellman Ford: FROM Mike Barker ---->  TO Jose Wells" << endl;
    cout << endl << "Managers of the company: " << endl;
    company.listManagers();
}
