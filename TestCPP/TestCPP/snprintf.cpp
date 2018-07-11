#include <stdafx.h>
int main()
{
	char buffer[50];
	char* s = new char[14];
	memcpy(s,"geeksforgeeks",14);

	// Counting the character and storing 
	// in buffer using snprintf
	int j = snprintf(buffer, 6, "%s\n", s);

	// Print the string stored in buffer and
	// character count
	printf("string:\n%s\ncharacter count = %d\n",buffer, j);

	int bufsize = 7;
	char* str = new char[14];
	memcpy(str, "GeeksforGeeks", 14);
	char* buff = new char(bufsize);
	if (snprintf(buff, bufsize, "%s", str) >= bufsize) {
		bufsize *= 2;
		printf("Not enough space. Trying %d bytes\n", bufsize);
		delete buff;
		buff = new char(bufsize);

		if (snprintf(buff, bufsize, "%s", str) >= bufsize) {
			printf("Still not enough space. Aborting\n");
			exit(1);
		}
	}

	printf("There was enough space!\n");
	printf("buf: %s\n", buff);

	getchar();
}