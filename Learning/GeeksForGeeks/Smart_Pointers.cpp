#include <stdafx.h>
// A generic smart pointer class
template <class T>
class SmartPtr
{
	T *ptr;  // Actual pointer
public:
	// Constructor
	explicit SmartPtr(T *p = NULL)
		:ptr(p)
	{}

	// Destructor
	~SmartPtr() { delete(ptr); }

	// Overloading dereferncing operator
	T & operator * () { return *ptr; }

	// Overloding arrow operator so that members of T can be accessed
	// like a pointer (useful if T represents a class or struct or 
	// union type)
	T * operator -> () { return ptr; }
};

class tmpSmart
{
public:
	tmpSmart(int _a,double _b)
		: a(_a)
		, b(_b)
	{}

	int a;
	double b;
};
int main()
{
	SmartPtr<int> ptr(new int());
	*ptr = 20;
	cout << *ptr <<endl;

	SmartPtr<double> ptrF(new double(456.65));
	cout << *ptrF << endl;

	SmartPtr<tmpSmart> ptrSm(new tmpSmart(162,345.326));
	cout << ptrSm->a << " "<<ptrSm->b << endl;
	getchar();
}