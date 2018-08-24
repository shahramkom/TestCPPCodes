#include <stdafx.h>
int main()
{
	double val1 = 225.0;
	double val2 = 300.0;

	cout << fixed << setprecision(8) << sqrt(val1) << endl;
	cout << fixed << setprecision(12) << sqrt(val2) << endl;

	float val1s = 225.0;
	float val2s = 300.0;

	cout << fixed << setprecision(12) << sqrtf(val1s) << endl
	cout << fixed << setprecision(12) << sqrtf(val2s) << endl;

	long long int val1l = 1000000000000000000;
	long long int val2l = 999999999999999999;

	cout << fixed << setprecision(12) << sqrt(val1l) << endl;
	cout << fixed << setprecision(12) << sqrt(val2l) << endl;

	long long int val1w = 1000000000000000000;
	long long int val2w = 999999999999999999;

	cout << fixed << setprecision(12) << sqrtl(val1w) << endl;
	cout << fixed << setprecision(12) << sqrtl(val2w) << endl;
	getchar();
}