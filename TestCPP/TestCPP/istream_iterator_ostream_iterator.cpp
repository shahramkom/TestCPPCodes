#include <stdafx.h>

int main()
{

	//EXAM 1
	/*
	// Get input stream and end of stream iterators
 	istream_iterator<int> cin_it(cin);
 	istream_iterator<int> eos;
 
 	// Get output stream iterators
 	ostream_iterator<int> cout_it(cout, " ");
 
 	// We have both input and output iterators, now we can treat them
 	// as containers. Using copy function we transfer data from one
 	// container to another.
 	// Copy elements from input to output using copy function
 	copy(cin_it, eos, cout_it);
	*/

	//EXAM 2
	/*
	// Define a vector to store the strings received from input
	vector<string> strings_v;

	// Define the filestream object used to read data from file
	ifstream fin("input_file.txt");

	// Get input stream and end of stream iterators
	istream_iterator<string> fin_it(fin);
	istream_iterator<string> eos;

	// Get output stream iterators
	ostream_iterator<string> cout_it(cout, " ");

	// Copy elements from input to vector using copy function
	copy(fin_it, eos, back_inserter(strings_v));

	// Sort the vector
	sort(strings_v.begin(), strings_v.end());

	// Copy elements from vector to output
	copy(strings_v.begin(), strings_v.end(), cout_it);
	*/

	//EXAM3
	// Define a vector to store the even integers received from input
	vector<int> vi;

	// Get input stream and end of stream iterators
	istream_iterator<int> cin_it(cin);
	istream_iterator<int> eos;

	// Get output stream iterators
	ostream_iterator<int> cout_it(cout, " ");

	// Copy even integer elements from input to vector using for_each function
	for_each(cin_it, eos, [&](int a) {
		if (a % 2 == 0) {
			// if a is even push it to vector
			vi.push_back(a);
		}
	});

	// Sort the vector
	sort(vi.begin(), vi.end());

	// Copy elements from vector to output
	copy(vi.begin(), vi.end(), cout_it);

	getchar();
}