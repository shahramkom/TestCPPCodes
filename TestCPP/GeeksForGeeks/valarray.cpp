#include <stdafx.h>
int main()
{
	// Initializing valarray
	valarray<int> varr = { 10, 2, 20, 1, 30 };

	// Declaring new valarray
	valarray<int> varr1;

	// Using apply() to increment all elements by 5
	varr1 = varr.apply([](int x) {return x = x + 5; });

	// Displaying new elements value
	cout << "The new valarray with manipulated values is : ";
	for (int &x : varr1) cout << x << " ";
	cout << endl;

	// Displaying sum of both old and new valarray
	cout << "The sum of old valarray is : ";
	cout << varr.sum() << endl;
	cout << "The sum of new valarray is : ";
	cout << varr1.sum() << endl;

	// Displaying largest element of valarray
	cout << "The largest element of valarray is : ";
	cout << varr.max() << endl;

	// Displaying smallest element of valarray
	cout << "The smallest element of valarray is : ";
	cout << varr.min() << endl;

	// using shift() to shift elements to left
	// shifts valarray by 2 position
	varr1 = varr.shift(2);

	// Displaying elements of valarray after shifting
	cout << "The new valarray after shifting is : ";
	for (int&x : varr1) cout << x << " ";
	cout << endl;

	// using cshift() to circulary shift elements to right
	// rotates valarray by 3 position
	varr1 = varr.cshift(-3);

	// Displaying elements of valarray after circular shifting
	cout << "The new valarray after circular shifting is : ";
	for (int&x : varr1) cout << x << " ";
	cout << endl;

	// Initializing 1st valarray
	valarray<int> varr1sw = { 1, 2, 3, 4 };

	// Initializing 2nd valarray
	valarray<int> varr2sw = { 2, 4, 6, 8 };

	// Displaying valarrays before swapping
	cout << "The contents of 1st valarray "
		"before swapping are : ";
	for (int &x : varr1sw)
		cout << x << " ";
	cout << endl;
	cout << "The contents of 2nd valarray "
		"before swapping are : ";
	for (int &x : varr2sw)
		cout << x << " ";
	cout << endl;

	// Use of swap() to swap the valarrays
	varr1sw.swap(varr2sw);

	// Displaying valarrays after swapping
	cout << "The contents of 1st valarray "
		"after swapping are : ";
	for (int &x : varr1sw)
		cout << x << " ";
	cout << endl;

	cout << "The contents of 2nd valarray "
		"after swapping are : ";
	for (int &x : varr2sw)
		cout << x << " ";
	cout << endl;
	getchar();

}