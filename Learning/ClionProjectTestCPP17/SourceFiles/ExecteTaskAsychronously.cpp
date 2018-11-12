//
// Created by Shahram on 11/8/2018.
//

#include "../HeaderFiles/ExecteTaskAsychronously.h"
#include "../HeaderFiles/Includes.h"

int func()
{
    int some_value = 0;
    // Do work...
    return some_value;
}

ExecteTaskAsychronously::ExecteTaskAsychronously() {

}

void ExecteTaskAsychronously::execte() {
    std::future<int> result_future = std::async(func);
    // Do something...
    int result = result_future.get();
}
