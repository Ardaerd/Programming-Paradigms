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


struct Func {
    int i = 0; // state

    // It is depend on the state. So, it is non-pure function
    void operator() () {
        cout << i << endl;
        i++;
    }
};

// This is not a pure function
// because it is not depend only function's input(parameters)
void func() {
    // it is depend the internal state
     static int i = 0; // non-pure function because it has a internal state

    cout << i << endl;
    i++;
}


int main()
{
    func();
    func();
    func();

    auto func2 = Func{};
    func2();
    func2();
    func2();

    return 0;
}
