#include <iostream>

#include "Fraction.h"

using namespace std;

int main(){
    // constructors
    Fraction fraction1(1, 3);
    Fraction fraction2(5, 25);
    fraction2.factor();

    Fraction fraction3 = fraction1 + fraction2;
    fraction1.print(cout);
    fraction2.print(cout);
    fraction3.print(cout);
    Fraction fraction4 = fraction1 - fraction2;
    fraction4.print(cout);

    // assignment operator
    // Fraction fraction3 = fraction1 + fraction2;
    
    // copy constructor
    // Fraction fraction4(fraction3);

    // addtiion, subtraction, division, multiplication overload
    // I/O overload


    return 0;
}