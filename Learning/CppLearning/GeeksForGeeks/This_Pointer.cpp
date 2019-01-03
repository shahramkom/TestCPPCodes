#include <stdafx.h>

 class Test
 {
 private:
 	int x;
 	int y;
 public:
 	Test(int x = 0, int y = 0) { x = x; y = y; }
 	Test &setX(int a) { x = a; return *this; }
 	Test &setY(int b) { y = b; return *this; }
 	void print() { cout << "x = " << x << " y = " << y << endl; }
 };

int main()
{
	Test obj1(5, 5);

	// Chained function calls.  All calls modify the same object
	// as the same object is returned by reference
	obj1.setX(10).setY(20);

	obj1.print();
	getchar();
}

 int main(void)
 {
 	int local = 10;
 	int *ptr = (int*)&local;
 
 	printf("Initial value of local : %d \n", local);
 
 	*ptr = 100;
 
 	printf("Modified value of local: %d \n", local);
 
 	getchar();
 }

 int main(void)
 {
 	const int local = 10;
 	int *ptr = (int*)&local;
 
 	printf("Initial value of local : %d \n", local);
 
 	*ptr = 100;
 
 	printf("Modified value of local: %d \n", local);
 
 	getchar();
 }

 int main(void)
 {
 	const volatile int local = 10;
 	auto *ptr = (int*)&local;
 	printf("Initial value of local : %d \n", local);
 	*ptr = 100;
 	printf("Modified value of local: %d \n", local);
 	getchar();
 }

