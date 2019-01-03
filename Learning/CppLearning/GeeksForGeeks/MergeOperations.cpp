#include <stdafx.h>


int main()
{
	// Initializing 1st vector
	vector<int> v1 = { 1, 3, 4, 5, 20, 30 };

	// Initializing 2nd vector
	vector<int> v2 = { 1, 5, 6, 7, 25, 30 };

	// Declaring resultant vector
	// for mergeing
	vector<int> v3(12);

	// Using merge() to merge vectors v1 and v2
	// and storing result in v3
	merge(v1.begin(), v1.end(), v2.begin(),v2.end(), v3.begin());

	// Displaying resultant container
	cout << "The new container after merging is :\n";
	for (int &x : v3)
		cout << x << " ";
	cout << endl;

	// Initializing new vector
	vector<int> v4 = { 1, 3, 4, 5, 6, 20, 25, 30 };

	// Using include() to check if v4 contains v1
	includes(v4.begin(), v4.end(), v1.begin(), v1.end()) ?
		cout << "v4 includes v1" :
		cout << "v4 does'nt include v1";

	auto it = copy(v1.begin(), v1.end(), v3.begin());
	copy(v2.begin(), v2.end(), it);

	// Using inplace_merge() to sort the container
	inplace_merge(v3.begin(), it, v3.end());

	// Displaying resultant container
	cout << "The new container after inplace_merging is :\n";
	for (int &x : v3)
		cout << x << " ";
	cout << endl;

	// using set_union() to compute union  of 2 
	// containers v1 and v2 and store result in v3
	it = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

	// using set_intersection() to compute intersection
	// of 2 containers v1 and v2 and store result in v4
	auto it1 = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v4.begin());

	// resizing new container
	v3.resize(it - v3.begin());

	// resizing new container
	v4.resize(it1 - v4.begin());

	// Displaying set union
	cout << "Union of two containers is : ";
	for (int &x : v3)
		cout << x << " ";
	cout << endl;

	// Displaying set intersection
	cout << "Intersection of two containers is : ";
	for (int &x : v4)
		cout << x << " ";
	cout << endl;


	v1 = vector<int>{ 1, 3, 4, 5, 20, 30 };

	// Initializing 2nd vector
	v2 = vector<int>{ 1, 5, 6, 7, 25, 30 };

	// Declaring resultant vector
	// for difference
	v3 = vector<int>(10);

	// Declaring resultant vector
	// for symmetric_difference
	v4 = vector<int>(10);
	// using set_difference() to compute difference
	// of 2 containers v1 and v2.
	auto itds = set_difference(v1.begin(), v1.end(),v2.begin(), v2.end(), v3.begin());

	// using set_symmetric_difference() to compute 
	// symmetric_difference/ of 2 containers
	auto it1ds = set_symmetric_difference(v1.begin(),v1.end(), v2.begin(), v2.end(), v4.begin());

	// resizing new container
	v3.resize(itds - v3.begin());

	// resizing new container
	v4.resize(it1ds - v4.begin());

	// Displaying set difference
	cout << "Difference of two containers is : ";
	for (int &x : v3)
		cout << x << " ";
	cout << endl;

	// Displaying set symmetric_difference
	cout << "symmetric_difference of two containers is : ";
	for (int &x : v4)
		cout << x << " ";
	cout << endl;
	getchar();
}

