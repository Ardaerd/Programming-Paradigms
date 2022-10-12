#include <iostream>

using namespace std;

// It is a global definiation of the Vector2d
typedef struct { int a; int b; } Vector2d;

Vector2d addVectors(Vector2d* K, Vector2d* L) {
    Vector2d M;

    M.a = K->a + L->a;
    M.b = K->b + L->b;

    return M;
}

int main()
{
    Vector2d A;
    A.a = 1;
    A.b = 5;

    Vector2d B;
    B.a = -1;
    B.b = 8;

    // It is not copiying objects any more. Now we are giving the reference of the these objects
    Vector2d C = addVectors(&A, &B);

    cout << "(" << C.a << "," << C.b << ")" << endl;

    return 0;
}
