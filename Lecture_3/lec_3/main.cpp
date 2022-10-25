// C has malloc and free for dynamic memory handling.
// C++ has new/delete.
// static variables, static member variables
// Generic Programming = Templates in C++

// const keyword

// OOP:
// ctor/dtor
// copy-ctor, copy-assignment
// inheritance (later)

// function overloading
// operators and operator overloading
// function parameters: pass by value, pass by reference

// next week:
// function pointers
// for_each

// auto, AAA rule (almost always auto)

#include <iostream>

template<typename T>
struct Vector {

    int n_dims;
    T* content; // lots of integers (actually n_dims of ints)

    Vector(int n_dims, T* content) {
        this->n_dims = n_dims;
        this->content = new T[n_dims];

        for (int i = 0; i < n_dims; i++) {
            this->content[i] = content[i];
        }
    }

    bool addVectors(Vector& v2) {
        Vector& v1 = *this;

        if (v1.n_dims != v2.n_dims)
            return false;

        for (int i = 0; i < v1.n_dims; i++)
            v1.content[i] += v2.content[i];

        return true;
    }

    void print() {
        for (int i = 0; i < n_dims; i++)
            std::cout << this->content[i] << std::endl;
    }

    bool operator+(Vector& v2) {
        Vector& v1 = *this;

        if (v1.n_dims != v2.n_dims)
            return false;

        for (int i = 0; i < v1.n_dims; i++)
            v1.content[i] += v2.content[i];

        return true;
    }

    ~Vector() {
        delete[] content;
    }
};


// For adding extra functionality to the + sign. Also we can use the function's name
//bool operator+(VectorInt& v1, VectorInt& v2) {
//    if (v1.n_dims != v2.n_dims)
//        return false;

//    for (int i = 0; i < v1.n_dims; i++)
//        v1.content[i] += v2.content[i];

//    return true;
//}


int main()
{
    double v1_values[2] = {10.7,20.9};
    Vector<double> v1 = Vector<double>(2, v1_values);
    v1.print();

    double v2_values[2] = {100.1,200.3};
    Vector<double> v2 = Vector<double>(2, v2_values);
    v2.print();

    // If the parameters match for the + sign (v1 + v2), operator+ is gonna executed
    // std::cout << v1 + v2 << std::endl;
    // In this case this declaration couldn't compile because operator+ is no longer a free function
    //std::cout << operator+(v1,v2) << std::endl;

    // It is automatically executed, even though it was in the OOP
    bool is_okay = v1 + v2;

    if (is_okay) {
        v1.print();
    } else {
        std::cout << "Dimensions of the vectors don't match!" << std::endl;
    }
    return 0;
}
