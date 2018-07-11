#include <stdafx.h>
class Base {
public:
	virtual int fun(int i) {
		cout << "Base::fun(int i) called"; return 0;
	}
};

class Derived : public Base {
private:
	int fun(int x) { cout << "Derived::fun(int x) called"; return 0; }
};

int main()
{
	Derived d;
	//d.fun(1);//Error compile
	Base *ptr = new Derived;
	ptr->fun(10);
	getchar();
}