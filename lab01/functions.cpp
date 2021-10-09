//
// Created by Orsi on 9/20/2021.
//

#include "functions.h"

void exercise1(){
//    int n;
//    cout<<"Enter a number:";
//    cin>>n;

//    cout<<"Number of set bits: "<<countBits(n);

    for(int i = 0; i < 128; i++){
        cout << "Number: "<< i <<", set bits: " << countBits(i) << endl;
    }
}

void exercise2() {
    for (int i = 0; i < 35; ++i) {
        int n = 0;
        if(setBit(n, i)){
            cout << i << " ---> " << n <<endl;
        }else{
            cout << "Impossible operation!" << endl;
        }
    }
}

void exercise3(){
    /*          Case 1: Ordinary (Average) array        */

    double array[] = {12.22, 33, 54};
    int n = sizeof(array) / sizeof(array[0]);

    printArray(array, n);
    cout << "\nAverage: " << mean(array, n) << endl << endl;


    /*          Case 2: Empty array        */

    double array2[] = {};
    int n2 = sizeof(array2) / sizeof(array2[0]);
    printArray(array2, n2);
    cout << endl << "Average: " << mean(array2, n2) << endl;
}

void exercise4() {
    /*          Case 1: Ordinary (Average) array        */

    double array[] = {10.2, 3.22, 45.3, -1.2};
    int n = sizeof(array) / sizeof(array[0]);

    printArray(array, n);
    cout << "Standard Deviation: " << stddev(array, n) << endl << endl;


    /*          Case 2: Empty array        */

    double array2[] = {};
    int n2 = sizeof(array2) / sizeof(array2[0]);

    printArray(array2, n2);
    cout << "Standard Deviation: " << stddev(array2, n2);
}

void exercise5() {
    /*          Case 1: Ordinary (Average) array        */

    double array[] = {10.2, 3.22, 45.3, -1.2};
    int n = sizeof(array) / sizeof(array[0]);

    printArray(array, n);
    pair<double, double> result = max2(array, n);
    cout<<"Largest: " << result.first << endl << "Second Largest: " << result.second << endl << endl;


    /*          Case 2: Array with a single element         */

    double array2[] = {10.2};
    int n2 = sizeof(array2) / sizeof(array2[0]);

    printArray(array2, n2);
    pair<double, double> result2 = max2(array2, n2);
    cout<<"Largest: " << result2.first << endl << "Second Largest: " << result2.second << endl << endl;


    /*          Case 3: Empty array        */

    double array3[] = {};
    int n3 = sizeof(array3) / sizeof(array3[0]);

    printArray(array3, n3);
    pair<double, double> result3 = max2(array3, n3);
    cout<<"Largest: " << result3.first << endl << "Second Largest: " << result3.second << endl << endl;
}

void exercise6() {
    istringstream string("123 alma 123 korte");
    double sum, number;

    while(string) {
        string >> number;
        sum += number;
    }

    cout << "Sum: " << sum;
}

void exercise7() {
    string text = "2 3 chocolate vanilla caramel 4";

    cout << "Number of words: " << countWords(text);
}

void exercise8() {
    string text = "He, Zack, was born in 1892, march.";
    text = code(text);
    cout<< "Coded: " << text << endl;
    cout << "Decoded: " << decode(text);
}

void exercise9() {
    string text;
    cout << "Enter the text (to finish enter an empty line):";

    fflush(stdin);

    while (getline(cin, text) && !text.empty()) {
        cout << capitalizeWords(text) << endl;
    }
}

void exercise10() {
    map<string, int> freq_words; // we store the word and it's frequency in a map
    int n;
    string file_name;

    cout << "Enter the filename (location):";
    cin >> file_name;

    cout << "Enter n:";
    cin >> n;

//    freq_words = frequencyWords("C:\\Users\\Orsi\\Desktop\\Egyetem\\CPP\\cpp-labor\\lab01\\cmake-build-debug\\input.txt");
    freq_words = frequencyWords(file_name);
    sort(freq_words, n); // sort the map in decreasing order
}

// function to sort the map according to value
void sort(map<string, int>& M, int n)
{
    vector<pair<string, int>> A;

    // Copy key-value pair from Map to vector
    for (auto& it : M) {
        A.push_back(it);
    }

    sort(A.begin(), A.end(), cmp);

    // print the result
    for(int i = 0; i < n; i++) {
        cout << A[i].first << " " << A[i].second << endl;
    }
}

// Comparator function to sort pairs according to value
bool cmp(pair<string, int>& a, pair<string, int>& b)
{
    return a.second > b.second;
}

map<string, int> frequencyWords(const string& file) {
    ifstream input(file); // open the file

    if(!input) {
        exit(2);
    }

    map<string, int> freq; // create a map which stores the frequency of the words
    string word, chars_to_delete = ",.()?!;:'-";

    while(input >> word) { // reading the file by word
        transform(word.begin(), word.end(), word.begin(), ::tolower); // convert whole text to lowercase

        // loop to delete every additional character
        for (char & i : chars_to_delete) {
            word.erase(std::remove(word.begin(), word.end(), i), word.end());
        }

        freq[word] += 1; // increment the current word's occurrence
    }

    return freq;
}


string capitalizeWords(string text) {
    transform(text.begin(), text.end(), text.begin(), ::tolower); // convert whole text to lowercase
    text[0] = toupper(text[0]); // convert first letter
    for(int i = 1; i < text.length(); i++) {
        if(text[i - 1] == ' ') { // if there is a space before = new word
           text[i] = toupper(text[i]);
        }
    }

    return text;
}

string code(string text) {
    for(int i = 0; i < text.length(); i++) { // we go through the text letter by letter
        if(isalpha(text[i])) { // if the character is a letter
           if(text[i] == 'z') {
               text[i] = 'a';
           } else if(text[i] == 'Z') {
               text[i] = 'A';
           } else  {
               text[i] += 1;
           }
        }
    }

    return text;
}

string decode(string text) {
    for(int i = 0; i < text.length(); i++) {
        if(isalpha(text[i])) {
            if(text[i] == 'a') {
                text[i] = 'z';
            } else if(text[i] == 'A') {
                text[i] = 'Z';
            } else  {
                text[i] -= 1;
            }
        }
    }

    return text;
}

int countWords(string text) { // function to count the number of the words of a text
    istringstream iss(text);
    string temp;
    int counter = 0;

    while(iss) {
        iss >> temp;
        counter++;
    }

    return counter;
}

pair<double, double> max2(double array[], int numElements) { // function to return the first 2 largest element of array
    pair<double, double> PAIR {NAN, NAN};

    if(numElements == 0) { // if the array is empty
        return PAIR;
    }

    if(numElements == 1) { // if the array has a single element
        PAIR.first = PAIR.second = array[0];
        return PAIR;
    }

    // initialize the PAIR in ascending order ( first >= second )
    PAIR.first = array[0] > array[1] ? array[0] : array[1];
    PAIR.second = array[0] < array[1] ? array[0] : array[1];

    if(numElements == 2) { // if the array has 2 elements return the pair
        return PAIR;
    }

    for(int i = 2; i < numElements; i++) {
        if(array[i] > PAIR.first) {
            PAIR.second = PAIR.first;
            PAIR.first = array[i];
        }
        else if (array[i] > PAIR.second) {
            PAIR.second = array[i];
        }
    }

    return PAIR;
}

double stddev(double array[], int numElements) { // function to return the standard deviation of array
    if(numElements <= 0) { // if the array is empty
        return NAN;
    }

    double stddev = 0.0, mean, sum = 0.0;

    for(int i = 0; i < numElements; i++){
        sum += array[i];
    }

    mean = sum / numElements;

    // for each data point, find the square of its distance to the mean and sum the values
    for(int i = 0; i < numElements; i++){
        stddev += pow(array[i] - mean, 2);
    }

    return sqrt(stddev / numElements);
}

double mean(double array[], int numElements) { // function to return average of given array
    if(numElements <= 0) { // if the array is empty
        return NAN;
    }

    double average = 0;

    for(int i = 0; i < numElements; i++) {
        average += array[i];
    }

    return average / numElements;
}

int countBits(int number) { // function to count the number of set bits of a positive integer
    int counter = 0;

    // loop through all bits in an integer
    while(number) {
        counter += number & 1; // check if a bit is set and increment the counter
        number >>= 1;
    }

    return counter;
}

bool setBit(int& number, int order) { // set K-th bit of a number
    if (order > 31 || order < 0) { // if the given order is out of range
        return false;
    }

    number |= ( 1 << order ); // set the "order"th bit of the number
    return true;
}

void printArray(double array[], int length) { // function to print a given array
    cout << "Array: ";

    if(length == 0) {
        cout << "{ }";
    } else {
        cout << "{ ";
        for(int i = 0; i < length; i++) {
            cout << array[i] <<" ";
        }
        cout << "}";
    }

    cout << endl;
}

void printExercises() {
    cout << "1. Count set bits of a number" << endl;
    cout << "2. Set Kth bit of a number" << endl;
    cout << "3. Average of array" << endl;
    cout << "4. Standard Deviation of array" << endl;
    cout << "5. First 2 greatest elements of array" << endl;
    cout << "6. Count sum of numbers in a string" << endl;
    cout << "7. Count number of words in a string" << endl;
    cout << "8. Code and Decode a string" << endl;
    cout << "9. Capitalize Words" << endl;
    cout << "10. Extra exercise" << endl << endl;
}