#include <stdafx.h>

void display(char* abc, char* xyz, int res, int count)
{
	if (res > 0)
		std::cout << xyz << " come-before " << abc;
	else if (res < 0)
		std::cout << abc << " come-before " << xyz;
	else
		std::cout << "First " << count << " characters of string "
		<< abc << " and " << xyz << " are same";
}

int main()
{
	// Take any two strings
	char str1[10] = "aksh";
	char str2[10] = "akash";

	// Compare strings using strncmp()
	int result = strncmp(str1, str2, 4);

	if (result == 0) {
		// num is the 3rd parameter of strncmp() function
		printf("str1 is equal to str2 upto num characters\n");
	}
	else if (result > 0)
		printf("str1 is greater than str2\n");
	else
		printf("str2 is greater than str1\n");

	printf("Value returned by strncmp() is: %d", result);


	cout << endl;

	memcpy(str1, "akash", 5);
	memcpy(str2, "aksh", 4);

	// Compare strings using strncmp()
	result = strncmp(str1, str2, 4);

	if (result == 0) {
		// num is the 3rd parameter of strncmp() function
		printf("str1 is equal to str2 upto num characters\n");
	}
	else if (result > 0)
		printf("str1 is greater than str2\n");
	else
		printf("str2 is greater than str1\n");

	printf("Value returned by strncmp() is: %d", result);


	cout << endl;

	memcpy(str1,"akash",5);
	memcpy(str2,"akas",4);

	// Compare strings using strncmp()
	result = strncmp(str1, str2, 4);

	if (result == 0) {
		// num is the 3rd parameter of strncmp() function
		printf("str1 is equal to str2 upto num characters\n");
	}
	else if (result > 0)
		printf("str1 is greater than str2\n");
	else
		printf("str2 is greater than str1\n");

	printf("Value returned by strncmp() is: %d", result);

	cout << endl;


	char abc[] = "GeeksforGeeks";
	char xyz[] = "Geeks";
	int res = std::strncmp(abc, xyz, 4);
	display(abc, xyz, res, 4);
	cout << endl;

	res = std::strncmp(abc, xyz, 6);
	display(abc, xyz, res, 6);
	getchar();
}