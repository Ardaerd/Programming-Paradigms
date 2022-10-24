1- Templates:

A template is a simple yet very powerful tool in C++. The simple idea is to pass data type as a parameter so that we don’t need to write the same code for different data types. For example, a software company may need to sort() for different data types. Rather than writing and maintaining multiple codes, we can write one sort() and pass data type as a parameter. 

C++ adds two new keywords to support templates: ‘template’ and ‘typename’. The second keyword can always be replaced by the keyword ‘class’.

- How Do Templates Work:

Templates are expanded at compiler time. This is like macros. The difference is, that the compiler does type checking before template expansion. The idea is simple, source code contains only function/class, but compiled code may contain multiple copies of the same function/class. 

- Function Templates:
We write a generic function that can be used for different data types.

	#include <iostream>
	using namespace std;
	  
	// One function works for all data types.  This would work
	// even for user defined types if operator '>' is overloaded
	template <typename T> T myMax(T x, T y)
	{
	    return (x > y) ? x : y;
	}
	  
	int main()
	{
	    cout << myMax<int>(3, 7) << endl; // Call myMax for int
	    cout << myMax<double>(3.0, 7.0)
		 << endl; // call myMax for double
	    cout << myMax<char>('g', 'e')
		 << endl; // call myMax for char
	  
	    return 0;
	}
	
	Output: 7
		7
		g
		
Class Template Example (Bubble Sort):


	// CPP code for bubble sort
	// using template function
	#include <iostream>
	using namespace std;
	  
	// A template function to implement bubble sort.
	// We can use this for any data type that supports
	// comparison operator < and swap works for it.
	template <class T> void bubbleSort(T a[], int n)
	{
	    for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; i < j; j--)
		    if (a[j] < a[j - 1])
		        swap(a[j], a[j - 1]);
	}
	  
	// Driver Code
	int main()
	{
	    int a[5] = { 10, 50, 30, 40, 20 };
	    int n = sizeof(a) / sizeof(a[0]);
	  
	    // calls template function
	    bubbleSort<int>(a, n);
	  
	    cout << " Sorted array : ";
	    for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	    cout << endl;
	  
	    return 0;
	}

	 Sorted array : 10 20 30 40 50 
	 
Class Templates:

Like function templates, class templates are useful when a class defines something that is independent of the data type. Can be useful for classes like LinkedList, BinaryTree, Stack, Queue, Array, etc. 
		
		
	#include <iostream>
	using namespace std;
	  
	template <typename T> class Array {
	private:
	    T* ptr;
	    int size;
	  
	public:
	    Array(T arr[], int s);
	    void print();
	};
	  
	template <typename T> Array<T>::Array(T arr[], int s)
	{
	    ptr = new T[s];
	    size = s;
	    for (int i = 0; i < size; i++)
		ptr[i] = arr[i];
	}
	  
	template <typename T> void Array<T>::print()
	{
	    for (int i = 0; i < size; i++)
		cout << " " << *(ptr + i);
	    cout << endl;
	}
	  
	int main()
	{
	    int arr[5] = { 1, 2, 3, 4, 5 };
	    Array<int> a(arr, 5);
	    a.print();
	    return 0;
	}
		
		
Can there be more than one argument to templates? 

Yes, like normal parameters, we can pass more than one data type as arguments to templates. The following example demonstrates the same.	
		
		
	#include <iostream>
	using namespace std;
	  
	template <class T, class U> class A {
	    T x;
	    U y;
	  
	public:
	    A() { cout << "Constructor Called" << endl; }
	};
	  
	int main()
	{
	    A<char, char> a;
	    A<int, double> b;
	    return 0;
	}	
	
		
Can we specify a default value for template arguments? 

Yes, like normal parameters, we can specify default arguments to templates. The following example demonstrates the same. 		
	
	#include <iostream>
	using namespace std;
	  
	template <class T, class U = char> class A {
	public:
	    T x;
	    U y;
	    A() { cout << "Constructor Called" << endl; }
	};
	  
	int main()
	{
	    A<char> a; // This will call A<char, char>
	    return 0;
	}		

What is the difference between function overloading and templates? 

Both function overloading and templates are examples of polymorphism features of OOP. Function overloading is used when multiple functions do quite similar (not identical) operations, templates are used when multiple functions do identical operations.
		
		
Can we pass non type parameters to templates? 

We can pass non-type arguments to templates. Non-type parameters are mainly used for specifying max or min values or any other constant value for a particular instance of a template. The important thing to note about non-type parameters is, that they must be const. The compiler must know the value of non-type parameters at compile time. Because the compiler needs to create functions/classes for a specified non-type value at compile time. In the below program, if we replace 10000 or 25 with a variable, we get a compiler error. 	
		
	// C++ program to demonstrate working of non-type
	// parameters to templates in C++
	#include <iostream>
	using namespace std;
	  
	template <class T, int max> int arrMin(T arr[], int n)
	{
	    int m = max;
	    for (int i = 0; i < n; i++)
		if (arr[i] < m)
		    m = arr[i];
	  
	    return m;
	}
	  
	int main()
	{
	    int arr1[] = { 10, 20, 15, 12 };
	    int n1 = sizeof(arr1) / sizeof(arr1[0]);
	  
	    char arr2[] = { 1, 2, 3 };
	    int n2 = sizeof(arr2) / sizeof(arr2[0]);
	  
	    // Second template parameter to arrMin must be a
	    // constant
	    cout << arrMin<int, 10000>(arr1, n1) << endl;
	    cout << arrMin<char, 256>(arr2, n2);
	    return 0;
	}		
	
		
Here is an example of a C++ program to show different data types using a constructor and template. We will perform a few actions 

- passing character value by creating an object in the main() function.
- passing integer value by creating an object in the main() function.
- passing float value by creating an object in the main() function.		
		
		
	// #include <conio.h>
	#include <iostream>
	using namespace std;
	  
	// defining a class template
	template <class T> class info {
	public:
	    info(T A) // constructor of type template
	    {
		cout << "\n"
		     << "A = " << A
		     << " size of data in bytes:" << sizeof(A);
	    } // end of info()
	}; // end of class
	  
	// Main Function
	int main()
	{
	    // clrscr();
	  
	    // passing character value by creating an objects
	    info<char> p('x');
	  
	    // passing integer value by creating an object
	    info<int> q(22);
	  
	    // passing float value by creating an object
	    info<float> r(2.25);
	  
	    return 0;
	} // end of Main Function	
		
	
	Output:
		A = x size of data in bytes:1
		A = 22 size of data in bytes:4
		A = 2.25 size of data in bytes:4
		

Function Pointers:

To point to data, pointers are used. Like normal data pointers, we have function pointers that point to functions. The address of a function is stored in a function pointer.

The Basic syntax of function pointers:

	void (*fun_ptr)(int);
	       fun_ptr = &fun;

We can think of function pointers like normal C++ functions. Where void is the function’s return type. *fun_ptr is a pointer to a function that takes one int argument. It’s as if we are declaring a function called *fun_ptr which takes int and returns void.

The key to writing the declaration for a function pointer is to think of it as a function declaration, but with *fun_name instead of func_name. The pointer symbol * precedes the declaration of the function pointer. Because the function pointer can accept many parameters, it can point to any function that accepts two integer arguments and returns void.

- Facts on function pointers that you should know:

1- Unlike other pointers, a function pointer points to code rather than data. The start of executable code is commonly stored in a function pointer.

2- We don’t use function pointers to allocate or de-allocate memory as we do with normal pointers.

3- The name of a function may also be used to find the address of that function as we had seen in the program above.

4- Regular pointers can be used with an array of function pointers in the same manner that regular pointers can.

5- In place of a switch case, function pointers can be utilized.

6- A function pointer, like a data pointer, can be supplied as an argument and returned from a function.

Example 1:

	#include <iostream>  
	using namespace std;  
	int add(int x , int y)  
	{  
	    return x+y;  
	}  
	int main()  
	{  
	 int (*funcptr)(int,int);  // Declaration of function pointer
	 funcpointr=add; // In this case we are pointing to the add function  

	 int sum=funcpointr(7,10);  
	 std::cout << "Sum=" <<sum<< std::endl;  
	  return 0;  
	}  
	
	Sum value is : 17
	
We declare the function pointer, int (*funcptr)(int,int), and then store the address of the add() function in funcptr in the preceding program. This means that the address of the add() method is stored in funcptr. We can now use funcptr to invoke the add() method. The add() function is called by the phrase funcptr(7,10), and the result is put in the sum variable.	

	#include <iostream>  
	using namespace std;  
	void printname(char *name)  
	{  
	    std::cout << "Name:" <<name<< std::endl;  
	}  
	  
	int main()  
	{  
	    char x[30];  // array declaration  
	    void (*ptr)(char*);  // function pointer declaration  
	    ptr=printname;  // storing the address of printname in ptr.  
	    std::cout << "Enter name: " << std::endl;  
	    cin>>x;  
	    cout<<x<<endl;  
	    ptr(x);  // calling printname() function  
	   return 0;  
	}  
	
	Enter name:
		Daniel
		Daniel
		Name: Daniel
		
We define the function printname() in the preceding program, which takes a char pointer as an argument. We declared our function pointer as void (*ptr)(char*).

We are setting the address of the printname() function to ptr with the expression ptr=printname. We can now use the ptr statement to call the printname() methods. We get the output above after entering the name as Daniel.

Passing function pointers as arguments
We can pass function pointer’s as arguments in our programs as shown below:

	#include <iostream>  
	using namespace std;  
	void function1()  
	{  
	    cout<<"function1 is called";  
	}  
	void function2(void (*funcptr)())  
	{  
	    funcptr();  
	}  
	int main()  
	{  
	  function2(function1);  
	  return 0;  
	} 
	
	Output:
 		function 1 is called 

In the program above, we have passed a function pointer as an argument to the function2() function. The address of function1() is provided to the func2() function by the main() method. The function2() function is indirectly invoking the function1() function in this manner.

Function pass by value vs. pass by reference:

I will call what you are passing in a to a function the actual parameters, and where you receive them, the parameters in the function, the formal parameters. They are also called actual and formal arguments.

When passing parameters, what it is called and what happens can be confusing. It is less essential that you call it the "correct" thing than you know exactly what is happening. It is critical to have a good mental model, a valid memory picture of the process.

Recall that when you call a function, a chunk of memory called an activation record is allocated. Critical to the discussion here is that this memory holds the formal parameter values and function local variables.

By definition, pass by value means you are making a copy in memory of the actual parameter's value that is passed in, a copy of the contents of the actual parameter. Use pass by value when when you are only "using" the parameter for some computation, not changing it for the client program.

In pass by reference (also called pass by address), a copy of the address of the actual parameter is stored. Use pass by reference when you are changing the parameter passed in by the client program.

Consider a swapping function to demonstrate pass by value vs. pass by reference. This function, which swaps ints, cannot be done in Java.

   main() {
      int i = 10, j = 20;
      swapThemByVal(i, j);
      cout << i << "  " << j << endl;     // displays 10  20
      swapThemByRef(i, j);
      cout << i << "  " << j << endl;     // displays 20  10
      ...
   }

   void swapThemByVal(int num1, int num2) {
      int temp = num1;
      num1 = num2;
      num2 = temp;
   }

   void swapThemByRef(int& num1, int& num2) {
      int temp = num1;
      num1 = num2;
      num2 = temp;
   }
First, we show the memory picture for swapThemByVal. The activation record holds the memory for the two parameters, num1 and num2, and the local variable, temp. A copy of the values from main, in the contents of i and j, are copied. All the manipulation is done in the activation record.
                       +-------------+                +-------------+  
        swapThemByVal: |+--+         | swapThemByVal: |+--+         |  
        (at start)     ||..| temp    | (after         ||10| temp    |  
main:                  |+--+         |  assignments)  |+--+         |  
  +----+               |+--+         |                |+--+         |  
i | 10 |               ||10| num1    |                ||20| num1    |  
  +----+               |+--+         |                |+--+         |  
  +----+               |+--+         |                |+--+         |  
j | 20 |               ||20| num2    |                ||10| num2    |  
  +----+               |+--+         |                |+--+         |  
                       +-------------+                +-------------+  
The contents of memory of   i   and   j   don't change. The contents of memory in the function's activation record changes, but when the function terminates, the memory is released and the changes are lost.

Contrast this with passing by reference. The addresses of   i   and   j   are passed (noted by the arrows) by reference. The compiler knows they are references so when the parameters are referred to in the function, the compiler dereferences num1 and num2 automatically so   i   and   j   of main's memory are changed.
                       +-------------+
        swapThemByRef: |+--+         |
                       ||..| temp    |
main:                  |+--+         |
  +----+               |+--+         |
i | 10 | <-------------||--| num1    |
  +----+               |+--+         |
  +----+               |+--+         |
j | 20 | <-------------||--| num2    |
  +----+               |+--+         |
                       +-------------+
After the assignments:
                       +-------------+
        swapThemByRef: |+--+         |
                       ||10| temp    |
main:                  |+--+         |
  +----+               |+--+         |
i | 20 | <-------------||--| num1    |
  +----+               |+--+         |
  +----+               |+--+         |
j | 10 | <-------------||--| num2    |
  +----+               |+--+         |
                       +-------------+
This is the essence of pass by value vs. pass by reference. It doesn't matter if the parameters are primitive types, arrays, or objects, either a copy is made or an address is stored. As noted elsewhere, when objects are copied, the copy constructor is called to do the copying.

Typically if you aren't going to change a variable, you use pass by value. But if you are passing something in that uses a lot of memory, i.e., passing an object or passing an array, even if you aren't changing it, you use what I like to call fake pass by value.

C++ malloc():

In this tutorial, we will learn about the C++ malloc() function with the help of examples.

The malloc() function in C++ allocates a block of uninitialized memory to a pointer. It is defined in the cstdlib header file.

Example
	#include <iostream>
	#include <cstdlib>
	using namespace std;

	int main() {

	  // allocate memory of int size to an int pointer
	  int* ptr = (int*) malloc(sizeof(int));

	  // assign the value 5 to allocated memory
	  *ptr = 5;

	  cout << *ptr;

	  return 0;
	}

// Output: 5
