// function pointers
// for_each

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


int dosmt1(int a, int b) { return a; }
int dosmt2(int a, int b) { return a + b; }
int dosmt3(int a, int b) { return a - b; }

// structure of the function pointer
// typedef int (*twointer)(int,int) // old way
using twoptr = int (*)(int,int);   // modern C++ way

int main()
{
    twoptr funcptr = &dosmt2;

    int retval = 0;
    retval = funcptr(1,2);

//    if (choice == 0)
//        retval = dosmt1(1,2);

//    else if (choice == 1)
//        retval = dosmt2(1,2);

//    else if (choice == 2)
//        retval = dosmt3(1,2);

    cout << retval << endl;

    return 0;
}






















