#include "polynomial.h"

int main() {
    double pol[]{2, 3, 0, 4};
    Polynomial poly1(3, pol);
    cout << poly1;

    cout << "poly1 result: " << poly1.evaluate(-1) <<  endl;

    Polynomial poly2 = poly1;
    cout << poly2;

    Polynomial derivative = poly1.derivative();
    cout << derivative;

    cout << "=====================================================" << endl;
    cout << poly1 << " + " << derivative << " = " << poly1 + derivative << endl;

    cout << "=====================================================" << endl;
    cout << poly1 << " - " << derivative << " = " << poly1 - derivative << endl;

    cout << "=====================================================" << endl;
    cout << poly1 << " + " << derivative << " = " << poly1 * derivative << endl;

    return 0;
}
