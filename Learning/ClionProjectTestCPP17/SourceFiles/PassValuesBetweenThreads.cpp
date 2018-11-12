//
// Created by Shahram on 11/7/2018.
//

#include "../HeaderFiles/PassValuesBetweenThreads.h"
#include "../HeaderFiles/Includes.h"


void func(std::promise<int> result_promise) noexcept
{
    result_promise.set_value(42);
}
void PassValuesBetweenThreads::passValue()
{
    std::promise<int> result_promise;
    std::future<int> result_future = result_promise.get_future();
    std::thread t{func, std::move(result_promise)};
    int result = result_future.get();
    t.join();
}