//
// Created by Orsi on 11/27/2021.
//

#ifndef LAB10_2_IGRADUATION_H
#define LAB10_2_IGRADUATION_H

#include "Student.h"

class IGraduation {
public:
    virtual int getNumEnrolled() const = 0;
    virtual int getNumPassed() const = 0;
    virtual int getNumFailed() const = 0;
    virtual Student getStudent(int ID) const = 0;
    virtual string getFirstName(int ID) const = 0;
    virtual string getLastName(int ID) const = 0;
    virtual double getAverage(int ID) const = 0;
    virtual map<string, double> getResults(int ID) const = 0;
    virtual void printResults(ostream& os) const = 0;
    virtual void printPassed(ostream& os) const = 0;
    virtual void printFailed(ostream& os) const = 0;
};

#endif //LAB10_2_IGRADUATION_H
