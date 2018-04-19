#include <cmath> // abs()
#include <iostream>
#include <vector>

#include "Fraction.h"

using namespace std;


// TODO : 25/15 should factor, but it doesn't right now

void Fraction::factor(){
    if (denominator == 0){
        throw domain_error("Can't factor a fraction with 0 as the denominator");
    } else {
        int common_factor = find_common_factor(numerator, denominator);
        if (common_factor != 0){
            numerator = numerator / common_factor;
            denominator = denominator / common_factor;
        }
    }
}


// TODO : support negative factoring

int find_common_factor(int x, int y){
    int common_factor = 0;
    vector<int> factors_of_x;

    // loop through finding ints that divide x, from 1 to x including x
    for(int i = 1; i != abs(x) + 1; ++i){
        if (x % i == 0)
            factors_of_x.push_back(i);
    }

    // loop from the last element (size - 1) to the second element (excluding first element) to find the largest common factor
    for(int i = factors_of_x.size() - 1; i != 0; --i){
        if (y % factors_of_x[i] == 0){
            common_factor = factors_of_x[i];
            break;
        }
    }

    return common_factor;
}


Fraction& operator+(const Fraction& fraction1, const Fraction& fraction2){
    int new_numerator = (fraction1.numerator * fraction2.denominator) + (fraction2.numerator * fraction1.denominator);
    int new_denominator = fraction1.denominator * fraction2.denominator;
    Fraction* new_fraction = new Fraction(new_numerator, new_denominator);
    new_fraction->factor();
    return *new_fraction;
}   


Fraction& operator-(const Fraction& fraction1, const Fraction& fraction2){
    int new_numerator = (fraction1.numerator * fraction2.denominator) - (fraction2.numerator * fraction1.denominator);
    int new_denominator = fraction1.denominator * fraction2.denominator;
    Fraction* new_fraction = new Fraction(new_numerator, new_denominator);
    new_fraction->factor();
    return *new_fraction;
}


Fraction& operator*(const Fraction& fraction1, const Fraction& fraction2){
    int new_numerator = fraction1.numerator * fraction2.numerator;
    int new_denominator = fraction1.denominator * fraction2.denominator;
    Fraction* new_fraction = new Fraction(new_numerator, new_denominator);
    new_fraction->factor();
    return *new_fraction;
}


Fraction& operator/(const Fraction& fraction1, const Fraction& fraction2){
    int new_numerator = fraction1.numerator * fraction2.denominator;
    int new_denominator = fraction1.denominator * fraction2.numerator;
    Fraction* new_fraction = new Fraction(new_numerator, new_denominator);
    new_fraction->factor();
    return *new_fraction;
}