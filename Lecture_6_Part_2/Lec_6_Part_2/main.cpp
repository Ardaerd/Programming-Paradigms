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

int main()
{
    auto v = vector<int>{1,2,3,4,5};

    // this is okay but silly
    // because we are calculating the vector size for each iteration.
    for (int i = 0; i < v.size(); i++)
        v[i] += 10;

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ", ";
    return 0;
}
