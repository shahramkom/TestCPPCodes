//Auto samples
auto var= 42;
auto a = func(3,5.2);
auto res= add(3,5.2);

auto func(int x, int y) -> int {
return x+y;
}
template <typename T, typename U>
auto add(T x, U y)->decltype(x+y){
return x+y;
}

std::vector<int> v{1,2,3,4,5};

auto it=v.cbegin();
std::cout << *it++<<'\n';

auto const fin=v.cend();
while(it!=fin)
    std::cout << *it++ << '\n';

for (auto i=v.begin(); i!=v.end();++i)
    *i *=2;

for (auto &x:v)
    x += 2;
for (auto const x:v)
    std::cout << x << ", ";

//Initializer
struct point{
    int x;
    int y;
    int z;
    };
point origin={0,0,0};
point line[2]={{1,1,1},{3,4,5}};

int i{3};
int g{};
std::vector<double> v{3,1,4,1,5,9,2,6};
std::vector<int> v2{10,0};
std::vector<int> v10(10,0);

auto i={3};

int i=3; // int
int &j=i;//int&
auto k=j; //int
decltype(auto) l=j;//int&
auto &&m=j; //int&
auto &&n=i; //int&&

template <size_t...I>
constexpr
auto make_compile_time_sequence(size_t const row,std::index_sequence<I...>)
{
return std::array<size_t,sizeof...(I)>{{row*(1+I)...}};
}

void testIndexSequenceArray(std::ostream &out){
    auto const v=
make_compile_time_sequence(1,std::make_index_sequence<20>{});
    for (auto i=v.cbegin(); i < v.cend(); ++i){
    out << '\n';
    std::for_each(cbegin(v),cend(v),[i,&out](auto j){
    out << std::setw(4)<< *i * j;
    });
}
out << '\n';
}

//Algorithms & λ
//First simple Lambda
auto hello=[] { cout << "hello world" << endl;};

auto even=[](int i){ return i%2==0;};
auto odd=[](int i)->bool{ return i%2;};

void multab_lambda_bind_vector(std::ostream &out) {
    std::vector<int> v(20); // not {20}!
    iota(begin(v),end(v),1);
        using oi=std::ostream_iterator<int>;
        using std::placeholders::_1;
    out << '\n';

        std::for_each(v.begin(),v.end(),[&out,v](auto y){
            transform(v.begin(), v.end(), oi{out,"\t"},
                bind(std::multiplies<>{},y,_1));
        out << '\n';
    });
}

for (int i:{2,3,5,8,13}) { cout << i << endl;}

//Memory

std::string demangle(char const *name){
    std::unique_ptr<char,decltype(&::free)>
    toBeFreed{ __cxxabiv1::__cxa_demangle(name,0,0,0),&::free};
    std::string result(toBeFreed.get());
    return result;
}

template<typename T,typename CMP=std::less<T>>
struct indexableSet : std::set<T,CMP>{
    using SetType=std::set<T,CMP>;
    using SetType=std::set<T,CMP>;
    using size_type=typename SetType::size_type;
    using std::set<T,CMP>::set; // inherit constructors of std::set
    
    T const & operator[](size_type index) const {
        return this->at(index);
    }
    T const & at(size_type index) const {
        if (index >= SetType::size())
            throw std::out_of_range{"indexableSet::operator[] out of range"};
        auto iter=SetType::begin();
        std::advance(iter,index);
        return *iter;
    }
};