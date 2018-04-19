#include <iostream>

#include "Fraction.h"

using namespace std;

void factor(Fraction& fraction){
    if (denominator == 0){
        throw domain_error("Can't factor a fraction with 0 as the denominator");
    } else if (numerator >= denominator && numerator % denominator == 0){
        numerator = numerator / denominator;
        denominator = 1;
    } else if (numerator < denominator && denominator % numerator == 0){ 
        // 10/15 = 2/3
        numerator = numerator / (denominator / numerator);
    }
}

Fraction& operator+(const Fraction& fraction1, const Fraction& fraction2){

}

Fraction& operator-(const Fraction& fraction1, const Fraction& fraction2){

}

Fraction& operator*(const Fraction& fraction1, const Fraction& fraction2){

}

Fraction& operator/(const Fraction& fraction1, const Fraction& fraction2){

}