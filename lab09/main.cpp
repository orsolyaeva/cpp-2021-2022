#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
using namespace std;

int main(int argc, char** argv) {
    // 1.
//    vector<string> fruits = {"melon", "strawberry", "raspberry","apple", "banana", "walnut", "lemon"};
//    string find_fruit = "berry";
//    auto pos = find_if(fruits.begin(), fruits.end(), [find_fruit](const string& fruit) {
//        return fruit.find(find_fruit) != std::string::npos;
//    });
//    cout << ((pos != fruits.end()) ? ((*pos)) : "Not found");

    // 2.
//    vector<int> numbers {3, 4, 6, 2, 5, 7, -2};
//    auto is_even = all_of(numbers.begin(), numbers.end(), [](const int& num) {
//        return num % 2 == 0;
//    });
//    cout << "All numbers are even: " << ((is_even) ? "True" : "False") << endl;

    // 3.
//    vector<int> numbers2 {3, 5, 6, 7, 1, 0, -1};
//    for_each(numbers2.begin(), numbers2.end(), [](int& num) {
//        num *= 2;
//    });
//    for_each(numbers2.begin(), numbers2.end(), [](const int& num) { cout << num << " "; });
//    cout << endl;

    // 4.
//    vector<string> months {
//            "January", "February", "March", "April", "May", "June",
//            "July", "August", "September", "October", "November", "December"
//    };
//    int letter = 5;
//    auto nr_months = count_if(months.begin(), months.end(), [letter](const string& month){
//        return month.size() == letter;
//    });
//    cout << "Months with " << letter << " letter: " << nr_months << endl;

    // 5.
//    vector<double> numbers3 {3.4, 2.2, -1.0, 4.55, 4.56, 9};
//    cout << "Array: ";
//    for_each(numbers3.begin(), numbers3.end(), [](const double& num) { cout << num << " "; });
//    cout << endl;
//    sort(numbers3.begin(), numbers3.end(), [](const double& a, const double& b) {
//        return a > b;
//    });
//    cout << "Lambda sort: ";
//    for_each(numbers3.begin(), numbers3.end(), [](const double& num) { cout << num << " "; });
//    cout << endl << endl;
//
//    auto rng = std::default_random_engine {};
//    shuffle(numbers3.begin(), numbers3.end(), rng);
//    cout << "Array: ";
//    for_each(numbers3.begin(), numbers3.end(), [](const double& num) { cout << num << " "; });
//    cout << endl;
//
//    sort(numbers3.begin(), numbers3.end(), greater<double>());
//    cout << "greater<> sort: ";
//    for_each(numbers3.begin(), numbers3.end(), [](const double& num) { cout << num << " "; });
//    cout << endl;

    // 6.
//    vector<pair<string, double>> temperature { {"January", 20.3}, {"February", 16.5},
//                                               {"March", 22.2}, {"April", 22.6}, {"May", 23},
//                                               {"June", 24.5}, {"July", 28},
//                                               {"August", 31.2},
//                                               {"September", 29.3}, {"October", 27.3},
//                                               {"November", 24.4}, {"December", 20.1} };
//    sort(temperature.begin(), temperature.end(), [] (const pair<string, double> & a, const pair<string, double> & b){
//        return a.second < b.second;
//    });
//    for_each(temperature.begin(), temperature.end(), [](const pair<string, double> & a){
//        cout << a.first << ": " << a.second << endl;
//    });

    // 7.
//    vector<double> numbers4 {-3.4, 2.2, -1.0, 4.55, -4.56, 9};
//    cout << "Array: ";
//    for_each(numbers4.begin(), numbers4.end(), [](const double& num) { cout << num << " "; });
//    cout << endl;
//    sort(numbers4.begin(), numbers4.end(), [](const double& a, const double& b) {
//        return abs(a) < abs(b);
//    });
//    cout << "Sorted: ";
//    for_each(numbers4.begin(), numbers4.end(), [](const double& num) { cout << num << " "; });
//    cout << endl;

 // 8.
    vector<string> months2 {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
    };
    for_each(months2.begin(), months2.end(), [] (string & month) {
        month[0] = tolower(month[0]);
    });
    for_each(months2.begin(), months2.end(), [](const string& month) { cout << month << " "; });
    cout << endl;

    // 9.
    vector<char> alphabet(26);
    iota(alphabet.begin(), alphabet.end(), 'a');
    auto rng1 = std::default_random_engine {};
    shuffle(alphabet.begin(), alphabet.end(), rng1);

    cout << "Shuffled alphabet: ";
    for_each(alphabet.begin(), alphabet.end(), [](const char& a) {
        cout << a << " ";
    });
    cout << endl;

    // find(alphabet.begin(), alphabet.end(), a[0]) < find(alphabet.begin(), alphabet.end(), b[0]);
    sort(months2.begin(), months2.end(), [alphabet](const string& a, const string &b)
    {
        return
    });
    for_each(months2.begin(), months2.end(), [](const string& month) { cout << month << " "; });

}
