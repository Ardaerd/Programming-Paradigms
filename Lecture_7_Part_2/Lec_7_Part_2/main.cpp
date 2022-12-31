// Multiply, Divide, IsSame
// parameter packs, pack expansions

// constexpr, if constexpr, concepts
// Pair
// print_container

#include <iostream>

using namespace std;




template<int first, int ... rest>
struct Multiply {
  static const int value = first * Multiply<rest...>::value;
};


// these all is available in compile time
template<int first, int second>
struct Multiply <first,second> {
  static const int value = first * second;
};


struct Multiply_20_2 {
    static const int value = 20 * 2;
};

struct Multiply_11_22 {
    static const int value = 22 * 11;
};

int main()
{
    // if you don't have variable which is vary in main function it is compile time
    int i1 = 20 * 2 * 5 * 3; // this is calculated in compile time
    cout << "i1 " << i1 << endl;

    int i2 = Multiply_20_2::value;
    cout << "i2 " << i2 << endl;

    int i3 = Multiply<20,2,3,4>::value;
    cout << "i3 " << i3 << endl;


    int i4 = Multiply<11,22>::value;
    cout << "i4 " << i4 << endl;


    return 0;
}
