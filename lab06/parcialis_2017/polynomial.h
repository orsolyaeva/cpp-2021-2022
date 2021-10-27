//
// Created by Orsi on 10/25/2021.
//

#ifndef PARCIALIS_2017_POLYNOMIAL_H
#define PARCIALIS_2017_POLYNOMIAL_H

#include <iostream>
#include <limits>

using namespace std;

class Polynomial {
/* coefficients of polynomial */
    double *coefficients;
/* number of coefficient */
    int capacity;
public:
/* Default constructor */
    Polynomial(int degree = 0, const double coefficients[] = {});
/* Copy constructor */
    Polynomial(const Polynomial &that);
/* Move constructor */
    Polynomial(Polynomial &&that);
/* Destructor */
    ~Polynomial();
/* Return the degree of polynomial (the highest power with a non-zero coefficients) */
    int degree() const;
/* Evaluate a polynomial for a specified value of X */
    double evaluate(double x) const;
/* Compute the derivative of a polynomial */
    Polynomial derivative() const;
/* Returns coefficient in given index */
    double operator[](int index) const;
/* Multiply every coefficient of polynomials with -1 */
    friend Polynomial operator -(const Polynomial &a);
/* addition operator: add two polynomials together and return a new polynomial that is the result  */
    friend Polynomial operator +(const Polynomial &a, const Polynomial &b);
/* subtraction operator: subtract two polynomials and return a new polynomial that is the result */
    friend Polynomial operator -(const Polynomial &a, const Polynomial &b);
/* multiplication operator: multiply two polynomials and return a new polynomial that is the result */
    friend Polynomial operator *(const Polynomial &a, const Polynomial &b);
/* insertion operator for output */
    friend ostream & operator <<(ostream& out, const Polynomial& what);

/* copy assignment - disable deep copy */
    Polynomial& operator=(const Polynomial&) = delete;
/* move assignment - disable shallow-copy */
    Polynomial& operator=(Polynomial&&) = delete;
};

/* check if all the polynomial coefficient are valid - there is at least 1 non-zero value */
bool validCoefficient(const double * coefficient, const int& degree);

/* Functions to test polynomial class implementation - User Interface */
void printExercises();
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
void exercise11();


#endif //PARCIALIS_2017_POLYNOMIAL_H
