#include <stdafx.h>
int main()
{
	// set base to hexadecimal
	std::cout << std::setbase(16);

	// displaying 255 in hexadecimal
	std::cout << 255 << std::endl;

	// set base to Octal
	std::cout << std::setbase(8);

	// displaying 255 in Octal
	std::cout << 255 << std::endl;

	// set width of 10
	std::cout << std::setw(10);
	std::cout << 100 << std::endl;

	std::string strG = "GFG";

	// set width of 12
	std::cout << std::setw(12);

	std::cout << strG << std::endl;

	// setfill is x and width is set as 10
	std::cout << std::setfill('x') << std::setw(10);

	std::cout << 77 << std::endl;

	std::string str = "Geeks";

	// setfill is G and width is set as 10
	// And std::left is used set str to left side
	std::cout << std::left << std::setfill('G') << std::setw(10);

	std::cout << str << std::endl;


	int n = 5;
	for (int i = 1; i <= n; i++) {
		std::cout << std::left << std::setfill(' ') << std::setw(n);
		std::cout << std::string(i, '*') << std::endl;
	}

	getchar();
}