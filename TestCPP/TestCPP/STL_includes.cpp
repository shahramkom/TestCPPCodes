#include <stdafx.h>

bool comp(int i, int j) { return i<j; }

int main()
{
	// initializing 1st container
	vector<int> arr1 = { 1, 4, 6, 3, 2 };

	// initializing 2nd container
	vector<int> arr2 = { 1, 2, 4 };

	// sorting initial containers
	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());

	// using include() check if all elements 
	// of arr2 lie in arr1 
	if (includes(arr1.begin(), arr1.end(), arr2.begin(), arr2.end()))
		cout << "All elements of 2nd container are in 1st container";
	else
		cout << "All elements of 2nd container are not in 1st container";

	cout << endl;
	// using include() check if all elements 
	// of arr2 lie in arr1 
	// using comparator function
	if (includes(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), comp))
		cout << "All elements of 2nd container are in 1st container";
	else
		cout << "All elements of 2nd container are not in 1st container";

	cout << endl;

	vector<int> lottery = { 1, 4, 6, 3, 2, 54 , 32 };

	// Numbers in user's card
	vector<int> user = { 1, 2, 4, 6 };

	// sorting initial containers
	sort(lottery.begin(), lottery.end());
	sort(user.begin(), user.end());

	// using include() check if all elements 
	// of user are present as lottery numbers
	if (includes(lottery.begin(), lottery.end(), user.begin(), user.end()))
		cout << "User has won lottery ( all numbers are lottey numbers )";
	else
		cout << "User has not won the lottery";
	getchar();
}