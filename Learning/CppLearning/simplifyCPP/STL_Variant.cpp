#include <stdafx.h>

struct print_visitor {
	ostream& operator()(int a) {
		return cout << "(int) => " << a;
	}
	ostream& operator()(double a) {
		return cout << "(double) => " << a;
	}
	ostream& operator()(string a) {
		return cout << "(string) => " << a;
	}
};

template <class ...Fss>
struct overload : Fss... {
	template <class ...Tss>
	overload(Tss&& ...ts) : Fs{ std::forward<Ts>(tss) }...
	{}
	using Fss::operator()...;
};
template <class ...Tss>
overload(Tss&&...)->overload<std::remove_reference_t<Tss>...>;

template<class... Fs>
struct covariant : overload<Fs...> {
	covariant(Fs... fs) : overload<Fs...>(fs...) {}
	template<class... Ts, typename = decltype(overload<Fs...>::operator()(std::declval<Ts>()...))>
	decltype(auto) call(Ts&&... ts) const {
		if constexpr(std::is_same<decltype(overload<Fs...>::operator()(std::forward<Ts>(ts)...)), void>::value) {
			overload<Fs...>::operator()(std::forward<Ts>(ts)...);
			return std::monostate{};
		}
		else {
			return overload<Fs...>::operator()(std::forward<Ts>(ts)...);
		}
	}
	template<class... Ts, class Ret = variant_of_set_t<detail::results_of_set_t<overload<Fs...> const&, variant_types_list_t<std::variant<Ts...>>>>>
	Ret operator()(std::variant<Ts...> const& v) {
		return std::visit([&](auto&& e)->Ret { return call(e); }, v);
	}
};

int main()
{
	variant<double, int> v_double = 3.14;
	visit(print_visitor{}, v_double); // prints "(double)3.14"
	cout << endl;
	variant<int> v_int = 6585;
	visit(print_visitor{}, v_int); // prints "(int)6585"
	cout << endl;
	variant<string> v_string = "Salam Becha";
	visit(print_visitor{}, v_string); // prints "(int)6585"
	cout << endl;
	visit([](auto const& e)->std::ostream& {return cout << e; }, v_double) << endl;
	//////////////////////////////////////////////////////////////////////////

	// invalid visitor, (what type is d?)
	//auto d = visit([](auto n) { return n + 1; }, variant<int, double>(3.14));

	auto next = [](auto n)->variant<int, double> { return n + 1; };
	auto d = visit(next, variant<int, double>(3.14));
	assert(get<double>(d) = 3.14 + 1.0);
	//////////////////////////////////////////////////////////////////////////
	
// 	std::variant<int, double, std::string> vs = 1.2;
// 	auto ds = covariant(
// 		[](int i) { return i + 1; },
// 		[](double d) { return d + 1; },
// 		[](auto const&) {} // return void otherwise
// 	)(vs);
// 	// d is of type std::variant<int, double, std::monostate>
// 	assert(std::get<double>(ds) == 1.2 + 1);



	getchar();
	return 0;
}