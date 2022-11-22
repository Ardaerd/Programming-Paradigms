// generic programming:
//   transform algorithm (map in other languages)
//   inline version with side-effects vs pure version
//   accumulate algorithm (reducer in other languages)
//   filter algorithm
//   count_if algorithm

#include <iostream>
#include <vector>
#include <list>

using namespace std;

template<typename T, typename FUNC>
void transform_inline(T& container, FUNC func) {
    for (auto& item : container)
        func(item);
}


// You can use auto instead of include
template<typename T, typename FUNC>
T transform(T& container, FUNC func) {
    // for not changing the orijinal container
    auto new_container = container;

    for (auto& item : new_container)
        func(item);

    return new_container;
}


int main()
{
    auto v = list<int>{1,2,3,4,5};

    transform_inline(v, [](auto& item) { item += 10; }); // output: 11 12 13 14 15
    auto v_transformed = transform(v, [](auto& item) { item += 10; });

    for (auto& item : v)
        cout << item << " ";
    cout << endl;

    return 0;
}
