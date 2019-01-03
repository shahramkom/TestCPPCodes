// Win32Project1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


template <class T>
class mypair {
	T a, b;
public:
	mypair(T first, T second)
	{
		a = first; b = second;
	}
	T getmax();
};

template <class T>
T mypair<T>::getmax()
{
	T retval;
	retval = a > b ? a : b;
	return retval;
}

int main()
{
	mypair <int> myobject(100, 75);
	cout << myobject.getmax();

	return 0;
}


// class template:
template <class T>
class mycontainer {
public:
	mycontainer(T arg) { element_ = arg; }
	T increase() { return ++element_; }
private:
	T element_;
};

// class template specialization:
template <>
class mycontainer <char> {
	char element;
public:
	mycontainer(char arg) { element = arg; }
	char uppercase()
	{
		if ((element >= 'a') && (element <= 'z'))
			element += 'A' - 'a';
		return element;
	}
};

int main() {
	mycontainer<int> myint(7);
	mycontainer<char> mychar('j');
	cout << myint.increase() << endl;
	cout << mychar.uppercase() << endl;
	return 0;
}


template <class T, int N>
class mysequence {
	T memblock[N];
public:
	void setmember(int x, T value);
	T getmember(int x);
};

template <class T, int N>
void mysequence<T, N>::setmember(int x, T value) {
	memblock[x] = value;
}

template <class T, int N>
T mysequence<T, N>::getmember(int x) {
	return memblock[x];
}

int main() {
	mysequence <int, 5> myints;
	mysequence <double, 5> myfloats;
	myints.setmember(0, 100);
	myfloats.setmember(3, 3.1416);
	cout << myints.getmember(0) << '\n';
	cout << myfloats.getmember(3) << '\n';
	return 0;
}


#include <iostream>
using namespace std;

template <typename T>
class Array {
private:
	T *ptr;
	int size;
public:
	Array(T arr[], int s);
	void print();
	T sum();
};

template <typename T>
Array<T>::Array(T arr[], int s) {
	ptr = new T[s];
	size = s;
	for (int i = 0; i < size; i++)
		ptr[i] = arr[i];
}

template <typename T>
void Array<T>::print() {
	for (int i = 0; i < size; i++)
		cout << " " << *(ptr + i);
	cout << endl;
}

template <typename T>
T Array<T>::sum()
{
	T retVal;
	for (int i = 0; i < size; i++)
		retVal += *(ptr + i);
	return retVal;
}

int main() {
	double arr[5] = { 1.0, 2.2, 3.5, 4.6, 5.8 };
	Array<double> a(arr, 5);
	a.print();
	cout << a.sum() << endl;
	return 0;
}



template <typename T>
inline T const& Max(T const& a, T const& b) {
	return a < b ? b : a;
}

template <typename T>
inline T Sum(T const& a, T const& b) {
	T sum = a + b;
	return sum;
}


int main() {
	int i = 39;
	int j = 20;
	cout << "Max(i, j): " << Max(i, j) << endl;
	cout << "Sum(i, j): " << Sum(i, j) << endl;

	double f1 = 13.5;
	double f2 = 20.7;
	cout << "Max(f1, f2): " << Max(f1, f2) << endl;
	cout << "Sum(f1, f2): " << Sum(f1, f2) << endl;

	string s1 = "Hello";
	string s2 = "World";
	cout << "Max(s1, s2): " << Max(s1, s2) << endl;
	cout << "Sum(s1, s2): " << Sum(s1, s2) << endl;

	return 0;
}
//___________________________________________________________________
//___________________________________________________________________

template <template<class, class> class V, class T, class A>
void f(V<T, A> &v) {
	// This can be "typename V<T, A>::value_type",
	// but we are pretending we don't have it

	T temp = v.back();
	v.pop_back();
	// Do some work on temp

	std::cout << temp << std::endl;
}
//#################################################################

template<typename T> class my_array {};

// two type template parameters and one template template parameter:
template<typename K, typename V, template<typename> typename C = my_array>
class Map
{
	C<K> key;
	C<V> value;
};

template<typename T> concept C1 = true;
template<template<typename> class X> concept C2 = true;
template<int N> concept C3 = true;
template<typename... Ts> concept C4 = true;
template<char... Cs> concept C5 = true;

template<C1 T> void f1();     // OK: T is a type template-parameter
template<C2 X> void f2();     // OK: X is a template with one type-parameter
template<C3 N> void f3();     // OK: N has type int
template<C4... Ts> void f4(); // OK: Ts is a template parameter pack of types
template<C4 T> void f5();     // OK: T is a type template-parameter
template<C5... Cs> void f6(); // OK: Cs is a template parameter pack of chars

template<C1 T = int> struct S1; // OK
template<typename T> struct S0;
template<C2 X = S0> struct S3;  // OK
template<C3 N = 0> struct S2;   // OK
template<C1 T = 0> struct S4;   // error: default argument is not a type

template<class T> void f(); // #1
template<int I> void f(); // #2
void g() {
	f<int()>(); // "int()" is both a type and an expression,
				// calls #1 because it is interpreted as a type
}

template<const int* pci> struct X {};
int ai[10];
X<ai> xi;  // ok: array to pointer conversion and cv-qualification conversion

struct Y {};
template<const Y& b> struct Z {};
Y y;
Z<y> z;  // ok: no conversion

template<int(&pa)[5]> struct W {};
int b[5];
W<b> w; // ok: no conversion

void f(char);
void f(int);
template<void(*pf)(int)> struct A {};
A<&f> a; // ok: overload resolution selects f(int)


template<class T, const char* p> class X {};
X<int, "Studebaker"> x1; // error: string literal as template-argument

template<int* p> class X {};
int a[10];
struct S
{
	int m;
	static int s;
} s;
X<&a[2]> x3;  // error: address of array element
X<&s.m> x4;   // error: address of non-static member
X<&s.s> x5;   // ok: address of static member
X<&S::s> x6;  // ok: address of static member

template<const int& CRI> struct B {};
B<1> b2;     // error: temporary would be required for template argument
int c = 1;
B<c> b1;     // ok


template<typename T> class X {}; // class template

struct A; // incomplete type
typedef struct {} B; // type alias to an unnamed type

int main()
{
	X<A> x1; // ok: 'A' names a type
	X<A*> x2; // ok: 'A*' names a type
	X<B> x3; // ok: 'B' names a type
}


template<typename T> class A { int x; }; // primary template
template<class T> class A<T*> { long x; }; // partial specialization

// class template with a template template parameter V
template<template<typename> class V> class C
{
	V<int> y; // uses the primary template
	V<int*> z; // uses the partial specialization
};

C<A> c; // c.y.x has type int, c.z.x has type long


template<typename T> struct eval; // primary template 

template<template<typename, typename...> class TT, typename T1, typename... Rest>
struct eval<TT<T1, Rest...>> {}; // partial specialization of eval

template<typename T1> struct A;
template<typename T1, typename T2> struct B;
template<int N> struct C;
template<typename T1, int N> struct D;
template<typename T1, typename T2, int N = 17> struct E;

eval<A<int>> eA; // ok: matches partial specialization of eval
eval<B<int, float>> eB; // ok: matches partial specialization of eval
eval<C<17>> eC; // error: C does not match TT in partial specialization because
				// TT's first parameter is a type template parameter,
				// while 17 does not name a type
eval<D<int, 17>> eD; // error: D does not match TT in partial specialization
					 // because TT's second parameter is a type parameter pack,
					 // while 17 does not name a type
eval<E<int, float>> eE; // error: E does not match TT in partial specialization
						// because E's third (default) parameter is a non-type

template<typename T = int> class X;
template<typename T = int> class X {}; // error

// class template, with a type template parameter with a default
template<typename T = float> struct B {};

// template template parameter T has a parameter list, which 
// consists of one type template parameter with a default
template<template<typename = float> typename T> struct A
{
	void f();
	void g();
};

// out-of-body member function template definitions
template<template<typename TT> class T>
void A<T>::f()
{
	T<> t; // error: TT has no default in scope
}
template<template<typename TT = char> class T>
void A<T>::g()
{
	T<> t; // ok: t is T<char>
}

class B {};

template<typename T> class C
{
protected:
	typedef T TT;
};

template<typename U, typename V = typename U::TT> class D : public U {};

D<C<B>>* d; // error: C::TT is protected

template<typename T, typename U = int> struct S { };
S<bool>* p; // The default argument for U is instantiated at this point
			// the type of p is S<bool, int>*

//@@@@@@@@@@@@@@
Non - Type template parameter

#include <iostream>

// simple non-type template parameter
template<int N>
struct S { int a[N]; };

template<const char*>
struct S2 {};

// complicated non-type example
template
<
	char c, // integral type
	int(&ra)[5], // lvalue reference to object (of array type)
	int(*pf)(int), // pointer to function
	int(S<10>::*a)[10] // pointer to member object (of type int[10])
> struct Complicated
{
	// calls the function selected at compile time
	// and stores the result in the array selected at compile time
	void foo(char base)
	{
		ra[4] = pf(c - base);
	}
};

S2<"fail"> s2; // error: string literal cannot be used
char okay[] = "okay"; // static object with linkage
S2< &okay[0] > s2; // error: array element has no linkage
S2<okay> s2; // works

int a[5];
int f(int n) { return n; }

int main()
{
	S<10> s; // s.a is an array of 10 int
	s.a[9] = 4;

	Complicated<'2', a, f, &S<10>::a> c;
	c.foo('0');

	std::cout << s.a[9] << a[4] << '\n';
}

// variable template
template<class T>
constexpr T pi = T(3.1415926535897932385L);  // variable template

template<class T>
T circular_area(T r) // function template
{
	return pi<T> * r * r; // pi<T> is a variable template instantiation
}

using namespace std::literals;
struct matrix_constants
{
	template<class T>
	using pauli = hermitian_matrix<T, 2>; // alias template

	template<class T> // static data member template
	static constexpr pauli<T> sigmaX = { { 0, 1 }, { 1, 0 } };

	template<class T>
	static constexpr pauli<T> sigmaY = { { 0, -1i }, { 1i, 0 } };

	template<class T>
	static constexpr pauli<T> sigmaZ = { { 1, 0 }, { 0, -1 } };
};


template<typename... Args>
bool all(Args... args) { return (... && args); }

bool b = all(true, true, true, false);
// within all(), the unary left fold expands as
//  return ((true && true) && true) && false;
// b is false


//___________________________________________________________________
//C++ 17

#include <iostream>
#include <vector>
#include <climits>
#include <cstdint>
#include <type_traits>
#include <utility>

template<typename ...Args>
void printer(Args&&... args) {
	(std::cout << ... << args) << '\n';
}

template<typename T, typename... Args>
void push_back_vec(std::vector<T>& v, Args&&... args)
{
	(v.push_back(args), ...);
}

// compile-time endianness swap based on http://stackoverflow.com/a/36937049 
template<class T, std::size_t... N>
constexpr T bswap_impl(T i, std::index_sequence<N...>) {
	return (((i >> N * CHAR_BIT & std::uint8_t(-1)) << (sizeof(T) - 1 - N)*CHAR_BIT) | ...);
}
template<class T, class U = std::make_unsigned_t<T>>
constexpr U bswap(T i) {
	return bswap_impl<U>(i, std::make_index_sequence<sizeof(T)>{});
}

int main()
{
	printer(1, 2, 3, "abc");

	std::vector<int> v;
	push_back_vec(v, 6, 2, 45, 12);
	push_back_vec(v, 1, 2, 9);
	for (int i : v) std::cout << i << ' ';

	static_assert(bswap<std::uint16_t>(0x1234u) == 0x3412u);
	static_assert(bswap<std::uint64_t>(0x0123456789abcdefULL) == 0xefcdab8967452301ULL);
}