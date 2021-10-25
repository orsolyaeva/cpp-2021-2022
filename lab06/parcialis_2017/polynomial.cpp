//
// Created by Orsi on 10/25/2021.
//

#include "polynomial.h"

/* Default constructor */
Polynomial::Polynomial(int degree, const double *coefficients) {
    this->capacity = degree + 1;
    this->coefficients = new double [this->capacity];

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
     this->capacity = that.capacity;
     this->coefficients = new double[that.capacity];
     for(int i = 0; i < this->capacity; i++) {
         this->coefficients[i] = that.coefficients[i];
     }

     that.capacity = 0;
     that.coefficients = nullptr;
}

/* Destructor */
Polynomial::~Polynomial() {
    this->capacity = 0;
    delete[] this->coefficients;
}

int Polynomial::degree() const {
    return this->capacity - 1;
}

double Polynomial::evaluate(double x) const {
    double result = this->coefficients[0];

    for(int i = 1; i < this->capacity; i++) {
        result = result * x + this->coefficients[i];
    }

    return result;
}

Polynomial Polynomial::derivative() const {
    Polynomial derivativeP(this->capacity - 2, this->coefficients);

    cout << " hlp: " << derivativeP;

    for(int i = 0; i < derivativeP.capacity; i++) {
        derivativeP.coefficients[i] *= (this->capacity - i - 1);
    }

    return derivativeP;
}

double Polynomial::operator[](int index) const {
    if(index >= this->capacity) {
        throw out_of_range("The given index is out of range!\n");
    }
    return this->coefficients[index];
}

Polynomial operator-(const Polynomial &a) {
    Polynomial negative(a.capacity - 1, a.coefficients);

    for(int i = 0; i < negative.capacity; i++) {
          negative.coefficients[i] *= -1;
    }

    return negative;
}

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

Polynomial operator-(const Polynomial &a, const Polynomial &b) {
    Polynomial substraction = (a.capacity > b.capacity) ? Polynomial(a.capacity - 1, a.coefficients) : Polynomial(b.capacity - 1, b.coefficients);

    int temp = substraction.capacity - 1;
    if(a.capacity > b.capacity) {
        for(int i = b.capacity - 1; i >= 0; i--) {
            substraction.coefficients[temp] -= b.coefficients[i];
            temp -= 1;
        }
    } else {
        for(int i = a.capacity - 1; i >= 0; i--) {
            substraction.coefficients[temp] -= a.coefficients[i];
            temp -= 1;
        }
    }

    return substraction;
}

Polynomial operator*(const Polynomial &a, const Polynomial &b) {
    int size = (a.capacity - 1) + (b.capacity - 1);
    auto * temp = new double[size];
    for(int i = 0; i < size; i++) {
        temp[i] = 0;
    }

    Polynomial multiplication(size - 1, temp);

    for(int i = 0; i < a.capacity; i++) {
        for(int j = 0; j < b.capacity; j++) {
            multiplication.coefficients[i + j] += a.coefficients[i] * b.coefficients[j];
        }
    }

    return multiplication;
}

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
