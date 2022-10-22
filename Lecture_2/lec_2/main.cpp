#include <iostream>

using namespace std;

// It is a global definiation of the Vector2d
// typedef struct { int a; int b; } Vector2d;

// It is the same thing as the definiation above. But in a simpler way
struct Vector2d {
  int a;
  int b;
};

// taking the references of the objects. In reference, we can use it like object but can't change the values.
Vector2d addVectors(Vector2d& K, Vector2d& L) {
    Vector2d M;

    M.a = K.a + L.a;
    M.b = K.b + L.b;

    return M;
}


// For constructing the contents of the vector
void constructVector2d(Vector2d& v, int a, int b) {
    v.a = a;
    v.b = b;
}

// For printing the content of the vector
void printVector(Vector2d& v) {
    std::cout << "Content of the Vector: " << "(" << v.a << "," << v.b << ")" << std::endl;
}


int main()
{
    Vector2d A;
    constructVector2d(A,1,5);
    printVector(A);


    Vector2d B;
    constructVector2d(B,-1,8);
    printVector(B);

    // Giving function the objects
    Vector2d C = addVectors(A, B);
    printVector(C);

    cout << "(" << C.a << "," << C.b << ")" << endl;

    return 0;
}
