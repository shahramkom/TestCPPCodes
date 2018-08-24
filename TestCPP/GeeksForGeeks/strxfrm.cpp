#include <stdafx.h>
int main()
{
	char src[10], dest[10];
	int len;
	strcpy(src, "geeksforgeeks");
	len = strxfrm(dest, src, 10);
	printf("Length of string %s is: %d", dest, len);


	char srcs[20], dests[200];
	strcpy(srcs, " hello geeksforgeeks");
	len = strxfrm(dests, srcs, 20);
	printf("Length of string %s is: %d", dests, len);
	getchar();
}