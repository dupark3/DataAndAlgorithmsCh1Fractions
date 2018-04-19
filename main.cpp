#include <iostream>

#include "Fraction.h"

using namespace std;

int main(){
    cout << "Constructors called" << '\n';
    Fraction fraction1(-1, -3);
    Fraction fraction2(-5, 25);
    cout << fraction1 << '\n';
    cout << fraction2 << '\n';
    
    cout << '\n' << "Arithmetic operators" << '\n';
    Fraction fraction3 = fraction1 + fraction2;
    Fraction fraction4 = fraction1 - fraction2;
    Fraction fraction5 = fraction1 * fraction2;
    Fraction fraction6 = fraction1 / fraction2;
    cout << fraction3 << '\n';
    cout << fraction4 << '\n';
    cout << fraction5 << '\n';
    cout << fraction6 << '\n';


    // I/O overload


    return 0;
}