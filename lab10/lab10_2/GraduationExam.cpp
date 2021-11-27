//
// Created by Orsi on 11/27/2021.
//

#include "GraduationExam.h"

void GraduationExam::enrollment(const string &filename) {
    fstream fin(filename);
    if(!fin) {
        exit(1);
    }

    int id;
    string firstname, lastname;

    while(fin >> id) {
        fin >> firstname >> lastname;
        this->students.insert(make_pair(id, *(new Student(id, firstname, lastname))));
    }

    fin.close();
}

int GraduationExam::numStudents() const {
    return this->students.size();
}

void GraduationExam::readGradesOfSubject(const string &subject, const string &filename) {
    fstream fin(filename);
    if(!fin) {
        exit(2);
    }

    int id;
    double grade;

    while(fin >> id >> grade) {
        auto it = this->students.find(id);
        if(it != this->students.end()) {
            it->second.addGrade(subject, grade);
        }
    }
}

void GraduationExam::computeFinalGrades() {
    for(auto& student : this->students) {
        student.second.computeAverage();
    }
}

map<string, double> GraduationExam::getGrades(int ID) const {
    auto it = this->students.find(ID);
    if(it != this->students.end()) {
        return it->second.getGrades();
    }
    throw domain_error("Could not find student with given ID!");
}

int GraduationExam::numPassed() const {
    int counter = 0;
    for(auto& student : this->students) {
        if(student.second.getAverage() >= 6) {
            ++counter;
        }
    }
    return counter;
}
