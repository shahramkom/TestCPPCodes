#include <stdafx.h>
using namespace std;

int main()
{
	char sr[] = "This is a sample";
	char ch = 's';
	int count = 13;

	if (memchr(sr, ch, count))
		cout << ch << " is present in first "
		<< count << " characters of \"" << sr << "\"";
	else
		cout << ch << " is not present in first "
		<< count << " characters of \"" << sr << "\"";
	cout << endl;

	char arr[] = { 'b', 'a', 'd', 'e', 'f', 'A', 'g' };
	char* pc = (char*)memchr(arr, 'g', sizeof arr);
	if (pc != NULL)
		cout << "search character found\n";
	else
		cout << "search character not found\n";

	getchar();
}