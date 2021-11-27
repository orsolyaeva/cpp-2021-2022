//
// Created by Orsi on 11/27/2021.
//

#ifndef LAB10_2_GRADUATIONEXAM_H
#define LAB10_2_GRADUATIONEXAM_H

#include "Student.h"

class GraduationInfo;
class GraduationExam {
private:
    int year;
    map<int, Student> students;
    friend class GraduationInfo;
public:
    void enrollment(const string& filename);
    int numStudents() const;
    void readGradesOfSubject(const string& subject, const string& filename);
    void computeFinalGrades();
    map<string, double> getGrades(int ID) const;
    int numPassed() const;
};

#endif //LAB10_2_GRADUATIONEXAM_H
