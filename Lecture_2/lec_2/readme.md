
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
