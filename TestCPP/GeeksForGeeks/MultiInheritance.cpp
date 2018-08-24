#include <stdafx.h>
class Person {
public:
	Person(int x) { cout << "Person::Person(int ) called" << endl; }
	Person() { cout << "Person::Person() called" << endl; }
};

class Faculty : virtual public Person {
public:
	Faculty(int x) :Person(x) {
		cout << "Faculty::Faculty(int ) called" << endl;
	}
};

class Student : virtual public Person {
public:
	Student(int x) :Person(x) {
		cout << "Student::Student(int ) called" << endl;
	}
};

class TA : public Faculty, public Student {
public:
	TA(int x) :Student(x), Faculty(x), Person(x) {
		cout << "TA::TA(int ) called" << endl;
	}
};

int main() {
	TA ta1(30);
	getchar();
}


// class A
// {
// 	int x;
// public:
// 	A(int i) { x = i; }
// 	void print() { cout << x; }
// };
// 
// class B : virtual public A
// {
// public:
// 	B() :A(10) {  }
// };
// 
// class C : virtual public A
// {
// public:
// 	C() :A(10) {  }
// };
// 
// class D : public B, public C {
// };
// 
// int main()
// {
// 	D d;
// 	d.print(); //Error on compile
// 	return 0;
// }