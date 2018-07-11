#include <stdafx.h>

class base {
public:
	base()
	{
		cout << "Constructing base \n";
	}
	~base()
	{
		cout << "Destructing base \n";
	}
};

class derived : public base {
public:
	derived()
	{
		cout << "Constructing derived \n";
	}
	~derived()
	{
		cout << "Destructing derived \n";
	}
};

int main(void)
{
	derived *d = new derived();
	base *b = d;
	delete b;
	getchar();
	return 0;
}

//OUTPUT:
	// Constructing base
	// Constructing derived
	// Destructing base
//////////////////////////////////////////////////////////////////////////

class base {
public:
	base()
	{
		cout << "Constructing base \n";
	}
	virtual ~base()
	{
		cout << "Destructing base \n";
	}
};

class derived : public base {
public:
	derived()
	{
		cout << "Constructing derived \n";
	}
	~derived()
	{
		cout << "Destructing derived \n";
	}
};

int main(void)
{
	derived *d = new derived();
	base *b = d;
	delete b;
	getchar();
	return 0;
}
//OUTPUT:
// 	Constructing base
//	Constructing derived
//	Destructing derived
//	Destructing base