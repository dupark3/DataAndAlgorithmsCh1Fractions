#include <iostream>
#include <vector>

#include "Fraction.h"

using namespace std;

void Fraction::factor(){
    if (denominator == 0){
        throw domain_error("Can't factor a fraction with 0 as the denominator");
    } else if (numerator >= denominator && numerator % denominator == 0){
        numerator = numerator / denominator;
        denominator = 1;
    } else if (numerator < denominator){ 
        int common_factor = find_common_factor(numerator, denominator);
        if (common_factor != 0){
            numerator = numerator / common_factor;
            denominator = denominator / common_factor;
        }
    }
}

int find_common_factor(int x, int y){
    int common_factor = 0;
    vector<int> factors_of_x;
    // loop through finding ints that divide x, from 1 to x including x
    for(int i = 1; i != x + 1; ++i){
        if (x % i == 0)
            factors_of_x.push_back(i);
    }

    // loop from the last element (size - 1) to the second element (excluding first element)
    for(int i = factors_of_x.size() - 1; i != 0; --i){
        if (y % factors_of_x[i] == 0){
            common_factor = factors_of_x[i];
            break;
        }
    }

    return common_factor;
}


Fraction& Fraction::operator+(const Fraction& fraction){
    int new_numerator = (numerator * fraction.denominator) + (fraction.numerator * denominator);
    int new_denominator = denominator * fraction.denominator;
    Fraction* new_fraction = new Fraction(new_numerator, new_denominator);
    new_fraction->factor();
    return *new_fraction;
}   


Fraction& Fraction::operator-(const Fraction& fraction){
    int new_numerator = (numerator * fraction.denominator) - (fraction.numerator * denominator);
    int new_denominator = denominator * fraction.denominator;
    Fraction* new_fraction = new Fraction(new_numerator, new_denominator);
    new_fraction->factor();
    return *new_fraction;
}

/*
Fraction& Fraction::operator*(const Fraction& fraction){

}

Fraction& Fraction::operator/(const Fraction& fraction){

}*/