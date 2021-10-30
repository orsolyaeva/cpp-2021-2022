//
// Created by Orsi on 10/25/2021.
//

#include "polynomial.h"

/* Default constructor */
Polynomial::Polynomial(int degree, const double *coefficients) {
    if(degree < 0 || !validCoefficient(coefficients, degree)) {
        throw invalid_argument("The degree of the polynomial must be a positive number and you must have at least 1 non-zero coefficient!");
    }

    this->capacity = degree + 1; // number of coefficients = degree + 1
    this->coefficients = new double[this->capacity];

    for(int i = 0; i < this->capacity; i++) {
        this->coefficients[i] = coefficients[i];
    }
}

/* Copy constructor */
Polynomial::Polynomial(const Polynomial &that) {
   this->capacity = that.capacity;
    this->coefficients = new double[that.capacity];

    for(int i = 0; i < that.capacity; i++) {
        this->coefficients[i] = that.coefficients[i];
    }
}

/* Move constructor */
Polynomial::Polynomial(Polynomial &&that) {
   // move that to this
     this->capacity = that.capacity;
     this->coefficients = new double[that.capacity];
     for(int i = 0; i < this->capacity; i++) {
         this->coefficients[i] = that.coefficients[i];
     }

     // leave that in valid state
     that.capacity = 0;
     that.coefficients = nullptr;
}

/* Destructor */
Polynomial::~Polynomial() {
    this->capacity = 0;
    delete[] this->coefficients;
}

/* Return the degree of polynomial (the highest power with a non-zero coefficients)*/
int Polynomial::degree() const {
    int degree = -1;
    for(int i = 0; i < this->capacity; i++) {
        /* the degree of polynomial is the highest of the degrees of the polynomial's monomials with non-zero coefficients */
        if(this->coefficients[i] != 0) {
            degree = this->capacity - i - 1;
            return degree;
        }
    }

    return degree;
}

/* Evaluate a polynomial for a specified value of X */
double Polynomial::evaluate(double x) const {
    double result = this->coefficients[0];

    // if there is only the last one coefficient (x^0) or if the given value is 0
    if(this->capacity - 1 == 0 || x == 0) {
        return this->coefficients[this->capacity - 1];
    }

    for(int i = 1; i < this->capacity; i++) {
        result = result * x + this->coefficients[i];
    }

    return result;
}

/* Compute the derivative of a polynomial */
Polynomial Polynomial::derivative() const {
    Polynomial derivativeP(this->capacity - 2, this->coefficients);

    for(int i = 0; i < derivativeP.capacity; i++) {
        derivativeP.coefficients[i] *= (this->capacity - i - 1);
    }

    return derivativeP;
}

/* Returns coefficient in given index */
double Polynomial::operator[](int index) const {
    if(index >= this->capacity || index < 0) {
        throw out_of_range("The given index is out of range!\n");
    }
    return this->coefficients[index];
}

/* Multiply every coefficient of polynomials with -1 */
Polynomial operator-(const Polynomial &a) {
    Polynomial negative(a.capacity - 1, a.coefficients);

    for(int i = 0; i < negative.capacity; i++) {
          negative.coefficients[i] *= -1;
    }

    return negative;
}

/* addition operator: add two polynomials together and return a new polynomial that is the result  */
Polynomial operator+(const Polynomial &a, const Polynomial &b) {
    Polynomial addition = (a.capacity > b.capacity) ? Polynomial(a.capacity - 1, a.coefficients) : Polynomial(b.capacity - 1, b.coefficients);

    int temp = addition.capacity - 1;
    if(a.capacity > b.capacity) {
        for(int i = b.capacity - 1; i >= 0; i--) {
            addition.coefficients[temp] += b.coefficients[i];
            temp -= 1;
        }
    } else {
        for(int i = a.capacity - 1; i >= 0; i--) {
            addition.coefficients[temp] += a.coefficients[i];
            temp -= 1;
        }
    }

    return addition;
}

/* subtraction operator: subtract two polynomials and return a new polynomial that is the result */
Polynomial operator-(const Polynomial &a, const Polynomial &b) {
    Polynomial subtraction = (a.capacity > b.capacity) ? Polynomial(a.capacity - 1, a.coefficients) : Polynomial(b.capacity - 1, b.coefficients);

    int temp = subtraction.capacity - 1;
    if(a.capacity > b.capacity) {
        for(int i = b.capacity - 1; i >= 0; i--) {
            subtraction.coefficients[temp] -= b.coefficients[i];
            temp -= 1;
        }
    } else {
        for(int i = a.capacity - 1; i >= 0; i--) {
            subtraction.coefficients[temp] -= a.coefficients[i];
            temp -= 1;
        }
    }

    return subtraction;
}

/* multiplication operator: multiply two polynomials and return a new polynomial that is the result */
Polynomial operator*(const Polynomial &a, const Polynomial &b) {
    int size = (a.capacity - 1) + (b.capacity - 1);
    auto * temp = new double[size];
    for(int i = 0; i < size; i++) {
        temp[i] = -1;
    }

    Polynomial multiplication(size, temp);

    for(int i = 0; i < size; i++) {
        multiplication.coefficients[i] = 0;
    }

    for(int i = 0; i < a.capacity; i++) {
        for(int j = 0; j < b.capacity; j++) {
            multiplication.coefficients[i + j] += a.coefficients[i] * b.coefficients[j];
        }
    }

    return multiplication;
}

/* insertion operator for output */
ostream &operator<<(ostream &out, const Polynomial &what) {
    for(int i = 0; i < what.capacity - 1; i++) {
       if(what.coefficients[i] != 0) {
           out << "( " << what.coefficients[i] << " * x^" << what.capacity - i - 1 << " )";
       }
        (what.coefficients[i + 1] != 0) ? cout << " + " : cout << "";
    }
    (what.coefficients[what.capacity - 1] != 0) ? out << what.coefficients[what.capacity - 1] << endl : out << endl;
    return out;
}

/* check if all the polynomial coefficient are valid - there is at least 1 non-zero value */
bool validCoefficient(const double * coefficient, const int& degree) {
    int countZeros = 0;
    for(int i = 0; i < degree + 1; i++) {
        if(coefficient[i] == 0) {
            countZeros += 1;
        }
    }

    if(countZeros == degree + 1) {
        return false;
    }

    return true;
}

/* Functions to test polynomial class implementation - User Interface */

void printExercises() {
    cout << "1. Test constructor" << endl;
    cout << "2. Test copy constructor" << endl;
    cout << "3. Test move constructor" << endl;
    cout << "4. Get degree of polynomial" << endl;
    cout << "5. Evaluate polynomial in given point" << endl;
    cout << "6. Compute the derivative of a polynomial" << endl;
    cout << "7. Returns coefficient in given index" << endl;
    cout << "8. Multiply every coefficient of polynomials with -1 " << endl;
    cout << "9. Add two polynomials together" << endl;
    cout << "10. Subtract two polynomials" << endl;
    cout << "11. Multiply two polynomials" << endl;
    cout << "12. EXIT" << endl;
}

void exercise1() {
    cout << endl << " ***************** CONSTRUCTOR ****************** " << endl << endl;

    double pol[]{2, 3, 0, 4};
    Polynomial poly1(3, pol);
    cout << "polynomial 1: " << poly1;

    cout << endl << "Case when all coefficients are zero: ";
    double pol2[]{0, 0, 0, 0};
    try{

        Polynomial poly2(3, pol2);
        cout << poly2;

    } catch (const exception& e) {
        cout << e.what() << endl << endl;
    }


    cout << "Case when the degree is a negative number: ";
    double pol3[]{2, 3, 0, 4};
    try{

        Polynomial poly3(-5, pol3);
        cout << poly3;

    } catch (const exception& e) {
        cout << e.what() << endl;
    }

}

void exercise2() {
    cout << endl << " ***************** COPY CONSTRUCTOR ****************** " << endl << endl;

    double pol[]{2, 3, 0, 4};
    Polynomial poly1(3, pol);
    cout << "polynomial 1: " << poly1;

    Polynomial poly2(poly1); // copy constructor called
    cout << "polynomial 2: " << poly2;
}

void exercise3() {
    cout << endl << " ***************** MOVE CONSTRUCTOR ****************** " << endl << endl;

    double pol[]{2, 3, 0, 4};
    Polynomial poly1(3, pol);
    cout << "polynomial 1: " << poly1;

    double pol2[]{3, 4, 5, 6};
    Polynomial poly2(3, pol2);
    cout << "polynomial 2: " << poly2;

    Polynomial poly3 = poly1 + poly2;
    cout << "polynomial 3: " << poly3;
}

void exercise4() {
    cout << endl << " ***************** GET DEGREE ****************** " << endl << endl;

    double pol[]{2, 3, 0, 4};
    Polynomial poly1(3, pol);
    cout << "polynomial 1: " << poly1;
    cout << "degree: " << poly1.degree() << endl << endl;

    double pol2[]{0, 0, 2};
    Polynomial poly2(2, pol2);
    cout << "polynomial 2: " << poly2;
    cout << "degree: " << poly2.degree() << endl << endl;

    double pol3[]{2};
    Polynomial poly3(0, pol3);
    cout << "polynomial 3: " << poly3;
    cout << "degree: " << poly3.degree() << endl << endl;
}

void exercise5() {
    cout << endl << " ***************** EVALUATE ****************** " << endl << endl;

    double pol[]{2, 3, 0, 4};
    Polynomial poly1(3, pol);
    cout << "polynomial 1: " << poly1;
    cout << "evaluate in x = 5: " << poly1.evaluate(5) << endl << endl;

    double pol2[]{0, 0, 2};
    Polynomial poly2(2, pol2);
    cout << "polynomial 2: " << poly2;
    cout << "evaluate in x = 7: " << poly2.evaluate(7) << endl << endl;

    double pol3[] {3, 4, 5, 2};
    Polynomial poly3(3, pol3);
    cout << "polynomial 3: " << poly3;
    cout << "evaluate in x = 0: " << poly3.evaluate(0) << endl << endl;
}

void exercise6() {
    cout << endl << " ***************** DERIVATIVE ****************** " << endl << endl;

    double pol[]{2, 3, 0, 4};
    Polynomial poly1(3, pol);
    cout << "polynomial 1: " << poly1;
    cout << "derivative: " << poly1.derivative() << endl << endl;

    double pol2[]{0, 0, 2};
    Polynomial poly2(2, pol2);
    cout << "polynomial 2: " << poly2;

    try {
        cout << "derivative: " << poly2.derivative() << endl << endl;
    } catch (const exception& e) {
        cout << "0" << endl << endl;
    }

    double pol3[] {3, 4, 5, 2, 6};
    Polynomial poly3(4, pol3);
    cout << "polynomial 3: " << poly3;
    cout << "derivative: " << poly3.derivative() << endl << endl;
}

void exercise7() {
    cout << endl << " ***************** COEFFICIENT IN GIVEN INDEX ****************** " << endl << endl;

    double pol[]{2, 3, 0, 4};
    Polynomial poly1(3, pol);
    cout << "polynomial 1: " << poly1;
    cout << "coefficient index = 2: " << poly1[2] << endl << endl;

    double pol2[]{0, 0, 2};
    Polynomial poly2(2, pol2);
    cout << "Case when given index is out of range: " << endl;
    cout << "polynomial 2: " << poly2;

    try {
        cout << "coefficient index = 6: " << poly2[6] << endl << endl;
    } catch (const exception& e) {
        cout << e.what() << endl << endl;
    }

    double pol3[] {3, 4, 5, 2, 6};
    Polynomial poly3(4, pol3);
    cout << "Case when given index is negative: " << endl;
    cout << "polynomial 3: " << poly3;
    cout << "coefficient index = -1: ";
    try {
        cout << poly3[-1] << endl << endl;
    } catch (const exception& e) {
        cout << e.what() << endl << endl;
    }
}

void exercise8() {
    cout << endl << " ***************** MULTIPLY WITH -1 ****************** " << endl << endl;

    double pol[]{2, 3, 0, 4};
    Polynomial poly1(3, pol);
    cout << "polynomial 1: " << poly1;
    cout << "(polynomial 1 * -1): " << -poly1 << endl << endl;
}

void exercise9() {
    cout << endl << " ***************** ADDITION OPERATOR ****************** " << endl << endl;

    double pol[]{2, 3, 0, 4};
    Polynomial poly1(3, pol);
    cout << "polynomial 1: " << poly1;

    double pol2[]{-1, 5, 2, 3, 4};
    Polynomial poly2(4, pol2);
    cout << "polynomial 2: " << poly2;

    cout << "SUM: " << poly1 + poly2 << endl << endl;
}

void exercise10() {
    cout << endl << " ***************** SUBTRACTION OPERATOR ****************** " << endl << endl;

    double pol[]{2, 3, 0, 4};
    Polynomial poly1(3, pol);
    cout << "polynomial 1: " << poly1;

    double pol2[]{-1, 5, 2, 3, 4};
    Polynomial poly2(4, pol2);
    cout << "polynomial 2: " << poly2;

    cout << "DIFFERENCE: " << poly1 + poly2 << endl << endl;
}

void exercise11() {
    cout << endl << " ***************** MULTIPLICATION ****************** " << endl << endl;

    double pol[]{2, 3, 0, 4};
    Polynomial poly1(3, pol);
    cout << "polynomial 1: " << poly1;

    double pol2[]{-1, 5, 2, 3, 4};
    Polynomial poly2(4, pol2);
    cout << "polynomial 2: " << poly2;

    cout << "Multiplication: " << poly1 * poly2 << endl << endl;
}