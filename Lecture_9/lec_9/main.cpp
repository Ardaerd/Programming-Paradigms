#include <iostream>

using namespace std;

template<typename T> struct IsIntegral { static const bool value = false; };
template<>           struct IsIntegral<int> { static const bool value = true; };
template<>           struct IsIntegral<short> { static const bool value = true; };
template<>           struct IsIntegral<char> { static const bool value = true; };
template<>           struct IsIntegral<long> { static const bool value = true; };

template<typename T>
const bool IsIntegral_v = IsIntegral<T>::value;

template<bool b, typename T1, typename T2> struct ConditionalType { using type = T1; };
template<typename U1, typename U2> struct ConditionalType<false,U1,U2> { using type = U2; };

template<typename ...>
struct TypeDisplayer;

template<typename T1, typename T2>
void func() {
    const bool same = std::is_same_v<T1,T2>;
    if (same)
        cout << "Types are the same" << endl;
    else
        cout << "Types are different" << endl;
}

template<typename T>
void generic_print(T)
{
    if constexpr(is_same_v<T, int>)
        cout << "int" << endl;
    else if constexpr(is_same_v<T, float>)
        cout << "float" << endl;
}

int main()
{
    auto a = IsIntegral<float>::value;
    cout << a << endl;

    auto a2 = IsIntegral_v<int>;
    cout << a2 << endl;


    using K = ConditionalType<false,int,float>::type;

    //auto b = TypeDisplayer< K >{};

    func<int,float>();

    generic_print(5);
    generic_print(5.3f);

    return 0;
}
