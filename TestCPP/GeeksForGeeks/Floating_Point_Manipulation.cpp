#include <stdafx.h>
int main() {

	double a, b, c, d, f;
	int g;

	// initializing values
	a = 9.6;
	b = 3.5;

	// using fmod() to compute the remainder
	// computes 2 as quotient (truncated)
	// returns 2.6 as remainder
	d = fmod(a, b);

	// using remainder() to compute the remainder
	// computes 3 as quotient (rounded)
	// returns -0.9 as remainder
	c = remainder(a, b);

	// using remquo() to return quotient and remainder
	// quotient stored in g
	f = remquo(a, b, &g);

	cout << "The remainder computed using fmod() is : " << d;
	cout << endl;

	cout << "The remainder computed using remainder() is : " << c;
	cout << endl;

	cout << "The remainder part of " << a << "/" << b << " is : " << f;
	cout << endl;
	cout << "The quotient part of " << a << "/" << b << " is : " << g;
	cout << endl;

	double af, bf, cf;
	
	// initializing values
	af = 9.6;
	bf = -3.5;
	cf = 0.0;

	// using copysign()
	cout << "The value returned after copysigning is : ";
	cout << copysign(af, bf);

	cout << endl;

	// using nextafter() to compute next approximated value 
	cout << "The next value approximated is : ";
	cout << nextafter(cf, bf);

	cout << endl;

	double ad, bd, cd;

	// initializing values
	ad = 2.5;
	bd = 2.0;
	cd = 2.5;

	// using fmax() to compute maximum of two numbers
	cout << "The largest of 2 numbers is : ";
	cout << fmax(ad, bd);

	cout << endl;

	// using fmin() to compute smallest of two numbers
	cout << "The smallest of 2 numbers is : ";
	cout << fmin(ad, bd);

	cout << endl;

	// using fdim() to compute positive difference of two numbers
	cout << "The positive difference of 2 numbers is : ";
	cout << fdim(ad, bd);

	cout << endl;

	// using fma() to compute multiply-add
	cout << "The multiply-add of 3 numbers is : ";
	cout << fma(ad, b, cd);
	getchar();
}