#include <stdafx.h>

void direction()
{
	switch (fegetround()) {
	case FE_TONEAREST:
		cout << "FE_TONEAREST";
		break;
	case FE_DOWNWARD:
		cout << "FE_DOWNWARD";
		break;
	case FE_UPWARD:
		cout << "FE_UPWARD";
		break;
	case FE_TOWARDZERO:
		cout << "FE_TOWARDZERO";
		break;
	default:
		cout << "unknown";
	};
	cout << endl;
}

int main()
{
	double x = 3.7, result;
	// setting rounding direction to the nearest integer
	fesetround(FE_TONEAREST);
	result = rint(x);
	cout << result << endl;

	// setting rounding direction towards zero
	fesetround(FE_TOWARDZERO);
	result = rint(x);
	cout << result << endl;

	// setting rounding direction to DOWNWARD
	fesetround(FE_DOWNWARD);
	result = rint(x);
	cout << result << endl;

	// setting rounding direction to UPWARD
	fesetround(FE_UPWARD);
	result = rint(x);
	cout << result << endl << endl;

	fesetround(FE_UPWARD);
	nearbyint(x);
	direction();

	fesetround(FE_DOWNWARD);
	nearbyint(x);
	direction();

	fesetround(FE_TOWARDZERO);
	nearbyint(x);
	direction();

	fesetround(FE_TONEAREST);
	nearbyint(x);
	direction();
	getchar();
}