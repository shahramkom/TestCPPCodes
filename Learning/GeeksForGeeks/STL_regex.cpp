#include <stdafx.h>
int main()
{
	string a = "GeeksForGeeks";

	// Here b is an object of regex (regular expression)
	regex b("(Geek)(.*)"); // Geeks followed by any character

						   // regex_match function matches string a against regex b
	if (regex_match(a, b))
		cout << "String 'a' matches regular expression 'b' \n";

	// regex_match function for matching a range in string 
	// against regex b
	if (regex_match(a.begin(), a.end(), b))
		cout << "String 'a' matches with regular expression "
		"'b' in the range from 0 to string end\n";
	cout << endl ;

	// Target sequence
	string s = "I am looking for GeeksForGeeks articles";

	// An object of regex for pattern to be searched
	regex r("Geek[a-zA-Z]+");

	// flag type for determining the matching behavior
	// here it is for matches on 'string' objects
	smatch m;

	// regex_search() for searching the regex pattern
	// 'r' in the string 's'. 'm' is flag for determining
	// matching behavior.
	regex_search(s, m, r);

	// for each loop
	for (auto x : m)
		cout << x << " ";
	cout << endl << endl;

	string spd = "I am looking for GeeksForGeek \n";
	// regex_replace() for replacing the match with 'geek' 
	cout << std::regex_replace(spd, r, "geek");

	string result;

	// regex_replace( ) for replacing the match with 'geek'
	regex_replace(back_inserter(result), spd.begin(), spd.end(),r, "geek");

	cout << result;
	getchar();
}