#include "../HeaderFiles/NicolasExamples.h"
#include "../HeaderFiles/Includes.h"


using namespace std;

long double operator "" _cm(long double x) { return x * 10; }
long double operator "" _m(long double x) { return x * 1000; }
long double operator "" _mm(long double x) { return x; }

int operator"" _bin(const char* str, size_t l)
{
	int ret = 0;
	for (int i = 0; i < l; i++)
	{
		ret <<= 1;
		if (str[i] == '1')
			ret += 1;
	}
	return  ret;
}

NicolasExamples::NicolasExamples()
{

}

void NicolasExamples::startTests()
{
	int m = 0;
	printDirSize("G:\\__Akkasi");
	testStringView();
	testOptional();
	testVariant();
	testAny();
	//parallelTest();
	cppPrintf();
	testNewIn17();
	long double height = 3.4_cm;
	cout << "My literal height is :" << height << endl;
	cout << "My literal height + is :" << height + 13.0_m << endl;
	cout << "My literal / is :" << 130.0_mm / 13.0_m << endl;
	cout << "My literal _bin is :" << "110"_bin << endl;
	cout << "My literal _bin is :" << "1100110"_bin << endl;
}

string BytesToSize(float Bytes) {
	float tb = 1099511627776;
	float gb = 1073741824;
	float mb = 1048576;
	float kb = 1024;

	char returnSize[256];

	if (Bytes >= tb)
		sprintf_s(returnSize, "%.2f TB", (float)Bytes / tb);
	else if (Bytes >= gb && Bytes < tb)
		sprintf_s(returnSize, "%.2f GB", (float)Bytes / gb);
	else if (Bytes >= mb && Bytes < gb)
		sprintf_s(returnSize, "%.2f MB", (float)Bytes / mb);
	else if (Bytes >= kb && Bytes < mb)
		sprintf_s(returnSize, "%.2f KB", (float)Bytes / kb);
	else if (Bytes < kb)
		sprintf_s(returnSize, "%.2f Bytes", Bytes);
	else
		sprintf_s(returnSize, "%.2f Bytes", Bytes);


	return string(returnSize);
}

void NicolasExamples::printDirSize(const string& dir) const
{
	vector<filesystem::path> paths;
	filesystem::recursive_directory_iterator dirpos(dir);
	copy(begin(dirpos), end(dirpos), back_inserter(paths));
	const auto sz = transform_reduce(execution::par, paths.cbegin(),
		paths.cend(), uintmax_t{ 0 }, plus<>(),
		[](const filesystem::path& p) {
		return filesystem::is_regular_file(p) ?
			filesystem::file_size(p) : uintmax_t{ 0 };
	});
	std::cout << "sum size of directory '" << dir << "':" << BytesToSize(sz) << endl;
}

void NicolasExamples::testStringView() const
{
	auto sw = "some text"sv;
	std::cout << "Show qtd string view: " << quoted(sw) << endl;

}

void NicolasExamples::testOptional()
{
	optional <string> empty;
	optional<string> optstr = "new Value";
	*optstr = "new Value";
	if (optstr) //optstr.has_value()
	{
		string s = *optstr;
	}
	try
	{
		string s = optstr.value();
		cout << "optional value: " << s << endl;
	}
	catch (const std::bad_optional_access& e)
	{
		optstr.reset();
	}
}

struct MyVisitor
{
	void operator() (double d) const
	{
		cout << d << endl;
	}
	void operator() (int i) const
	{
		cout << i << endl;
	}
	void operator() (string s) const
	{
		cout << s << endl;
	}
};

void NicolasExamples::testVariant()
{
	variant<int, string > var(42);
	var = "new value";
	try
	{
		string s = get<string>(var);
		string d = get<1>(var);
		//int f = get<0>(var); //excp
		//int m = get<int>(var);
		cout << "variant get<0>:" << "'excp'" << " get<int>:" << 'excp' <<
			" get<1>:" << d << " get<string>:" << s << endl;
	}
	catch (const bad_variant_access& e)
	{
		cout << "exception in variant access" << e.what() << endl;
	}

	variant<int, int, string> var2;
	var2 = "hello";
	var2.emplace<1>(42);
	try
	{
		//auto s = get<string>(var2); //excp
		//auto a = get<double>(var2); //Compile Error
		//auto b = get<4>(var2); //Compile Error
		//auto c = get<int>(var2); //Compile Error
		auto i = get<1>(var2);
		//auto j = get<0>(var2); //excp
		get<1>(var2) = 77;
		//get<0>(var2) = 99; //excp
	}
	catch (const bad_variant_access& e)
	{
		cout << "exception in variant access 2" << e.what() << endl;
	}
	visit(MyVisitor(), var2);
	visit([](auto&& val) {cout << val << endl; }, var2);
	var2.valueless_by_exception() == true;
	var2.index() == variant_npos;

}

void NicolasExamples::testAny()
{
	any empty;
	any anyval(42);
	anyval = string("hello");
	anyval = "oops";
	if (anyval.has_value())
	{
		if (anyval.type() == typeid(string))
		{
			string s = any_cast<string>(anyval);
		}
	}
	try
	{
		int i = any_cast<int>(anyval);
	}
	catch (const bad_any_cast& e)
	{
		anyval.reset();
	}
	string s = "abi";
	any a;
	a = move(s);
	s = any_cast<string>(move(a));
}

struct s
{
	operator int() const { throw "Exception"; } //any conversion to int exception
};

mutex m;

void NicolasExamples::parallelTest()
{
	vector<int> vect1 = { 10,20,30,40,50,60,70,80,90 };
	vector<int> vect2 = { 1,2,3,4,5,6,7,8 };
	ofstream logFile;
	transform(execution::par_unseq,
		vect1.begin(), vect1.end(),
		vect2.begin(), [](auto x) {auto y = x * x; return y; });

	transform(execution::par,
		vect1.begin(), vect1.end(),
		vect2.begin(), [](auto x)
	{
		std::lock_guard<mutex> lg(m);
		return x * x; });

	transform(execution::seq,
		vect1.begin(), vect1.end(),
		vect2.begin(), [](auto x)
	{
		//logFile << x;
		return x * x; });

}

void NicolasExamples::cppPrintf()
{
	array<char, 10> str;
	if (auto[p, ec] = std::to_chars(str.data(), str.data() + str.size(), 42);
		ec == std::errc())
		std::cout << std::string_view(str.data(), p - str.data());

	char arr[128];
	auto[p, ec] = std::to_chars(std::begin(arr), std::end(arr), 52);
	if (ec != std::errc::value_too_large)
		std::cout << arr << '\n';

	float val;
	auto res2 = std::from_chars(std::begin(arr), std::end(arr), val);
	if (res2.ec != std::errc::invalid_argument &&
		res2.ec != std::errc::result_out_of_range)
		std::cout << arr << '\n';

}

template < typename T>
std::string as_string(T x)
{
	if (constexpr(is_arithmetic_v<T>))
	{
		int f = 5;
		return std::to_string(f);
		//TODO
		//return std::to_string(x);
	}
	else if constexpr (is_same_v<T, string>) {
		return  x;
	}
	else
	{
		string(x);
	}
}
void NicolasExamples::asStringTest()
{
	//TODO
	//cout << as_string(42) << endl;
	//cout << as_string(string("Hello")) << endl;
	//cout << as_string("Hello") << endl;
}

void NicolasExamples::testNewIn17()
{
	//[[maybe_unused]];
	//vector<int> a;
	//std::decay_t<a>;
	//std::is_trivially_destructible_v<a>;
	//std::decay<vector>::type;
	//std::is_trivially_destructible<a>::value;
	//auto l1([](auto... xs) {return  sizeof...(xs); });
	//auto l2([](auto x, auto s) {return x * s; });

	//if constexpr ()
	//{}
	////foldexpression

	//async;
	//future;
	//packaged_task;
	//dispatch_get_global_queue;
	//dispatch_async_f;

}
/*
template<typename T1, typename... T>
auto sum(const T1& arg1, const T&... args)
{
	if constexpr (sizeof... (args) > 0)
		return arg1 + sum(args...);
	return arg1;
}

template <typename... T>
auto sum(const T&... args)
{
	return (args + ...);
}

template <typename T,
	typename = typename std::enable_if<std::is_floating_point<T>::value>::type>
	class Point
{
	T x; T y;
};

template <typename T>
class PointSame requires FloatingPoint<T>
{
	T x; T y;
};

template<FloatingPoint T>
class PointSameToo
{
	T x; T y;
};

FloatingPoint{ T } class PointSameTooo
{
	T x; T y;
};


*/