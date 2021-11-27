//
// Created by Orsi on 11/20/2021.
//

#ifndef LAB10_1_PERSON_H
#define LAB10_1_PERSON_H

#include <iostream>
#include <string>
using namespace std;

template <typename Base, typename T>
inline bool instanceof(const T* t) {
    return dynamic_cast <const Base*>(t) != nullptr;
}

class Person {
protected:
    string firstname, lastname;
    int birthdate;
public:
    Person(const string &firstname, const string &lastname, int birthdate);
    virtual void print(ostream& os) const;
};

ostream& operator<<(ostream &os, const Person& person);


#endif //LAB10_1_PERSON_H
