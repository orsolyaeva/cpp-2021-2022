#include "exam.h"

int main() {
    Writer writer1("Nyitrai", "Orsolya");
    cout << writer1;

    Writer * writer2 = new Writer("Nyitrai", "Orsolya");
    cout << *writer2;

    vector<Writer> writers = loadWriters("input.txt");
    printWriters(writers);

    writers.emplace_back(writer1);
    writers.emplace_back(*writer2);

    printWriters(writers);

    vector<Book> books;
    vector<Writer> writers1;

    string temp_title, firstname, lastname;
    int year, n;

    cout << "Number of books you would like to enter:";
    cin >> n;

    for(int i = 0; i < n; i++) {
        writers1.clear();
        fflush(stdin);
        cout << "Book title:";
        getline(cin, temp_title);
        int nr_writer;
        cout << "Number of writers:";
        cin >> nr_writer;
        for(int j = 0; j < nr_writer; j++) {
            cout << "Writer " << j + 1 << "\nFirstname:";
            cin >> firstname;
            cout << "Lastname:";
            cin >> lastname;
            writers1.emplace_back(Writer(firstname, lastname));
        }
        cout << "Year:";
        cin >> year;
        books.emplace_back(Book(temp_title, writers1, year));
    }

    for_each(books.begin(), books.end(), [](const Book& book){
        cout << book;
    });

    for_each(books.begin(), books.end(), [](const Book& book){
        if(book.getPublicationYear() > 1989 && book.getNumberOfWriters() == 1) { cout << book; }
    });
}
