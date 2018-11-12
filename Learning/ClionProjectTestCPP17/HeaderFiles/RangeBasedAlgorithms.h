//
// Created by Shahram on 11/7/2018.
//

#ifndef TEST17_RANGEBASEDALGORITHMS_H
#define TEST17_RANGEBASEDALGORITHMS_H


#include <initializer_list>

class RangeBasedAlgorithms {
public:
    RangeBasedAlgorithms()= default;
    template <typename ForwardRange>
    void doWork(ForwardRange& range)
    {
        using std::begin;
        using std::end;
        using iterator = decltype(begin(range));
        iterator it_begin = begin(range);
        iterator it_end = end(range);
        // Now use it_begin and it_end to implement algorithm
    }
};


#endif //TEST17_RANGEBASEDALGORITHMS_H
