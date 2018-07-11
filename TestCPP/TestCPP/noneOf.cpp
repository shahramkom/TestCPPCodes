#include <stdafx.h>
bool comp(int a) { return a < 0; }

// Driver code
int main()
{
	int arr[] = { 2, 4, 6, 8, 12, 0 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Array contains :";
	for (int i = 0; i < n; i++)
		cout << ' ' << arr[i];
	cout << "\n";
	//if (none_of(arr, arr + n, comp))
	if (none_of(arr, arr + n, [](int a) {return a < 0; }))
		cout << "No negative elements in the range.\n";
	else
		cout << "There is at least one negative"
		" element in the array range.\n";
	getchar();
}