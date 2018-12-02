// Threads.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <Windows.h>

auto __stdcall work(void*) -> DWORD
{
	TRACE(L"Work!");
	return  123;
}
int main()
{
	std::cout << "Hello World!\n";

	auto t = null_handle{
		CreateThread(nullptr, 0 , work ,nullptr, 0, nullptr)
	};

	if (t)
	{
		VERIFY_(WAIT_OBJECT_0, WaitForSingleObject(t.get(), INFINITE));
	}
	getchar();

}
