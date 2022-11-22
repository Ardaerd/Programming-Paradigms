// overview of encapsulating functions (OOP):
//   functions themselves (with func pointers)
//   function objects (overloading the function call operator  "operator()"
//   lambda functions

// GENERATORS (Coroutines): for functional programming
// mutable lambdas: fibonacci generator

// generic programming:
//   transform algorithm (map in other languages)
//     inline version with side-effects vs pure version
//   accumulate algorithm (reducer in other languages)
//   filter algorithm
//   count_if algorithm

#include <iostream>
#include <vector>    // an array dynamically allocated contiguously in heap memory
#include <list>      // this is a linked list implementation
#include <string>

using namespace std;

// 1, 1, 2, 3, 5, 8, 13, ...

struct FibonacciGenerator {

    int a;
    int b;

    // this '{' is a new type of initilization and it has more strong type checking
    FibonacciGenerator() : a{1}, b{0} { }
    FibonacciGenerator(int a, int b) : a{a}, b{b} { }

    // This is the OOP approach and it make sense
    int give_me_next_value() {
        auto retval = a + b;
        a = b;
        b = retval;
        return retval;

    }

};

// It is an free function bu it is not make sense
int give_me_next_value(FibonacciGenerator& fgref) {
    auto retval = fgref.a + fgref.b;
    fgref.a = fgref.b;
    fgref.b = retval;
    return retval;

}

int main()
{
    auto fg = FibonacciGenerator();

    for (int i = 0; i <= 10; i++)
        cout << fg.give_me_next_value() << ", ";
    cout << endl;

    return 0;
}
