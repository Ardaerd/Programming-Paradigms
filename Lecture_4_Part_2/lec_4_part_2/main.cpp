// Fraction class: Want to represent rational numbers with a numerator and denominator

// OOP: (encapsulates all necessary tools in a box that communicates
//  with outside via c-tors, assignment operators, and casting
// ctor/dtor
// copy-ctor, copy-assignment
// casting
// inheritance (will discuss later)

// function overloading, overload set
// operators and operator overloading

// literals, types of constants (remember units in your Physics class: 9.8 m/s^2)
// user-defined literals (a special way to create your own literals)

// Celsius/Fahrenheit example
// converting constructors

// pass by value, pass by reference, pass by constant reference
// implicit/explicit constructors

// operator== and operator+ overloads for Celsius/Fahrenheit
// static attributes and staticness. static variable initialization


#include <iostream>

using namespace std;


struct Fraction {
    int n;
    int d;

    // Defining a constructur with the default values
    Fraction() : n(0), d(1) { }
    Fraction(int n) : n(n), d(1) { }
    Fraction(int n, int d) : n(n), d(d) { }

    // another way for declaring a constructor with the default value
    // Fraction(int n, int d=1) : n(n), d(d) { }
};


void print(const Fraction& f) {
    cout << f.n << "/" << f.d << endl;
}

int main()
{
    auto f1 = Fraction(10,3);
    auto f2 = Fraction(10);
    auto f3 = Fraction();

    print(f1);
    print(f2);
    print(f3);

    f1 = f3;
    print(f1);

    return 0;
}
