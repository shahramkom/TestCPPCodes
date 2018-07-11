#include <stdafx.h>

long double operator"" _kg(long double x)
{
	return x * 1000;
}

// Gram
long double operator"" _g(long double x)
{
	return x;
}

// MiliGram
long double operator"" _mg(long double x)
{
	return x / 1000;
}

constexpr complex <double> operator"" _i(long double d)
{
	return complex <double> { 0.0, static_cast <double> (d) };
}

// Driver code
int main()
{
	long double weight = 3.6_kg;
	cout << weight << endl;
	cout << (weight + 2.3_mg) << endl;
	cout << (32.3_kg / 2.0_g) << endl;
	cout << (32.3_mg *2.0_g) << endl;

	complex <double> z = 3.0 + 4.0_i;
	complex <double> y = 2.3 + 5.0_i;
	cout << "z + y = " << z + y << endl;
	cout << "z * y = " << z * y << endl;
	cout << "abs(z) = " << abs(z) << endl;

	getchar();
}