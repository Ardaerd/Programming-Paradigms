#include <iostream>
#include <vector>
#include <list>

using namespace std;

template<typename T>
auto filter_(const T& container, auto func) {
    auto new_container = T{};

    for (const auto& item : container)
        if(func(item))
            new_container.push_back(item);

    return new_container;
}

auto filter(auto func) {
    return [func](const auto& container) {
        return filter_(container,func);
    };
}

template<typename T, typename Func, typename K>
auto accumulate_(const T& v, Func func, K initial_value) {

    auto acc = initial_value;
    for (const auto& item : v)
        acc = func(acc,item);

    return acc;
}

auto accumulate(auto func, auto initial_value) {
    return [func,initial_value] (const auto& container) {
      return accumulate_(container,func,initial_value);
    };
}

auto adder_ = [](auto a, auto b) { return a + b; };
auto multiplier_ = [](auto a, auto b) { return a*b; };

auto adder = []() {
    return adder_;
};

auto multiplier = []() {
    return multiplier_;
};

auto compose(auto f, auto g) {
    return [f,g](auto item) {
        return g(f(item));
    };
}

auto operator|(auto f, auto g) {
    return compose(f,g);
}

int main()
{

    auto v = vector<int>{10,20,30,15,25};

    auto sum = accumulate_(v, adder_, 0.01f);
    cout << sum << endl;

    auto product = accumulate_(v, multiplier_, 1);
    cout << product << endl;

    auto v_filtered = filter_(v, [](const auto& item) { return item > 20; });
    auto sum_filtered_float = accumulate_(v_filtered,adder(),0.0f);
    cout << sum_filtered_float << endl;

    auto filter_rule = [](const auto& item) { return item > 20; };
    auto filter_rule2 = [](const auto& item) { return item < 30; };

    auto composition = filter(filter_rule) | filter(filter_rule2) | accumulate(adder(),0.0f);
    auto result = composition(v);


    cout << result << endl;

    return 0;
}
