//
// Created by Shahram on 11/11/2018.
//

#include <cassert>
#include "../HeaderFiles/TemplateExample.h"
#include "../HeaderFiles/Includes.h"
using namespace std;

TemplateExample::TemplateExample() {}

template<size_t NM_OF_COPIES>
void copyPrint(const string& str)
{
    for (int i = 0; i < NM_OF_COPIES; ++i) {
        cout <<"template exam: "<< str<<endl;
    }
}

template <size_t n>
struct fact{
    const static auto value = fact<n-1>::value;
};
void TemplateExample::tempExam() {
    copyPrint<3>("Copy Template");
    //cout <<"template vale:" << fact<5>::value << endl;
}

void printStff(){
    cout <<endl;
}

template <typename tFirst, typename... tRest>
void printStff(tFirst frst, tRest... rest){
    cout <<frst <<" ";
    printStff(rest...);
}

void TemplateExample::multiPrint() {
    printStff(3,3.3,"foo",42);
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
struct TupleElement<0, Tuple<tValue, tRest...>>{
    using type_t = tValue;
    using TupleType_t = Tuple<tValue, tRest...>;
};

//template <size_t idx, typename... tRest>
//type_t& get(Tuple<tRest...>& tuple){
//    return static_cast<TupleType_t&>(tuple).value;
//}

template <size_t idx, typename tValue, typename... tRest>
struct TupleElement<idx,Tuple<tValue, tRest...>>
        : public TupleElement<idx-1, Tuple<tRest...>>{};

template <size_t idx, typename... Ttype>
typename TupleElement<idx, Tuple<Ttype...>>::type_t& get(Tuple<Ttype...>& tuple){
    using TupleType_t = typename TupleElement<idx, Tuple<Ttype...>>::TupleType_t;
    return static_cast<TupleType_t&>(tuple).value;
}

template <size_t idx, typename Ttuple>
void fillTuple(Ttuple& toFill){}

template <size_t idx, typename Ttuple, typename tFirst,typename... tRest>
void fillTuple(Ttuple& toFill, const tFirst& first, tRest... rest){
    get<idx>(toFill) = first;
    fillTuple<idx+1>(toFill, rest...);
}


template <typename... ttype>
Tuple<ttype...> makeTuple(ttype... args) {
    Tuple<ttype...> reslts;
    fillTuple<0> (reslts, args...);
    return  reslts;
};

void TemplateExample::testTupleAssignment()
{
    Tuple<int , char> tpl;
    get<0> (tpl) = 32;
    get<0> (tpl) = 'm';

    auto v1 =get<0> (tpl);
    auto v2 =get<1> (tpl);

    cout << "My TUPLE: "<< v1 <<"  " << v2 <<endl;

}

void TemplateExample::testMakeTuple()
{
    auto t2 = makeTuple(64,'H', string{"Foo"});
    assert(get<0>(t2) == 64);
    assert(get<1>(t2) == 'H');
    assert(get<2>(t2) == "Foo");
    cout << "MAKE TPL: " <<get<0>(t2) <<" " <<get<1>(t2) <<" " <<get<2>(t2)<< endl;
}