#include <iostream>
#include <vector>


using namespace std;

enum class Color {
    Red,
    Blue,
    Yellow
};

struct Painting {
    Color color;
    int year;
    string painter;
};

bool greater_than(int i, int j) { return i > j; }
bool greater_than_1900(int i) { return i > 1900; }

auto greater_than_lambda(int i) {
    return [i](int j) {
        return j > i;
    };
}

auto get_painter_(const auto& p) {
    return p.painter;
}

auto get_painter() {
    return [](const auto& p) {
        return get_painter_(p);
    };
}

auto get_year_(const auto& p) {
    return p.year;
}

auto get_year() {
    return [](const auto& p) {
        return get_year_(p);
    };
}

// using Fucntion object
struct GreaterThan {
    int i;
    bool operator() (int j) { return i > j; }
};

// this is returning a lambda which calculates a business logic
auto greaterThanLambda = [](int i, int j) { return i > j; };
auto greaterThan1900_Lambda = [i = 1900](int j) { return i > j; };


auto gt = GreaterThan{1900};
auto isGreater = gt(2000);

template<typename T>
struct TypeDisplayer;

template<typename Container, typename Func>
auto transform(const Container& container, Func func) {
    using T = decltype (func(*container.begin()));
    auto v = vector<T>{};

    // auto t = TypeDisplayer<T>{};

    for (const auto& item : container) {
        v.push_back(func(item));
    }

    return v;
}

void print(const auto& container) {

    for (const auto& item : container)
        cout << item << ", ";
    cout << endl;
}

int main()
{
    auto gt_l = greater_than_lambda(10);
    cout << gt_l(41) << endl;
    auto gtl = greaterThanLambda(10,20);
    auto gt1900_L = greaterThan1900_Lambda(200);

    cout << isGreater << endl;
    cout << gtl << endl;
    cout << gt1900_L << endl;


    auto p =  Painting{Color::Red,1950,"Picasso"};
    bool isGreater = p.year > 1900;
    cout << isGreater << endl;
    cout << p.painter << endl;

    auto v = vector<Painting>{
      {Color::Red,1950,"Picasso"},
      {Color::Yellow,1975,"Dali"},
      {Color::Blue,1530,"Da Vinci"},
    };

    auto v_painter = transform(v,get_painter());
    print(v_painter);

    auto v_year = transform(v,get_year());
    print(v_year);

    auto v_name = vector<string>{
        "Picasso",
        "Dali",
        "Monet"
    };

    auto v_year_after1900 = vector<int>{
        1950,
        1975
};

    return 0;
}
