#include <stdafx.h>
// random generator function
int randomfunc(int j)
{
	return rand() % j;
}

int main()
{
	srand(unsigned(time(0)));
	vector<int> arr;

	// set some values:
	for (int j = 1; j < 10; ++j)

		// 1 2 3 4 5 6 7 8 9
		arr.push_back(j);

	// using built-in random generator
	random_shuffle(arr.begin(), arr.end());

	// using randomfunc
	random_shuffle(arr.begin(), arr.end(), randomfunc);

	// print out content:
	cout << "arr contains:";
	for (int & i : arr)
		cout << ' ' << i;

	cout << endl;

	array<int, 7> s{ 1, 2, 3, 4, 5, 6, 7 };

	// To obtain a time-based seed
	unsigned seed = 0;

	// Use of shuffle
	shuffle(s.begin(), s.end(), default_random_engine(seed));

	cout << "shuffled elements are:";
	for (int& i : s)
		cout << ' ' << i;
	cout << endl;
	getchar();
}
