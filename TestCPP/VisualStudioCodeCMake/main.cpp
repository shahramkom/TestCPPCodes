#include <iostream>
#include <chrono>
#include <experimental/optional>
#include <Windows.h>

int main()
{
    std::cout << "hello start1" << std::endl;
    HANDLE hand = CreateSemaphore(nullptr, 5, 5, "MySem");

    std::cout << "hello end2" << std::endl;
    return 0;
}