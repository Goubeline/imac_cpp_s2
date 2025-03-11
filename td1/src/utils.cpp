#include "utils.hpp"

unsigned int gcd(int a, unsigned int b) {
    unsigned int ua = a;
    if (a < 0)
    {
        ua = -1 * a;
    }
    
    while (b != 0) {
        unsigned int modulo {ua % b};
        ua = b;
        b = modulo;
    }

    return ua;
}
// recursive version
// unsigned int gcd(unsigned int a, unsigned int b) {
//     if (b == 0) {
//         return a;
//     }
//
//     return gcd(b, a % b);
// }
// ternary operator version
// unsigned int gcd(unsigned int a, unsigned int b) {
//     return b == 0 ? a : gcd(b, a % b);
// }


Fraction simplify(Fraction const& f) {
    unsigned int divisor { gcd(f.numerator, f.denominator) };
    
    return {
        f.sign * static_cast<int>(static_cast<unsigned int>(f.sign * f.numerator) / divisor),
        f.denominator / divisor
    };
}