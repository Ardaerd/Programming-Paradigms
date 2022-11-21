Lambada

- Lambda expression was introduced in C++11 for creating anonymous functors in a more convenient and concise way.

- They are more convenient because we don't need to overload the () operator in a separate class or struct.

Creating a Lambda Expression in C++
A basic lambda expression can look something like this:

	auto greet = []() {
	  // lambda function body
	};
Here,

- [] is called the lambda introducer which denotes the start of the lambda expression
- () is called the parameter list which is similar to the () operator of a normal function

The above code is equivalent to:

	void greet() {
	  // function body
	}
Now, just like the normal functions, we can simply invoke the lambda expression using:

	greet();
Note: We have used the auto keyword to automatically deduce the return type for lambda expression.

	#include <iostream>
	using namespace std;

	int main() {

	  // create a lambda function that prints "Hello World!"
	  auto greet = []() {
	    cout << "Hello World!";
	  };

	  // call lambda function
	  greet();

	  return 0;
	}
	
	Output: Hello World!
	
	auto greet = []() {
	  cout << "Hello World!";
	};
	
Then, we have called the lambda function using the greet variable along with the () operator:

	// displays "Hello World!"
	greet(); 

C++ Lambda Function With Parameters
Just like a regular function, lambda expressions can also take parameters. For example,

	#include <iostream>
	using namespace std;

	int main() {

	  // lambda function that takes two integer
	  //  parameters and displays their sum
	  auto add = [] (int a, int b) {
	   cout << "Sum = " << a + b;
	  };

	  // call the lambda function
	  add(100, 78);

	  return 0;
	}
	Run Code
	Output

	Sum = 178
	
In the above example, we have created a lambda function to which takes two integer parameters and displays their sum.

	auto add = [] (int a, int b) {
	  cout << "Sum = " << a + b;
	};
This is equivalent to:

	void add(int a, int b) {
	  cout << "Sum = " << a + b; 
	}
We have then called the lambda function by passing two integer arguments:

	// returns 178
	add(100, 78);


C++ Lambda Function With Return Type
Like with normal functions, C++ lambda expressions can also have a return type.

The compiler can implicitly deduce the return type of the lambda expression based on the return statement(s).

	auto add = [] (int a, int b) {
	  // always returns an 'int'
	  return a + b;
	};
	
- In the above case, we have not explicitly defined the return type for the lambda function. This is because there is a single return statement which always returns an integer value.

But for multiple return statements of different types, we have to explicitly define the type. For example,

	auto operation = []  (int a, int b,  string op) -> double {
	  if (op == "sum") {
	    // returns integer value
	    return a + b;
	  } 
	  else {
	    // returns double value
	    return (a + b) / 2.0;
	  }
	};
	
Notice the code -> double above. This explicitly defines the return type as double, since there are multiple statements which return different types based on the value of op.

So no matter what type of value is returned by the various return statements, they are all explicitly converted to double type.

C++ Lambda Function Capture Clause:

By default, lambda functions cannot access variables of the enclosing function. In order to access those variables, we use the capture clause.

We can capture the variables in two ways:

Capture by Value
This is similar to calling a function by value. Here, the actual value is copied when the lambda is created.

Note: Here, we can only read the variable inside the lambda body but cannot modify it.

A basic lambda expression with capture by value looks as follows:

	int num_main = 100;

	// get access to num_main from the enclosing function
	auto my_lambda = [num_main] () {
	  cout << num_main;
	};
Here, [num_main] allows the lambda to access the num_main variable.

If we remove num_main from the capture clause, we will get an error since num_main cannot be accessed from the lambda body.

Capture by Reference
This is similar to calling a function by reference i.e. the lambda has access to the variable address.

Note: Here, we can read the variable as well as modify it inside the lambda body.

A basic lambda expression with capture by reference looks as follows:

	int num_main = 100;

	// access the address of num_main variable
	auto my_lambda = [&num_main] () {
	  num_main = 900;
	};
Notice the use of the & operator in [&num_main]. This indicates that we are capturing the address of the num_main variable.

What's the difference between a lambda expression and a function pointer (callback) in C++?








