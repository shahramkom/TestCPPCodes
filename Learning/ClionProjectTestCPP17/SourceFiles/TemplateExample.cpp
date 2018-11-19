//
// Created by Shahram on 11/11/2018.
//

#include <cassert>
#include "../HeaderFiles/TemplateExample.h"
#include "../HeaderFiles/Includes.h"
#include <variant>
using namespace std;

TemplateExample::TemplateExample() {}

template<size_t NM_OF_COPIES>
void copyPrint(const string& str)
{
	for (int i = 0; i < NM_OF_COPIES; ++i) {
		cout << "template exam: " << str.c_str() << endl;
	}
}

template <size_t n>
struct fact {
	const static auto value = fact<n - 1>::value;
};
void TemplateExample::tempExam() {
	copyPrint<3>("Copy Template");
	//cout <<"template vale:" << fact<5>::value << endl;
}

void printStff() {
	cout << endl;
}

template <typename tFirst, typename... tRest>
void printStff(tFirst frst, tRest... rest) {
	cout << frst << " ";
	printStff(rest...);
}

void TemplateExample::multiPrint() {
	printStff(3, 3.3, "foo", 42);
}



template <typename... ttype> class Tuple;

template <> class Tuple<> {};

template <typename tValue, typename... tRest>
class Tuple<tValue, tRest...> : public Tuple<tRest...>
{
public:
	tValue value;
};

template <size_t idx, typename Ttuple> struct TupleElement;
template <typename tValue, typename... tRest>
struct TupleElement<0, Tuple<tValue, tRest...>> {
	using type_t = tValue;
	using TupleType_t = Tuple<tValue, tRest...>;
};

//template <size_t idx, typename... tRest>
//type_t& get(Tuple<tRest...>& tuple) {
//	return static_cast<TupleType_t&>(tuple).value;
//}

template <size_t idx, typename tValue, typename... tRest>
struct TupleElement<idx, Tuple<tValue, tRest...>>
	: public TupleElement<idx - 1, Tuple<tRest...>> {};

template <size_t idx, typename... Ttype>
typename TupleElement<idx, Tuple<Ttype...>>::type_t& get(Tuple<Ttype...>& tuple) {
	using TupleType_t = typename TupleElement<idx, Tuple<Ttype...>>::TupleType_t;
	return static_cast<TupleType_t&>(tuple).value;
}

template <size_t idx, typename Ttuple>
void fillTuple(Ttuple& toFill) {}

template <size_t idx, typename Ttuple, typename tFirst, typename... tRest>
void fillTuple(Ttuple& toFill, const tFirst& first, tRest... rest) {
	get<idx>(toFill) = first;
	fillTuple<idx + 1>(toFill, rest...);
}


template <typename... ttype>
Tuple<ttype...> makeTuple(ttype... args) {
	Tuple<ttype...> reslts;
	fillTuple<0>(reslts, args...);
	return  reslts;
};

void TemplateExample::testTupleAssignment()
{
	Tuple<int, char> tpl;
	get<0>(tpl) = 32;
	get<0>(tpl) = 'm';

	auto v1 = get<0>(tpl);
	auto v2 = get<1>(tpl);

	cout << "My TUPLE: " << v1 << "  " << v2 << endl;

}

void TemplateExample::testMakeTuple()
{
	auto t2 = makeTuple(64, 'H', string{ "Foo" });
	assert(get<0>(t2) == 64);
	assert(get<1>(t2) == 'H');
	assert(get<2>(t2) == "Foo");
	cout << "MAKE TPL: " << get<0>(t2) << " " << get<1>(t2) << " " << string(get<2>(t2)).c_str() << endl;
}

//template <bool dmyKeepSorted = true>
//typename enable_if<!dmyKeepSorted, void>::type add(const T& val){
//    [[fallthrough]] asd;
//};d

void afd()
{
	//[[fallthrough]];
}

[[nodiscard]] int testfnv()
{
	int a = 0;
#if __has_include(<iostream>)
	a = 1;
#endif
	[[maybe_unused]] int val = 3;
	return 12;
}

template <typename  a, typename ... b>
void call(a aa, b&&... bb)
{
	aa(forward<b>(bb)...);
}

template <typename  a, typename ... b>
auto&& call(a aa, b&&... bb)
{
	aa(forward<b>(bb)...);
}

template <typename  a, typename ... b>
decltype(auto) call(a aa, b&&... bb)
{
	aa(forward<b>(bb)...);
}

decltype(auto) foo()
{
	int i = 9;
	return i;
}

decltype(auto) foo1()
{
	int i = 9;
	return (i); //LValue
}

void test()
{
	std::is_same<decltype(foo()), int>::value; //true
	std::is_same<decltype(foo1()), int&>::value; //true
//    process(compute(t));
//    auto && val = compute(t);
//    process(forward<decltype(val)>(val));
}

template <typename Callable, typename ... Args>
decltype(auto) call(Callable&& op, Args&&... args)
{
	if constexpr (std::is_same_v<std::invoke_result_t<Callable, Args...>, void>)
	{
		std::invoke(std::forward<Callable>(op), std::forward<Args>(args)...);
		return;
	}
	else {

	}
	decltype(auto) ret{ std::invoke(std::forward<Callable>(op),std::forward<Args>(args)...) };
	return ret;
}

int Func(int a, int b) { return a + b; }
struct S {
	void operator() (int a) { std::cout << a << '\n'; }
};
int tstFnc() {
	std::cout << std::invoke(Func, 10, 20) << '\n'; // 30
	std::invoke(S(), 42); // 42
	std::invoke([]() { std::cout << "hello\n"; }); // hello

	return 0;
}


template <typename... Types>
void print(Types... args)
{
	(std::cout << ... << args);
}


template<decltype(auto) msg>
class Message {
public:
	void print() {
		cout << msg << endl;
	}
};

static int x;
void tstMsg()
{
	Message<42> m2;
	m2.print();
	extern int x;
	x = 43;
	Message<(x)> m5; //int&
	m5.print();

	x *= 10;
	m5.print();

}

struct Printer {
	void operator() (int i) const {
		cout << "int: " << i << endl;
	}
	void operator() (string s) const {
		cout << "string: " << s.c_str() << endl;
	}
};

struct Printer2 {
	template<typename T>
	void operator()(const T& x) const {
		cout << x << endl;
	}
};

void variantVisit()
{
	//std::variant<int, string > var{ 42 };
	//std::visit(Printer{}, var);
	//std::visit([](const auto& x) {cout << x << endl; }, var);
}

template <typename... Functor>
struct Ovld : Functor...{
	using Functor::operator()...;
};

template <typename ... Functor>
Ovld(Functor...)->Ovld<Functor...>;