//
// Created by Shahram on 11/8/2018.
//

#ifndef TEST17_CLASSTEMPLATESFINAE_H
#define TEST17_CLASSTEMPLATESFINAE_H

#include "Includes.h"

template <typename T, typename Enable = void>
class foo;
template <typename T>
class foo<T, typename std::enable_if<std::is_integral<T>::value>::type>
{ };
template <typename T>
class foo<T, typename std::enable_if<std::is_floating_point<T>::value>::type>
{ };



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


#endif //TEST17_CLASSTEMPLATESFINAE_H
