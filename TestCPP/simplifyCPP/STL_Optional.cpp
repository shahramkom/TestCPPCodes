#include <stdafx.h>

std::optional<unsigned> firstEvenNumberIn(std::string text)
{
	auto oComplex = make_optional<unsigned>(123);

	// in_place
	std::optional<std::complex<unsigned>> o7{ std::in_place, 3 };

	// will call vector with direct init of {1, 2, 3}
	return oComplex;
}

int main()
{
	std::string text = "ali pass 123";
	std::optional<unsigned> opt = firstEvenNumberIn(text);
	if (opt.has_value())
	{
		std::cout << "The first even number is "
			<< opt.value()
			<< ".\n";
	}
	return 0;
}