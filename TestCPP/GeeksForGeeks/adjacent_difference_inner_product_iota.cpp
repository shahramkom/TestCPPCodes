#include <stdafx.h>

int myfun(int x, int y)
{
	return x + y;
}

int fun(int x, int y)
{
	return x - y;
}

int fun1(int x, int y)
{
	return x + y;
}

int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6 };
	int b[6];

	// using adjacent_difference function
	adjacent_difference(a, a + 6, b);
	cout << "\nResult using adjacent_difference: ";
	for (int i : b)
		std::cout << i << ' ';

	// using adjacent_difference function
	// user defined function    
	adjacent_difference(a, a + 6, b, myfun);
	cout << "\nResult using accumulate with user-defined function: ";
	for (int i : b)
		std::cout << i << ' ';

	// using adjacent_difference with pre-defined function
	adjacent_difference(a, a + 6, b, multiplies<int>());

	cout << "\nResult using accumulate with pre-defined function: ";
	for (int i : b)
		std::cout << i << ' ';
	cout << endl;

	int var = 200;
	int as[] = { 10, 15, 20 };
	int bs[] = { 1, 3, 5 };

	cout << "\nResult using inner_product ";

	// inner_product with default method
	cout << inner_product(as, as + 3, bs, var);

	// inner_product with pre-defined function
	cout << "\nResult using inner_product with pre-defined function: ";
	cout << inner_product(as, as + 3, bs, var, minus<int>(), divides<int>());

	// inner_product with user defined function
	cout << "\nResult using inner_product with user-defined function: ";
	cout << inner_product(as, as + 3, bs, var, fun, fun1);

	cout << endl << endl;

	int am[7];

	//using iota function to store 100, 101, 102,...    
	iota(am, am + 7, 100);
	cout << " am : ";
	for (int& x : am)
		cout << ' ' << x;
	getchar();
}