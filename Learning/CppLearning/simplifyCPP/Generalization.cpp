#include "stdafx.h"

template <class K, class V>
std::map<K, std::pair<V, V>> diffMaps(std::map<K, V>& before, std::map<K, V>& after)
{
	std::map<K, std::pair<V, V>> changed;
}

// class Rational /* : operator groups... */ {
// 	/* ... */
// public:
// 	Rational(int n, int d) //the old one, without default parameters
// 		: numerator((d > 0) ? n : -n)
// 		, denominator((d > 0) ? d : -d)
// 	{
// 		cancel();
// 	}
// 
// 	Rational()
// 		: numerator(0)
// 		, denominator(1)
// 	{}
// 
// 	template <typename T, typename enable_if<is_integral::value>::type* = nullptr> Rational(T n)
// 		: numerator{ n }
// 		, denominator{ 1 }
// 	{}
// };

// enable_if example: two ways of using enable_if
#include <iostream>
#include <type_traits>

// 1. the return type (bool) is only valid if T is an integral type:
template <class T>
typename std::enable_if<std::is_integral<T>::value, bool>::type
is_odd(T i) { return bool(i % 2); }

// 2. the second template argument is only valid if T is an integral type:
template < class T,
	class = typename std::enable_if<std::is_integral<T>::value>::type>
	bool is_even(T i) { return !bool(i % 2); }

int main() {

	short int i = 1;    // code does not compile if type of i is not integral

	std::cout << std::boolalpha;
	std::cout << "i is odd: " << is_odd(i) << std::endl;
	std::cout << "i is even: " << is_even(i) << std::endl;

	return 0;
}

