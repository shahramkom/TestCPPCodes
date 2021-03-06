// DesignPatterns.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <chrono>
#include <time.h>
#include <unordered_set>
#include <unordered_map>

vector<int> uniqueArr(vector<int> arr)
{
	std::unordered_set<int> storedValues;
	vector<int> uniqueArr;
	for (int i = 0; i < arr.size(); ++i) {
		if (storedValues.insert(arr[i]).second)
			uniqueArr.emplace_back(arr[i]);
		return uniqueArr;
	}
}

vector<int> uniqueArrUMP(vector<int> arr)
{
	std::unordered_map<int, int> storedValues;
	vector<int> uniqueArr;
	for (int i = 0; i < arr.size(); ++i) {
		if(storedValues.insert(std::make_pair(arr[i], arr[i])).second)
			uniqueArr.emplace_back(arr[i]);
		return uniqueArr;
	}
}

void DeleteDuplicates_vector_bool(std::vector<int>& v, unsigned range_size)
{
	std::vector<bool> v1(range_size);
	for (auto& x : v)
	{
		v1[x] = true;
	}
	v.clear();

	unsigned count = 0;
	for (auto x : v1)
	{
		if (x)
		{
			v.emplace_back(count);
		}
		++count;
	}
}

void EraseVectorRepeats(vector <int> & v) {
TOP:for (int y = 0; y < v.size();++y) {
	for (int z = 0; z < v.size();++z) {
		if (y == z) { //This if statement makes sure the number that it is on is not erased-just skipped-in order to keep only one copy of a repeated number
			continue;
		}
		if (v[y] == v[z]) {
			v.erase(v.begin() + z); //whenever a number is erased the function goes back to start of the first loop because the size of the vector changes
			goto TOP;
		}
	}
}
}

int mainTest()
{
	vector<int> v = { 1, 1, 3, 3, 3, 10, 1, 3, 3, 7, 7, 8 }, i;

	for (int i = 0; i < 2 * 1000 * 1000; i++)
	{
		v.emplace_back(1);
		v.emplace_back(5);
		v.emplace_back(3);
		v.emplace_back(4);
		v.emplace_back(2);
		v.emplace_back(10);
		v.emplace_back(50);
		v.emplace_back(30);
		v.emplace_back(40);
		v.emplace_back(20);
	}

//	590													<<<P7_1 Without search, P7_2 With Search>>>
// 	auto start = std::chrono::steady_clock::now();
// 	vector<int>uniArr = uniqueArrUMP(v);
// 	auto duration = std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - start);
// 	cout << duration.count() << endl;

// 85 315    *1440# slower than previous
// 	auto start = std::chrono::steady_clock::now();
// 	unordered_map<int, int> mp;
// 	for (const auto & it : v)
// 	{
// 		auto search = mp.find(it);
// 		if (search == mp.end())
// 			mp[it] = it;
// 	}
// 	auto duration = std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - start);
// 	cout << duration.count() << endl;

//_____________________________________________________________________________________________________

//	630
// 	auto start = std::chrono::steady_clock::now();
// 	vector<int>uniArr = uniqueArr(v);
// 	auto duration = std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - start);
// 	cout << duration.count() << endl;

//	1 212													<<<ME , P6 With Search, EV Without Search>>>>
// 	auto start = std::chrono::steady_clock::now();
// 	ip = std::unique(v.begin(), v.end());
// 	v.resize(std::distance(v.begin(), ip));
// 	auto duration = std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - start);
//  	cout<< duration.count() << endl;

//	10 633
// 	auto start = std::chrono::steady_clock::now();
// 	sort(v.begin(), v.end());
// 	v.erase(unique(v.begin(), v.end()), v.end());
// 	auto duration = std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - start);
// 	cout << duration.count() << endl;

// 87 866
// 	auto start = std::chrono::steady_clock::now();
// 	map<int, int> mp;
// 	for (const auto & it : v)
// 	{
// 		auto search = mp.find(it);
// 		if (search == mp.end())
// 			mp[it] = it;
// 	}
// 	auto duration = std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - start);
// 	cout << duration.count() << endl;

// 51 323
// 	auto start = std::chrono::steady_clock::now();
// 	DeleteDuplicates_vector_bool(v, v.size());
// 	auto duration = std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - start);
// 	cout << duration.count() << endl;

// 61 601
// 	auto start = std::chrono::steady_clock::now();
// 	set<int> values;
// 	v.erase(std::remove_if(v.begin(), v.end(), [&](const int & value) { return !values.insert(value).second; }), v.end());
// 	auto duration = std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - start);
// 	cout << duration.count() << endl;

// 69 703
// 	auto start = std::chrono::steady_clock::now();
// 	set<int> s;
// 	unsigned size = v.size();
// 	for (unsigned i = 0; i < size; ++i) s.insert(v[i]);
// 	v.assign(s.begin(), s.end());
// 	auto duration = std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - start);
// 	cout << duration.count() << endl;
	
// 171 895												<<<F A T T A H I, N A S I R I>>> With Search P7_2 Without Search
// 	auto start = std::chrono::steady_clock::now();
// 	set<int> s(v.begin(), v.end());
// 	v.assign(s.begin(), s.end());
// 	auto duration = std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - start);
// 	cout << duration.count() << endl;

// 55 850
// 	auto start = std::chrono::steady_clock::now();
// 	vector<int> mm;
// 	for (const auto & it : v)
// 	{
// 		if (find(mm.begin(), mm.end(), it) == mm.end())
// 			mm.emplace_back(it);
// 	}
// 	auto duration = std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - start);
// 	cout << duration.count() << endl;


//13 523 523												<<<P6 Without Search>>>>
// 	auto start = std::chrono::steady_clock::now();
// 	EraseVectorRepeats(v);
// 	auto duration = std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - start);
// 	cout << duration.count() << endl;

	getchar();
    return 0;
}

