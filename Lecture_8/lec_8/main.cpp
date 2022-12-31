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
    string Painter;
};

bool greater_than(int i, int j) { return i > j; }
bool greater_than_1900(int i) { return i > 1900; }

auto greater_than_lambda(int i) {
    return [i](int j) {
        return j > i;
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
    cout << p.Painter << endl;

    auto v = vector<Painting>{
      {Color::Red,1950,"Picasso"},
      {Color::Yellow,1975,"Dali"},
      {Color::Blue,1530,"Da Vinci"},
    };

    auto v_name = vector<string>{
        "Picasso",
        "Dali",
        "Monet"
    };

    auto v_year = vector<int>{
        1950,
        1975,
        1530
    };

    return 0;
}
