
1- Pointer(*) and Reference(&) definitaion:
	string* and string& differ in a couple of ways. First of all, the pointer points to
	the address location of the data. The referencepoints to the data.
	If you had following function:
		int foo(string* param1);
		- You would have to check in the function declaration to make sure that param1 pointed 				to valid location.
	
Comparatively:
		int foo(string& param1);
	
Here, it is the caller's responsibility to make sure the pointed to data is valid. You can't pass a "NULL" value, for example, int hr second function above.
	
With regards to your second question, about the method return values being a reference, consider the following three functions:
		string& foo();
		string* foo();
		string foo();
	
In the first case, you would be returning a reference to the data. If your function declaration looked like this:
		
		string &foo() {
			string localString = "Hello!";
			return localString;
		}
	
You would probably get some compiler errors, since you are returning a reference to a string that was 
initialized in the stack for that function. On the function return, that data location is no longer valid. Typically, you would wnat to return a reference to a class member or something like that.
	
The second function above return a pointer in actual memory, so it would stay at the same. You would have to check for NULL-pointers, though.
	
Finally, in third case, the data returned would be copied into the return value for the caller. So if your function was like this:
	
		string foo() {
			string localString = "Hello!";
			return localString;
		}
	
You would be okay, since the string "Hello" would be copied into the return value for that function, accessible in the caller's memory space.

2- Pointer(*) and Reference(&) definitaion:
Your function declares a constant reference to a string:

		int foo(const string &myname) {
		  cout << "called foo for: " << myname << endl;
		  return 0;
		}
A reference has some special properties, which make it a safer alternative to pointers in many ways:

- it can never be NULL
- it must always be initialised
- it cannot be changed to refer to a different variable once set
- it can be used in exactly the same way as the variable to which it refers (which means you do not need to deference it like a pointer)

How does the function signature differ from the equivalent C:

		int foo(const char *myname)
		
There are several differences, since the first refers directly to an object, while const char* must be dereferenced to point to the data.

Is there a difference between using string *myname vs string &myname?

The main difference when dealing with parameters is that you do not need to dereference &myname. A simpler example is:

		int add_ptr(int *x, int* y)
		{
		    return *x + *y;
		}
		int add_ref(int &x, int &y)
		{
		    return x + y;
		}
which do exactly the same thing. The only difference in this case is that you do not need to dereference x and y as they refer directly to the variables passed in.

	const string &GetMethodName() { ... }
What is the & doing here? Is there some website that explains how & is used differently in C vs C++?

This returns a constant reference to a string. So the caller gets to access the returned variable directly, but only in a read-only sense. This is sometimes used to return string data members without allocating extra memory.

There are some subtleties with references - have a look at the C++ FAQ on References for some more details.

----------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------

- Struct:

C++ struct, short for C++ Structure, is an user-defined data type available in C++. It allows a user to combine data items of (possibly) different data types under a single name.

C++ structs are different from arrays because arrays only hold data of similar data-types; C++ struct, on the other hand,​ can store data of multiple data-types.

	struct Employee
	{
	  char name[50];
	  int age;
	  float salary;
	};
	
Structures can be assigned values when they are initialized.

	struct Employee
	{
	  char name[50];
	  int age;
	  float salary;
	};

	int main() {
	  struct Employee e1 = {"John", 32, 4200};

	  //accessing the values in the variable
	  printf("Name: %s\n", e1.name);
	  printf("Age : %d\n", e1.age);
	  printf("Salary : %f\n", e1.salary);
	}
	
- Struct vs Class:
It's worth remembering C++'s origins in, and compatibility with, C.

C has structs, it has no concept of encapsulation, so everything is public.

Being public by default is generally considered a bad idea when taking an object-oriented approach, so in making a form of C that is natively conducive to OOP (you can do OO in C, but it won't help you) which was the idea in C++ (originally "C With Classes"), it makes sense to make members private by default.

On the other hand, if Stroustrup had changed the semantics of struct so that its members were private by default, it would have broken compatibility (it is no longer as often true as the standards diverged, but all valid C programs were also valid C++ programs, which had a big effect on giving C++ a foothold).

So a new keyword, class was introduced to be exactly like a struct, but private by default.

If C++ had come from scratch, with no history, then it would probably have only one such keyword. It also probably wouldn't have made the impact it made.

In general, people will tend to use struct when they are doing something like how structs are used in C; public members, no constructor (as long as it isn't in a union, you can have constructors in structs, just like with classes, but people tend not to), no virtual methods, etc. Since languages are as much to communicate with people reading the code as to instruct machines (or else we'd stick with assembly and raw VM opcodes) it's a good idea to stick with that.

-------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------

- Const Keyword:
The various functions of the const keyword which is found in C++ are discussed. Whenever const keyword is attached with any method(), variable, pointer variable, and with the object of a class it prevents that specific object/method()/variable to modify its data items value.

Constant Variables:
There are a certain set of rules for the declaration and initialization of the constant variables:

The const variable cannot be left un-initialized at the time of the assignment.
It cannot be assigned value anywhere in the program.
Explicit value needed to be provided to the constant variable at the time of declaration of the constant variable.

	const int var; x
	
	const int var;
	var = 5;         x
	
	const int var = 5; +
	
The error faced for faulty declaration: If you try to initialize the const variable without assigning an explicit value then a compile-time error (CTE) is generated. 

Const Keyword With Pointer Variables:
Pointers can be declared with a const keyword. So, there are three possible ways to use a const keyword with a pointer, which are as follows:

When the pointer variable point to a const value:

Syntax: 

const data_type* var_name;

	include <iostream>
	using namespace std;
	 
	// Driver Code
	int main()
	{
	    int x{ 10 };
	    char y{ 'M' };
	 
	    const int* i = &x;
	    const char* j = &y;
	 
	    // Value of x and y can be altered,
	    // they are not constant variables
	    x = 9;
	    y = 'A';
	 
	    // Change of constant values because,
	    // i and j are pointing to const-int
	    // & const-char type value
	    // *i = 6;
	    // *j = 7;
	 
	    cout << *i << " " << *j;
	}

Explanation: Here in the above case, i and j are two pointer variables that are pointing to a memory location const int-type and char-type, but the value stored at these corresponding locations can be changed as we have done above. 

Otherwise, the following error will appear: If we try to modify the value of the const variable.

Pass const-argument value to a non-const parameter of a function cause error: Passing const argument value to a non-const parameter of a function isn’t valid it gives you a compile-time error.

	#include <iostream>
	using namespace std;
	 
	int foo(int* y)
	{
	    return *y;
	}
	 
	// Driver code
	int main()
	{
	    int z = 8;
	    const int* x = &z;
	    cout << foo(x);
	    return 0;
	}

Output: The compile-time error that will appear as if const value is passed to any non-const argument of the function then the following compile-time error will appear:


Constant Function Parameters And Return Type:
A function() parameters and return type of function() can be declared as constant. Constant values cannot be changed as any such attempt will generate a compile-time error.

	#include <iostream>
	using namespace std;
	 
	// Function foo() with variable
	// const int
	void foo(const int y)
	{
	    // y = 6; const value
	    // can't be change
	    cout << y;
	}
	 
	// Function foo() with variable int
	void foo1(int y)
	{
	    // Non-const value can be change
	    y = 5;
	    cout << '\n'
		 << y;
	}
	 
	// Driver Code
	int main()
	{
	    int x = 9;
	    const int z = 10;
	   
	    foo(z);
	    foo1(x);
	 
	    return 0;
	}


-------------------------------------------------------------------------------------------------------

- What is Dynamic Memory Allocation:
Resources are always a premium. We have strived to achieve better utilization of resources at all times; that is the premise of our progress. Related to this pursuit, is the concept of memory allocation.

Memory has to be allocated to the variables that we create, so that actual variables can be brought to existence. Now there is a constraint as how we think it happens, and how it actually happens.

- How Computer Creates a Variable:

When we think of creating something, we think of creating something from the very scratch, while this isn’t what actually happens when a computer creates a variable ‘X’; to the computer, is more like an allocation, the computer just assigns a memory cell from a lot of pre-existing memory cells to X. It’s like someone named ‘RAJESH’ being allocated to a hotel room from a lot of free or empty pre-existing rooms. This example probably made it very clear as how the computer does the allocation of memory.

Now, What is a Static Memory Allocation:

When we declare variables, we actually are preparing all the variables that will be used, so that the compiler knows that the variable being used is actually an important part of the program that the user wants and not just a rogue symbol floating around. So, when we declare variables, what the compiler actually does is allocate those variables to their rooms (refer to the hotel analogy earlier). Now, if you see, this is being done before the program executes, you can’t allocate variables by this method while the program is executing. 


	// All the variables in below program
	// are statically allocated.
	void fun()
	{
	   int a;
	}
	int main()
	{
	   int b;
	   int c[10]
	}

- Why do we need to intoduce another allocation method if this just gets the job done:

Why would we need to allocate memory while the program is executing? Because, even though it isn’t blatantly visible, not being able to allocate memory during run time precludes flexibility and compromises with space efficiency. Specially, those cases where the input isn’t known beforehand, we suffer in terms of inefficient storage use and lack or excess of slots to enter data (given an array or similar data structures to store entries). So, here we define Dynamic Memory Allocation: The mechanism by which storage/memory/cells can be allocated to variables during the run time is called Dynamic Memory Allocation (not to be confused with DMA). So, as we have been going through it all, we can tell that it allocates the memory during the run time which enables us to use as much storage as we want, without worrying about any wastage.

Note: Dynamic memory allocation is the process of assigning the memory space during the execution time or the run time.

Reasons and Advantage of Allocating Memory Dynamically:

1- When we do not know how much amount of memory would be needed for the program beforehand.

2- When we want data structures without any upper limit of memory space.

3- When you want to use your memory space more efficiently.Example: If you have allocated memory space for a 1D array as array[20] and you end up using only 10 memory spaces then the remaining 10 memory spaces would be wasted and this wasted memory cannot even be utilized by other program variables.

4- Dynamically created lists insertions and deletions can be done very easily just by the manipulation of addresses whereas in case of statically allocated memory insertions and deletions lead to more movements and wastage of memory.

5- When you want you to use the concept of structures and linked list in programming, dynamic memory allocation is a must.

- There are two types of available memories- stack and heap. Static memory allocation can only be done on stack whereas dynamic memory allocation can be done on both stack and heap. An example of dynamic allocation to be done on the stack is recursion where the functions are put into call stack in order of their occurrence and popped off one by one on reaching the base case. Example of dynamic memory allocation on the heap is: 

	int main()
	{
	   // Below variables are allocated memory
	   // dynamically on heap.
	   int *ptr1 = new int;
	   int *ptr2 = new int[10];
	 
	   // Dynamically allocated memory is
	   // deallocated
	   delete ptr1;
	   delete [] ptr2;
	}


While allocating memory on heap we need to delete the memory manually as memory is not freed(deallocated) by the compiler itself even if the scope of allocated memory finishes(as in case of stack).

To conclude the above topic, static memory is something that the compiler allocates in advance. While dynamic memory is something that is controlled by the program during execution. The program may ask more of it or may delete some allocated.
























