    auto
    nullptr
    Range-based for loops
    Override and final
    Strongly-typed enums
    Smart pointers 
    Lambdas
    non-member begin() and end()
    static_assert and type traits
    Move semantics
//Auto
auto i = 42;        // i is an int
auto l = 42LL;      // l is an long long
auto p = new foo(); // p is a foo*
std::map<std::string, std::vector<int>> map;
for(auto it = begin(map); it != end(map); ++it) 
template <typename T1, typename T2>
auto compose(T1 t1, T2 t2) -> decltype(t1 + t2)
{
   return t1+t2;
}
auto v = compose(2, 3.14); // v's type is double

//Nullptr
void foo(int* p) {}
void bar(std::shared_ptr<int> p) {}
int* p1 = NULL;
int* p2 = nullptr;   
if(p1 == p2){}
foo(nullptr);
bar(nullptr);
bool f = nullptr;
int i = nullptr; // error: A native nullptr can only be converted to bool or, using reinterpret_cast, to an integral type

//Range-based for loops
std::map<std::string, std::vector<int>> map;
std::vector<int> v;
v.push_back(1);
v.push_back(2);
v.push_back(3);
map["one"] = v;
for(const auto& kvp : map) 
{
  std::cout << kvp.first << std::endl;
  for(auto v : kvp.second)
     std::cout << v << std::endl;
}
int arr[] = {1,2,3,4,5};
for(int& e : arr) 
  e = e*e;

//Override and final

//Strongly-typed enums
enum class Options {None, One, All};
Options o = Options::All;

//Smart pointers
void foo(int* p)
{
   std::cout << *p << std::endl;
}
std::unique_ptr<int> p1(new int(42));
std::unique_ptr<int> p2 = std::move(p1); // transfer ownership

if(p1)
  foo(p1.get());

(*p2)++;

if(p2)
  foo(p2.get());
//_______________
void foo(int* p)
{
}
void bar(std::shared_ptr<int> p)
{
   ++(*p);
}
std::shared_ptr<int> p1(new int(42));
std::shared_ptr<int> p2 = p1;
   
bar(p1);   
foo(p2.get());
//_______________
auto p3 = std::make_shared<int>(42);
//_______________
void foo(std::shared_ptr<int> p, int init)
{
   *p = init;
}
foo(std::shared_ptr<int>(new int(42)), seed());
//_______________
auto p = std::make_shared<int>(42);
std::weak_ptr<int> wp = p;

{
  auto sp = wp.lock();
  std::cout << *sp << std::endl;
}

p.reset();

if(wp.expired())
  std::cout << "expired" << std::endl;

//Lambdas
std::vector<int> v;
v.push_back(1);
v.push_back(2);
v.push_back(3);

std::for_each(std::begin(v), std::end(v), [](int n) {std::cout << n << std::endl;});

auto is_odd = [](int n) {return n%2==1;};
auto pos = std::find_if(std::begin(v), std::end(v), is_odd);
if(pos != std::end(v))
  std::cout << *pos << std::endl;
//_________________
auto fib = [&fib](int n) {return n < 2 ? 1 : fib(n-1) + fib(n-2);};
error C3533: 'auto &': a parameter cannot have a type that contains 'auto'
error C3531: 'fib': a symbol whose type contains 'auto' must have an initializer
error C3536: 'fib': cannot be used before it is initialized
error C2064: term does not evaluate to a function taking 1 arguments
//
std::function<int(int)> lfib = [&lfib](int n) {return n < 2 ? 1 : lfib(n-1) + lfib(n-2);};
//_________________

//non-member begin() and end()
int arr[] = {1,2,3};
std::for_each(&arr[0], &arr[0]+sizeof(arr)/sizeof(arr[0]), [](int n) {std::cout << n << std::endl;});

auto is_odd = [](int n) {return n%2==1;};
auto begin = &arr[0];
auto end = &arr[0]+sizeof(arr)/sizeof(arr[0]);
auto pos = std::find_if(begin, end, is_odd);
if(pos != end)
  std::cout << *pos << std::endl;

>>>>>>>>
int arr[] = {1,2,3};
std::for_each(std::begin(arr), std::end(arr), [](int n) {std::cout << n << std::endl;});

auto is_odd = [](int n) {return n%2==1;};
auto pos = std::find_if(std::begin(arr), std::end(arr), is_odd);
if(pos != std::end(arr))
  std::cout << *pos << std::endl;

 //__________________
 template <typename Iterator>
void bar(Iterator begin, Iterator end) 
{
   std::for_each(begin, end, [](int n) {std::cout << n << std::endl;});

   auto is_odd = [](int n) {return n%2==1;};
   auto pos = std::find_if(begin, end, is_odd);
   if(pos != end)
      std::cout << *pos << std::endl;
}

template <typename C>
void foo(C c)
{
   bar(std::begin(c), std::end(c));
}

template <typename T, size_t N>
void foo(T(&arr)[N])
{
   bar(std::begin(arr), std::end(arr));
}

int arr[] = {1,2,3};
foo(arr);

std::vector<int> v;
v.push_back(1);
v.push_back(2);
v.push_back(3);
foo(v);

//static_assert and type traits
template <typename T, size_t Size>
class Vector
{
   static_assert(Size < 3, "Size is too small");
   T _points[Size];
};

int main()
{
   Vector<int, 16> a1;
   Vector<double, 2> a2;
   return 0;
}
//______
template <typename T1, typename T2>
auto add(T1 t1, T2 t2) -> decltype(t1 + t2)
{
   return t1 + t2;
}
std::cout << add(1, 3.14) << std::endl;
std::cout << add("one", 2) << std::endl;
//_________________
template <typename T1, typename T2>
auto add(T1 t1, T2 t2) -> decltype(t1 + t2)
{
   static_assert(std::is_integral<T1>::value, "Type T1 must be integral");
   static_assert(std::is_integral<T2>::value, "Type T2 must be integral");

   return t1 + t2;
}

//Move semantics

template <typename T>
class Buffer 
{
   std::string          _name;
   size_t               _size;
   std::unique_ptr<T[]> _buffer;

public:
   // default constructor
   Buffer():
      _size(16),
      _buffer(new T[16])
   {}

   // constructor
   Buffer(const std::string& name, size_t size):
      _name(name),
      _size(size),
      _buffer(new T[size])
   {}

   // copy constructor
   Buffer(const Buffer& copy):
      _name(copy._name),
      _size(copy._size),
      _buffer(new T[copy._size])
   {
      T* source = copy._buffer.get();
      T* dest = _buffer.get();
      std::copy(source, source + copy._size, dest);
   }

   // copy assignment operator
   Buffer& operator=(const Buffer& copy)
   {
      if(this != &copy)
      {
         _name = copy._name;

         if(_size != copy._size)
         {
            _buffer = nullptr;
            _size = copy._size;
            _buffer = _size > 0 > new T[_size] : nullptr;
         }

         T* source = copy._buffer.get();
         T* dest = _buffer.get();
         std::copy(source, source + copy._size, dest);
      }

      return *this;
   }

   // move constructor
   Buffer(Buffer&& temp):
      _name(std::move(temp._name)),
      _size(temp._size),
      _buffer(std::move(temp._buffer))
   {
      temp._buffer = nullptr;
      temp._size = 0;
   }

   // move assignment operator
   Buffer& operator=(Buffer&& temp)
   {
      assert(this != &temp); // assert if this is not a temporary

      _buffer = nullptr;
      _size = temp._size;
      _buffer = std::move(temp._buffer);

      _name = std::move(temp._name);

      temp._buffer = nullptr;
      temp._size = 0;
      
      return *this;
   }
};

template <typename T>
Buffer<T> getBuffer(const std::string& name) 
{
   Buffer<T> b(name, 128);
   return b;
}
int main()
{
   Buffer<int> b1;
   Buffer<int> b2("buf2", 64);
   Buffer<int> b3 = b2;
   Buffer<int> b4 = getBuffer<int>("buf4");
   b1 = getBuffer<int>("buf5");
   return 0;
}
//_____________
template <typename T>
class Buffer
{
   std::string          _name;
   size_t               _size;
   std::unique_ptr<T[]> _buffer;
 
public:
   // constructor
   Buffer(const std::string& name = "", size_t size = 16):
      _name(name),
      _size(size),
      _buffer(size? new T[size] : nullptr)
   {}
 
   // copy constructor
   Buffer(const Buffer& copy):
      _name(copy._name),
      _size(copy._size),
      _buffer(copy._size? new T[copy._size] : nullptr)
   {
      T* source = copy._buffer.get();
      T* dest = _buffer.get();
      std::copy(source, source + copy._size, dest);
   }
 
   // copy assignment operator
   Buffer& operator=(Buffer copy)
   {
       swap(*this, copy);
       return *this;
   }
 
   // move constructor
   Buffer(Buffer&& temp):Buffer()
   {
      swap(*this, temp);
   }
 
   friend void swap(Buffer& first, Buffer& second) noexcept
   {
       using std::swap;
       swap(first._name  , second._name);
       swap(first._size  , second._size);
       swap(first._buffer, second._buffer);
   }
};