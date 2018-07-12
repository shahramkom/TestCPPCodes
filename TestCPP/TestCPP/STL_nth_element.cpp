#include <stdafx.h>
bool comp(int a, int b)
{
	return (a < b);
}

int main()
{
	int vElem[] = { 3, 2, 10, 45, 33, 56, 23, 47 }, iElem;

	// Using std::nth_element with n as 5
	std::nth_element(vElem, vElem + 4, vElem + 8);

	// Since, n is 5 so 5th element should be sorted
	for (iElem = 0; iElem < 8; ++iElem) 
		cout << vElem[iElem] << " ";
	//////////////////////////////////////////////////////////////////////////
	
	cout << endl << endl;
	int vShelem[] = { 3, 2, 10, 45, 33, 56, 23, 47 }, iShelem;

	// Using std::nth_element with n as 6
	std::nth_element(vShelem, vShelem + 5, vShelem + 8, comp);

	// Since, n is 6 so 6th element should be the same
	// as the sixth element present if we sort this array
	// Sorted Array
	/* 2 3 10 23 33 45 47 56 */
	for (iShelem = 0; iShelem < 8; ++iShelem) 
		cout << vShelem[iShelem] << " ";
	cout << endl << endl;
//////////////////////////////////////////////////////////////////////////

// C++ program to find first n smallest numbers
	int v[] = { 30, 20, 10, 40, 60, 50, 70, 80 }, i;

	// Using std::nth_element with n as 3
	std::nth_element(v, v + 2, v + 8);

	// Since, n is 3 so now first three numbers will be the
	// three smallest numbers in the whole array
	// Displaying first three smallest number
	for (i = 0; i < 3; ++i)
		cout << v[i] << " ";

	//////////////////////////////////////////////////////////////////////////
	cout << endl << endl;
	// C++ program to find first n largest numbers
	int vSpd[] = { 30, 20, 50, 60, 70, 10, 80, 40 }, iSpd;
	
	// Using std::nth_element with n as 2
	std::nth_element(vSpd, vSpd + 1, vSpd + 8, std::greater<int>());
	
	// Since, n is 2 so first 2 elements will be the largest
	// among all the array elements
	// Displaying First 2 elements
	for (iSpd = 0; iSpd < 2; ++iSpd)
		cout << vSpd[iSpd] << " ";

	//////////////////////////////////////////////////////////////////////////
	cout << endl << endl;
	// C++ program to find the median of the vector
	vector<int> vert = { 3, 2, 10, 45, 33, 56, 23, 47, 60 }, iert;

	// Using std::nth_element with n as v.size()/2 + 1
	std::nth_element(vert.begin(), vert.begin() + vert.size() / 2, vert.end());

	cout << "The median of the array is " << vert[vert.size() / 2];

	getchar();
}