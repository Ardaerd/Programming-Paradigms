// stack memory vs heap memory
// value semantics vs reference semantics

// global scope, local scope
// free-functions

// class/struct? object? ------> type? instance?
// typedef (C)

// c-tor of a primitive type
// c-tor of a complex type (struct)

// write a c-tor of a struct instance as a free function (imperative programming paradigm)
// write a c-tor of a struct instance as a member function (OOP paradigm)

// allocate memory at run-time (dynamic memory allocation)
// free memory at run-time

// write a dtor as a free function (imperative programming paradigm)
// write a dtor as a member function (OOP paradigm)

// member variables ~= attributes ~= properties (OOP)


#include <iostream>

using namespace std;

// It is a global definiation of the Vector2d
// typedef struct { int a; int b; } Vector2d;

// It is the same thing as the definiation above. But in a simpler way
struct Vector2d {
  int a;
  int b;
  char* c;

  // construct the vector in the struct. There is no need to define a free function
  Vector2d(int a = 0, int b = 0) {
      // In the stack memory compiler delete the objects automaticly.
      // However, in the Heap memory developer should destructor it manually.
      c = new char[1000];
      this->a = a;
      this->b = b;
  }
};

// taking the references of the objects. In reference, we can use it like object but can't change the values.
Vector2d addVectors(Vector2d& K, Vector2d& L) {
    Vector2d M;

    M.a = K.a + L.a;
    M.b = K.b + L.b;

    return M;
}

// For printing the content of the vector
void printVector(const Vector2d& v) {
    // With using const this function can only read the contents of object. Writing to the object is not available
    std::cout << "Content of the Vector: " << "(" << v.a << "," << v.b << ")" << std::endl;
}


int main()
{
    Vector2d A(1,5);
    printVector(A);


    Vector2d B(-1,8);
    printVector(B);

    // Giving function the objects
    Vector2d C = addVectors(A, B);
    printVector(C);

    cout << "(" << C.a << "," << C.b << ")" << endl;

    return 0;
}
