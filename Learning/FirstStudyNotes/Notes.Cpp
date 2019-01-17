//Copy
std::copy(std::begin(source), std::end(source),std::begin(target2));
std::copy(std::begin(source), std::end(source),std::back_inserter(target3));
//Count
int count = std::count(std::begin(numbers),std::end(numbers),3);
//Sort
std::sort(std::begin(arr), std::end(arr));
std::sort(std::begin(arr), std::end(arr),std::greater<int>{});
//Swap
std::swap_ranges(std::begin(v1), std::end(v1), std::begin(v2));
v1.swap(v2);
swap(v1, v2);
//Tuple
std::tie(a1,b2,c3);
//Classes
//Concurency
    //Thread
    std::thread t{func, str, std::ref(x)};
    t.join();
    //Async
    std::future<int> result_future = std::async(func);
	int result = result_future.get();
    //Pass Value Between Thread
    void func(std::promise<int> result_promise) noexcept
	    result_promise.set_value(42);

	std::promise<int> result_promise;
	std::future<int> result_future = result_promise.get_future();
	std::thread t{func, std::move(result_promise)};
	int result = result_future.get();
	t.join();
//Find Map
std::map<std::string, int> m = {{"a", 1}, {"b", 2}, {"c", 3}};
if (m.count("b"))
//Remove From Map
std::vector<int> v = {1, 2, 3, 4, 2, 5, 2, 6};
v.erase(std::remove(std::begin(v), std::end(v), 2),std::end(v)); 
v.erase(std::remove_if(std::begin(v), std::end(v),[](int i) { return i%2 == 0; }),std::end(v)); 
//Optional Parameter
void foo(int i,optional<double> f,optional<bool> b)
foo(5, 1.0, true);
foo(5, nullopt, true);
foo(5, 1.0, nullopt);
foo(5, nullopt, nullopt);
//Dynamic & Static Array
void compile_time(std::array<int, 3> arr)
void run_time(std::experimental::dynarray<int> arr)
std::array<int, 3> arr = {4, 8, 15};
compile_time(arr);
compile_time({16, 23, 42});
std::experimental::dynarray<int> dynarr = {1, 2, 3};
run_time(dynarr);
run_time({1, 2, 3, 4, 5});
//Return Multiple Value
std::tuple<int, bool, float> foo()
	return std::make_tuple(128, true, 1.5f);

std::tuple<int, bool, float> result = foo();
int value = std::get<0>(result);
int obj1;
bool obj2;
float obj3;
std::tie(obj1, obj2, obj3) = foo();
//Split and Get integer From String
std::istringstream stream{"4 36 72 8"};
std::vector<int> values;
std::copy(std::istream_iterator<int>{stream},std::istream_iterator<int>{},std::back_inserter(values));
//Shared Ptr
struct foo {};
void func(std::shared_ptr<foo> obj)

std::shared_ptr<foo> obj = std::make_shared<foo>();
func(obj);
//Unique Ptr
struct foo {};
void func(std::unique_ptr<foo> obj)

std::unique_ptr<foo> obj = std::make_unique<foo>();
func(std::move(obj));
//Weak Ptr
class bar;
class foo
{
public:
	foo(const std::shared_ptr<bar>& b)
		: forward_reference{b}
	{ }
private:
	std::shared_ptr<bar> forward_reference;
};
class bar
{
public:
	void set_back_reference(const std::weak_ptr<foo>& f)
	{
		this->back_reference = f;
	}
	void do_something()
	{
		std::shared_ptr<foo> shared_back_reference = this->back_reference.lock();
		if (shared_back_reference) {
			// Use *shared_back_reference
		}
	}
private:
	std::weak_ptr<foo> back_reference;
};
int main()
{
	std::shared_ptr<bar> b = std::make_shared<bar>();
	std::shared_ptr<foo> f = std::make_shared<foo>(b);
	b->set_back_reference(f);
	b->do_something();
}
//Types
std::vector<int> vec = {1, 2, 3, 4, 5};
std::map<std::string, int> map = {{"Foo", 10}, {"Bar", 20}};
std::string str = "Some text";
std::unique_ptr<int> ptr1 = std::make_unique<int>(8);
std::shared_ptr<int> ptr2 = std::make_shared<int>(16);
//Write data in column
std::cout << std::left << std::setw(12) << "John Smith"<< std::right << std::setw(3) << 23<< '\n';
std::cout << std::left << std::setw(12) << "Sam Brown"<< std::right << std::setw(3) << 8<< '\n';
//Overload << operator
class foo
{
	public:
		friend std::ostream& operator<<(std::ostream& stream, foo const& f);
	private:
		int x = 10;
};

std::ostream& operator<<(std::ostream& stream, foo const& f)
	return stream << "A foo with x = " << f.x;

foo f;
std::cout << f << std::endl;
//Select Random from vector
std::vector<int> v = {10, 15, 20, 25, 30};
std::random_device random_device;
std::mt19937 engine{random_device()};
std::uniform_int_distribution<int> dist(0, v.size() - 1);
int random_element = v[dist(engine)];
//Random Boolean >>>>>bernoulli_distribution
std::random_device random_device;
std::mt19937 random_engine{random_device()};
std::bernoulli_distribution coin_distribution{0.25};
bool outcome = coin_distribution(random_engine);
//random integer >>>>>uniform_int_distribution
std::random_device random_device;
std::mt19937 random_engine{random_device()};
std::uniform_int_distribution<int> die_distribution{1, 6};
int die_roll = die_distribution(random_engine);
//seed random nmber
std::random_device r;
std::seed_seq seed_seq{r(), r(), r(), r(), r(), r()};
std::mt19937 engine{seed_seq};
//range iterator
int arr[] = {1, 2, 3, 4, 5};
for (int value : arr) {
	// Use value
}
std::vector<int> vec = {1, 2, 3, 4, 5};
for (int& ref : vec) {
	// Modify ref
}
//Class Templates
template <typename T, typename Enable = void>
class foo;
template <typename T>
class foo<T, typename std::enable_if<std::is_integral<T>::value>::type>
{ };
template <typename T>
class foo<T, typename std::enable_if<std::is_floating_point<T>::value>::type>
{ };
	
foo<int> f1;
foo<float> f2;
//Function Templates
template <typename T>
typename std::enable_if<std::is_integral<T>::value, bool>::type
	equal(T lhs, T rhs)
{
	return lhs == rhs;
}
template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, bool>::type
	equal(T lhs, T rhs)
{
	return std::abs(lhs - rhs) < 0.0001;
}

equal(3, 3);
equal(0.9f / 9.0f, 0.1f);

//Perfect forwarding
template<typename T, typename U>
std::pair<T, U> make_pair_wrapper(T&& t, U&& u)
{
	return std::make_pair(std::forward<T>(t),
	                      std::forward<U>(u));
}

std::pair<int, int> p1{ make_pair_wrapper(1, 2) };

//calc time of done work
using clock = std::chrono::steady_clock;
clock::time_point next_time_point = clock::now() + 5s;
some_complex_work();
std::this_thread::sleep_until(next_time_point);
//measure time of a long task
using clock = std::chrono::steady_clock;
clock::time_point start = clock::now();
// A long task...
clock::time_point end = clock::now();
clock::duration execution_time = end - start;
//Sleep new method
std::chrono::milliseconds sleepDuration(20);
std::this_thread::sleep_for(sleepDuration);
std::this_thread::sleep_for(5s);
