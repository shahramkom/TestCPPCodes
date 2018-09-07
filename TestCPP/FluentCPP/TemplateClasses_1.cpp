#include <stdafx.h>

template<class T1, class T2, int I>
class A {};            // primary template

template<class T, int I>
class A<T, T*, I> {};  // #1: partial specialization where T2 is a pointer to T1

template<class T, class T2, int I>
class A<T*, T2, I> {}; // #2: partial specialization where T1 is a pointer

template<class T>
class A<int, T*, 5> {}; // #3: partial specialization where T1 is int, I is 5,
						//     and T2 is a pointer

template<class X, class T, int I>
class A<X, T*, I> {};   // #4: partial specialization where T2 is a pointer
//////////////////////////////////////////////////////////////////////////

template<class T1, class T2, int I> 
class B {}; // primary template

//template<class X, class Y, int N> 
//class B<X, Y, N> {}; // error


template<int N, typename T1, typename... Ts>
struct BX;
//template<typename... Ts>
//struct BX<0, Ts...> { }; // Error: not more specialized

//////////////////////////////////////////////////////////////////////////

template <int I, int J> 
struct AA {};
//template <int I> 
//struct AA<I + 5, I * 2> {}; // error, I is not deducible

template <int I, int J, int K>
struct BB {};
template <int I>
struct BB<I, I * 2, 2> {};  // OK: first parameter is deducible
//////////////////////////////////////////////////////////////////////////

template <class T, T t>
struct C {}; // primary template
//template <class T>
//struct C<T, 1>; // error: type of the argument 1 is T,
			   // which depends on the parameter T

template< int X, int(*array_ptr)[X] >
class BBB {}; // primary template
//int array[5];
//template< int X >
//class B<X, &array> { }; // error: type of the argument &array
					   // is int(*)[X], which depends on the parameter X

//////////////////////////////////////////////////////////////////////////
namespace N {
	template<class T1, class T2>
	class Z { }; // primary template
}
using N::Z; // refers to the primary template
namespace N {
	template<class T>
	class Z<T, T*> { }; // partial specialization
}
Z<int, int*> z; // name lookup finds N::Z (the primary template),
				// the partial specialization with T = int is then used

//////////////////////////////////////////////////////////////////////////
// given the template A as defined above
A<int, int, 1> a1;   // no specializations match, uses primary template
A<int, int*, 1> a2;  // uses partial specialization #1 (T=int, I=1)
A<int, char*, 5> a3; // uses partial specialization #3, (T=char)
A<int, char*, 1> a4; // uses partial specialization #4, (X=int, T=char, I=1)
//A<int*, int*, 2> a5; // error: matches #2 (T=int, T2=int*, I=2)
					   //        matches #4 (X=int*, T=int, I=2)
					   // neither one is more specialized than the other
//////////////////////////////////////////////////////////////////////////
template<int I, int J, class T>
struct X { }; // primary template
template<int I, int J>          
struct X<I, J, int> {
	static const int s = 1;
}; // partial specialization #1
   // fictitious function template for #1 is
   // template<int I, int J> void f(X<I, J, int>); #A

template<int I>                 
struct X<I, I, int> {
	static const int s = 2;
}; // partial specialization #2
   // fictitious function template for #2 is 
   // template<int I>        void f(X<I, I, int>); #B

int main1()
{
	X<2, 2, int> x; // both #1 and #2 match
					// partial ordering for function templates:
					// #A from #B: void(X<I,J,int>) from void(X<U1, U1, int>): deduction ok
					// #B from #A: void(X<I,I,int>) from void(X<U1, U2, int>): deduction fails
					// #B is more specialized
					// #2 is the specialization that is instantiated
	std::cout << x.s << '\n'; // prints 2
	return 0;
}
//////////////////////////////////////////////////////////////////////////
template<class T, int I>  // primary template
struct AAA {
	void f(); // member declaration
};

template<class T, int I>
void AAA<T, I>::f() { } // primary template member definition

					  // partial specialization
template<class T>
struct AAA<T, 2>
{
	void f();
	void g();
	void h();
};

// member of partial specialization
template<class T>
void AAA<T, 2>::g() { }

// explicit (full) specialization
// of a member of partial specialization
template<>
void AAA<char, 2>::h() {}

int main() {
	AAA<char, 0> a0;
	AAA<char, 2> a2;
	a0.f(); // OK, uses primary template’s member definition
	a2.g(); // OK, uses partial specialization's member definition
	a2.h(); // OK, uses fully-specialized definition of
			// the member of a partial specialization
	a2.f(); // error: no definition of f() in the partial
			// specialization A<T,2> (the primary template is not used)
}
//////////////////////////////////////////////////////////////////////////
template<class T>
struct AB { // enclosing class template
	template<class T2>
	struct BC {}; // primary member template
	template<class T2>
	struct BC<T2*> {}; // partial specialization of member template
};

template<>
template<class T2>
struct AB<short>::BC {}; // full specialization of primary member template
					   // (will ignore the partial)

AB<char>::BC<int*> abcip; // uses partial specialization T2=int
AB<short>::BC<int*> absip; // uses full specialization of the primary (ignores partial)
AB<char>::BC<int> abci; // uses primary

