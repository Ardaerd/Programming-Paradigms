 #include <iostream>
#include <array>
#include <vector>
#include <list>

using namespace std;

template<typename Container, typename Func>
void transform(Container& container, Func func) {
    for (auto& item : container)
        func(item);
}


int main()
{
    int x[3] = {10,20,30}; // C array
    auto y = array<int,3>{10,20,30}; // modern C++ way
    auto z = vector<int>{10,20,30};
    auto l = list<int>{10,20,30};


    char* s = "hi there"; // null-terminated c string
    auto S = string("hi there");

    auto v = vector<char>(3);

    transform(y, [](auto& item) {item++;});

    for (auto value : y)
        cout << value << endl;

    for (auto value : S)
        cout << value << endl;

    return 0;
}
