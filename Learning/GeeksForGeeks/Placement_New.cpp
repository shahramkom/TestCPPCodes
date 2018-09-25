#include <stdafx.h>

class Complex
{
private:
	double re_, im_;
public:
	// Constructor
	Complex(double re = 0, double im = 0) : re_(re), im_(im)
	{
		cout << "Constructor : (" << re_<< ", " << im_ << ")" << endl;
	}

	// Destructor
	~Complex()
	{
		cout << "Destructor : (" << re_ << ", "<< im_ << ")" << endl;
	}

	double normal()
	{
		return sqrt(re_*re_ + im_ * im_);
	}

	void print()
	{
		cout << "|" << re_ << " +j" << im_<< " | = " << normal() << endl;
	}
};

class TestPlacement
{
public:
	int var1;
	int var2;
	vector<string> vectStr;
	TestPlacement(int v1,int v2)
		: var1(v1)
		, var2(v2)
	{
	}
	void printVars()
	{
		cout<<endl << this << ":Var1:" << var1 << "Var2:" << var2;
	}
protected:
private:
};

int main()
{
	// buffer on stack
	unsigned char buf[sizeof(int) * 2];

	// placement new in buf
	auto *pInt = new (buf) int(3);

	auto *qInt = new (buf + sizeof(int)) int(5);
	auto *pBuf = (int*)(buf + 0);
	auto *qBuf = (int*)(buf + sizeof(int));
	cout << "Buff Addr             Int Addr" << endl;
	cout << pBuf << "             " << pInt << endl;
	cout << qBuf << "             " << qInt << endl;
	cout << "------------------------------" << endl;
	cout << "1st Int             2nd Int" << endl;
	cout << *pBuf << "                         "
		<< *qBuf << endl;
	//////////////////////////////////////////////////////////////////////////
	BYTE  testClassBuffer[sizeof(TestPlacement)];
	auto testObject = new (testClassBuffer) TestPlacement(100,200);
	testObject->printVars();
	//////////////////////////////////////////////////////////////////////////
	int X = 10;
	cout << endl<<endl<<"Before placement new :" << endl;
	cout << "X : " << X << endl;
	cout << "&X : " << &X << endl;

	// Placement new changes the value of X to 100
	int *mem = new (&X) int(100);

	cout << "\nAfter placement new :" << endl;
	cout << "X : " << X << endl;
	cout << "mem : " << mem << endl;
	cout << "&X : " << &X << endl << endl;
	//////////////////////////////////////////////////////////////////////////
	// buffer on stack
	unsigned char bufq[100];

	Complex* pc = new Complex(4.2, 5.3);
	Complex* pd = new Complex[2];

	// using placement new
	Complex *pe = new (bufq) Complex(2.6, 3.9);

	// use objects
	pc->print();
	pd[0].print();
	pd[1].print();
	pe->print();

	// Release objects
	// calls destructor and then release memory
	delete pc;

	// Calls the destructor for object pd[0]
	// and then release memory
	// and it does same for pd[1]
	delete[] pd;

	// No delete : Explicit call to Destructor.
	pe->~Complex();
	cout << endl << endl;
	// Fine
	int i = 10;
	int *ipt = &i;
	int *i1 = new(ipt) int(9);

	// Incorrect as ip may not
	// be a valid address
	int *ip;
	int *i2 = new(ip) int(4);

	// Fine
	void *vd = &i;
	int *i3 = new(vd) int(34);

	// Incorrect as x is not an address
	int x;
	int *i5 = new(x) int(3);
	getchar();
}