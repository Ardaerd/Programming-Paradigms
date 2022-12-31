#include <iostream>
#include <map>

using namespace std;


template<typename T, typename U> struct IsSame { static const bool value = false; };
template<typename T> struct IsSame<T,T> { static const bool value = true; };

template<typename T> struct RemoveTypeModifiers { using type = T; };
template<typename T> struct RemoveTypeModifiers<const T> { using type = T; };
template<typename T> struct RemoveTypeModifiers<T&> { using type = T; };
template<typename T> struct RemoveTypeModifiers<const T&> { using type = T; };


int main()
{

    auto is_same = IsSame<int,double>::value;
    cout << (is_same ? "true" : "false") << endl;

    is_same = IsSame<int,int>::value;
    cout << (is_same ? "true" : "false") << endl;

    using INTREF = int&;
    using ICONSTNTREF = const int&;

    using T = RemoveTypeModifiers<const int>::type;
    cout << IsSame<T,  int>::value << endl;

    auto m = map<int,string> {
        {1,"one"},
        {2,"two"},
        {3,"three"},
        {4,"four"}
    };

    cout << m[4] << endl;



    return 0;
}
