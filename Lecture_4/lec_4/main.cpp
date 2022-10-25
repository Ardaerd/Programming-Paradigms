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
#include <vector>

using namespace std;


int dosmt1(int a, int b) { return a; }
int dosmt2(int a, int b) { return a + b; }
int dosmt3(int a, int b) { return a - b; }

// structure of the function pointer
// typedef int (*twointer)(int,int) // old way
using twointer = int (*)(int,int);   // modern C++ way

template<typename T>
using oneinter = T (*)(T);

template<typename T>
void for_each(vector<T>& container, oneinter<T> funcptr) {
    auto size = container.size();

    for (int i = 0; i < size; i++)
        container[i] = funcptr(container[i]);

}

// adding one to the parameter and return it
int add_one(int i) { return i + 1; }

// multiplying parameter by ten. Then, return it
int multiply_by10(int i) { return 10 * i; }


int main()
{
    vector<int> v(10);

    for (int i = 0; i < 10; i++)
        v[i] = i;

    for_each(v, &multiply_by10);
    for (int i = 0; i < 10; i++)
        cout << v[i] << endl;

    twointer funcptr = &dosmt2;

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






















