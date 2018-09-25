#include "pch.h"
#include <iostream>

#include "BubbleSort.h"
#include "BubbleSort1.h"
#include "BucketSort.h"
#include "CombSort.h"
#include "CountingSort.h"
#include "CycleSort.h"
#include "HeapSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "PigeonholeSort.h"
#include "QuickSort.h"
#include "RadixSort.h"
#include "SelectionSort.h"
#include "ShellSort.h"

int main()
{
// Driver program to test above functions
	int sel_arr[] = { 64, 25, 12, 22, 11 };
	int sel_n = sizeof(sel_arr) / sizeof(sel_arr[0]);
	selectionSort(sel_arr, sel_n);
	printf("Sorted selection array: \n");
	printArray(sel_arr, sel_n);
	printf("\n");
	//////////////////////////////////////////////////////////////////////////
	int bub_arr[] = { 64, 34, 25, 12, 22, 11, 90 };
	int bub_n = sizeof(bub_arr) / sizeof(bub_arr[0]);
	bubbleSort(bub_arr, bub_n);
	printf("Sorted bubble array: \n");
	printArray(bub_arr, bub_n);
	printf("\n");
	//////////////////////////////////////////////////////////////////////////
	int bub1_arr[] = { 64, 34, 25, 12, 22, 11, 90 };
	int bub1_n = sizeof(bub1_arr) / sizeof(bub1_arr[0]);
	bubbleSort1(bub1_arr, bub1_n);
	printf("Sorted bubble 1 array: \n");
	printArray(bub1_arr, bub1_n);
	printf("\n");
	//////////////////////////////////////////////////////////////////////////
	int ins_arr[] = { 12, 11, 13, 5, 6 };
	int ins_n = sizeof(ins_arr) / sizeof(ins_arr[0]);
	insertionSort(ins_arr, ins_n);
	printf("Sorted insertions array: \n");
	printArray(ins_arr, ins_n);
	//////////////////////////////////////////////////////////////////////////
	int mrg_arr[] = { 12, 11, 13, 5, 6, 7 };
	int arr_size = sizeof(mrg_arr) / sizeof(mrg_arr[0]);
	printf("Given array is \n");
	printArray(mrg_arr, arr_size);
	mergeSort(mrg_arr, 0, arr_size - 1);
	printf("\nSorted merge array is \n");
	printArray(mrg_arr, arr_size);
	printf("\n");
	//////////////////////////////////////////////////////////////////////////
	int hep_arr[] = { 12, 11, 13, 5, 6, 7 };
	int hep_n = sizeof(hep_arr) / sizeof(hep_arr[0]);
	heapSort(hep_arr, hep_n);
	cout << "Sorted heap array is \n";
	printArray(hep_arr, hep_n);
	printf("\n");
	//////////////////////////////////////////////////////////////////////////
	int quck_arr[] = { 10, 7, 8, 9, 1, 5 };
	int quck_n = sizeof(quck_arr) / sizeof(quck_arr[0]);
	quickSort(quck_arr, 0, quck_n - 1);
	printf("Sorted Quick array: ");
	printArray(quck_arr, quck_n);
	printf("\n");
	//////////////////////////////////////////////////////////////////////////
	int rdx_arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
	int rdx_n = sizeof(rdx_arr) / sizeof(rdx_arr[0]);
	radixsort(rdx_arr, rdx_n);
	printArray(rdx_arr, rdx_n);
	//////////////////////////////////////////////////////////////////////////
	char cnt_arr[] = "geeksforgeeks";//"applepp"; 
	countSort(cnt_arr);
	printf("Sorted count character array is %sn\n", cnt_arr);
	printf("\n");
	//////////////////////////////////////////////////////////////////////////
	float buc_arr[] = { 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434 };
	int buc_n = sizeof(buc_arr) / sizeof(buc_arr[0]);
	bucketSort(buc_arr, buc_n);
	cout << "Sorted bucket array is \n";
	for (int i = 0; i < buc_n; i++)
		cout << buc_arr[i] << " ";
	printf("\n");
	//////////////////////////////////////////////////////////////////////////
	int a[] = { 8, 4, 1, 56, 3, -44, 23, -6, 28, 0 };
	int cmb_n = sizeof(a) / sizeof(a[0]);
	combSort(a, cmb_n);
	printf("Sorted comb array: \n");
	for (int i = 0; i < cmb_n; i++)
		printf("%d ", a[i]);
	printf("\n");
	//////////////////////////////////////////////////////////////////////////
	int pgl_arr[] = { 8, 3, 2, 7, 4, 6, 8 };
	int pgl_n = sizeof(pgl_arr) / sizeof(pgl_arr[0]);
	pigeonholeSort(pgl_arr, pgl_n);
	printf("Sorted pigeonhole order is : ");
	for (int i = 0; i < pgl_n; i++)
		printf("%d ", pgl_arr[i]);
	printf("\n\n");
	//////////////////////////////////////////////////////////////////////////
	int cyc_arr[] = { 1, 8, 3, 9, 10, 10, 2, 4 };
	int cyc_n = sizeof(cyc_arr) / sizeof(cyc_arr[0]);
	cycleSort(cyc_arr, cyc_n);
	cout << "After cycle sort : " << endl;
	for (int i = 0; i < cyc_n; i++)
		cout << cyc_arr[i] << " ";
	printf("\n\n");
	//////////////////////////////////////////////////////////////////////////
	int shl_arr[] = { 12, 34, 54, 2, 3 }, i;
	int shl_n = sizeof(shl_arr) / sizeof(shl_arr[0]);
	cout << "Array before shell sorting: \n";
	printArray(shl_arr, shl_n);
	shellSort(shl_arr, shl_n);
	cout << "\nArray after shell sorting: \n";
	printArray(shl_arr, shl_n);
	printf("\n");
	//////////////////////////////////////////////////////////////////////////
	getchar();
	return 0;
}