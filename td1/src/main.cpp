#include <iostream>
#include "fraction.hpp"

int main()
{
    Fraction f1 { 3, 4 };
    Fraction f2 { 1, 2 };

    std::cout << "f1 = " << f1;
    std::cout << " f2 = " << f2;
    std::cout << std::endl;

    Fraction f3 { f1 + f2 };

    std::cout << "add(f1, f2) = "<< f3;

    std::cout << std::endl << "sub(f1, f2) = " << (f1 - f2);

    std::cout << std::endl << "mul(f1, f2) = " << (f1 * f2);

    std::cout << std::endl << "div(f1, f2) = " << (f1 / f2);

    std::cout << std::endl << "add(1/6, 2/6) = " << (Fraction {1, 6} + Fraction {2, 6});

    std::cout << std::endl << "f1 < f2 = " << (f1 < f2);
    std::cout << std::endl << "f2 <= f1 = " << (f2 <= f1);
    std::cout << std::endl << "f1 >= f2 = " << (f1 >= f2);
    std::cout << std::endl << "f2 > f1 = " << (f2 > f1);
    std::cout << std::endl << "f1 == f1 = " << (f1 == f1);
    std::cout << std::endl << "f1 != f2 = " << (f1 != f2);

    std::cout << std::endl << "float de f1 = " << f1.to_float();
    std::cout << std::endl << "float de f2 = " << float(f2);
    std::cout << std::endl << "float de 1/3 = " << Fraction{1, 3}.to_float();

    std::cout << std::endl << "f1 + 2 = " << (f1 + 2);
    std::cout << std::endl << "f1 - 2 = " << (f1 - 2);
    std::cout << std::endl << "f1 * 14 = " << (f1 * 14);
    std::cout << std::endl << "f1 / -7 = " << (f1 / -7);

    std::cout << std::endl << "abs(-1/7) = " << Fraction{-1, 7}.abs();
    std::cout << std::endl << "ceiling(-1/7) = " << Fraction{-1, 7}.ceil();
    std::cout << std::endl << "ceiling(11/7) = " << Fraction{11, 7}.ceil();
    std::cout << std::endl << "floor(-11/9) = " << Fraction{-11, 9}.floor();
    std::cout << std::endl << "floor(2/4) = " << Fraction{2, 4}.floor();
    std::cout << std::endl << "round(-6/5) = " << Fraction{-6, 5}.round();
    std::cout << std::endl << "round(16/7) = " << Fraction{16, 7}.round();
    std::cout << std::endl << "round(2/4) = " << Fraction{2, 4}.round();
  
    return 0;
}