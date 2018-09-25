#include <stdafx.h>
#include <fstream>
#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main()
{
	/*
	fstream file;
	file.open("cout.txt", ios::out);
	string line;

	// Backup streambuffers of  cout
	streambuf* stream_buffer_cout = cout.rdbuf();
	streambuf* stream_buffer_cin = cin.rdbuf();

	// Get the streambuffer of the file
	streambuf* stream_buffer_file = file.rdbuf();

	// Redirect cout to file
	cout.rdbuf(stream_buffer_file);

	cout << "This line written to file" << endl;

	// Redirect cout back to screen
	cout.rdbuf(stream_buffer_cout);
	cout << "This line is written to screen" << endl;

	file.close();
	getchar();
	*/

	int a;
	char str[80];

	// Enter input from user
	// - 4 for example
	cin >> a;

	// discards the input buffer
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	// Get input from user - 
	// GeeksforGeeks for example
	cin.getline(str, 80);

	// Prints 4
	cout << a << endl;

	// Printing string : This
	// will print string now
	cout << str << endl;

}

using namespace std;
int main()
{
	int input;
	int count = 0;
	cout << "To stop enter any character";
	cout << "\nEnter Your Input::";

	// cin returns false when a character
	// is entered
	while (cin >> input)
		count++;

	cout << "\nTotal number of inputs entered: "
		<< count;
	return 0;
}

