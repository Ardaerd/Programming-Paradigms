#include <iostream>
#include <vector>
#include <list>

using namespace std;

template<typename T, typename Func, typename K>
auto accumulate(const T& v, Func func, K initial_value) {

    auto acc = initial_value;
    for (const auto& item : v)
        acc += item;

    return acc;
}

auto adder = [](auto a, auto b) { return a + b; };

int main()
{

    auto v = vector<int>{10,20,30,15,25};

    auto sum = accumulate(v, adder, 0.01f);
    cout << sum << endl;

    return 0;
}
