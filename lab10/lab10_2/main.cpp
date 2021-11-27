#include "Student.h"
#include "GraduationExam.h"
#include "GraduationInfo.h"

string subjects[] {"Romanian", "Hungarian", "Math"};

int main() {
    GraduationExam exam;
    exam.enrollment("names.txt");
    exam.readGradesOfSubject(subjects[0], "romanian.txt");
    exam.readGradesOfSubject(subjects[1], "hungarian.txt");
    exam.readGradesOfSubject(subjects[2], "math.txt");
    exam.computeFinalGrades();

    IGraduation * graduation = new GraduationInfo( exam );
    cout<<"Graduation Information"<<endl;
    cout<<"Number of enrolled students: "<<graduation->getNumEnrolled()<<endl;
    cout<<"Number of passed students: "<<graduation->getNumPassed()<<endl;
    cout<<"Number of failed students: "<<graduation->getNumFailed()<<endl << endl;
    int ID;
    for( ;; ){
        cout<<"Enter an ID < 0 for termination>:";
        cin>>ID;
        if( ID <= 0 ){
            break;
        }
        cout<<"Information:"<<endl;
        try{
            const Student& student = graduation->getStudent( ID );
            cout<<student<<endl;
        }catch( domain_error& e){
            cout<<e.what()<<endl<<endl;
        }
    }

    delete graduation;
    return 0;
}
