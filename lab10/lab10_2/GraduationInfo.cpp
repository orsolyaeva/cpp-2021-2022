//
// Created by Orsi on 11/27/2021.
//

#include "GraduationInfo.h"

GraduationInfo::GraduationInfo(GraduationExam &graduationExam) : graduationExam(graduationExam) {}

int GraduationInfo::getNumEnrolled() const {
    return graduationExam.numStudents();
}

int GraduationInfo::getNumPassed() const {
    return graduationExam.numPassed();
}

int GraduationInfo::getNumFailed() const {
    return graduationExam.numStudents() - graduationExam.numPassed();
}

Student GraduationInfo::getStudent(int ID) const {
    auto it = graduationExam.students.find(ID);
    if(it != graduationExam.students.end()) {
        return it->second;
    }
    throw domain_error("Could not find student with given ID!");
}

string GraduationInfo::getFirstName(int ID) const {
    auto it = graduationExam.students.find(ID);
    if(it != graduationExam.students.end()) {
        return it->second.getFirstname();
    }
    throw domain_error("Could not find student with given ID!");
}

string GraduationInfo::getLastName(int ID) const {
    auto it = graduationExam.students.find(ID);
    if(it != graduationExam.students.end()) {
        return it->second.getLastname();
    }
    throw domain_error("Could not find student with given ID!");
}

double GraduationInfo::getAverage(int ID) const {
    auto it = graduationExam.students.find(ID);
    if(it != graduationExam.students.end()) {
        return it->second.getAverage();
    }
    throw domain_error("Could not find student with given ID!");
}

map<string, double> GraduationInfo::getResults(int ID) const {
    return graduationExam.getGrades(ID);
}

void GraduationInfo::printResults(ostream &os) const {
    for(auto& student : graduationExam.students) {
        cout << student.second;
    }
}

void GraduationInfo::printPassed(ostream &os) const {
    for(auto& student : graduationExam.students) {
        if(student.second.getAverage() >= 6) {
            cout << student.second;
        }
    }
}

void GraduationInfo::printFailed(ostream &os) const {
    for(auto& student : graduationExam.students) {
        if(student.second.getAverage() < 6) {
            cout << student.second;
        }
    }
}
