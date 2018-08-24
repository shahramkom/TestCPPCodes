#include <stdafx.h>
// Driver function to demonstrate bind()
void func(int a, int b, int c)
{
	cout << (a - b - c) << endl;
}

int main()
{
	// Use of bind() to bind the function
	// _1 is for first parameter and assigned
	// to 'a' in above declaration.
	// 2 is assigned to b
	// 3 is assigned to c
	auto fn1 = bind(func, _1, 2, 3);

	// 2 is assigned to a.
	// _1 is for first parameter and assigned
	// to 'b' in above declaration.
	// 3 is assigned to c.
	auto fn2 = bind(func, 2, _1, 3);

	// calling of modified functions
	fn1(10);
	fn2(10);

	// Second parameter to fn1() is assigned
	// to 'a' in fun().
	// 2 is assigned to 'b' in fun
	// First parameter to fn1() is assigned
	// to 'c' in fun().
	auto fn1s = bind(func, _2, 2, _1);

	// calling of function
	cout << "The value of function is : ";
	fn1s(1, 13);

	// First parameter to fn2() is assigned
	// to 'a' in fun().
	// 2 is assigned to 'b' in fun
	// Second parameter to fn2() is assigned
	// to 'c' in fun().
	auto fn2s = bind(func, _1, 2, _2);

	// calling of same function
	cout << "The value of function after changing"
		" placeholder position is : ";
	fn2s(1, 13);


	// 1 placeholder  
	auto fn1q = bind(func, _1, 2, 4);

	// calling of function with 1 argument
	cout << "The value of function with 1 "
		"placeholder is : ";
	fn1q(10);

	// 2 placeholders 
	auto fn2q = bind(func, _1, 2, _2);

	// calling of function with 2 arguments
	cout << "The value of function with 2"
		" placeholders is : ";
	fn2q(13, 1);

	// 3 placeholders 
	auto fn3q = bind(func, _1, _3, _2);

	// calling of function with 3 arguments
	cout << "The value of function with 3 "
		"placeholders is : ";
	fn3q(13, 1, 4);
	getchar();
}