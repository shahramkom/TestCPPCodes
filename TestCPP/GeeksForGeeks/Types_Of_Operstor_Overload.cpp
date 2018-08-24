#include <stdafx.h>


class overload {
private:
	int count;

public:
	overload()
		: count(4)
	{
	}

	void operator++()
	{
		count = count + 1;
	}
	void Display()
	{
		cout << "Count: " << count;
	}
};

int main()
{
	overload i;
	// this calls "function void operator ++()" function
	++i;
	i.Display();
	return 0;
}
//////////////////////////////////////////////////////////////////////////
class overload {
	int a[3];

public:
	overload(int i, int j, int k)
	{
		a[0] = i;
		a[1] = j;
		a[2] = k;
	}
	int operator[](int i)
	{
		return a[i];
	}
};
int main()
{
	overload ob(1, 2, 3);
	cout << ob[1]; // displays 2
	return (0);
}

//////////////////////////////////////////////////////////////////////////
class GFG {
public:
	int num;
	GFG(int j)
	{
		num = j;
	}
	GFG* operator->(void)
	{
		return this;
	}
};

// Driver code
int main()
{
	GFG T(5);
	GFG* Ptr = &T;

	// Accessing num normally
	cout << "T.num = " << T.num << endl;

	// Accessing num using normal object pointer
	cout << "Ptr->num = " << Ptr->num << endl;

	// Accessing num using -> operator
	cout << "T->num = " << T->num << endl;

	return 0;
}
//////////////////////////////////////////////////////////////////////////
class cantover {
public:
	void fun();
};
class X { // assume that you can overload .
	cantover* p;
	cantover& operator.()
	{
		return *p;
	}
	void fun();
};
void g(X& x)
{
	x.fun(); // X::fun or cantover::fun or error?
}
