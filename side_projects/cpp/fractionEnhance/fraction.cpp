#include "fraction.hpp"
#include <algorithm>
#include <string>
using namespace std;

Fraction::Fraction(int num, int den)
    :num(num), den(den) {
        this->reduce();
    };

int Fraction::getNumerator() {
    return this->num;
};

int Fraction::getDenominator() {
    return this->den;
};

void Fraction::reduce() {
    int gcd = 1;
    int minimum = min(abs(this->num), abs(this->den));
    for (int i = 2; i < (int)(minimum + 1); i++) {
        if (this->num % i == 0 && this->den % i == 0)
            gcd = i;
    }

    this->num /= gcd;
    this->den /= gcd;

    if (this->num == 0)
        this->den = 1;
};

string Fraction::toString() {
    return to_string(this->num) + "/" + to_string(this->den);
};

Fraction Fraction::operator+ (Fraction other) {
    int num = (this->num * other.getDenominator()) + (other.getNumerator() * this->den);
    int den = this->den * other.getDenominator();
    return Fraction(num, den);
};

Fraction Fraction::operator- (Fraction other) {
    int num = (this->num * other.getDenominator()) - (other.getNumerator() * this->den);
    int den = this->den * other.getDenominator();
    return Fraction(num, den);
};

Fraction Fraction::operator* (Fraction other) {
    int num = this->num * other.getNumerator();
    int den = this->den * other.getDenominator();
    return Fraction(num, den);
};

Fraction Fraction::operator/ (Fraction other) {
    int num = this->num * other.getDenominator();
    int den = this->den * other.getNumerator();
    return Fraction(num, den);
};

Fraction Fraction::operator+= (Fraction other) {
    Fraction temp = *this + other;
    *this = temp;
};

Fraction Fraction::operator-= (Fraction other) {
    Fraction temp = *this - other;
    *this = temp;
};

Fraction Fraction::operator*= (Fraction other) {
    Fraction temp = *this * other;
    *this = temp;
};

Fraction Fraction::operator/= (Fraction other) {
    Fraction temp = *this / other;
    *this = temp;
};

bool Fraction::operator== (Fraction other) {
    return this->num == other.getNumerator() && this->den == other.getDenominator();
};

bool Fraction::operator<= (Fraction other) {
    if (this->den == other.getDenominator()) {
        if (this->num <= other.getNumerator())
            return true;
        else
            return false;
    }
    else return this->den > other.getDenominator();
};

bool Fraction::operator>= (Fraction other) {
    if (this->den == other.getDenominator()) {
        if (this->num >= other.getNumerator())
            return true;
        else
            return false;
    }
    else return this->den < other.getDenominator();
};