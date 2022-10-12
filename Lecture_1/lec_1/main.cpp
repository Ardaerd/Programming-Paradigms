#include <iostream>

using namespace std;

int main()
{
    // It is not a instance, it is a new type
    typedef struct {int a; int b;} Vector2d;

    Vector2d A;
    A.a = 1;
    A.b = 5;

    Vector2d B;
    B.a = -1;
    B.b = 8;

    Vector2d C;
    C.a = A.a + B.a;
    C.b = A.b + B.b;

    cout << "(" << C.a << "," << C.b << ")" << endl;

    return 0;
}
