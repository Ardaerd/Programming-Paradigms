#include <iostream>

using namespace std;

template<typename T> struct IsIntegral { static const bool value = false; };
template<>           struct IsIntegral<int> { static const bool value = true; };
template<>           struct IsIntegral<short> { static const bool value = true; };
template<>           struct IsIntegral<char> { static const bool value = true; };
template<>           struct IsIntegral<long> { static const bool value = true; };

template<bool b, typename T1, typename T2> struct ConditionalType { using type = T1; };
template<typename U1, typename U2> struct ConditionalType<false,U1,U2> { using type = U2; };

template<typename ...>
struct TypeDisplayer;

int main()
{
    auto a = IsIntegral<float>::value;
    cout << a << endl;

    using K = ConditionalType<true,int,float>::type;

    auto b = TypeDisplayer< K >{};

    return 0;
}
