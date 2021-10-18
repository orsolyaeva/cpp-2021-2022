//
// Created by Orsi on 10/18/2021.
//

#include "matrix.h"

/* Default constructor */
Matrix::Matrix(int mRows, int mCols): mRows(mRows), mCols(mCols) {
    this->mElements = new double*[mRows];
    for(int i = 0; i < mRows; i++) {
        this->mElements[i] = new double[mCols];
    }
}

/* Copy constructor */
Matrix::Matrix(const Matrix &what) {
    this->mRows = what.mRows;
    this->mCols = what.mCols;
    this->mElements = new double*[what.mRows];
    for(int i = 0; i < what.mRows; i++) {
        this->mElements[i] = new double[what.mCols];
        for(int j = 0; j < what.mCols; j++) {
            this->mElements[i][j] = what.mElements[i][j];
        }
    }
}

/* Move constructor */
Matrix::Matrix(Matrix &&what) {
    this->mRows = what.mRows;
    this->mCols = what.mCols;
    this->mElements = new double*[this->mRows];

    for(int i = 0; i < this->mRows; i++) {
        this->mElements[i] = new double[this->mCols];
        for(int j = 0; j < this->mCols; j++) {
            this->mElements[i][j] = what.mElements[i][j];
        }
        what.mElements[i] = nullptr;
    }
    what.mElements = nullptr;
    what.mCols = what.mRows = 0;
}

/* Destructor */
Matrix::~Matrix() {
    for(int i = 0; i < this->mRows; i++) {
        delete[] this->mElements[i];
    }
    delete[] this->mElements;
}

/* fills the matrix with identical elements */
void Matrix::fillMatrix(double value) {
    for(int i = 0; i < this->mRows; i++) {
        fill(this->mElements[i], this->mElements[i] + this->mCols, value);
    }
}

/* fills the matrix with random real numbers in the range [a, b) */
void Matrix::randomMatrix(int a, int b) {
    if(a > b) {
        swap(a, b);
    }

    random_device rd; // seed the random number generator named rd
    // random_device() is slower than mt19937, but it does not need to be seeded because it requests random data from your operating system
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(a, b); // return a number in the given range

    for(int i = 0; i < this->mRows; i++){
        for(int j = 0; j < this->mCols; j++){
            this->mElements[i][j] = dist(mt);
        }
    }
}

/* prints the matrix */
void Matrix::printMatrix(ostream &os) const {
    for(int i = 0; i < this->mRows; i++) {
        for(int j = 0; j < this->mCols; j++) {
            os << this->mElements[i][j] << " ";
        }
        os << endl;
    }
}

/* checks whether this matrix is a square one */
bool Matrix::isSquare() const {
    return this->mCols == this->mRows;
}

/* operation is permitted on matrices having the same dimensions, otherwise throws an out_of_range exception */
Matrix operator+(const Matrix &x, const Matrix &y) {
    if(x.mRows != y.mRows || x.mCols != y.mCols) {
        throw out_of_range("The 2 matrix are not the same size!");
    }

    Matrix sum(x.mRows, x.mCols);
    for(int i = 0; i < x.mRows; i++){
        for(int j = 0; j < x.mCols; j++) {
            sum.mElements[i][j] = x.mElements[i][j] + y.mElements[i][j];
        }
    }

    return sum;
}

/* operation is permitted on matrices having proper dimensions, otherwise throws an out_of_range exception */
Matrix operator*(const Matrix &x, const Matrix &y) {
    if(x.mRows != y.mCols) {
        throw out_of_range("Can not multiply the two matrix!");
    }
    Matrix multiply(x.mRows, y.mCols);
    multiply.fillMatrix(0);
    for(int i = 0; i < x.mRows; i++) {
        for(int j = 0; j < y.mCols; j++) {
            for(int k = 0; k < y.mRows; k++) {
                multiply.mElements[i][j] += x.mElements[i][k] * y.mElements[k][j];
            }
        }
    }

    return multiply;
}

/* extractor operator */
istream &operator>>(istream &is, Matrix &mat) {
    for(int i = 0; i < mat.mRows; i++) {
        for(int j = 0; j < mat.mCols; j++) {
            is >> mat.mElements[i][j];
        }
    }
    return is;
}

/* inserter operator */
ostream &operator<<(ostream &os, const Matrix &mat) {
    mat.printMatrix(os);
    return os;
}

/* index operator */
double *Matrix::operator[](int index) {
    return this->mElements[index];
}

/* index operator that works on constant matrices */
double *Matrix::operator[](int index) const {
    return this->mElements[index];
}

/* Copy assignment operation is permitted between matrices having the same dimensions otherwise throws an exception (out_of_range) */
Matrix &Matrix::operator=(const Matrix &mat) {
   if(this->mRows != mat.mRows || this->mCols != mat.mCols) {
       throw out_of_range("The matrices does not have identical size!");
   }

   for(int i = 0; i < this->mRows; i++) {
       for(int j = 0; j < this->mCols; j++) {
           this->mElements[i][j] = mat.mElements[i][j];
       }
   }

   return *this;
}

/* Move assignment */
Matrix &Matrix::operator=(Matrix &&mat) {
    for(int i = 0; i < this->mRows; i++) {
        delete[] this->mElements[i];
    }
    delete[] this->mElements;

    this->mRows = mat.mRows;
    this->mCols = mat.mCols;
    this->mElements = new double*[mat.mRows];
    for(int i = 0; i < this->mRows; i++) {
        this->mElements[i] = new double[mat.mCols];
        for(int j = 0; j < this->mCols; j++) {
            this->mElements[i][j] = mat.mElements[i][j];
        }
        mat.mElements[i] = nullptr;
    }
    mat.mElements = nullptr;
    mat.mCols = 0;
    mat.mRows = 0;

    return *this;
}





