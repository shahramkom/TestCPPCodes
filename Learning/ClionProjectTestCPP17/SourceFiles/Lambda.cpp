//
// Created by Shahram on 11/10/2018.
//

#include "../HeaderFiles/Lambda.h"
#include "../HeaderFiles/Includes.h"
using namespace std;

Lambda::Lambda() {

}


struct  isEven
{
    template <typename  T>
    bool operator()(T x) { return  !(x%2);}
};

template <typename Col>
long fn(Col const& col)
{
    auto c = count_if(begin(col), end(col),[](typename Col::value_type x){ return !(x%2);});
    //auto c = count_if(begin(col), end(col), isEven());
    return  c;
}

void Lambda::func1()
{
    vector<int> vect = {2,5,9,7,6,4,3,2,5,6,9,88};
    uint64_t  sm = 0;
    for_each(vect.begin(), vect.end(), [&sm](int x){sm+= x;});
    cout << "sm of lambda vect: " << sm <<endl;
    cout << "cnt of lambda vect: " << fn (vect) << endl;
}

void Lambda::checkLambdaFncs() {
    func1();
}
