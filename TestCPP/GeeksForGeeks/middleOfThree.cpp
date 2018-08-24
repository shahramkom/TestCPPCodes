#include <stdafx.h>

/*
int middleOfThree(int a, int b, int c)
{
// Checking for b
if ((a < b && b < c) || (c < b && b < a))
return b;

// Checking for a
else if ((b < a && a < c) || (c < a && a < b))
return a;

else
return c;
}
*/
int middleOfThree(int a, int b, int c)
{
	// x is positive if a is greater than b. 
	// x is negative if b is greater than a.
	int x = a - b;

	int y = b - c;  // Similar to x
	int z = a - c;  // Similar to x and y.

					// Checking if b is middle (x and y both
					// are positive)
	if (x * y > 0)
		return b;

	// Checking if c is middle (x and z both
	// are positive)
	else if (x * z > 0)
		return c;
	else
		return a;
}

// Driver Code
int main()
{
	int a = 20, b = 30, c = 40;
	cout << middleOfThree(a, b, c);
	getchar();
}
