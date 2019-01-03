#include <stdafx.h>

#define __PRETTY_FUNCTION__ "FUNC"
namespace containerdisplay
{
	template<typename T, template<class, class...> class C, class... Args>
	std::ostream& operator <<(std::ostream& os, const C<T, Args...>& objs)
	{
		std::cout << __PRETTY_FUNCTION__ << '\n';
		for (auto const& obj : objs)
			os << obj << ' ';
		return os;
	}
}

template< typename K, typename V>
std::ostream& operator << (std::ostream& os,
	const std::map< K, V > & objs)
{

	std::cout << __PRETTY_FUNCTION__ << '\n';
	for (auto& obj : objs)
	{
		os << obj.first << ": " << obj.second << std::endl;
	}

	return os;
}


int main()
{

	{
		using namespace containerdisplay;
		std::vector<double> vf{ 1.1, 2.2, 3.3, 4.4 };
		std::cout << vf << '\n';

		std::list<char> lc{ 'a', 'b', 'c', 'd' };
		std::cout << lc << '\n';

		std::deque<int> di{ 1, 2, 3, 4 };
		std::cout << di << '\n';
	}

	std::map< std::string, std::string > m1
	{
		{ "foo", "bar" },
	{ "baz", "boo" }
	};

	std::cout << m1 << std::endl;

	std::map< std::string, double > m2
	{
		{ "3,300", 2.2 },
	{ "2,200", 3.3 }
	};

	std::cout << m2 << std::endl;
	getchar();
	return 0;
}
