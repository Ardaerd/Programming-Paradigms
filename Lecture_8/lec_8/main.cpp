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

int main()
{

    auto p =  Painting{Color::Red,1950,"Picasso"};
    bool isGreater = p.year > 1900;
    cout << isGreater << endl;
    cout << p.Painter << endl;

    auto v = vector<Painting>{
      {Color::Red,1950,"Picasso"},
      {Color::Yellow,1975,"Dali"},
      {Color::Blue,1530,"Da Vinci"},
    };

    return 0;
}
