#include <stdafx.h>
int main()
{
	// Declaring forward list
	forward_list<int> flist1;

	// Declaring another forward list
	forward_list<int> flist2;

	// Assigning values using assign()
	flist1.assign({ 1, 2, 3 });

	// Assigning repeating values using assign()
	// 5 elements with value 10
	flist2.assign(5, 10);

	// Displaying forward lists
	cout << "The elements of first forward list are : ";
	for (int&a : flist1)
		cout << a << " ";
	cout << endl;

	cout << "The elements of second forward list are : ";
	for (int&b : flist2)
		cout << b << " ";
	cout << endl;


	forward_list<int> flist = { 10, 20, 30, 40, 50 };

	// Inserting value using push_front()
	// Inserts 60 at front
	flist.push_front(60);

	// Displaying the forward list
	cout << "The forward list after push_front operation : ";
	for (int&c : flist)
		cout << c << " ";
	cout << endl;

	// Inserting value using emplace_front()
	// Inserts 70 at front
	flist.emplace_front(70);

	// Displaying the forward list
	cout << "The forward list after emplace_front operation : ";
	for (int&c : flist)
		cout << c << " ";
	cout << endl;

	// Deleting first value using pop_front()
	// Pops 70
	flist.pop_front();

	// Displaying the forward list
	cout << "The forward list after pop_front operation : ";
	for (int&c : flist)
		cout << c << " ";
	cout << endl;


	// Initializing forward list
	forward_list<int> flistm = { 10, 20, 30 };

	// Declaring a forward list iterator
	forward_list<int>::iterator ptrm;

	// Inserting value using insert_after()
	// starts insertion from second position
	ptrm = flistm.insert_after(flistm.begin(), { 1, 2, 3 });

	// Displaying the forward list
	cout << "The forward list after insert_after operation : ";
	for (int&c : flistm)
		cout << c << " ";
	cout << endl;

	// Inserting value using emplace_after()
	// inserts 2 after ptr
	ptrm = flistm.emplace_after(ptrm, 2);

	// Displaying the forward list
	cout << "The forward list after emplace_after operation : ";
	for (int&c : flist)
		cout << c << " ";
	cout << endl;

	// Deleting value using erase.after Deleted 2
	// after ptr
	ptrm = flistm.erase_after(ptrm);

	// Displaying the forward list
	cout << "The forward list after erase_after operation : ";
	for (int&c : flistm)
		cout << c << " ";
	cout << endl;

	// Initializing forward list
	forward_list<int> flists = { 10, 20, 30, 25, 40, 40 };

	// Removing element using remove()
	// Removes all occurrences of 40
	flists.remove(40);

	// Displaying the forward list
	cout << "The forward list after remove operation : ";
	for (int&c : flists)
		cout << c << " ";
	cout << endl;

	// Removing according to condition. Removes 
	// elements greater than 20. Removes 25 and 30
	flists.remove_if([](int x) { return x > 20; });

	// Displaying the forward list
	cout << "The forward list after remove_if operation : ";
	for (int&c : flists)
		cout << c << " ";
	cout << endl;

	forward_list<int> flist1w = { 10, 20, 30 };

	// Initializing second list
	forward_list<int> flist2w = { 40, 50, 60 };

	// Shifting elements from first to second
	// forward list after 1st position
	flist2w.splice_after(flist2w.begin(), flist1w);

	// Displaying the forward list
	cout << "The forward list after splice_after operation : ";
	for (int&c : flist2w)
		cout << c << " ";
	cout << endl;
	getchar();
}