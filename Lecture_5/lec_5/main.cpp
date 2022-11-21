// pointers, dereferencing, pointer arithmetic

// encapsulating functions:
//   functions themselves (with func pointers),
//   function objects
//   lambda functions

// iterators and range-for-loop
// introducing std::vector<T>
// "transform/map" algorithm with function pointers

// unified/universal construction:
//   stricter construction with {} instead of (),
//   designated initializers
//   initializer_list support for ctors

#include <iostream>

using namespace std;

struct Vector3d {
    int x = -1;
    int y = -1;
    int z = -1;

    Vector3d() {

    }

    void operator() () {
        cout << "function call operator has been called." << endl;
        print();
    }

    void operator() (int n_times) {
        cout << "function call operator has been called." << endl;
        for (int i = 0; i < n_times; i++)
            print();
    }

    void print() {
        cout << "x = " << x << " y = " << y << " z = " << z << endl;
    }

};

template<typename Container, typename BusinessLogic>
void transform(Container& v, BusinessLogic& func) {
    func(v);  // implement BusinessLogic and gives it the container
}

// BusinessLogic
// This is a more generic way
struct IncrementByX {
    int amount;
    IncrementByX(int amount = 1) : amount(amount) { }

    template<typename T>
    void operator() (T& v) { // You can use auto also
        v.x += amount;
        v.y += amount;
        v.z += amount;
    }
};

// BusinessLogic
// This is a more generic way
struct MultiplyByX {
    int amount;

        MultiplyByX(int amount) : amount(amount) { }

        template<typename T>
        void operator() (T& v) { v.x*=amount; v.y*=amount; v.z*=amount; }
};

int main()
{
    // Container
    auto v = Vector3d();

    // because of the operator()
    v();
    v(3);

    // you don't need to write int for amount
    // this is the lambada expression in C++
    auto incrementBy22 = [amount = 22](auto& v) {v.x += amount; v.y += amount; v.z += amount;};

    // BusinessLogic
    auto incrementByX = IncrementByX(100);
    auto multiplyByX = MultiplyByX(3);


    transform(v,incrementByX);
    v();
    transform(v, multiplyByX);
    v();
    transform(v,incrementBy22);
    v();

    return 0;
}
