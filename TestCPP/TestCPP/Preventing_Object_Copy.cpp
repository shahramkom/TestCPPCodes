#include <stdafx.h>

class Base {
	int x;
public:
	Base() {  }
	Base(int y) : x(y) {  }
private:

	// Copy constructor
	Base(const Base& obj) : x(obj.x) {   }

	// copy assignment operator
	Base& operator=(const Base& tmp_obj)
	{
		x = tmp_obj.x;
		return *this;
	}
};

int main()
{
	Base b1(10);
	Base b2(b1); // calls copy constructor
	b2 = b1; // calls copy assignment operator
	return 0;
}


class Dummy {
public:
	Dummy() {  }
private:
	Dummy(const Dummy& temp_obj) {   }
	Dummy& operator=(const Dummy& temp_obj) {   }
};

class Base : public Dummy {
	int x;
public:
	Base() {   }
	Base(int y) : x(y) {  }
};

int main()
{
	Base b1(10);
	Base b2(b1); // Calls copy constructor
	b2 = b1; // Calls copy assignment operator
	return 0;
}


class Base {
	int x;
public:
	Base() {     }
	Base(int y) : x(y) {    }
	Base(const Base& temp_obj) = delete;
	Base& operator=(const Base& temp_obj) = delete;
};

int main()
{
	Base b1(10);
	Base b2(b1); // Calls copy constructor
	b2 = b1; // Calls copy assignment operator
	return 0;
}