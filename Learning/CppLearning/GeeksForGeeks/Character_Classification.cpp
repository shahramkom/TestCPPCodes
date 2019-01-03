#include <stdafx.h>
int main()
{
	// initializing character array
	char ch[5] = "g1";

	// checking for isalpha() function
	for (int i = 0; i < 2; i++)
	{
		if (isalpha(ch[i]))
			cout << ch[i] << " is alphabet" << endl;
		else
			cout << ch[i] << " is not alphabet" << endl;
	}

	cout << endl;

	// checking for isalnum() function
	for (int i = 0; i < 2; i++)
	{
		if (isalnum(ch[i]))
			cout << ch[i] << " is alphanumeric" << endl;
		else
			cout << ch[i] << " is not alphanumeric" << endl;
	}

	cout << endl;

	// checking for isdigit() function
	for (int i = 0; i < 2; i++)
	{
		if (isdigit(ch[i]))
			cout << ch[i] << " is digit" << endl;
		else
			cout << ch[i] << " is not digit" << endl;
	}

	cout << endl;
	// initializing character array
	char chs[4] = " \n\t";

	// checking for iscntrl() function
	for (int i = 0; i < 3; i++)
	{
		if (iscntrl(chs[i]))
			cout << " Character is control code " << endl;
		else
			cout << " Character is not control code" << endl;
	}

	cout << endl;

	// checking for isblank() function
	for (int i = 0; i < 3; i++)
	{
		if (isblank(chs[i]))
			cout << " Character is blank" << endl;
		else
			cout << " Character is not blank" << endl;
	}

	cout << endl;

	// checking for isspace() function
	for (int i = 0; i < 3; i++)
	{
		if (isspace(chs[i]))
			cout << " Character is space" << endl;
		else
			cout << " Character is not space" << endl;
	}

	cout << endl;

	// initializing character array
	char cha[6] = "\t@gf1";

	// checking for isprint() function
	for (int i = 0; i < 5; i++)
	{
		if (isprint(cha[i]))
			cout << cha[i] << " is printable character " << endl;
		else
			cout << cha[i] << " is not printable Character" << endl;
	}

	cout << endl;

	// checking for isxdigit() function
	for (int i = 0; i < 5; i++)
	{
		if (isxdigit(cha[i]))
			cout << cha[i] << " is hexadecimal Character" << endl;
		else
			cout << cha[i] << " is not hexadecimal Character" << endl;
	}

	cout << endl;

	// checking for ispunct() function
	for (int i = 0; i < 5; i++)
	{
		if (ispunct(cha[i]))
			cout << cha[i] << "  is punctuation mark" << endl;
		else
			cout << cha[i] << "  is not punctuation mark" << endl;
	}
	getchar();
}