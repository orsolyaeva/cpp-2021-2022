//
// Created by Orsi on 11/27/2021.
//

#ifndef LAB10_2_STUDENT_H
#define LAB10_2_STUDENT_H

#include <iostream>
#include <fstream>
#include <map>
using namespace std;

class Student {
private:
    int ID;
    string firstname, lastname;
    map<string, double> grades;
    double average {0};
public:
    Student(int id, const string &firstname, const string &lastname);
    int getId() const;
    const string &getFirstname() const;
    const string &getLastname() const;
    double getAverage() const;
    void addGrade(const string& subject, double grade);
    double getGrade(const string& subject) const;
    map<string, double> getGrades() const;
    void computeAverage();
    friend ostream& operator<<(ostream& os, const Student& student);
};

#endif //LAB10_2_STUDENT_H
