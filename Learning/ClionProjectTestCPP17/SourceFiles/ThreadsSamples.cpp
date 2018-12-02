#include "../HeaderFiles/Includes.h"
#include "../HeaderFiles/ThreadsSamples.h"

using namespace std;
std::once_flag onceFlag;
std::condition_variable cond;

ThreadsSamples::ThreadsSamples()
{

}

int factorial(int n)
{
	int res = 1;
	for (int i = n; i > 1; i--)
		res *= i;
	return  res;
}

int factorialt(std::future<int>& f)
{
	int res = 1;
	int n = f.get();
	for (int i = n; i > 1; i--)
		res *= i;
	return  res;
}

int factorials(std::shared_future<int> f)
{
	int res = 1;
	int n = f.get();
	for (int i = n; i > 1; i--)
		res *= i;
	return  res;
}

void ThreadsSamples::startTests()
{
	std::thread::hardware_concurrency();
	cout << "ID of This Thread: " << this_thread::get_id << endl;
	///////////////////////////////////////////////
	std::call_once(onceFlag, [&]() {auto m = 0l; });
	///////////////////////////////////////////////
	cond.notify_one(); //notify one waiting thread, if there is one
	cond.notify_all();
	///////////////////////////////////////////////
	mutex mt;
	unique_lock<mutex> locker(mt);
	//cond.wait(locker); //spurious wake
	//cond.wait(locker, []() {return  !false; });
	///////////////////////////////////////////////
	int x = 0;
	std::future<int> xx = std::async(factorial, 4);
	std::future<int> xxs = std::async(std::launch::async, factorial, 4);
	std::future<int> xxm = std::async(std::launch::deferred, factorial, 4);
	std::future<int> xxd = std::async(std::launch::deferred | std::launch::async, factorial, 4);
	x = xx.get();

	std::promise<int> p;
	std::future<int> f = p.get_future();
	std::future<int> xxp = std::async(std::launch::async, factorialt, std::ref(f));

	p.set_exception(std::make_exception_ptr(std::runtime_error("To err is human")));
	//TODO
	//p.set_value(4); //if (not assign value) std::future_errc::broken_promise;

	//int s = xxp.get();

	std::shared_future<int> sf = f.share();
	std::future<int> xdp = std::async(std::launch::async, factorials, sf);

}

class A
{
public:
	void f(int x, char c) {}
	long g(double x) {}
	int operator()(int x) { return  0; }
};

void foo(int x) {}
void ThreadsSamples::testsThreads2() const
{
	A a;
	thread t1(a, 6); //copy of a in  a diffrent thread
	thread t2(std::ref(a), 6); //a() in a diffrent thread
	thread t2_1(std::move(a), 6); //a is no longer usable in main thread 
	thread t3(A(), 6); //temp A
	thread t4([](int x) {return  x * x; }, 6);
	thread t5(foo, 7);
	thread t6(&A::f, a, 8, 'W');//copy of a.f(8,'W') in  a diffrent thread
	thread t7(&A::f, &a, 8, 'W');// a.f(8,'W') in  a diffrent thread
}

std::deque<packaged_task<int()>> task_q;
mutex mo;
condition_variable cnd;
void thread_1()
{
	packaged_task<int()> t;
	{
		std::unique_lock<mutex> locker(mo);
		cnd.wait(locker, []() {return !task_q.empty(); });
		t = std::move(task_q.front());
		task_q.pop_front();
	}
	t();
}
void ThreadsSamples::testsThreads3()
{
	std::packaged_task<int(int)> t(factorial);
	t(6); //in diffrence context
	int x = t.get_future().get();

	std::thread(factorial, 6);

	thread t1(thread_1);
	std::packaged_task<int()> ts(bind(factorial, 6));
	ts();
	std::future<int> fu = ts.get_future();
	task_q.push_back(std::move(ts));
	std::cout << endl;
	cnd.notify_one();

	cout << fu.get() << endl;

	t1.join();
}