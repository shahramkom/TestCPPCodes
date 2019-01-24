//
// Created by Shahram on 11/7/2018.
//

#include "../HeaderFiles/ApplyTupleFunction.h"
#include "../HeaderFiles/Includes.h"

template<typename F, typename Tuple, size_t ...S >
decltype(auto) apply_tuple_impl(F&& fn, Tuple&& t, std::index_sequence<S...>)
{
    return std::forward<F>(fn)(std::get<S>(std::forward<Tuple>(t))...);
}
template<typename F, typename Tuple>
decltype(auto) apply_from_tuple(F&& fn, Tuple&& t)
{
    std::size_t constexpr tSize
        = std::tuple_size<typename std::remove_reference<Tuple>::type>::value;
    return apply_tuple_impl(std::forward<F>(fn),
                            std::forward<Tuple>(t),
                            std::make_index_sequence<tSize>());
}
int ApplyTupleFunction::doSum(int a, int b)
{
    return a + b;
}
int ApplyTupleFunction::applyTuple()
{
    return apply_from_tuple(doSum, std::make_tuple(10, 20));
}
