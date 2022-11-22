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
void transform(T& container, FUNC func) {
    // for not changing the orijinal container
    auto new_container = container;

    for (auto& item : new_container)
        func(item);

    return new_container;
}


int main()
{
    auto v = list<int>{1,2,3,4,5};

    // This curly brackets means it is a local scope in the main
    // it is creating everythin and when it is finished destruct the variables
    {
        // in this example list operation is costly
        // this one is not working in list
//        auto sz = v.size();
//        for (int i = 0; i < sz; i++)
//            v[i] += 10;

        // instead of the above example use the below one
        // because in this one we are using manipulation of pointer
        for (auto it = v.begin(); it != v.end(); it++)
            (*it) += 10;

        // However, this one is the simplest one
        for (auto& item : v)
            item += 10;
    }

    {
        for (auto& item : v)
            cout << item << ' ';
        cout << endl;

    }

    return 0;
}
