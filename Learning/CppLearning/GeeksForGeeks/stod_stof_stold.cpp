#include <stdafx.h>
int main(void)

{
	std::string str = "y=4.4786754x+5.6";

	double y, x, a, b;
	y = 0;
	x = 0;

	// offset will be set to the length of 
	// characters of the "value" - 1.
	std::size_t offset = 0;

	a = std::stod(&str[2], &offset);
	b = std::stod(&str[offset + 3]);

	std::cout << a << endl;
	std::cout << b << endl;
	cout << endl;
	string bs = "5.32165";
	double as = stod(bs);
	int cs = stoi(bs);
	cout << bs << " " << as << " " << cs << endl;

	std::string xs;
	xs = "20";
	float ys = std::stof(xs) + 2.5;
	std::cout << ys;
	getchar();
}