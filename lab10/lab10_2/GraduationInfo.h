//
// Created by Orsi on 11/27/2021.
//

#ifndef LAB10_2_GRADUATIONINFO_H
#define LAB10_2_GRADUATIONINFO_H

#include "IGraduation.h"
#include "GraduationExam.h"

class GraduationInfo : public IGraduation {
private:
    GraduationExam& graduationExam;
public:
    GraduationInfo(GraduationExam &graduationExam);
    int getNumEnrolled() const override;
    int getNumPassed() const override;
    int getNumFailed() const override;
    Student getStudent(int ID) const override;
    string getFirstName(int ID) const override;
    string getLastName(int ID) const override;
    double getAverage(int ID) const override;
    map<string, double> getResults(int ID) const override;
    void printResults(ostream &os) const override;
    void printPassed(ostream &os) const override;
    void printFailed(ostream &os) const override;
};

#endif //LAB10_2_GRADUATIONINFO_H
