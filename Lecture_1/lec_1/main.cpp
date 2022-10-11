#include <iostream>

using namespace std;

int main()
{
    // Struct is a type like int
    struct {int a; int b;} A;
    A.a = 1;
    A.b = 5;

    struct {int a; int b;} B;
    B.a = -1;
    B.b = 8;

    struct {int a; int b;} C;
    C.a = A.a + B.a;
    C.b = A.b + B.b;

    cout << "(" << C.a << "," << C.b << ")" << endl;


    return 0;
}
