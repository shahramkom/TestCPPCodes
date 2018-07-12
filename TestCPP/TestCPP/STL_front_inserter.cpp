#include <stdafx.h>
int main()
{
	// Declaring first container
	deque<int> vs1 = { 1, 2, 3 };

	// Declaring second container for
	// copying values
	deque<int> vs2 = { 4, 5, 6 };

	// Using front_inserter inside copy
	copy(vs1.begin(), vs1.end(), front_inserter(vs2));
	// v2 now contains 3 2 1 4 5 6

	// Displaying v1 and v2
	cout << "v1 = ";

	int i;
	for (i = 0; i < 3; ++i) {
		cout << vs1[i] << " ";
	}

	cout << "\nv2 = ";
	for (i = 0; i < 6; ++i) {
		cout << vs2[i] << " ";
	}
	//////////////////////////////////////////////////////////////////////////
	cout << endl;
	// Declaring first container
	deque<int> vm1 = { 1, 2, 3 };

	// Declaring second container
	// for storing the reverse
	deque<int> vm2;

	// Using front_inserter inside copy
	copy(vm1.begin(), vm1.end(), front_inserter(vm2));
	// v2 now contains 3 2 1

	// Displaying v1 and v2
	cout << "v1 = ";

	int im;
	for (im = 0; im < 3; ++im) {
		cout << vm1[im] << " ";
	}

	cout << "\nv2 = ";
	for (im = 0; im < 3; ++im) {
		cout << vm2[im] << " ";
	}
	//////////////////////////////////////////////////////////////////////////
	cout << endl;
	// Declaring first container
	deque<int> vi1 = { 1, 2, 3 };

	// Declaring second container for
	// copying values
	deque<int> vi2 = { 4, 5, 6 };

	// Declaring a front_insert_iterator
	front_insert_iterator<deque<int> > front_i1(vi2);

	// Using the iterator in the copy()
	copy(vi1.begin(), vi1.end(), front_i1);
	// v2 now contains 3 2 1 4 5 6

	// Displaying v1 and v2
	cout << "v1 = ";

	int ii;
	for (ii = 0; ii < 3; ++ii) {
		cout << vi1[ii] << " ";
	}

	cout << "\nv2 = ";
	for (ii = 0; ii < 6; ++ii) {
		cout << vi2[ii] << " ";
	}
	//////////////////////////////////////////////////////////////////////////
	getchar();
}