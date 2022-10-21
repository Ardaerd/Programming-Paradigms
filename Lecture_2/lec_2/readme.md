
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
	
	You would probably get some compiler errors, since you are returning a reference to a string that was initialized in the stack for that function. On the function return, that data location is no longer valid. Typically, you would wnat to return a reference to a class member or something like that.
	
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
