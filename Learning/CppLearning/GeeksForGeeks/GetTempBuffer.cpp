#include <stdafx.h>


void sorting(int b[], int n)
{
	int i, c = 0;
	for (i = 0; i < n; i++)
		if (b[i] % 2 == 0) 
			c++;
	
	cout << "The total even numbers are:  " << c << endl;
	cout << "original array :" << " " <<endl;
	for (i = 0; i < 10; i++) 
		cout << b[i] << " ";
	cout << endl;

	pair<int*, ptrdiff_t> p = get_temporary_buffer<int>(10);

	// copy the contents in temporary buffer with pair
	std::uninitialized_copy(b, b + p.second, p.first);

	cout << "sorted array :" << endl;
	for (i = 0; i < p.second; i++)
	{
		sort(p.first, p.first + p.second);
		cout << p.first[i] << " ";
	}
}
// driver program to test above function
int main()
{
	int b[] = { 8, 9, 2, 1, 10, 14, 37, 18, 17, 5 };
	int n = sizeof(b) / sizeof(b[0]);
	sorting(b, n);
	getchar();
}


// int main()
// {
// 	std::vector<std::string> v = { "This", "is", "an", "example" };
// 
// 	std::string* p;
// 	std::size_t sz;
// 	std::tie(p, sz) = std::get_temporary_buffer<std::string>(v.size());
// 	sz = std::min(sz, v.size());
// 
// 	std::uninitialized_copy(v.begin(), v.begin() + sz, p);
// 
// 	for (std::string* i = p; i != p + sz; ++i) {
// 		std::cout << *i << ' ';
// 		i->~basic_string<char>();
// 	}
// 	std::return_temporary_buffer(p);
// 	getchar();
// }