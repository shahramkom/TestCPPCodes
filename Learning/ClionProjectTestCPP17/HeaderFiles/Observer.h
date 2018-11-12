//
// Created by Shahram on 11/8/2018.
//

#ifndef TEST17_OBSERVER_H
#define TEST17_OBSERVER_H


#include "Includes.h"

class observer
{
public:
    virtual void notify() = 0;
};
class observer_concrete : public observer
{
public:
    virtual void notify() override
    { }
};
class subject
{
public:
    void register_observer(observer& o)
    {
        observers.push_back(o);
    }
    void notify_observers()
    {
        for (observer& o : observers) {
            o.notify();
        }
    }
private:
    std::vector<std::reference_wrapper<observer>> observers;
};


#endif //TEST17_OBSERVER_H
