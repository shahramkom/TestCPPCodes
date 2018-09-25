/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <type_traits>

using namespace std;

enum class my_e {
       e1,
       e2
    };
    
int main()
{
    typedef std::integral_constant<int, 2> two_t;
    typedef std::integral_constant<int, 4> four_t;
    typedef std::integral_constant<uint64_t, UINT64_MAX> max_int64;
    
    cout << max_int64::value <<endl;
    
    static_assert(two_t::value*2 == four_t::value,"2*2 != 4");
    typedef std::integral_constant<my_e, my_e::e1> my_e_e1;
    typedef std::integral_constant<my_e, my_e::e2> my_e_e2; 
    static_assert(std::is_same<my_e_e2, my_e_e2>::value,"my_e_e2 != my_e_e2");
}
