#include <stdafx.h>
int randomize()
{
	return (rand() % 1000);
}

int main()
{
	// for different values each time we run the code
	srand(time(NULL));

	vector<int> vect(10); // declaring the vector

						  // Fill all elements using randomize()
	generate(vect.begin(), vect.end(), []() {return rand() % 1000; });

	// displaying the content of vector
	for (int i : vect)
		cout << i << " ";
	cout << endl;
	vector<int> vectg(10); // declaring the vector

						  // Fill 6 elements from beginning using randomize()
	generate_n(vectg.begin(), 6, randomize);

	// displaying the content of vector
	for (int i : vectg)
		cout << i << " ";
	getchar();
}