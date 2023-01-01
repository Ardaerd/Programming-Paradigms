#include <iostream>
#include <vector>


using namespace std;

template<typename T>
concept IsContainer = requires(T t) {
    t.begin();
    t.end();
    t.size();
    t.begin()++;
};


auto compose(auto f, auto g) {
    return [f,g](const auto& item) { return g(f(item)); };
}

auto operator|(auto f, auto g) { return compose(f,g); }

template<IsContainer T>
auto operator|(T input, auto f) {
    return f(input);
}

auto print_(const IsContainer auto& container) {
    for (const auto& item : container)
        cout << item <<endl;
    cout << endl;
    return container;
}

auto print() {
    return [](const IsContainer auto& container) {
        return print_(container);
    };
}

auto reverse_(const IsContainer auto& container) {
    auto new_container = container;
    auto sz = new_container.size();
    auto it1 = new_container.begin();
    auto it2 = new_container.end();

    for (int i = 0; i < sz/2; i++)
        swap(*it1++,*--it2);

    return new_container;
}

auto reverse() {
    return [](const IsContainer auto& container) {
      return reverse_(container);
    };
}


template<typename CONTAINER>
auto filter_(const CONTAINER& container, auto lambda) {
    auto new_container = CONTAINER{};

    for (const auto& item : container) {
        if (lambda(item))
            new_container.push_back(item);
    }

    return new_container;
}


auto filter(auto lambda) {
    return [lambda](const auto& container) {
        return filter_(container,lambda);
    };
}


auto higher_than_(auto item, auto limit) { return item > limit; }
auto less_than_(auto item, auto limit) { return item < limit; }

auto higher_than(auto limit) {
    return [limit](auto item) {
        return higher_than_(item,limit);
    };
}

auto less_than(auto limit) {
    return [limit](auto item) {
        return less_than_(item,limit);
    };
}

template<typename ... Preds>
auto all_of_(auto item, Preds ... preds) {
    return (preds(item) && ...);
}

auto all_of(auto ... predes) {
    return [predes...] (auto item) {
        return all_of_(item,predes...);
    };
}


int main()
{
    using CONTAINER = std::vector<float>;

    auto PRINT = print();

    CONTAINER{1.1,50.3,-3,5,10,100}
        | PRINT
        | reverse() | PRINT
        | filter(all_of(higher_than(0),less_than(60))) | PRINT;

    return 0;
}






















