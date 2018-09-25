#include <stdafx.h>

bool Pred(int a, int b)
{
	return (a == b);
}



bool pred1(int a, int b)
{
	if (a % b != 0) {
		return 1;
	}
	else {
		return 0;
	}
}

// Defining the Predicate Function to find last occurrence
// of an even number
bool pred2(int a, int b)
{
	if (a % b == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int main()
{
	// Defining first container
	vector<int>vs = { 1, 3, 10, 3, 10, 1, 3, 3, 10, 7, 8, 1, 3, 10 };

	// Defining second container
	vector<int>vs1 = { 1, 3, 10 };

	vector<int>::iterator ip;

	// Using std::find_end
	ip = std::find_end(vs.begin(), vs.end(), vs1.begin(),vs1.end());

	// Displaying the index where the last common occurrence 
	// begins
	; cout << "position:" << &ip << ",Index:" << (ip - vs.begin()) << endl << endl;

	//////////////////////////////////////////////////////////////////////////

	// Defining first container
	vector<int>v = { 1, 5, 7, 11, 13, 15, 30, 30, 7 }, i;

	// Defining second container
	vector<int>vm1 = { 13, 15 };

	vector<int>::iterator ips;

	// Using std::find_end
	ips = std::find_end(v.begin(), v.end(), vm1.begin(),vm1.end(), Pred);

	// Displaying the index where the last common occurrence
	// begins
	cout << (ips - v.begin()) << endl << endl;
	//////////////////////////////////////////////////////////////////////////

	// Declaring the sequence to be searched into
	vector<int> vw1 = { 1, 2, 3, 4, 5, 6, 7, 3, 4, 5 };

	// Declaring the subsequence to be searched for
	vector<int> vw2 = { 3, 4 };

	// Declaring an iterator for storing the returning pointer
	vector<int>::iterator iw1;

	// Using std::search to find the first occurrence of v2
	iw1 = std::search(vw1.begin(), vw1.end(), vw2.begin(),vw2.end());

	// checking if iterator i1 contains end pointer of v1 or
	// not
	if (iw1 != vw1.end()) {
		cout << "vector2 is present firstly at index "
			<< (iw1 - vw1.begin());
	}
	else {
		cout << "vector2 is not present in vector1";
	}

	// Using std::find_end to find the last occurrence of v2
	iw1 = std::find_end(vw1.begin(), vw1.end(), vw2.begin(),vw2.end());

	// checking if iterator i1 contains end pointer of v1 or 
	//not
	if (iw1 != vw1.end()) {
		cout << "\nvector2 is present lastly at index "<< (iw1 - vw1.begin());
	}
	else {
		cout << "vector2 is not present in vector1";
	}
	//////////////////////////////////////////////////////////////////////////
	cout << endl << endl;
	// Defining a vector
	vector<int>v1 = { 1, 3, 4, 5, 6, 7, 8, 10 };

	// Declaring a sub-sequence
	vector<int>v2 = { 2 };

	// Using std::find_end to find the last occurrence of an
	// odd number
	vector<int>::iterator ipq;
	ipq = std::find_end(v1.begin(), v1.end(), v2.begin(),v2.end(), pred1);

	// Displaying the index where the last odd number occurred
	cout << "Last odd no. occurs at " << (ipq - v1.begin());


	// Using std::find_end to find the last occurrence of an 
	// even number
	ipq = std::find_end(v1.begin(), v1.end(), v2.begin(),v2.end(), pred2);

	// Displaying the index where the last even number occurred
	cout << "\nLast even no. occurs at " << (ipq - v1.begin());
	getchar();
}