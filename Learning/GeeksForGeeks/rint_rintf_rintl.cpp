#include <stdafx.h>
int main()
{
	double a, b, x = 3.3, y = 3.7;

	// Saves the rounded value to a variable
	fesetround(FE_UPWARD);
	a = rint(x);
	fesetround(FE_DOWNWARD);
	b = rint(y);

	// Prints the rounded value
	cout << a << endl;

	cout << b<<endl;

	long double xl = 3.765426764, yl = 3.37562657, resultl;

	// setting rounding direction to DOWNWARD
	fesetround(FE_DOWNWARD);

	resultl = rintl(xl);
	cout << resultl << endl;

	// setting rounding direction to UPWARD
	fesetround(FE_UPWARD);

	resultl = rintl(yl);
	cout << resultl << endl;
	
	auto xs = 3.76542;
	auto ys = 3.37562;
	// setting rounding direction to DOWNWARD
	fesetround(FE_DOWNWARD);

	auto result = rintf(xs);
	cout << result << endl;

	// setting rounding direction to UPWARD
	fesetround(FE_UPWARD);

	result = rintf(ys);
	cout << result << endl;

	getchar();
}