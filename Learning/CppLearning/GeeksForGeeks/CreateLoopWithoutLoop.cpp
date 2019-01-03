#include <stdafx.h>
 template<int N>
 class PrintOneToN
 {
 public:
 	static void print()
 	{
 		PrintOneToN<N - 1>::print();  // Note that this is not recursion
 		cout << N << endl;
 	}
 };
 
 template<>
 class PrintOneToN<1>
 {
 public:
 	static void print()
 	{
 		cout << 1 << endl;
 	}
 };
 int main()
 {
 	const int N = 100;
 	PrintOneToN<N>::print();
 	getchar();
 }

//class A
//{
//public:
//	static int a;
//	A()
//	{
//		cout << a++ << endl;
//	}
//};
//
//int A::a = 1;
//
//int main()
//{
//	constexpr int N = 100;
//	A obj[N];
//	return 0;
//}