// pure functions != free functions
// pure functions are better. eliminate state if possible.
// if state is definitely required, better use OOP to encapsulate it from the outside world in a lambda function

// compile-time pure functions are represented by template meta programming in C++
// and also "constexpr" keyword.
// meta-programming trick in templates

// Multiply, Divide, IsSame
// parameter packs, pack expansions

// constexpr, if constexpr, concepts
// Pair
// print_container

#include <iostream>
#include <string>

using namespace std;


// This is not a pure function
// because it is not depend only function's input(parameters)
void func(int i) {
    // it is depend the internal state
    // static int i = 0; // non-pure function because it has a internal state

    cout << i << endl;
}


int main()
{
    int i = 0;
    // now, it is a pure function because it is depend on the parameter of the function
    func(i++);
    func(i++);
    func(i++);

    return 0;
}
