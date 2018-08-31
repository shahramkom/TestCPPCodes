#include <stdafx.h>

//Implemant class that support begin , end , ...
class Flow
{
public:
	Flow() {};
};

class FlowCollection
{
public:
	// ...domain interface...

	// iterators to allow data access
	using const_iterator = vector<Flow>::const_iterator;
	const_iterator begin() const;
	const_iterator end() const;

	// iterators to allow data modification
	using iterator = vector<Flow>::iterator;
	iterator begin();
	iterator end();

	// other iterators...

private:
	vector<Flow> m_flows;
	// ...domain data...
};


// IMPLEMENTATION

FlowCollection::iterator FlowCollection::begin()
{
	return m_flows.begin();
}


///////////////////////////////////////////////////////////////////////////
//\\\\\\\\\\\\\\\\\\\C O P Y\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
/////////////////////////////////////////////////////////////////////////
class Material
{
public:
	double getMaxPressure() const;
};

class Product
{
public:
	double getDensity() const;
};

class Box
{
public:
	Box(double length, double width, double height, Material material);
	double getVolume() const;
	double getSidesSurface() const;
	Material getMaterial() const;
private:
	double length_;
	double width_;
	double height_;
	Material material_;
};

class Resists
{
public:
	explicit Resists(const Product& product) : product_(product) {}
	bool operator()(const Box& box)
	{
		const double volume = box.getVolume();
		const double weight = volume * product_.getDensity();
		const double sidesSurface = box.getSidesSurface();
		const double pressure = weight / sidesSurface;
		const double maxPressure = box.getMaterial().getMaxPressure();
		return pressure <= maxPressure;
	}
private:
	Product product_;
};

std::vector<Box> boxes;
std::vector<Box> goodBoxes;

std::copy_if(boxes.begin(), boxes.end(), std::back_inserter(goodBoxes), Resists(product));

auto resists(const Product& product)
{
	return [product](const Box& box)
	{
		const double volume = box.getVolume();
		const double weight = volume * product.getDensity();
		const double sidesSurface = box.getSidesSurface();
		const double pressure = weight / sidesSurface;
		const double maxPressure = box.getMaterial().getMaxPressure();
		return pressure <= maxPressure;
	};
}
std::vector<Box> goodBoxes;
std::copy_if(boxes.begin(), boxes.end(), std::back_inserter(goodBoxes), resists(product));

auto goodBoxes = boxes | ranges::view::filter(resists(product));

///////////////////////////////////////////////////////////////////////////
/////////////////////F O R  E A C H///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

class Bump
{
public:
	explicit Bump(double bumpValue) : bumpValue_(bumpValue) {}
	void operator()(double& number) const
	{
		number += bumpValue_;
	}
private:
	double bumpValue_;
};

std::vector<double> numbers = { 1, 2, 3, 4, 5 };

std::for_each(numbers.begin(), numbers.end(), Bump(2));


double bumpValue = 2;
std::for_each(numbers.begin(), numbers.end(), [bumpValue](double& number) {number += bumpValue; });

///////////////////////////////////////////////////////////////////////////
////////////////////C O U N////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

class Count7
{
public:
	Count7() : counter_(0) {}
	void operator()(int number)
	{
		if (number == 7) ++counter_;
	}
	int getCounter() const { return counter_; }
private:
	int counter_;
};

std::vector<int> numbers = { 1, 7, 4, 7, 7, 2, 3, 4 };
int count = std::for_each(numbers.begin(), numbers.end(), Count7()).getCounter();
//OR
Count7 count7;
std::for_each(numbers.begin(), numbers.end(), count7);
int count = count7.getCounter();
//OR
int count = 0;
std::for_each(numbers.begin(), numbers.end(),[&count](int number) { if (number == 7) ++count; });
//OR
int count = std::count(numbers.begin(), numbers.end(), 7);

///////////////////////////////////////////////////////////////////////////
//////////////////F I N D  I F     F O R  E A C H/////////////////////////
//////////////////////////////////////////////////////////////////////////

std::vector<int> numbers = { 8, 4, 3, 2, 10, 4, 2, 7, 3 };

bool goOn = true;
for (size_t n = 0; n < numbers.size() && goOn; ++n)
{
	if (numbers[n] < 10)
	{
		std::cout << numbers[n] << '\n';
	}
	else
	{
		goOn = false;
	}
}
//The Above code Equal to Below code
auto first10 = std::find_if(numbers.begin(), numbers.end(), [](int number) {return number >= 10; });
std::for_each(numbers.begin(), first10, [](int number) {std::cout << number << std::endl; });

///////////////////////////////////////////////////////////////////////////
///////////////C O M P A R E///////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

class Employee
{
public:
	int getId() const;

private:
	int id_;
};
std::vector<Employee> employees;

std::find(employees.begin(), employees.end(), 42); // doesn't compile
std::find_if(employees.begin(), employees.end(), [](Employee const& e) {return e.getId() == 42; }); // OK

auto employeesWith42 = employees.equal_range(42); // doesn't compile

bool compareWithIdLeft(Employee const& employee, int id)
{
	return employee.getId() < id;
}
auto lowerPosition = std::lower_bound(employees.begin(), employees.end(), 42, compareWithIdLeft);

bool compareWithIdRight(int id, Employee const& employee)
{
	return id < employee.getId();
}
auto upperPosition = std::upper_bound(lowerPosition, employees.end(), 42, compareWithIdRight);
/////////
struct CompareWithId
{
	bool operator()(Employee const& employee, int id)
	{
		return employee.getId() < id;
	}
	bool operator()(int id, Employee const& employee)
	{
		return id < employee.getId();
	}
};
std::find_if(employees.begin(), employees.end(), 42, CompareWithId);
//////////////////////////////////////////////////////////////////////////
/////////////S P L I T  S T R I N G///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
std::string text = "Let me split this into words";

std::istringstream iss(text);
std::vector<std::string> results((std::istream_iterator<std::string>(iss)),
	std::istream_iterator<std::string>());

std::vector<std::string> split(const std::string& s, char delimiter)
{
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(s);
	while (std::getline(tokenStream, token, delimiter))
	{
		tokens.push_back(token);
	}
	return tokens;
}