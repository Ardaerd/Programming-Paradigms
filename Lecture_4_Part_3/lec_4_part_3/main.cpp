// Celsius/Fahrenheit example
// converting constructors

// pass by value, pass by reference, pass by constant reference
// implicit/explicit constructors

// operator== and operator+ overloads for Celsius/Fahrenheit
// static attributes and staticness. static variable initialization


#include <iostream>

using namespace std;

struct Fahrenheit;

struct Celcius {
    double value;

    Celcius(double value) : value(value) { }
    Celcius(Fahrenheit& f);

    // Fahrenheit is declared after the celcius. Therefore, we should declare the fahrenheit in the above
    void operator= (Fahrenheit& f);

//    void operator= (Fahrenheit& f) {
//        value = (f.value - 32) / 180 * 100; // You didn't define the content of the Fahrenheit
//        cout << "did nothing" << endl;
//    }

};

struct Fahrenheit {
    double value;

    Fahrenheit(double value) : value(value) { }
};

void Celcius::operator= (Fahrenheit& f) {
    value = (f.value - 32) / 180 * 100; // You didn't define the content of the Fahrenheit
    cout << "did nothing" << endl;
}

Celcius::Celcius(Fahrenheit& f) : value((f.value - 32) / 180 * 100) { }

auto operator"" _c(long double value) { return Celcius(value); }
auto operator"" _f(long double value) { return Fahrenheit(value); }

// bool foo_initialized = false; // It is a free variable

void foo() {
    // If we don't want to use free variable
    // bool foo_initialized = false; // However, It is gonna declared false each time when we call Foo()
    // Because of that we can use static variable
    // It is like a global variabal but in the local scope
    static bool foo_initialized = false;
    cout << foo_initialized << endl;

    if (!foo_initialized) {
        foo_initialized = true;
        cout << foo_initialized << endl;

    }
}


int main()
{
    auto c1 = Celcius(10.1);
    auto c2 = 10.1_c;

    auto f1 = Fahrenheit(30.3);
    auto f2 = 30.3_f;

    cout << "C1: " << c1.value << endl;
    c1 = f1; // using operator '=' in Celcius struct
    cout << "C1: " << c1.value << endl;

    c2 = f2; // Assignment
    // Celcius c3 = f1;
    auto c3 = (Celcius)f1; // If you wanna use auto like that, you should cast the right hand sight

    cout << "C3: " << c3.value << endl;
    foo();
    foo();


    return 0;
}
