#include <stdafx.h>

std::optional<unsigned> firstEvenNumberIn(std::string text)
{
	auto oComplex = make_optional<unsigned>(123);

	// in_place
	optional<std::complex<unsigned>> o7{ std::in_place, 3 };

	// will call vector with direct init of {1, 2, 3}
	return oComplex;
}

using ItsOk = variant<vector<int>, double>;


using MyVariant = variant<int, string, /*and more...*/>;
std::ostream& operator<< (std::ostream& os, MyVariant const& v) {
	switch (v.index()) {
	case 0:
		os << std::get<0>(v);
		break;
	case 1:
		os << std::get<1>(v);
		break;
		// and so on...
	}
	return os;
}


std::ostream& operator<< (std::ostream& os, MyVariant const& v) {
	std::visit([&os](auto const& e) { os << e; }, v);
	return os;
}


struct MyVisitor {
	std::ostream& os_;

	MyVisitor(std::ostream& os) : os_{ os } {}
	void operator()(int const& a) {
		os_ << "It's an A!";
	}
	void operator()(B const& b) {
		os_ << "It's a B!";
	}
};

std::ostream& operator<< (std::ostream& os, MyVariant const& v) {
	std::visit(MyVisitor{ os }, v);
	return os;
}

int main()
{
	ItsOk io = vector{ 22, 44, 66 }; //set the variant to vector, this constructs the internal vector
	io = 13.7; // reset to double - the internal vector is properly destroyed
	int i = get<vector<int>>(io)[2]; // There's no vector in the variant - throws an exception


	using MyVariant = variant<vector<int>, vector<double>>;

	//construct the vector<int> in place with an initializer list
	MyVariant v{ std::in_place_index_t<0>{},{ 1, 2, 5, 13 } };
	auto numbers = std::get<0>(v);

	//replace with a vector<double> with the same values
	v.emplace<1>(std::begin(numbers), std::end(numbers));


	string text = "ali pass 123";
	optional<unsigned> opt = firstEvenNumberIn(text);
	if (opt.has_value())
	{
		cout << "The first even number is "
			<< opt.value()
			<< ".\n";
	}

	auto optVec = make_optional<vector<int>>(3, 22); //{22, 22, 22}
	set<int> ints{ 4, 7, 1, 41 };
	optVec.emplace(begin(ints), end(ints));
	copy(optVec->begin(), optVec->end(), ostream_iterator<int>(cout, ", "));

	getchar();
	return 0;
}

//////////////////////////////////////////////////////////////////////////
// optional can be used as the return type of a factory that may fail
optional<string> create(bool b) {
	if (b)
		return "Godzilla";
	return {};
}

// std::nullopt can be used to create any (empty) std::optional
auto create2(bool b) {
	return b ? optional<string>{"Godzilla"} : nullopt;
}

// std::reference_wrapper may be used to return a reference
auto create_ref(bool b) {
	static string value = "Godzilla";
	return b ? optional<reference_wrapper<string>>{value} : nullopt;
}


void addFieldToQuery(ostringstream& oss, const string& field, const optional<string>& value, bool& first)
{
	if (value)
	{
		oss << (first ? "where " : "and ") << field << " = '" << *value << "' ";
		first = false;
	}
}

template<typename T>
optional<T> checkValue(const optional<T>& opt)
{
	return opt.has_value() ? opt : nullopt;
}

string buildQuery(const optional<string>& gender,
	const optional<string>& nationality,
	const optional<string>& eyeColor)
{
	ostringstream oss;
	oss << "SELECT * FROM persons ";

	bool first = true;
	addFieldToQuery(oss, "gender", checkValue(gender), first);
	addFieldToQuery(oss, "nationality", checkValue(nationality), first);
	addFieldToQuery(oss, "eyeColor", checkValue(eyeColor), first);
	//Attention  return newF().get_value_or(-1);
	//gender.value_or()
	return oss.str();
}
int main()
{
	cout << max_int64::value << endl;
	string gender = "male";
	string nationality = "";
	string eyeColor = "blue";
	buildQuery(gender, nullopt, eyeColor);
	return 0;
}