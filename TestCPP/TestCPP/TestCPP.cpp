// TestCPP.cpp : Defines the entry point for the console application.
//

#include <stdafx.h>

template <class T>
void func(T t)
{
	printf("%d", sizeof(t));
}

int main()
{
// 	auto inp = getchar();
// 	func(inp);


	uint64_t arr[5], i;

	printf("Size of integer in this compiler is %u\n", sizeof(uint64_t));

	for (i = 0; i < 5; i++)
		// The use of '&' before a variable name, yields
		// address of variable.
		cout << "Address arr" << i << " is " << &arr[i] << endl;



	getchar();
}


