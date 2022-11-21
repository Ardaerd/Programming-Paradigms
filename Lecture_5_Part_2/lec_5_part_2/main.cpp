#include <iostream>
#include <array>
#include <vector>

using namespace std;

int main()
{
    int x[3] = {10,20,30}; // C array
    auto y = array<int,3>{10,20,30}; // modern C++ way

    char* s = "hi there"; // null-terminated c string
    auto S = string("hi there");

    auto v = vector<char>(3);

    // begin() is pointing to the first element
    for (auto it = y.begin(); it != y.end(); it++)
        cout << *it << endl;

    for (auto it = S.begin(); it != S.end(); it++)
        cout << *it << endl;

    for (auto value : y)
        cout << value << endl;

    for (auto value : S)
        cout << value << endl;

    return 0;
}
