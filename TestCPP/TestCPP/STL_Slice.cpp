#include <stdafx.h>

int main()
{
	valarray<int> sample(12);
	// initialising valarray
	for (int i = 0; i < 13; ++i)
		sample[i] = i;

	// using slice from start 1 and size 3 and stride 4
	valarray<int> bar = sample[slice(2, 3, 4)];

	// display slice result
	cout << "slice(2, 3, 4):";
	for (size_t n = 0; n < bar.size(); n++)
		cout << ' ' << bar[n];
	cout << endl;
	cout << endl;


	// row and column of matrix
	int row = 3, col = 3;

	// matrix of size row*col in row major form.
	valarray<int> matrix(row * col);

	// initialising matrix
	for (int i = 0; i < row * col; ++i)
		matrix[i] = i + 1;

	// using slice from start 0 with size as col and stride col+1
	valarray<int> diagonal = matrix[slice(0, col, col + 1)];

	// finding trace using diagonal we got using slice
	int index = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			cout << matrix[index++] << " "; // same as matrix[i][j]
		cout << endl;
	}

	int sum = 0; // initialising sum as 0
				 // calculating trace of matrix
 	for (int i = 0; i < diagonal.size(); i++)
 		sum += diagonal[i];
	cout << "Trace of matrix is : ";
	cout << sum << endl; // sum is trace of matrix

	getchar();
}