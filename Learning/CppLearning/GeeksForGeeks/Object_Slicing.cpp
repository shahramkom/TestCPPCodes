#include <stdafx.h>
class Base
{
protected:
	int i;
public:
	Base(int a) { i = a; }
	virtual void display()
	{
		cout << "I am Base class object, i = " << i << endl;
	}
};

class Derived : public Base
{
	int j;
public:
	Derived(int a, int b) : Base(a) { j = b; }
	virtual void display()
	{
		cout << "I am Derived class object, i = "
			<< i << ", j = " << j << endl;
	}
};

// Global method, Base class object is passed by value
void somefunc(Base &obj)
{
	obj.display();
}
//Output:
//I am Base class object, i = 33
//I am Derived class object, i = 45, j = 54

// void somefunc(Base obj)
// {
// 	obj.display();
// }
//Output:
//I am Base class object, i = 33
//I am Base class object, i = 45

//void somefunc(Base *objp)
//{
//	objp->display();
//}
//Output:
//I am Base class object, i = 33
//I am Derived class object, i = 45, j = 54

int main()
{
 	Base b(33);
 	Derived d(45, 54);
 	somefunc(b);
 	somefunc(d);  // Object Slicing, the member j of d is sliced off
	getchar();
}

