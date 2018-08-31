#include <stdafx.h>

template <typename T, typename Parameter>
class NamedType
{
public:
	explicit NamedType(T const& value) : value_(value) {}
	explicit NamedType(T&& value) : value_(std::move(value)) {}
	T& get() { return value_; }
	T const& get() const { return value_; }
private:
	T value_;
};

struct MeterParameter {};
struct WidthParameter {};
struct HeightParameter {};

using Meter = NamedType<double, struct MeterParameter>;

using Width = NamedType<Meter, struct HeightParameter>;
using Height = NamedType<Meter, struct HeightParameter>;

Meter operator"" _meter(unsigned long long length)
{
	return Meter(length);
};

class Mostatil
{
public:
 	Mostatil(Width w, Height h)
 		: width_(w.get())
 		, height_(h.get())
 	{
 	}
private:
 	Meter width_;
 	Meter height_;
};

//////////////////////////////////////////////////////////////////////////
///BY REFRENCE
template<typename T, typename Parameter>
class NamedTypeRef
{
public:
	explicit NamedTypeRef(T& t) : t_(std::ref(t)) {}
	T& get() { return t_.get(); }
	T const& get() const { return t_.get(); }
private:
	reference_wrapper<T> t_;
};

using NameRef = NamedTypeRef<string, struct NameRefParameter>;

void printName(const NameRef name)
{
	cout << &name << endl;
}

//////////////////////////////////////////////////////////////////////////

int main()
{
	Mostatil rs (Width(10_meter), Height(12_meter));
	string userInput = "jonathan";
	printName(NameRef(userInput));
}