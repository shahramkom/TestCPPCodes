#include <stdafx.h>
int main()
{
	// Declaring first vector
	vector<int> vfp1;
	int ifp;

	// v1 contains 0 1 2 3 4 5 6 7 8 9
	for (ifp = 0; ifp < 10; ++ifp)
	{
		vfp1.push_back(ifp);
	}


	// Declaring second vector
	// v2 contains 100 100 100 100 100
	vector<int> vfp2(5, 100);

	// Performing swap
	std::swap_ranges(vfp1.begin() + 3, vfp1.begin() + 7, vfp2.begin());

	// Displaying v1 after swapping
	for (ifp = 0; ifp < 10; ++ifp)
		cout << vfp1[ifp] << " ";

	cout << endl;

	// Displaying v2 after swapping
	for (ifp = 0; ifp < 5; ++ifp)
		cout << vfp2[ifp] << " ";
	cout << endl;
	//////////////////////////////////////////////////////////////////////////
	// Here 5 is the central element and the two halves
	// on its either side contain the same elements 1 2 3 4
	vector<int> v1 = { 1, 2, 3, 4, 5, 1, 2, 3, 4 };

	int i;

	// Declaring second vector and making it equal to v1
	vector<int> v2 = v1;

	// Here there is no central element and the two halves
	// are 1 2 3 4 and 1 2 3 5 which are different
	vector<int> v3 = { 1, 2, 3, 4, 1, 2, 3, 5 };


	// Declaring fourth vector and making it equal to v3
	vector<int> v4 = v3;

	// Performing swap between two halves of vector v1
	if (v1.size() % 2 == 0)
		std::swap_ranges(v1.begin(), v1.begin() + (v1.size() / 2),v1.begin() + v1.size() / 2);

	else
		std::swap_ranges(v1.begin(), v1.begin() + v1.size() / 2,v1.begin() + (v1.size() / 2) + 1);

	if (v1 == v2)
		cout << "Yes";
	else
		cout << "No";
	

	// Now, Performing swap between two halves of vector v3
	if (v3.size() % 2 == 0)
		std::swap_ranges(v3.begin(), v3.begin() + (v3.size() / 2),v3.begin() + v3.size() / 2);

	else
		std::swap_ranges(v3.begin(), v3.begin() + v3.size() / 2,v3.begin() + (v3.size() / 2) + 1);

	cout << "\n";

	if (v3 == v4)
		cout << "Yes";
	else
		cout << "No";

	getchar();
}