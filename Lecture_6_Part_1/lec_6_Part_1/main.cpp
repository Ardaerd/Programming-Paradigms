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

    // Referrencing the variables in the main function
    int& a;
    int& b;

    // this '{' is a new type of initilization and it has more strong type checking
    // FibonacciGenerator() : a{1}, b{0} { }
    FibonacciGenerator(int& a, int& b) : a{a}, b{b} { }

    // This is the OOP approach and it make sense
    // you can use operator() () for converting the nextBalue function to unname function
    int operator() () {
        auto retval = a + b;
        a = b;
        b = retval;
        return retval;

    }

};

int main()
{
    int k = 1;
    int l = 0;

    auto fg = FibonacciGenerator(k,l);

    // implementing NextValue function with the lambada way
    // In the lambda expression default is const.
    // Therefore, we should write mutable for changing the variables
    auto fg_lambda = [&a=k, &b=l]() mutable {
        auto retval = a + b;
        a = b;
        b = retval;
        return retval;
    };

    for (int i = 0; i <= 10; i++)
        cout << fg() << ", ";
    cout << endl;

    cout << "Lambada: " << endl;

    for (int i = 0; i <= 10; i++)
        cout << fg_lambda() << ", ";
    cout << endl;

    // k and l are changing also because we are reffering them in the Fibonacci struct
    cout << "k: " << k << endl;
    cout << "l: " << l << endl;

    return 0;
}
