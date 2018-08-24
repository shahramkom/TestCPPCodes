#include <stdafx.h>
// int main()
// {
// 	//valarray sample of size 14
// 	std::valarray<int> sample(14);
// 	for (int i = 0; i<14; ++i) sample[i] = i;
// 
// 	std::size_t start = 1;
// 	std::size_t lengths[] = { 2,3 };
// 	std::size_t strides[] = { 7,2 };
// 
// 	//gslice object which can be used directly
// 	std::gslice mygslice(start,
// 		std::valarray<std::size_t>(lengths, 2),
// 		std::valarray<std::size_t>(strides, 2));
// 	//creating data using gslice
// 	std::valarray<int> data = sample[mygslice];
// 
// 	/* Can also be done in the following way
// 	(without creating gslice object):
// 	std::valarray<int> data=sample[std::gslice(start,
// 	std::valarray<std::size_t>(lengths,2),
// 	std::valarray<std::size_t>(strides,2))];
// 	*/
// 
// 	std::cout << "gslice:";
// 
// 	//displaying content of data 
// 	for (int i = 0; i<data.size(); i++)
// 		std::cout << ' ' << data[i];
// 	std::cout << '\n';
// 
// 	getchar();
// }

void test_print(std::valarray<int>& v, int rows, int cols, int planes)
{
	for (int r = 0; r < rows; ++r) {
		for (int c = 0; c < cols; ++c) {
			for (int z = 0; z < planes; ++z)
				std::cout << v[r*cols*planes + c * planes + z] << ' ';
			std::cout << '\n';
		}
		std::cout << '\n';
	}
}
int main()
{
	// 3d array: 2 x 4 x 3 elements
	std::valarray<int> v =
	{ 111,112,113 , 121,122,123 , 131,132,133 , 141,142,143,
		211,212,213 , 221,222,223 , 231,232,233 , 241,242,243 };

	// int ar3D [2][4][3]
	std::cout << "Initial 2x4x3 array:\n";
	test_print(v, 2, 4, 3);

	// update every value in the first columns of both planes
	// two level one strides of 12 elements
	// then four level two strides of 3 elements
	v[std::gslice(0, { 2, 4 }, { 4 * 3, 3 })] = 1;


	// subtract the third column from the 
	// second column in the 1st plane
	v[std::gslice(1, { 1, 4 }, { 4 * 3, 3 })]
		-= v[std::gslice(2, { 1, 4 }, { 4 * 3, 3 })];

	std::cout << "After column operations: \n";
	test_print(v, 2, 4, 3);
	getchar();
}
