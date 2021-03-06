// AlgorithmsImp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include "BinarySearch.h"
#include "ExponentialSearch.h"
#include "InterpolationSearch.h"
#include "JumpSearch.h"
#include "TernarySearch.h"

int mainSearch()
{
	int bin_arr[] = { 2, 3, 4, 10, 40 };
	int bin_n = sizeof(bin_arr) / sizeof(bin_arr[0]);
	int bin_x = 10;
	int result = binarySearch(bin_arr, 0, bin_n - 1, bin_x);
	(result == -1) ? printf("binary Search Element is not present in array\n") : printf("binary Search Element is present at index %d\n", result);
	//////////////////////////////////////////////////////////////////////////
	  // be conducted.
	int int_arr[] = { 10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47 };
	int int_n = sizeof(int_arr) / sizeof(int_arr[0]);

	int int_x = 18; // Element to be searched
	int int_index = interpolationSearch(int_arr, int_n, int_x);

	// If element was found
	if (int_index != -1)
		printf("interpolation Search Element found at index %d\n", int_index);
	else
		printf("interpolation Search Element not found.\n");
	//////////////////////////////////////////////////////////////////////////
	int jmp_arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610 };
	int jmp_x = 55;
	int jmp_n = sizeof(jmp_arr) / sizeof(jmp_arr[0]);

	// Find the index of 'x' using Jump Search
	int jmp_index = jumpSearch(jmp_arr, jmp_x, jmp_n);

	// Print the index where 'x' is located
	cout << "jump Search Number " << jmp_x << " jump Search is at index " << jmp_index <<endl;
	//////////////////////////////////////////////////////////////////////////
	int exp_arr[] = { 2, 3, 4, 10, 40 };
	int exp_n = sizeof(exp_arr) / sizeof(exp_arr[0]);
	int exp_x = 10;
	int exp_result = exponentialSearch(exp_arr, exp_n, exp_x);
	(exp_result == -1) ? printf("exponential Search Element is not present in array\n") : printf("exponential Search Element is present at index %d\n", result);
	//////////////////////////////////////////////////////////////////////////
	int ter_arr[] = { 2, 3, 4, 10, 40 };
	int ter_n = sizeof(exp_arr) / sizeof(exp_arr[0]);
	int ter_x = 10;
	int ter_result = ternarySearch(ter_arr, 0, ter_n, ter_x);
	(ter_result == -1) ? printf("ternary Search Element is not present in array\n") : printf("ternary Search Element is present at index %d\n", result);

	getchar();
	return 0;
}
