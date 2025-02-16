#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class fraction {
private:
    long numerator;   // Numerator of the fraction
    long denominator; // Denominator of the fraction

    void reduce();   // Helper function to reduce the fraction

public:
    fraction();                      // default constructor
    fraction(long num);              // constructor with only numerator
    fraction(long num, long denom);  // constructor with both numerator and denominator
    fraction(const fraction& other); // copy constructor

    // Conversion to double
    operator double() const;

    // Arithmetic operators
    fraction operator *(const fraction& other) const;
    fraction operator /(const fraction& other) const;
    fraction operator +(const fraction& other) const;
    fraction operator -(const fraction& other) const;

    // negates a fraction
    fraction operator -() const;

    // Assignment operator
    fraction& operator =(const fraction& other);

    // Reciprocal function
    fraction reciprocal() const;

    // Exponentiation function
    fraction exp(int power) const;

    // Comparison operators
    bool operator ==(const fraction& other) const;
    bool operator !=(const fraction& other) const;
    bool operator <(const fraction& other) const;
    bool operator <=(const fraction& other) const;
    bool operator >(const fraction& other) const;
    bool operator >=(const fraction& other) const;

    // Friend functions for input and output
    friend std::istream& operator >>(std::istream& in, fraction& f);
    friend std::ostream& operator <<(std::ostream& out, const fraction& f);
};

#endif // FRACTION_H

