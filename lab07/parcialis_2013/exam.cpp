//
// Created by Orsi on 11/4/2021.
//

#include "exam.h"

Writer::Writer(const string &firstname, const string &lastname) : firstname(firstname), lastname(lastname) {}

const string &Writer::getFirstname() const {
    return firstname;
}

const string &Writer::getLastname() const {
    return lastname;
}

ostream &operator<<(ostream &os, const Writer &writer) {
    os << "Name: " << writer.firstname << " " << writer.lastname << endl;
    return os;
}

vector<Writer> loadWriters(const string &filename) {
    ifstream fin(filename);
    if(!fin) {
        exit(1);
    }

    vector<Writer> writers;
    string firstN, lastN;
    while(fin >> firstN >> lastN) {
        writers.emplace_back(Writer(firstN, lastN));
    }

    return writers;
}

void printWriters(const vector<Writer>& writers) {
    int counter = 1;
    for(const auto & writer : writers) {
        cout << counter << " ";
        cout << writer;
        counter += 1;
    }

    cout << endl;
}

Book::Book(const string &title, const vector<Writer> &writers, int publicationYear) : title(title), writers(writers),
                                                                                      publication_year(
                                                                                              publicationYear) {}

const string &Book::getTitle() const {
    return title;
}

void Book::setTitle(const string &title) {
    this->title = title;
}

int Book::getPublicationYear() const {
    return publication_year;
}

void Book::setPublicationYear(int publicationYear) {
    publication_year = publicationYear;
}

void Book::hireWriter(const Writer& writer) {
    this->writers.emplace_back(writer);
}

ostream &operator<<(ostream &os, const Book &book) {
    os << "Title: " << book.title << endl << "Writers: " << endl;
    for(const auto& writer : book.writers) {
        os << '\t' << writer;
    }
    os << "Publication year: " << book.publication_year << endl << endl;
    return os;
}

int Book::getNumberOfWriters() const {
    return this->writers.size();
}

Writer Book::getWriterGivenIndex(int index) const {
    if(index < 0 || index > this->writers.size() - 1) {
        throw out_of_range("The given index is out of range!");
    }
    return this->writers[index];
}
