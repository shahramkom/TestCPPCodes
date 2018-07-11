#include <stdafx.h>
int main()
{
	// using nextafter
	printf("Smallest positive floating point number : %e\n",
		nextafter(0.0, 1.0));
	printf("Largest negative floating point number :%e\n",
		nextafter(0.0, -1.0));
	printf("Largest positive floating point number smaller than 0.5 : %e\n",
		nextafter(0.5, 0.0));

	// using nexttoward
	printf("Smallest positive floating point number : %e\n",
		nexttoward(0.0, 1.0));
	printf("Largest negative floating point number : %e\n",
		nexttoward(0.0, -1.0));
	printf("Largest positive floating point number smaller than 0.5 : %e\n",
		nexttoward(0.5, 0.0));

	getchar();
}