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
void transform(Container& v, BusinessLogic func) {
    func(v);  // implement BusinessLogic and gives it the container
}


// BusinessLogic
struct IncrementBy1 {
    void operator() (Vector3d& v) {
        v.x++;
        v.y++;
        v.z++;
    }
};


int main()
{
    // Container
    auto v = Vector3d();
    // because of the operator()
    v();
    v(3);

    auto incrementBy1 = IncrementBy1();

    transform(v, incrementBy1);
    v();

    return 0;
}
