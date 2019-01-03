#include <stdafx.h>
int main()
{
	int arr[] = { 1, 2, 3, 4 };

	sort(arr, arr + 4);

	cout << "The 4! possible permutations with 4 elements:\n";
	do 
	{
		cout << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << "\n";
	} while (next_permutation(arr, arr + 4));

	cout << "After loop: " << arr[0] << ' ' << arr[1] << ' ' << arr[2]<< ' ' << arr[3] << '\n';


	int arr2[] = { 1, 2, 3 };

	sort(arr2, arr2 + 3);
	reverse(arr2, arr2 + 3);

	cout << "The 3! possible permutations with 3 elements:\n";
	do {
		cout << arr2[0] << " " << arr2[1] << " " << arr2[2] << "\n";
	} while (prev_permutation(arr2, arr2 + 3));

	cout << "After loop: " << arr2[0] << ' ' << arr2[1]
		<< ' ' << arr2[2] << '\n';

	getchar();
}