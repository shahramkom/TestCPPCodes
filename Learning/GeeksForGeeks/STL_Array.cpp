#include <stdafx.h>
int main()
{
	// Initializing the array elements
	array<int, 6> ar = { 1, 2, 3, 4, 5, 6 };

	// Printing array elements using at()
	cout << "The array elemets are (using at()) : ";
	for (int i = 0; i < 6; i++)
		cout << ar.at(i) << " ";
	cout << endl;

	// Printing array elements using get()
	cout << "The array elemets are (using get()) : ";
	cout << get<0>(ar) << " " << get<1>(ar) << " ";
	cout << get<2>(ar) << " " << get<3>(ar) << " ";
	cout << get<4>(ar) << " " << get<5>(ar) << " ";
	cout << endl;

	// Printing array elements using operator[]
	cout << "The array elements are (using operator[]) : ";
	for (int i = 0; i < 6; i++)
		cout << ar[i] << " ";
	cout << endl;

	array<int, 6> ars = { 1, 2, 3, 4, 5, 6 };

	// Printing first element of array
	cout << "First element of array is : ";
	cout << ars.front() << endl;

	// Printing last element of array
	cout << "Last element of array is : ";
	cout << ars.back() << endl;


	// Initializing the array elements
	array<int, 6> arm = { 1, 2, 3, 4, 5, 6 };

	// Printing number of array elements
	cout << "The number of array elements is : ";
	cout << arm.size() << endl;

	// Printing maximum elements array can hold
	cout << "Maximum elements array can hold is : ";
	cout << arm.max_size() << endl;


	array<int, 6> ard = { 1, 2, 3, 4, 5, 6 };

	// Initializing 2nd array
	array<int, 6> ard1 = { 7, 8, 9, 10, 11, 12 };

	// Printing 1st and 2nd array before swapping
	cout << "The first array elements before swapping are : ";
	for (int i = 0; i < 6; i++)
		cout << ard[i] << " ";
	cout << endl;
	cout << "The second array elements before swapping are : ";
	for (int i = 0; i < 6; i++)
		cout << ard1[i] << " ";
	cout << endl;

	// Swapping ar1 values with ar
	ard.swap(ard1);

	// Printing 1st and 2nd array after swapping
	cout << "The first array elements after swapping are : ";
	for (int i = 0; i < 6; i++)
		cout << ard[i] << " ";
	cout << endl;
	cout << "The second array elements after swapping are : ";
	for (int i = 0; i < 6; i++)
		cout << ard1[i] << " ";
	cout << endl;


	array<int, 6> arw;

	// Declaring 2nd array
	array<int, 0> arw1;

	// Checking size of array if it is empty
	arw1.empty() ? cout << "Array empty" :
		cout << "Array not empty";
	cout << endl;

	// Filling array with 0
	arw.fill(0);

	// Displaying array after filling
	cout << "Array after filling operation is : ";
	for (int i = 0; i < 6; i++)
		cout << arw[i] << " ";

	getchar();

}