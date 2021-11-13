#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <any>
using namespace std;

template <typename T>
void print(const vector<T>& vector,const string& title) {
    cout << title << ": ";
    for_each(vector.begin(), vector.end(), [](const T& element){
        cout << element << " ";
    });
    cout << endl;
}

int main(int argc, char** argv) {
     // 1.
     cout << "**************************** exercise 1 *****************************" << endl << endl;

    vector<string> fruits = {"melon", "strawberry", "raspberry","apple", "banana", "walnut", "lemon"};
    print(fruits, "Fruits");

    string find_fruit = "berry";
    auto pos = find_if(fruits.begin(), fruits.end(), [find_fruit](const string& fruit) {
        return fruit.find(find_fruit) != std::string::npos;
    });

    cout << "First fruit that contains the word \"" << find_fruit << "\": " << ((pos != fruits.end()) ? ((*pos)) : "Not found") << endl << endl;

    // 2.
    cout << "**************************** exercise 2 *****************************" << endl << endl;

    vector<int> numbers {3, 4, 6, 2, 5, 7, -2};
    print(numbers, "Numbers");

    auto is_even = all_of(numbers.begin(), numbers.end(), [](const int& num) {
        return num % 2 == 0;
    });
    cout << "All numbers are even: " << ((is_even) ? "True" : "False") << endl << endl;

    // 3.

    cout << "**************************** exercise 3 *****************************" << endl << endl;

    vector<int> numbers2 {3, 5, 6, 7, 1, 0, -1};
    print(numbers2, "Numbers");

    for_each(numbers2.begin(), numbers2.end(), [](int& num) {
        num *= 2;
    });
    print(numbers2, "Numbers x 2");
    cout << endl;

    // 4.
    cout << "**************************** exercise 4 *****************************" << endl << endl;

    vector<string> months {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
    };
    print(months, "Months");

    int letter = 5;
    auto nr_months = count_if(months.begin(), months.end(), [letter](const string& month){
        return month.size() == letter;
    });
    cout << "Nr. months with " << letter << " letter: " << nr_months << endl << endl;

    // 5.
    cout << "**************************** exercise 5 *****************************" << endl << endl;

    vector<double> numbers3 {3.4, 2.2, -1.0, 4.55, 4.56, 9};
    print(numbers3, "Numbers");

    sort(numbers3.begin(), numbers3.end(), [](const double& a, const double& b) {
        return a > b;
    });

    print(numbers3, "Lambda sort");

    auto rng = std::default_random_engine {};
    shuffle(numbers3.begin(), numbers3.end(), rng);
    print(numbers3, "Array");

    sort(numbers3.begin(), numbers3.end(), greater<double>());
    print(numbers3, "greater<> sort");
    cout << endl;

    // 6.
    cout << "**************************** exercise 6 *****************************" << endl << endl;

    vector<pair<string, double>> temperature { {"January", 20.3}, {"February", 16.5},
                                               {"March", 22.2}, {"April", 22.6}, {"May", 23},
                                               {"June", 24.5}, {"July", 28},
                                               {"August", 31.2},
                                               {"September", 29.3}, {"October", 27.3},
                                               {"November", 24.4}, {"December", 20.1} };

    sort(temperature.begin(), temperature.end(), [] (const pair<string, double> & a, const pair<string, double> & b){
        return a.second < b.second;
    });
    for_each(temperature.begin(), temperature.end(), [](const pair<string, double> & a){
        cout << a.first << ": " << a.second << endl;
    });
    cout << endl << endl;

    // 7.
    cout << "**************************** exercise 7 *****************************" << endl << endl;

    vector<double> numbers4 {-3.4, 2.2, -1.0, 4.55, -4.56, 9};
    print(numbers4, "Array");
    sort(numbers4.begin(), numbers4.end(), [](const double& a, const double& b) {
        return abs(a) < abs(b);
    });
    print(numbers4, "Sorted array");
    cout << endl;

    // 8.
    cout << "**************************** exercise 8 *****************************" << endl << endl;

    vector<string> months2 {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
    };

    for_each(months2.begin(), months2.end(), [] (string & month) {
        month[0] = tolower(month[0]);
    });
    print(months2, "Lower");
    cout << endl;

    // 9.
    cout << "**************************** exercise 9 *****************************" << endl << endl;

    vector<char> alphabet(26);
    iota(alphabet.begin(), alphabet.end(), 'a');
    auto rngABC = std::default_random_engine {};
    shuffle(alphabet.begin(), alphabet.end(), rngABC);

    print(alphabet, "Shuffled alphabet");

    sort(months2.begin(), months2.end(), [alphabet](const string& a, const string &b)
    {
        return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end(), [alphabet](const char& c1, const char& c2) {
            return find(alphabet.begin(), alphabet.end(), c1) < find (alphabet.begin(), alphabet.end(), c2);
        });
    });

    print(months2, "Strange sort");
}
