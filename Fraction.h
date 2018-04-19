#ifndef GUARD_Fraction_h
#define GUARD_Fraction_h

#include <iostream>

class Fraction{
public:
    Fraction() : numerator(0), denominator(0) { }
    Fraction(int n, int d) : numerator(n), denominator(d) { check_signs(); }
    // assignment operator, copy constructor, destructor, the BIG THREE

    void factor();
    void print(std::ostream& os){
        os << numerator << '/' << denominator << '\n';
    }
    
private:
    int numerator;
    int denominator;
    void check_signs();
    
    friend Fraction& operator+(const Fraction&, const Fraction&);
    friend Fraction& operator-(const Fraction&, const Fraction&);
    friend Fraction& operator*(const Fraction&, const Fraction&);
    friend Fraction& operator/(const Fraction&, const Fraction&);

    friend std::ostream& operator<<(std::ostream&, const Fraction&);
    //  friend std::istream& operator>>(std::istream&, Fraction&);
};

int find_common_factor(int, int);
Fraction& operator+(const Fraction&, const Fraction&);
Fraction& operator-(const Fraction&, const Fraction&);
Fraction& operator*(const Fraction&, const Fraction&);
Fraction& operator/(const Fraction&, const Fraction&);
// std::ostream& operator<<(std::ostream&, const Fraction&)
// std::istream& operator>>(std::istream&, Fraction&);

#endif