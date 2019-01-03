#include <stdafx.h>
int main()
{
	// Initializing vector with array values
	int arr[] = { 10, 20, 5, 23 ,42 , 15 };
	int n = sizeof(arr) / sizeof(arr[0]);
	vector<int> vect(arr, arr + n);

	cout << "Vector is: ";
	for (int i = 0; i < n; i++)
		cout << vect[i] << " ";

	// Sorting the Vector in Ascending order
	sort(vect.begin(), vect.end());

	cout << "\nVector after sorting is: ";
	for (int i = 0; i < n; i++)
		cout << vect[i] << " ";

	// Reversing the Vector
	reverse(vect.begin(), vect.end());

	cout << "\nVector after reversing is: ";
	for (int i = 0; i < 6; i++)
		cout << vect[i] << " ";

	cout << "\nMaximum element of vector is: ";
	cout << *max_element(vect.begin(), vect.end());

	cout << "\nMinimum element of vector is: ";
	cout << *min_element(vect.begin(), vect.end());

	// Starting the summation from 0
	cout << "\nThe summation of vector elements is: ";
	cout << accumulate(vect.begin(), vect.end(), 0);
	cout << endl;

	// Initializing vector with array values
	int arr1[] = { 10, 20, 5, 23 ,42, 20, 15 };
	int na = sizeof(arr) / sizeof(arr1[0]);
	vector<int> vect1(arr1, arr1 + na);

	cout << "Occurrences of 20 in vector : ";

	// Counts the occurrences of 20 from 1st to
	// last element
	cout << count(vect1.begin(), vect1.end(), 20);

	// find() returns iterator to last address if
	// element not present
	find(vect1.begin(), vect1.end(), 5) != vect1.end() ?
		cout << "\nElement found" :
		cout << "\nElement not found";
	cout << endl;

	int arrn[] = { 5, 10, 15, 20, 20, 23, 42, 45 };
	int nn = sizeof(arrn) / sizeof(arrn[0]);
	vector<int> vectn(arrn, arrn + nn);

	// Sort the array to make sure that lower_bound()
	// and upper_bound() work.
	sort(vectn.begin(), vectn.end());

	// Returns the first occurrence of 20
	auto q = lower_bound(vectn.begin(), vectn.end(), 20);

	// Returns the last occurrence of 20
	auto p = upper_bound(vectn.begin(), vectn.end(), 20);

	cout << "The lower bound is at position: ";
	cout << q - vectn.begin() << endl;

	cout << "The upper bound is at position: ";
	cout << p - vectn.begin() << endl;

	cout << endl;

	// Initializing vector with array values
	int arrm[] = { 5, 10, 15, 20, 20, 23, 42, 45 };
	int nm = sizeof(arrm) / sizeof(arrm[0]);
	vector<int> vectm(arrm, arrm + nm);

	cout << "Vector is :";
	for (int i = 0; i < nm; i++)
		cout << vectm[i] << " ";

	// Delete second element of vector
	vectm.erase(vectm.begin() + 1);

	cout << "\nVector after erasing the element: ";
	for (int i = 0; i < nm-1; i++)
		cout << vectm[i] << " ";

	// sorting to enable use of unique()
	sort(vectm.begin(), vectm.end());

	cout << "\nVector before removing duplicate "
		" occurrences: ";
	for (int i = 0; i < nm-1; i++)
		cout << vectm[i] << " ";

	// Deletes the duplicate occurrences
		vectm.erase(unique(vectm.begin(), vectm.end()), vectm.end());

	cout << "\nVector after deleting duplicates: ";
	for (int i : vectm)
		cout << i << " ";

	cout << endl;


	int arrs[] = { 5, 10, 15, 20, 20, 23, 42, 45 };
	int ns = sizeof(arrs) / sizeof(arrs[0]);
	vector<int> vects(arrs, arrs + ns);

	cout << "Given vectsor is:\n";
	for (int i = 0; i < ns; i++)
		cout << vects[i] << " ";

	// modifies vectsor to its next permutation order
	next_permutation(vects.begin(), vects.end());
	cout << "\nvectsor after performing next permutation:\n";
	for (int i = 0; i < ns; i++)
		cout << vects[i] << " ";

	prev_permutation(vects.begin(), vects.end());
	cout << "\nvectsor after performing prev permutation:\n";
	for (int i = 0; i < ns; i++)
		cout << vects[i] << " ";
	cout << endl;

	// Initializing vector with array values
	int arrp[] = { 5, 10, 15, 20, 20, 23, 42, 45 };
	int np = sizeof(arrp) / sizeof(arrp[0]);
	vector<int> vectp(arrp, arrp + np);

	// Return distance of first to maximum element
	cout << "Distance between first to max element: ";
	cout << distance(vectp.begin(),
		max_element(vectp.begin(), vectp.end()));
	getchar();
}