#include <iostream>
#include <map>

using namespace std;

template<typename Container, typename Func>
void print(Container& cont, Func func) {
    for (auto& item : cont)
        func(item[1]);
}

int main()
{
    int arr[5] = {1,2,3,4,5};
    auto m = map<int,string> {
        {1,"one"},
        {2,"two"},
        {3,"three"},
        {4,"four"}
    };

    print(m, [](int item) { cout <<  item << endl;});
    cout << "Hello World!" << endl;
    return 0;
}
