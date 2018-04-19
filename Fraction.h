#ifndef GUARD_Fraction_h
#define GUARD_Fraction_h

#include <iostream>

class Fraction{
public:
    Fraction() : numerator(0), denominator(0) { }
    Fraction(int n, int d) : numerator(n), denominator(d) { }
    // assignment operator, copy constructor, destructor, the BIG THREE

    void factor();
    void print(std::ostream& os){
        os << numerator << '/' << denominator << '\n';
    }
    
    friend Fraction& operator+(const Fraction&, const Fraction&);
    friend Fraction& operator-(const Fraction&, const Fraction&);
    friend Fraction& operator*(const Fraction&, const Fraction&);
    friend Fraction& operator/(const Fraction&, const Fraction&);


    /* 
    output operator - to member or not to member.. to friend or not to friend..
    we want it to be a member if... symmetry. If we want to be able to write f1 + 3 or 3 + f1, it has to be non-member
    we dont' want to accidentally write ostream >>
    we want it to be a member, it is assymetrical. cout << fraction
    
    std::ostream& operator<<(std::ostream& os, const Fraction& fraction);
    std::istream& operator>>(std::istream& is, Fraction& fraction);
    */
private:
    int numerator;
    int denominator;

};

int find_common_factor(int, int);
Fraction& operator+(const Fraction&, const Fraction&);
Fraction& operator-(const Fraction&, const Fraction&);
Fraction& operator*(const Fraction&, const Fraction&);
Fraction& operator/(const Fraction&, const Fraction&);

#endif