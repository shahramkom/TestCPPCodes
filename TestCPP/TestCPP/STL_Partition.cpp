#include <stdafx.h>

int main()
{
	// Initializing vector
	vector<int> vect = { 2, 1, 5, 6, 8, 7 };

	// Checking if vector is partitioned 
	// using is_partitioned()
	is_partitioned(vect.begin(), vect.end(), [](int x)
	{
		return x % 2 == 0;

	}) ?

		cout << "Vector is partitioned" :
		cout << "Vector is not partitioned";
	cout << endl;

	// partitioning vector using partition()
	partition(vect.begin(), vect.end(), [](int x)
	{
		return x % 2 == 0;

	});

	// Checking if vector is partitioned 
	// using is_partitioned()
	is_partitioned(vect.begin(), vect.end(), [](int x)
	{
		return x % 2 == 0;

	}) ?

		cout << "Now, vector is partitioned after partition operation" :
		cout << "Vector is still not partitioned after partition operation";
	cout << endl;

	// Displaying partitioned Vector
	cout << "The partitioned vector is : ";
	for (int &x : vect) cout << x << " ";

	cout << endl;

	stable_partition(vect.begin(), vect.end(), [](int x)
	{
		return x % 2 == 0;
	});

	// Displaying partitioned Vector
	cout << "The partitioned vector is : ";
	for (int &x : vect) cout << x << " ";
	cout << endl;

	// Declaring iterator
	vector<int>::iterator it1;

	// using partition_point() to get ending position of partition
	auto it = partition_point(vect.begin(), vect.end(), [](int x)
	{
		return x % 2 == 0;
	});

	// Displaying partitioned Vector
	cout << "The vector elements returning true for condition are : ";
	for (it1 = vect.begin(); it1 != it; it1++)
		cout << *it1 << " ";
	cout << endl;

	vector<int> vect1;

	// Declaring vector1
	vector<int> vect2;

	// Resizing vectors to suitable size using count_if() and resize()
	int n = count_if(vect.begin(), vect.end(), [](int x)
	{
		return x % 2 == 0;

	});
	vect1.resize(n);
	vect2.resize(vect.size() - n);

	// Using partition_copy() to copy partitions
	partition_copy(vect.begin(), vect.end(), vect1.begin(),
		vect2.begin(), [](int x)
	{
		return x % 2 == 0;
	});


	// Displaying partitioned Vector
	cout << "The elements that return true for condition are : ";
	for (int &x : vect1)
		cout << x << " ";
	cout << endl;

	// Displaying partitioned Vector
	cout << "The elements that return false for condition are : ";
	for (int &x : vect2)
		cout << x << " ";
	cout << endl;

	getchar();

}