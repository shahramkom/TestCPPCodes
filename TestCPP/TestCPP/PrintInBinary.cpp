#include <stdafx.h>

void printInBinary(uint64_t num)
{
	uint64_t n = CHAR_BIT * sizeof(num);
	stack<bool> s;
	for (auto i = 1; i <= n; i++)
	{
		s.push(num % 2);
		num = num / 2;
	}
	for (auto i = 1; i <= n; i++)
	{
		cout << s.top();
		s.pop();

		// Put a space after every byte. 
		if (i % CHAR_BIT == 0)
			cout << " ";
	}
}

int main()
{
	uint64_t num = 465432136546876513;
	printInBinary(num);
	getchar();
}