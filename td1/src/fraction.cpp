#include "fraction.hpp"
#include "utils.hpp"

std::ostream& operator<<(std::ostream& os, Fraction const& p){
    return os << p.numerator << "/" << p.denominator;
}

Fraction& Fraction::operator+=(Fraction const& b) {
    numerator = numerator * b.denominator + b.numerator * denominator;
    denominator *= b.denominator;
    sign = (numerator >= 0) * 2 - 1;
    *this = simplify(*this);
    return *this;
}

Fraction& Fraction::operator-=(Fraction const& b) {
    numerator = numerator * b.denominator - b.numerator * denominator;
    denominator *= b.denominator;
    sign = (numerator >= 0) * 2 - 1;
    *this = simplify(*this);
    return *this;
}

Fraction& Fraction::operator*=(Fraction const& b) {
    numerator *= b.numerator;
    denominator *= b.denominator;
    sign *= b.sign;
    *this = simplify(*this);
    return *this;
}

Fraction& Fraction::operator/=(Fraction const& b) {
    numerator *= b.sign * b.denominator;
    denominator *= (b.sign * b.numerator);
    sign *= b.sign;
    *this = simplify(*this);
    return *this;
}

float Fraction::to_float() const {
    return static_cast<float>(numerator) / denominator;
}

Fraction::operator float() const {
    return this->to_float();
}

Fraction Fraction::abs() const{
    return Fraction{sign * numerator, denominator};
}

bool is_int(Fraction const& f) {
    return (f.numerator / f.denominator) * f.denominator == f.numerator;
}

int Fraction::ceil() const{
    int div = sign * static_cast<int>((sign * numerator)/denominator);
    if (sign == -1 || is_int(*this))
    {
        return div;
    }
    return div + 1;
}

int Fraction::floor() const{
    int div = sign * static_cast<int>((sign * numerator)/denominator);
    if (sign == 1 || is_int(*this))
    {
        return div;
    }
    return div - 1;
}

int Fraction::round() const {
    int ceiling = this->ceil();
    int floore = this->floor();
    if (ceiling - *this > *this - floore)
    {
        return floore;
    }
    return ceiling;
}

Fraction operator+(Fraction const& f1, Fraction const& f2) {
    Fraction f3 = f1;
    return f3 += f2;
    // return simplify({
    //     f1.numerator * f2.denominator + f2.numerator * f1.denominator,
    //     f1.denominator * f2.denominator
    // });
}

Fraction operator-(Fraction const& f1, Fraction const& f2) {
    Fraction f3 = f1;
    return f3 -= f2;
    // return simplify({
    //     f1.numerator * f2.denominator - f2.numerator * f1.denominator,
    //     f1.denominator * f2.denominator
    // });
}

Fraction operator*(Fraction const& f1, Fraction const& f2) {
    Fraction f3 = f1;
    return f3 *= f2;
    // return simplify({
    //     f1.numerator * f2.numerator,
    //     f1.denominator * f2.denominator
    // });
}

Fraction operator/(Fraction const& f1, Fraction const& f2) {
    Fraction f3 = f1;
    return f3 /= f2;
    // return simplify({
    //     f1.numerator * f2.denominator,
    //     f1.denominator * f2.numerator
    // });
}


bool operator==(Fraction const& a, Fraction const& b) {
    return (a.numerator * b.denominator == a.denominator * b.numerator);
}

bool operator!=(Fraction const& a, Fraction const& b) {
    return !(a == b);
}

bool operator<(Fraction const& a, Fraction const& b) {
    return (a.numerator * b.denominator < a.denominator * b.numerator);
}

bool operator>=(Fraction const& a, Fraction const& b) {
    return !(a < b);
}

bool operator<=(Fraction const& a, Fraction const& b) {
    return (a < b || a == b);
}

bool operator>(Fraction const& a, Fraction const& b) {
    return !(a <= b);
}

Fraction operator+(Fraction const& f, int const i) {
    return f + Fraction{i, 1};
}

Fraction operator+(int const i, Fraction const& f) {
    return f + i;
}

Fraction operator-(Fraction const& f, int const i) {
    return f - Fraction{i, 1};
}

Fraction operator-(int const i, Fraction const& f) {
    return Fraction{i, 1} - f;
}

Fraction operator*(Fraction const& f, int const i) {
    return f * Fraction{i, 1};
}

Fraction operator*(int const i, Fraction const& f) {
    return f * i;
}

Fraction operator/(Fraction const& f, int const i) {
    return f / Fraction{i, 1};
}

Fraction operator/(int const i, Fraction const& f) {
    return Fraction{i, 1} / f;
}
