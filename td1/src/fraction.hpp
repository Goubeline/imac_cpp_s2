#pragma once

#include <iostream>

struct Fraction {
    int numerator;
    unsigned int denominator;
    int sign = (numerator >= 0) * 2 - 1;
    Fraction& operator+=(Fraction const& b);
    Fraction& operator-=(Fraction const& b);
    Fraction& operator/=(Fraction const& b);
    Fraction& operator*=(Fraction const& b);
    float to_float() const;
    operator float() const;
    Fraction abs() const;
    int ceil() const;
    int floor() const;
    int round() const;
};
std::ostream& operator<<(std::ostream& os, Fraction const& p);
Fraction operator+(Fraction const& f1, Fraction const& f2);
Fraction operator-(Fraction const& f1, Fraction const& f2);
Fraction operator*(Fraction const& f1, Fraction const& f2);
Fraction operator/(Fraction const& f1, Fraction const& f2);

bool operator==(Fraction const& a, Fraction const& b);
bool operator!=(Fraction const& a, Fraction const& b);
bool operator<(Fraction const& a, Fraction const& b);
bool operator<=(Fraction const& a, Fraction const& b);
bool operator>(Fraction const& a, Fraction const& b);
bool operator>=(Fraction const& a, Fraction const& b);

Fraction operator+(Fraction const& f, int const i);
Fraction operator+(int const i, Fraction const& f);
Fraction operator-(Fraction const& f, int const i);
Fraction operator-(int const i, Fraction const& f);
Fraction operator*(Fraction const& f, int const i);
Fraction operator*(int const i, Fraction const& f);
Fraction operator/(Fraction const& f, int const i);
Fraction operator/(int const i, Fraction const& f);