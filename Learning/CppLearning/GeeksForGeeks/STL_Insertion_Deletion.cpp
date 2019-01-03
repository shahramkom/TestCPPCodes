#include <stdafx.h>

#define EMPLACE

int main()
{
	// declaring set
	set<int> st;

	// declaring iterators
	set<int>::iterator it = st.begin();
	set<int>::iterator it1, it2;

	// declaring pair for return value of set containing
	// set iterator and bool
	pair< set<int>::iterator, bool> ptr;

	// using insert() to insert single element
	// inserting 20
#ifndef EMPLACE
	ptr = st.insert(20);
#else
	ptr = st.emplace(24);
#endif

	// checking if the element was already present or newly inserted
	if (ptr.second)
		cout << "The element was newly inserted";
	else cout << "The element was already present";

	// printing set elements after insertion
	cout << "\nThe set elements after 1st insertion are : ";
	for (it1 = st.begin(); it1 != st.end(); ++it1)
		cout << *it1 << " ";

#ifndef EMPLACE
	// inserting set elements using hint
	st.insert(it, 24);
#else
	// using emplace() to insert single element
	// inserting 24 // not inserted this time
	ptr = st.emplace(24); 
	// checking if the element was already present or
	// newly inserted returns false. already inserted
	if (ptr.second)
		cout << "\nThe element was newly inserted";
	else cout << "\nThe element was already present";

#endif


	// printing set elements after insertion
	cout << "\nThe set elements after 2nd insertion are : ";
	for (it1 = st.begin(); it1 != st.end(); ++it1)
		cout << *it1 << " ";
#ifndef EMPLACE
	// inserting array elements in set
	// 24 is not inserted again
	int arr[3] = { 25, 24, 26 };
	st.insert(arr, arr + 3);
#else
	// inserting set elements using hint
	st.emplace_hint(it, 25);
#endif
	
	// printing set elements after insertion
	cout << "\nThe set elements after 3rd insertion are : ";
	for (it1 = st.begin(); it1 != st.end(); ++it1)
		cout << *it1 << " ";

	cout << endl;

	

	// declaring set
	set<int> stsp;

	// declaring iterators
	set<int>::iterator itsp;
	set<int>::iterator it1sp;
	set<int>::iterator it2sp;

	// declaring pair for return value of set containing
	// set iterator and bool
	pair< set<int>::iterator, bool> ptrsp;

	// inserting values in set
	for (int i = 1; i < 10; i++)
		stsp.insert(i * 5);

	// printing initial set elements
	cout << "The set elements after insertion are : ";
	for (it1sp = stsp.begin(); it1sp != stsp.end(); ++it1sp)
		cout << *it1sp << " ";

	itsp = stsp.begin();

	cout << endl;

	// erasing element using iterator
	// erases 2nd element i.e., 10
	++itsp;
	stsp.erase(itsp);

	// printing set elements after deletion
	cout << "The set elements after 1st deletion are : ";
	for (it1sp = stsp.begin(); it1sp != stsp.end(); ++it1sp)
		cout << *it1sp << " ";

	// erasing element using value
	stsp.erase(40);

	// printing set elements after deletion
	cout << "\nThe set elements after 2nd deletion are : ";
	for (it1sp = stsp.begin(); it1sp != stsp.end(); ++it1sp)
		cout << *it1sp << " ";

	++itsp;
	++itsp;
	++itsp;
	++itsp;

	// erasing element using range iterator
	// deletes 25 - last(45)
	stsp.erase(itsp, stsp.end());

	// printing set elements 3rd deletion
	cout << "\nThe set elements after 3rd deletion are : ";
	for (it1sp = stsp.begin(); it1sp != stsp.end(); ++it1sp)
		cout << *it1sp << " ";

	cout << endl;

	getchar();
}