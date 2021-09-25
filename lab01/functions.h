//
// Created by Orsi on 9/20/2021.
//

#ifndef CPP_2021_FUNCTIONS_H
#define CPP_2021_FUNCTIONS_H

#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <utility>
#include <sstream>
#include <algorithm>

using namespace std;

void exercise1();
void exercise2();
void exercise3();
void exercise4();
void exercise5();
void exercise6();
void exercise7();
void exercise8();
void exercise9();
void exercise10();

int countBits(int number);
bool setBit(int& number, int order);
double mean(double array[], int numElements);
double stddev(double array[], int numElements);
pair<double, double> max2(double array[], int numElements);
int countWords(string text);
void printArray(double array[], int length);
string code(string text);
string decode(string text);
string capitalizeWords(string text);
map<string, int> frequencyWords(const string& file);
void sort(map<string, int>& M, int n);
bool cmp(pair<string, int>& a, pair<string, int>& b);
void printExercises();

#endif //CPP_2021_FUNCTIONS_H
