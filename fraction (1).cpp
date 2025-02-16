//**************************************************************
// Homework #3
// Name: Sravani Seelam and Ashritha Parupati
// Date of Submission - 11/10/2024
//***************************************************************
//
// General Program Documentation
//
// Purpose:
// This program defines and implements a fraction class for representing
// and manipulating fractions with basic arithmetic, comparison, and 
// utility functions. It supports addition, subtraction, multiplication,
// and division of fractions, as well as comparison operators for ordering 
// and equality. The program also allows conversion of fractions to 
// floating-point representation.
//
// How to Run the Program: 
// - Keep all files in a folder. 
// - Open the folder in microsoft visual studio 2022 to run the program.
//
// Input Format:
// The program expects fractions in the format "numerator/denominator".
// If a whole number is provided, the program will interpret it as
// "whole_number/1". Invalid input, such as zero denominators, will result
// in an error.
//
// Filenames:
// This program uses the following files:
// - fraction.h: Header file containing the class definition and function
//   declarations for the Fraction class.
// - fraction.cpp: Source file implementing the functions defined in
//   fraction.h.
//
//*****************************************************************
#include "fraction.h"
#include <stdexcept>
#include <cmath>
#include <limits>

using namespace std;

//**************************************************************
// Function: GCD
// Parameters: 
//   - unsigned long a: First number to calculate GCD.
//   - unsigned long b: Second number to calculate GCD.
// Purpose: Uses the Euclidean algorithm to find the Greatest 
//          Common Divisor (GCD) of two unsigned long values.
// Returns: The GCD of a and b.
//**************************************************************
unsigned long GCD(unsigned long a, unsigned long b) {
    return a % b ? GCD(b, a % b) : b;
}

//**************************************************************
// Function: fraction::reduce
// Parameters: None
// Purpose: Simplifies the fraction by dividing both numerator 
//          and denominator by their GCD. Ensures the fraction
//          is in its simplest form with a positive denominator.
// Returns: None
// Throws: invalid_argument if the denominator is zero.
//**************************************************************
void fraction::reduce() {
    if (denominator == 0) {
        throw invalid_argument("Illegal rational number, denominator cannot be zero.");
    }
    unsigned long gcd_value = GCD(abs(numerator), abs(denominator));
    numerator /= gcd_value;
    denominator /= gcd_value;
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

//**************************************************************
// Function: fraction (Default Constructor)
// Parameters: None
// Purpose: Initializes a fraction to 0/1.
// Returns: None
//**************************************************************
fraction::fraction() : numerator(0), denominator(1) {}

//**************************************************************
// Function: fraction (Single Parameter Constructor)
// Parameters: 
//   - long num: Integer value to be set as the numerator.
// Purpose: Initializes a fraction with the given integer value, 
//          setting denominator to 1 (e.g., num/1).
// Returns: None
//**************************************************************
fraction::fraction(long num) : numerator(num), denominator(1) {}

//**************************************************************
// Function: fraction (Constructor with Two Parameters)
// Parameters: 
//   - long num: Numerator of the fraction.
//   - long denom: Denominator of the fraction.
// Purpose: Constructs a fraction with the given numerator and 
//          denominator and automatically reduces it.
// Returns: None
// Throws: invalid_argument if the denominator is zero.
//**************************************************************
fraction::fraction(long num, long denom) : numerator(num), denominator(denom) {
    reduce();
}

//**************************************************************
// Function: fraction (Copy Constructor)
// Parameters:
//   - const fraction& other: Another fraction to copy.
// Purpose: Initializes a new fraction object with values copied
//          from an existing fraction object.
// Returns: None
//**************************************************************
fraction::fraction(const fraction& other) : numerator(other.numerator), denominator(other.denominator) {}

//**************************************************************
// Function: operator double
// Parameters: None
// Purpose: Converts the fraction to a double for decimal 
//          representation.
// Returns: Double value of the fraction (numerator/denominator).
//**************************************************************
fraction::operator double() const {
    return static_cast<double>(numerator) / denominator;
}

//**************************************************************
// Function: operator *
// Parameters:
//   - const fraction& other: Another fraction to multiply with.
// Purpose: Multiplies two fractions and returns the result.
// Returns: A new fraction object representing the product of 
//          the two fractions.
//**************************************************************
fraction fraction::operator *(const fraction& other) const {
    return fraction(numerator * other.numerator, denominator * other.denominator);
}

//**************************************************************
// Function: operator /
// Parameters:
//   - const fraction& other: Another fraction to divide by.
// Purpose: Divides the fraction by another fraction and returns 
//          the result.
// Returns: A new fraction object representing the division.
// Throws: invalid_argument if the numerator of other is zero.
//**************************************************************
fraction fraction::operator /(const fraction& other) const {
    if (other.numerator == 0) {
        throw invalid_argument("Division by zero error.");
    }
    return fraction(numerator * other.denominator, denominator * other.numerator);
}

//**************************************************************
// Function: operator +
// Parameters:
//   - const fraction& other: Another fraction to add.
// Purpose: Adds two fractions and returns the result.
// Returns: A new fraction object representing the sum of the 
//          two fractions.
//**************************************************************
fraction fraction::operator +(const fraction& other) const {
    return fraction(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
}

//**************************************************************
// Function: operator -
// Parameters:
//   - const fraction& other: Another fraction to subtract.
// Purpose: Subtracts one fraction from another and returns the result.
// Returns: A new fraction object representing the difference 
//          between the two fractions.
//**************************************************************
fraction fraction::operator -(const fraction& other) const {
    return fraction(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
}

//**************************************************************
// Function: operator - (Unary)
// Parameters: None
// Purpose: Returns the negative of the fraction.
// Returns: A new fraction object representing the negated fraction.
//**************************************************************
fraction fraction::operator -() const {
    return fraction(-numerator, denominator);
}

//**************************************************************
// Function: operator =
// Parameters:
//   - const fraction& other: Another fraction to assign.
// Purpose: Assigns the values of one fraction to another.
// Returns: Reference to the assigned fraction object.
//**************************************************************
fraction& fraction::operator =(const fraction& other) {
    if (this != &other) {
        numerator = other.numerator;
        denominator = other.denominator;
    }
    return *this;
}

//**************************************************************
// Function: reciprocal
// Parameters: None
// Purpose: Returns the reciprocal of the fraction (swaps numerator and denominator).
// Returns: A new fraction object representing the reciprocal.
// Throws: invalid_argument if the numerator is zero (undefined reciprocal).
//**************************************************************
fraction fraction::reciprocal() const {
    if (numerator == 0) {
        throw invalid_argument("Reciprocal of zero is undefined.");
    }
    return fraction(denominator, numerator);
}

//**************************************************************
// Function: exp
// Parameters:
//   - int power: The power to which the fraction is raised.
// Purpose: Raises the fraction to a specified integer power.
// Returns: A new fraction object representing the exponentiated fraction.
//**************************************************************
fraction fraction::exp(int power) const {
    return fraction(pow(numerator, power), pow(denominator, power));
}

//**************************************************************
// Function: operator ==
// Parameters:
//   - const fraction& other: Another fraction to compare.
// Purpose: Checks if two fractions are equal.
// Returns: True if fractions are equal, otherwise false.
//**************************************************************
bool fraction::operator ==(const fraction& other) const {
    return numerator == other.numerator && denominator == other.denominator;
}

//**************************************************************
// Function: operator !=
// Parameters:
//   - const fraction& other: Another fraction to compare.
// Purpose: Checks if two fractions are not equal.
// Returns: True if fractions are not equal, otherwise false.
//**************************************************************
bool fraction::operator !=(const fraction& other) const {
    return !(*this == other);
}

//**************************************************************
// Function: operator <
// Parameters:
//   - const fraction& other: Another fraction to compare.
// Purpose: Checks if one fraction is smaller than another.
// Returns: True if the fraction is smaller, otherwise false.
//**************************************************************
bool fraction::operator <(const fraction& other) const {
    return numerator * other.denominator < other.numerator * denominator;
}

//**************************************************************
// Function: operator <=
// Parameters:
//   - const fraction& other: Another fraction to compare.
// Purpose: Checks if one fraction is smaller than or equal to another.
// Returns: True if the fraction is smaller or equal, otherwise false.
//**************************************************************
bool fraction::operator <=(const fraction& other) const {
    return *this < other || *this == other;
}

//**************************************************************
// Function: operator >
// Parameters:
//   - const fraction& other: Another fraction to compare.
// Purpose: Checks if one fraction is larger than another.
// Returns: True if the fraction is larger, otherwise false.
//**************************************************************
bool fraction::operator >(const fraction& other) const {
    return !(*this <= other);
}

//**************************************************************
// Function: operator >=
// Parameters:
//   - const fraction& other: Another fraction to compare.
// Purpose: Checks if one fraction is larger than or equal to another.
// Returns: True if the fraction is larger or equal, otherwise false.
//**************************************************************
bool fraction::operator >=(const fraction& other) const {
    return !(*this < other);
}

//**************************************************************
// Function: operator >>
// Parameters:
//   - istream& in: Input stream for reading.
//   - fraction& f: Fraction object to store the input values.
// Purpose: Reads a fraction from the input stream in the form "numerator/denominator".
// Returns: Reference to the input stream (for chaining).
//**************************************************************
istream& operator >>(istream& in, fraction& f) {
    long num = 0, denom = 1;
    char slash;
    if (!(in >> num)) {
        in.clear();
        in.ignore(numeric_limits<streamsize>::max(), '\n');
        f = fraction();
        return in;
    }
    if (in.peek() == '/') {
        in >> slash >> denom;
        if (in.fail()) {
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
            f = fraction();
            return in;
        }
    }
    f = fraction(num, denom);
    return in;
}

//**************************************************************
// Function: operator <<
// Parameters:
//   - ostream& out: Output stream for writing.
//   - const fraction& f: Fraction object to write.
// Purpose: Writes the fraction to the output stream in the form "numerator/denominator".
// Returns: Reference to the output stream (for chaining).
//**************************************************************
ostream& operator <<(ostream& out, const fraction& f) {
    out << f.numerator;
    if (f.denominator != 1) out << '/' << f.denominator;
    return out;
}
