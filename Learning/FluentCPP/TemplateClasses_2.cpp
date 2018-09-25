#include <stdafx.h>
template<auto n>
struct B { /* ... */ };
B<5> b1;   // OK: non-type template parameter type is int
B<'a'> b2; // OK: non-type template parameter type is char
//B<2.5> b3; // error: non-type template parameter type cannot be double
//////////////////////////////////////////////////////////////////////////
template<auto...>
struct C {};
C<'C', 0, 2L, nullptr> x; // OK
//////////////////////////////////////////////////////////////////////////
struct A { friend auto operator<=> (const A&, const A&) = default; };
template<A a>
void f() {
	&a; // OK
	const A& ra = a, &rb = a; // Both bound to the same template parameter object
	assert(&ra == &rb); // passes
}
//////////////////////////////////////////////////////////////////////////
template<typename T>
class my_array {};

// two type template parameters and one template template parameter:
template<typename K, typename V, template<typename> typename C = my_array>
class Map
{
	C<K> key;
	C<V> value;
};

//////////////////////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////////////////////
template<typename T> concept C1 = true;
template<typename... Ts> concept C2 = true; // variadic concept
template<typename T, typename U> concept C3 = true;

template<C1 T> struct s1;      // constraint-expression is C1<T>
template<C1... T> struct s2;   // constraint-expression is (C1<T> && ...)
template<C2... T> struct s3;   // constraint-expression is C2<T...>
template<C3<int> T> struct s4; // constraint-expression is C3<T, int>
//////////////////////////////////////////////////////////////////////////
template<class T>
void f(); // #1
template<int I>
void f(); // #2
void g() {
	f<int()>(); // "int()" is both a type and an expression,
				// calls #1 because it is interpreted as a type
}
//////////////////////////////////////////////////////////////////////////
template<const int* pci>
struct X {};
int ai[10];
X<ai> xi;  // ok: array to pointer conversion and cv-qualification conversion

struct Y {};
template<const Y& b>
struct Z {};
Y y;
Z<y> z;  // ok: no conversion

template<int(&pa)[5]> struct W {};
int b[5];
W<b> w; // ok: no conversion

void f(char);
void f(int);
template<void(*pf)(int)> struct A {};
A<&f> a; // ok: overload resolution selects f(int)
//////////////////////////////////////////////////////////////////////////
template<class T, const char* p>
class XP {};
//X<int, "Studebaker"> x1; // error: string literal as template-argument

template<int* p> class X {};
int arr[10];
struct S
{
	int m;
	static int s;
} ss;
XP<&arr[2]> x3;  // error: address of array element
XP<&ss.m> x4;   // error: address of non-static member
XP<&ss.s> x5;   // ok: address of static member
XP<&S::s> x6;  // ok: address of static member

template<const int& CRI> struct B {};
B<1> b2;     // error: temporary would be required for template argument
int c = 1;
B<c> b1;     // ok
//////////////////////////////////////////////////////////////////////////
template<typename T>
class A { int x; }; // primary template
template<class T> class A<T*> { long x; }; // partial specialization

										   // class template with a template template parameter V
template<template<typename> class V> class C
{
	V<int> y; // uses the primary template
	V<int*> z; // uses the partial specialization
};

C<A> c; // c.y.x has type int, c.z.x has type long
//////////////////////////////////////////////////////////////////////////
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
//////////////////////////////////////////////////////////////////////////
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