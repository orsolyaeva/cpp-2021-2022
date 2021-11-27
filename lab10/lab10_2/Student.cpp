//
// Created by Orsi on 11/27/2021.
//

#include "Student.h"

Student::Student(int id, const string &firstname, const string &lastname) : ID(id), firstname(firstname),
                                                                            lastname(lastname) {}

int Student::getId() const {
    return ID;
}

const string &Student::getFirstname() const {
    return firstname;
}

const string &Student::getLastname() const {
    return lastname;
}

double Student::getAverage() const {
    return average;
}

void Student::addGrade(const string &subject, double grade) {
    this->grades.insert({subject, grade});
}

double Student::getGrade(const string &subject) const {
    auto it = this->grades.find(subject);
    if (it == this->grades.end()) {
        return -1;
    }
    return it->second;
}

map<string, double> Student::getGrades() const {
    return this->grades;
}

void Student::computeAverage() {
    double sum = 0;
    for(auto& grade : this->grades) {
        if(grade.second < 5) {
            return;
        }
        sum += grade.second;
    }
    this->average = sum / this->grades.size();
}

ostream &operator<<(ostream &os, const Student &student) {
    os << student.getId() << " " << student.getFirstname() << " " << student.getLastname() << endl;
    os << "Grades: " << endl;
    for(auto& it : student.getGrades()) {
        os << '\t' << it.first << ": " << it.second << endl;
    }
    os << "Average: " << student.getAverage() << endl << endl;
    return os;
}
