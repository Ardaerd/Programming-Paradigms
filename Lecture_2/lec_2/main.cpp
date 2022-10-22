#include <iostream>

using namespace std;

// It is a global definiation of the Vector2d
// typedef struct { int a; int b; } Vector2d;

// It is the same thing as the definiation above. But in a simpler way
struct Vector2d {
  int a;
  int b;

  // construct the vector in the struct. There is no need to define a free function
  Vector2d(int a = 0, int b = 0) {
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
    // Now, we are creating A on the Heap memory and pointed the object's address
    // It is not recommended because It is not a modern way to solve dynamic memory allocation problems
    // It is open to the mistakes
    Vector2d* A = new Vector2d(1,5);
    printVector(*A);


    Vector2d B(-1,8);
    printVector(B);

    // Giving function the objects
    Vector2d C = addVectors(*A, B);
    printVector(C);

    cout << "(" << C.a << "," << C.b << ")" << endl;

    return 0;
}
