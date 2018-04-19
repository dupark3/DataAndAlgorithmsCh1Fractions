#include <cmath> // abs()
#include <cstdio> // getline()
#include <iostream>
#include <vector>
#include <string>

#include "Fraction.h"

using namespace std;

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
    check_signs();
}

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

void Fraction::check_signs(){
    if (denominator < 0){
        numerator = -numerator;
        denominator = -denominator;
    } 
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

ostream& operator<<(ostream& os, const Fraction& fraction){
    os << fraction.numerator << '/' << fraction.denominator;
    return os;
}

istream& operator>>(istream& is, Fraction& fraction){
    string s;
    getline(is, s);

    // find the divide character at or after index 1
    size_t divide_sign_position = s.find('/', 1);

    // numerator is from the beginning of the string to the divide sign position (excluding the '/')
    fraction.numerator = stoi(s.substr(0, divide_sign_position));

    // denominator is from one past the divide sign position to the end of the string
    fraction.denominator = stoi(s.substr(divide_sign_position + 1));
    return is;
}