// Threads.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <ppl.h>
#include <ppltasks.h>
#include <ppltaskscheduler.h>
#include <chrono>
#include <random>

using namespace std;
using namespace Concurrency;

int main()
{
	cout << "Hello World!\n";
	//concurrent_queue
	vector<int > c;
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	uniform_int_distribution<> dis(1, 1*1000*1000);

	for (auto i = 0; i < 1 * 1000 * 1000; i++)
		c.emplace_back(dis(gen));

	auto start1 = chrono::system_clock::now();
	parallel_sort(begin(c), end(c), greater<int>(), c.size()); //3.7
	auto end1 = chrono::system_clock::now();
	cout << chrono::duration_cast<chrono::milliseconds>(end1 - start1).count() <<endl;


	auto start2 = chrono::system_clock::now();
	sort(begin(c), end(c), [](int i, int j) {return i < j; }); // 3.4
	auto end2 = chrono::system_clock::now();
	cout << chrono::duration_cast<chrono::milliseconds>(end2 - start2).count() << endl;

	auto start3 = chrono::system_clock::now();
	partial_sort(begin(c), begin(c) + 1 * 1000 * 1000, end(c), [](int i , int j) {return i < j; });//4.2
	auto end3 = chrono::system_clock::now();
	cout << chrono::duration_cast<chrono::milliseconds>(end3 - start3).count() << endl;

	auto start4 = chrono::system_clock::now();
	stable_sort(begin(c), end(c), [](int i, int j) {return i < j; });//2.4
	auto end4 = chrono::system_clock::now();
	cout << chrono::duration_cast<chrono::milliseconds>(end4 - start4).count() << endl;


	
	//for(auto cs : c)
	//	printf("%d ", cs);
	
	getchar();

}
