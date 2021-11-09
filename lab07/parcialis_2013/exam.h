//
// Created by Orsi on 11/4/2021.
//

#ifndef PARCIALIS_2013_EXAM_H
#define PARCIALIS_2013_EXAM_H

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

class Writer{
private:
    string firstname;
    string lastname;

public:
    Writer(const string &firstname, const string &lastname);
    const string &getFirstname() const;
    const string &getLastname() const;

    friend ostream &operator<<(ostream &os, const Writer &writer);
};

class Book {
private:
    string title;
    vector<Writer> writers;
    int publication_year;
public:
    Book(const string &title, const vector<Writer> &writers, int publicationYear);
    const string &getTitle() const;
    void setTitle(const string &title);
    int getPublicationYear() const;
    void setPublicationYear(int publicationYear);
    void hireWriter(const Writer& writer);
    int getNumberOfWriters() const;
    Writer getWriterGivenIndex(int index) const;

    friend ostream &operator<<(ostream &os, const Book &book);
};

vector<Writer> loadWriters(const string& filename);
void printWriters(const vector<Writer>& writers);

#endif //PARCIALIS_2013_EXAM_H
