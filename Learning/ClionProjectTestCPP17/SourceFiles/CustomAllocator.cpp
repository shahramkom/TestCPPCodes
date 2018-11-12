//
// Created by Shahram on 11/11/2018.
//

#include "../HeaderFiles/CustomAllocator.h"
#include "../HeaderFiles/Includes.h"
using namespace std;

CustomAllocator::CustomAllocator() {}

template <typename type>
struct MyAlloc : allocator<type>{
    type * allocate(size_t size){
        cout  << "alloc size: " << size <<endl;
        return new type[size];
    }
    void deallocate(type* ptr, size_t size){
        cout  << "deAlloc size: " << size <<endl;
        delete[] ptr;
    }
};

void CustomAllocator::allocat() {
    vector<int, MyAlloc<int>> v1;
    v1.push_back(10);

    for (auto & var : v1) {
        cout <<var <<endl;
    }
}

