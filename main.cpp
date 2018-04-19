#include <iostream>

#include "Fraction.h"

using namespace std;

int main(){
    // constructors
    Fraction fraction1(3, 4);
    Fraction fraction2(2, 8);
    fraction2.factor();
    fraction2.print(cout);
    fraction1.print(cout);
    
    // assignment operator
    // Fraction fraction3 = fraction1 + fraction2;
    
    // copy constructor
    // Fraction fraction4(fraction3);

    // addtiion, subtraction, division, multiplication overload
    // I/O overload


    return 0;
}