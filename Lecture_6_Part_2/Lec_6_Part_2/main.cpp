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


void print(const auto& container) {
    for (const auto& item : container)
        cout << item << ", ";
    cout << endl;
}


template<typename T, typename FUNC>
void transform_inline(T& container, FUNC func) {
    for (auto& item : container)
        func(item);
}


// You can use auto instead of include
// we use const for continer because we are not changing the original container
template<typename T, typename FUNC>
T transform(const T& container, FUNC func) {
    // for not changing the orijinal container
    auto new_container = container;

    for (auto& item : new_container)
        func(item);

    return new_container;
}


template<typename T>
auto filter(const T& container, auto func) {
    auto new_container = T{};

    for (auto item : container)
        if (func(item))
            new_container.push_back(item);

    return new_container;
}


int main()
{
    auto v = list<int>{1,2,3,4,5};

    transform_inline(v, [](auto& item) { item += 10; }); // output: 11 12 13 14 15

    // output is same because we are using copy constructer in transform()
    auto v_transformed = transform(v, [](auto& item) { item += 10; }); // output: 11 12 13 14 15

    auto v_filtered = filter(v_transformed, [](const auto& item) {
        return item > 23;
    });

    for (auto& item : v)
        cout << item << " ";
    cout << endl;

    cout << "transform(): " << endl;
    for (auto& item : v_transformed)
        cout << item << " ";
    cout << endl;

    cout << "Filtered: " << endl;
    for (auto& item : v_filtered)
        cout << item << " ";
    cout << endl;

    return 0;
}
