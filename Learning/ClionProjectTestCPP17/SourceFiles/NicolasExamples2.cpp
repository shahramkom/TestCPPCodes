#include "../HeaderFiles/NicolasExamples2.h"
#include "../HeaderFiles/Includes.h"
#include <amp.h>
#if __has_include(<optional>)
#include <optional>
#define HAS_OPT 1
#elif __has_include(<exprimental/optional>)
#include <exprimental/optional>
#define HAS_OPT 1
#else
#define HAS_OPT 0
#endif

using namespace std;
using namespace concurrency;

NicolasExamples2::NicolasExamples2()
{

}

template <class T>
const T& MyMin(const T& a, const T& b) { return b < a ? b : a; };

int& f2() { int m = 3; return m; }
int f3() { return 1; }

void NicolasExamples2::testMinTemplate()
{
	int x = 10, y = 2;
	const int& ref = MyMin(x, y);
	cout << ref << endl;
	const int bad = MyMin(x, y + 1);//Error bad initialize
	cout << "bad init:" << bad << endl;

	int& f2();
	int f3();
	//const int& bad2 = MyMin(x, f2()); //Error
	//const int& bad3 = MyMin(x, f3()); //Error
}


bool testBool() { return true; }
int testInt() { return 2; }

template<typename T>
struct D : string, complex<T>
{
	string data;
};

enum ENM
{
	foobar = 0,
	foobat[[deprecated]] = foobar
};

namespace[[deprecated]] xyz{
	class xyz
	{
		xyz() = default;
	};
}

template<typename T>
void PRINT(T x)
{
	cout << "-def: " << std::defaultfloat << x << endl;
	cout << "-hex: " << std::hexfloat << x << endl << endl;
}

struct MyStruct
{
	int i;
	double d;
};

MyStruct f1;

template<typename T>
void FOO(T t)
{
	if constexpr (is_integral_v<T>) {
		if (t > 0)
		{
			foo(t - 1);
		}
	}
	else
	{
		undeclared(t);
		undeclared();
		static_assert(false, "no integral");
		static_assert(is_integral_v<T>, "no integral");
	}
}

template<typename T>
void food(T t)
{

}

template<typename... T>
auto foldSum(T... s)
{
	return(... + s); //s1+s2+s3
}

template<typename... T>
auto foldSun(T... s)
{
	return(0 + ... + s); //even work if size of s = 0
}

//TODO
//template<typename T, typename... TP>
//T* travers(T np, TP... paths)
//{
//	return (np->* ...->*paths); //np->*path1->*path2
//}

struct Node
{
	int value;
	Node* left;
	Node* right;
};

//template<auto N> class Spd
//{
//};
//Spd<42> spd1;
//Spd<'a'> spd2;
//Spd<2.5> spd3;//Error

void NicolasExamples2::startTests()
{
	//auto[w] = f1(); //Error
	//TODO
	auto[v, m] = f1;
	//auto f2 -> int(&)[2];
	//auto[x, y] = f2;
	std::array<int, 4> f3 = { 1,2,3,4 };
	auto[i, j, k, l] = f3;
	tuple<char, float, string> f4;
	auto[c, f, s] = f4;
	map<string, double> mp;
	for (const auto&[n, b] : mp)
		cout << n << ":" << b << endl;
	//////////////////////////////////////////////////
	if (const auto bs = testBool(); bs)
		cout << "bs Is true" << endl;
	mutex mx;
	if (lock_guard<mutex> lg(mx); !mp.empty())
		cout << "mp map is not empty" << endl;
	switch (auto ii = testInt())
	{
	case 1: cout << "switch is 1"; break;
	case 2: cout << "switch is 2"; break;
	default: cout << "switch def"; break;
	}
	//////////////////////////////////////////////////
	D<float> S{ {"Hello"} , {4.5,5.6}, "World" };
	cout << "Template Struct: " << S.data << endl;
	cout << "Template Struct: " << static_cast<string>(S) << endl;
	cout << "Template Struct: " << static_cast<complex<double>>(S) << endl;
	cout << "Template Struct: " << is_aggregate<decltype(S)>::value << endl;
	//////////////////////////////////////////////////
	PRINT(0xA);
	PRINT(0x1p4);
	PRINT(5e0);
	PRINT(0x1.4p+2);
	PRINT(1e5);
	PRINT(0x1.86ap+16);
	PRINT(0xC.68p+2);
	///////////////////////////////////////////////////

	if constexpr (numeric_limits<char>::is_signed) {
		food(42);
	}
	else
	{
		//undeclared(42);
	}

	///////////////////////////////////////////////////////
	auto root = new Node{ 0 };
	auto left = new Node{ 0 };
	auto right = new Node{ 0 };
	//auto p = travers(root, left, right);
	/////////////////////////////////////////////////////////
	cout << "hash of salam: " << std::hash<string>()("salam") << endl;
	///////////////////////////////////////////////////////
	int iio = std::uncaught_exceptions();
	cout << "uncaught_exceptions:" << iio << endl;
	///////////////////////////////////////////////////////////
	//TODO
	//is_nothrow_move_constructible<T>::value

	std::array<int, 10> array_data;
	array_view<int> array_data_view1(array_data);
	char dst[100]; ZeroMemory(dst, 100);

	[[suppress(boundes)]]{
		memcpy(dst,array_data_view1.data(),100);
	}
	cout << "destination of [[suppress(boundes)]] is :" << dst << endl;
	///////////////////////////////////////////////////////////
	int isp = 1;
	int& rei = isp;
	int* pi = &rei;
	int ** ppo = &pi; // pointer to pointer pi

	auto sx = make_shared<int>(2);
	auto* ps = &sx; //pointer to owner sx


	auto ssx = make_shared<int>(1);
	int* ol = ssx.get();
	*ol = 42;
	ssx = make_shared<int>(2); //->modify ssx and invalidate ol
	*ol = 43; // p was invalidate
	////////////////////////////////////////////////////////
	//TODO
	// volatile  ???
	////////////////////////////////////////////////////////////
	//auto& ref = *returns_a_shared_ptr();
	//ref.boooom();//ERROR

}

