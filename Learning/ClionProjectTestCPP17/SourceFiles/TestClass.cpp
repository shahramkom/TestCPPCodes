//
// Created by Shahram on 11/7/2018.
//

#include "../HeaderFiles/TestClass.h"
#include <array>
#include <algorithm>
#include <iostream>
#include <experimental/optional>
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <memory>
#include <numeric>
#include <iterator>
#include <set>
#include <deque>
//#include <execution>
//#include <variant>

using std::experimental::optional;
using std::experimental::nullopt;
//using std::cout;
//using std::sort;
//using std::array;
//using std::for_each;
//using std::endl;
using namespace std;

TestClass::TestClass() = default;


void TestClass::SortRange() {
    std::array<int, 5> arr = {3, 4, 1, 5, 2};
    std::sort(std::begin(arr), std::end(arr),std::greater<int>{});
    for_each(arr.begin(), arr.end(), [=](int it){std::cout<<it << " ";});
    cout  << endl;
}

void foo(int i, optional<double> f, optional<bool> b)
{
//    if(f != nullopt)
//        cout << "F Param is:" << f.value() << endl;
//    if(b != nullopt)
//        cout << "B Param is:" << b.value()<< endl;;
}

void TestClass::useOptional()
{
    foo(5, 1.0, true);
    foo(5, nullopt, false);
    foo(5, 2.0, nullopt);
    foo(5, nullopt, nullopt);
}

template <typename T>
void times2(T val)
{
    cout << "temp Val*2: " << val * val << endl;
}
template <typename T>
T add (T val1, T val2)
{
    return val1+val2;
}

template <typename T>
T max (vector<T> val)
{
    T first = val[0];
    for(const auto& it : val)
        if(it > first)
            first = it;
    return first;
}

template <typename T ,typename O>
class persons{
public:
    T height;
    O weight;
    static int nm;
    persons(T h, O w)
    : height(h)
    , weight(w)
    {
        nm++;
    }
    void getData()
    {
        cout << "height : " << height << " width: "<<weight <<endl;
    }
};

template <typename T ,typename O> int persons<T,O>::nm;
////////////////////////////////////////////////////////////////
struct Address {
    string* house_name = nullptr;
};

struct Person {
    Address* address = nullptr;
};

template <typename T> struct Maybe;
template <typename T> Maybe<T> maybe(T* context)
{
    return Maybe<T>(context);
}
template <typename T> struct Maybe
{
    T* context;
    Maybe(T* context): context{context} {}
    template <typename TFunc> auto With (TFunc evaluator)
    {
        return context != nullptr ? maybe(evaluator(context)) : nullptr;
    };
    template <typename Func> auto Do (Func action)
    {
        if (context != nullptr)
            action(context);
        return *this;
    }
};

void print_house_name(Person* p)
{
    //    if (p != nullptr && p->address != nullptr && p->address->house_name != nullptr)
    //        cout << *p->address->house_name << endl;
    auto z = maybe(p)
            .With([](auto x) { return x->address; })
            .With([](auto x) { return x->house_name; })
            .Do([](auto x) { cout << *x << endl; });
}

void TestClass::separatedCommands() {
    std::initializer_list<string> initList = {"a","b","c"};
    cout << "sabz" <<endl;

    cout << 36 << ":";
    streambuf* bfStrm = cout.rdbuf();
    ostream myot(bfStrm);
    myot << 35;
    myot.setf(ios::showpos);
    myot.setf(ios::showbase);
    myot.setf(ios::showpoint);
    myot.width(20);
    myot << 15 <<endl;
    cout << 16 <<endl;
/////////////////////////////////////////////////////////////////////
    vector<function<double (int)>> zarab;
    zarab.emplace_back([=](int m){ return m*m;});
    zarab.emplace_back([=](int m){ return m*m*m;});
    zarab.emplace_back([=](int m){ return m*m*m*m;});
    zarab.emplace_back([=](int m){ return m*5;});
    cout << "Calc z2:"<< zarab[0](5)<< "->" << zarab[1](10)<< "->" << zarab[2](15) << "->" << zarab[3](6) << endl;
//////////////////////////////////////////////////////////////////////
    vector<uint64_t> intVect = {1,9,15,55,65};
    vector<double_t> dblVect = {120.32,22,65.69,117,65.3};
    times2(5);
    times2(6.5);
    cout << "template Add: " << add(5,5) << endl;
    cout << "template Add: " << add(6.23,7.25) << endl;
    cout << "template Add: " << add(string("sabz"), string("zard")) << endl;
    cout << "template get Max int: " << max(intVect) << endl;
    cout << "template get Max dbl: " << max(dblVect) << endl;
//////////////////////
    //TODO
    persons <double , int > person1 (5.83 , 6);
    person1.getData();
    cout << "nm of persons: " << persons<double, int>::nm <<endl;
////////////////////////////////////
    //TODO
    Person p;
    p.address = new Address;

    p.address->house_name = new string("my template person address");
    print_house_name(&p);
    delete p.address->house_name;
    delete p.address;
//////////////////////////////////////////

//    string_view sw;
//    auto v = variant<int, double>(42);
//    int b = get<int>(v);
//    v = 6.56;
//    double m = get<double>(v);
//    auto h = any(42);
//    int nn = any_cast<int>(h);
//    string y = any_cast<string>(h); //Error
//    h = "Xyz";
//    cout << any_cast<string>(h);
/////////////////////////////////////////////////////

    vector<int> baseVect={4,5};
    vector<int> op = {12,15,16,19,88};
    int* op_k = &op[0];
    vector<int>::iterator it = find(op.begin(),op.end(),16);
    vector<int>::iterator it2 = find(op.begin(),op.end(),10);
    insert_iterator<vector<int>> i_itr(op, it);
    copy(op.begin(),op.end(),i_itr);
    vector<string> stringVect;

    //TODO Need to read from output
//    copy(istream_iterator<string>(cin),istream_iterator<string>(), back_inserter(stringVect) );
//    copy(stringVect.begin(), stringVect.end() , ostream_iterator<string>(cout," ") );
//    unique_copy(istream_iterator<string>(cin),istream_iterator<string>(), ostream_iterator<string>(cout, " ") );

//    advance(i_itr, 2);
//    distance(it,it2);

}

class X
{
public:
    X(int i ){}
    void operator()(string str){
        cout << " calling x is :" <<str << endl;
    }
    operator string() const { return "X";}
};

void TestClass::testCommands2()
{
//    X foo;
//    foo("Shah");
    X(8)("Hi");
}

class AddValue{
    int val;
public:
    AddValue(int j)
    : val(j){}
    void operator()(int i)
    {
        cout<<i+val<<endl;
    }
};

void addVal(int i , int val){
    cout <<i+val <<endl;
}

double Pow(double a , double b)
{
    return pow(a,b);
}

bool lsb_less(int x , int y)
{
    return (x%10)<(y%10);
}
class Lsb_Less{
public:
    bool operator()(int x , int y){
        return (x%10)<(y%10);
    }
};
int mn()
{
    set<int> mySet = {5,6,8,7};
    vector<int> vec = {2,3,4,5,6};
    int x  =2;
    for_each(vec.begin(),vec.end(), AddValue(x));
    transform(mySet.begin(),mySet.end(),
            back_inserter(vec),
            bind(multiplies<int>(), placeholders::_1, 10));
    for_each(vec.begin(), vec.end(), bind(addVal, placeholders::_1, 2));
    auto f = function<double (double, double)>(Pow);

    deque<int> d;
    transform(mySet.begin(),mySet.end(),
              back_inserter(d),
              bind(f, placeholders::_1, 10));

    transform(mySet.begin(),mySet.end(),
              back_inserter(d),
              bind(logical_or<bool>(),
                      bind(greater<int>(), placeholders::_1,20),
                      bind(less<int>(), placeholders::_1, 5))
                      );
    set<int,less<int>> set2 = {3,1,25,7,12};
    set<int,Lsb_Less> set3 = {2,6,8,9,77};
}
