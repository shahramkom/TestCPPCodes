#include <stdafx.h>

int main()
{
	// Initializing array
	int ar[6] = { 1, 2, 3, 4, 5, -6 };

	// Checking if all elements are positive
	all_of(ar, ar + 6, [](int x) { return x > 0; }) ?
		cout << "All are positive elements" :
		cout << "All are not positive elements";

	cout << endl;

	int ars[6] = { 1, 2, 3, 4, 5, -6 };

	// Checking if any element is negative
	any_of(ars, ars + 6, [](int x) { return x < 0; }) ?
		cout << "There exists a negative element" :
		cout << "All are positive elements";

	cout << endl;

	int arq[6] = { 1, 2, 3, 4, 5, 6 };

	// Checking if no element is negative
	none_of(arq, arq + 6, [](int x) { return x < 0; }) ?
		cout << "No negative elements" :
		cout << "There are negative elements";

	cout << endl;

	int art[6] = { 1, 2, 3, 4, 5, 6 };

	// Declaring second array
	int art1[6];

	// Using copy_n() to copy contents
	copy_n(art, 6, art1);

	// Displaying the copied array
	cout << "The new array after copying is : ";
	for (int i = 0; i < 6; i++)
		cout << art1[i] << " ";
	cout << endl;

	int arz[6] = { 0 };

	// Using iota() to assign values
	iota(arz, arz + 6, 20);

	// Displaying the new array
	cout << "The new array after assigning values is : ";
	for (int i = 0; i < 6; i++)
		cout << arz[i] << " ";


	getchar();

}