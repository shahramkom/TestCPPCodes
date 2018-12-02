#include "../HeaderFiles/ArrayView.h"
#include "../HeaderFiles/Includes.h"

#include <amp.h>
#include <cassert>
using namespace concurrency;
using std::vector;

ArrayView::ArrayView()
{
}
void ArrayView::samples()
{
	// matrixC = matrixA X matrixB
	// matrixD = matrixC X matrixA
	// pA, pB, pC and pD are pointers and contain the contents of 
	// matrixA, matrixB, matrixC and matrixD respectively in CPU memory
	int N = 2;
	float pA[2]{ 1.2,2.3 };
	float pB[2]{ 2.2,5.3 };
	float pC[2]{ 3.2,4.3 };
	array_view<const float, 2> matrixA(N, N, pA);
	array_view<const float, 2> matrixB(N, N, pB);
	array_view<float, 2> matrixC(N, N, pC);
	matrixC.discard_data();


	// array_views "matrixA" and "matrixB" are captured in this parallel_for_each
	// and the data is implicitly transferred from the CPU (pA, pB) to the accelerator

	//TODO
	//parallel_for_each(matrixC.extent, [=](index<1> idx) restrict(amp) {
	//	MatrixMultiplyKernel(idx, matrixA, matrixB, matrixC);
	//});

	float pD[2]{ 14.2,23.3 };
	array_view<float, 2> matrixD(N, N, pD);
	matrixD.discard_data();


	// array_views "matrixC" and "matrixA" are captured in the parallel_for_each.
	// Since their contents are already cached on the accelerator no data transfers
	// are performed by the runtime.

	//TODO
	//parallel_for_each(matrixD.extent, [=](index<1> idx) restrict(amp) {
	//	MatrixMultiplyKernel(idx, matrixC, matrixA, matrixD);
	//});


	// The contents of "matrixC" and "matrixD" are implicitly transferred
	// from the accelerator to the CPU when the array_views are accessed on the CPU
	float firstC = matrixC(0, 0);
	float firstD = matrixD(0, 0);
	// Multiple array_views created from the same array share the same data source
	// and are guaranteed to be coherent

	array<int> array_data(10);
	array_view<int> array_data_view1(array_data); // OK, array_data is the data source
	array_view<int> array_data_section_view(array_data.section(0, 5)); // OK, array_data is the data source
	array_view<int> array_data_view1_alias(array_data);                // OK, array_data is the data source
	parallel_for_each(extent<1>(1), [=](index<1>) restrict(amp) { array_data_section_view[2] = 15; });

	assert(array_data_view1[2] == array_data_section_view[2]);       // OK, never fails, both equal 15
	assert(array_data_section_view[2] == array_data_view1_alias[2]); // OK, never fails, both equal 15

	int storage[10];
	array_view<int> storage_view(10, &storage[0]);
	// Note: "storage_bad_alias_view" is a top-level array_view and incorrectly aliases
	// another top level array_view "storage_view" since both of them are created
	// over the same raw "storage" independently. array_views aliased in this fashion
	// are not guaranteed to appear coherent; i.e. modifications made through one
	// array_view may not be visible when accessing the other array_view

	array_view<int> storage_bad_alias_view(10, &storage[0]);
	parallel_for_each(extent<1>(1), [=](index<1>) restrict(amp) { storage_bad_alias_view[7] = 16; });
	parallel_for_each(extent<1>(1), [=](index<1>) restrict(amp) { storage_view[7] = 17; });
	assert(storage_view[7] == storage_bad_alias_view[7]); // undefined results

	// The array_view "storage_good_alias_view" is OK as it is 
	// created from the top-level array_view "storage_view"
	array_view<int> storage_good_alias_view(storage_view);
	parallel_for_each(extent<1>(1), [=](index<1>) restrict(amp) { storage_good_alias_view[7] = 16; });
	parallel_for_each(extent<1>(1), [=](index<1>) restrict(amp) { storage_view[7] = 22; });
	assert(storage_view[7] == storage_good_alias_view[7]); // OK, never fails, both equal 22

	const size_t size = 5;
	std::vector<int> sourceData(size, 2);
	array_view<int> view(size, sourceData);
	array_view<int> view1 = view.section(0, size / 2 + 1);
	array_view<int> view2 = view.section(size / 2 - 1, size / 2 + 1); // Overlaps "view1"

	concurrency::task<void> asyncCPUTask([&]() {
		view1[0]++;
	});

	// Undefined behavior: Accessing "view1" when another access to "view1" 
	// (by asyncCPUTask above) may be concurrently in progress,
	// even if different elements of the "view1" are accessed by the concurrent
	// operations
	parallel_for_each(extent<1>(1), [=](index<1> idx) restrict(amp) {
		view1[1]++;

	});

	asyncCPUTask.get();
	// OK to access "view1" after the concurrent accesses are synchronized (asyncCPUTask.get())
	view1[0]++;

	std::vector<int> outData(size);
	auto fut = copy_async(view2, outData.begin());
	// Incorrect: Illegal to access "view1" since an asynchronous copy operation
	// on an overlapping array_view "view2" is in flight.
	parallel_for_each(extent<1>(1), [=](index<1> idx) restrict(amp) {
		view1[1]++;
	});


	array_view<const int> readOnlyView1(view1);
	// OK to access "readOnlyView1" in read-only fashion when the concurrent copy
	// operation is accessing the overlapping array_view "view2" only for reading
	int value = readOnlyView1[0];
}

void ArrayView::testArrayView()
{
	// a small data size for example
	// a sample constrain require data to be equal and power of 2
	int width = 16;
	int height = 16;
	// generate dummy data
	vector<float> data(width * height);
	for (int x = 0; x < (width * height); x++)
	{
		data[x] = x * 1.0f;
	}
	// wrap data so it is ready to copy to accelerator
	array_view<float, 2> qin(height, width, data);
	// repeat reduction
	// till data can't be reduced
	while (width > 1)
	{
		height /= 2;
		width /= 2;
		extent<2> quarterdim(height, width);
		array<float, 2> qout(quarterdim);
		// view the data in 4 quarters 
		// create an array_view with offset to each quarters
		const array_view<const float, 2> q1 =
			qin.section(index<2>(0, 0) /*origin*/, quarterdim /*extent*/);
		const array_view<const float, 2> q2 =
			qin.section(index<2>(height, 0), quarterdim);
		const array_view<const float, 2> q3 =
			qin.section(index<2>(0, width), quarterdim);
		const array_view<const float, 2> q4 =
			qin.section(index<2>(height, width));
		// execute the kernel to accumulate all quarters into the first one
		parallel_for_each(quarterdim, [=, &qout](index<2> idx) restrict(amp)
		{
			// accumulate all quarters in output quarter
			// using same index but in different section
			qout[idx] = q1[idx] + q2[idx] + q3[idx] + q4[idx];
		});
		// set output data array as input view
		// for next loop
		// NOTE: that doesn't sync data from GPU to host
		qin = qout;
		// only for demo, print output data
		// transition after every iteration
		printf("\n");
		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				// accessing qin here force sync that quarter back to host
				// this cause a performance hit 
				printf("%0.1f ", qin(y, x));
			}
			printf("\n");
		}
		printf("===============================================\n");
	} // while loop
	// final summation result can be obtained from

	// qin(0,0) here

}
