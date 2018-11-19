//
// Created by Shahram on 11/11/2018.
//
#include "../HeaderFiles/Includes.h"
#include "../HeaderFiles/ChangeAlgorithms.h"
#include <random>
using namespace std;

ChangeAlgorithms::ChangeAlgorithms() {}

vector<int> vect1 = { 10,20,30,40,50,60,70,80,90 };
vector<int> vect2 = { 1,2,3,4,5,6,7,8 };
vector<int> vect3 = { 0,0,0,0,0,0,0,0,0,0,0,0 };


void ChangeAlgorithms::changeFnc() {
	copy(vect1.begin(), vect1.end(), vect3.begin());
	copy_if(vect1.begin(), vect1.end(), vect2.begin(), [](int x) { return x > 80; });
	copy_n(vect1.begin(), 4, vect2.begin());
	//TODO
	//copy_backward(vect1.begin(), vect1.end(), vect3.begin());
	//move(vect1.begin(), vect1.end(), vect2.begin());
	//move_backward(vect1.begin(), vect1.end(), vect2.end());

	transform(vect1.begin(), vect1.end(), vect3.begin(), [](int x) { return x - 1; });
	//transform(vect1.begin(), vect1.end(), vect2.begin(), vect3.begin(), [](int x, int y) { return x + y; }); //vect3[0] = vect2[0]+vect1[0]

	//swap_ranges(vect1.begin(), vect1.end(), vect2.begin());

	fill(vect1.begin(), vect1.end(), 2);
	fill_n(vect1.begin(), 3, 9);
	generate(vect1.begin(), vect1.end(), rand);
	generate_n(vect1.begin(), 3, rand);

	replace(vect1.begin(), vect1.end(), 6, 9);
	replace_if(vect1.begin(), vect1.end(), [](int x) { return x > 80; }, 9);
	//replace_copy(vect1.begin(), vect1.end(), vect2.begin(), 6, 9);

	remove(vect1.begin(), vect1.end(), 6);
	remove_if(vect1.begin(), vect1.end(), [](int x) { return x > 80; });
	//remove_copy(vect1.begin(), vect1.end(), vect2.begin(), 6);

	unique(vect1.begin(), vect1.end());
	unique(vect1.begin(), vect1.end(), less<int>());
	unique_copy(vect1.begin(), vect1.end(), vect2.begin());

	reverse(vect1.begin() + 1, vect1.end() - 1);
	reverse_copy(vect1.begin() + 1, vect1.end() - 1, vect2.begin());

	rotate(vect1.begin(), vect1.begin() + 3, vect1.end());

	//rotate_copy(vect1.begin(), vect1.end() + 3, vect1.begin(), vect2.begin());

	next_permutation(vect1.begin(), vect1.end());
	prev_permutation(vect1.begin(), vect1.end());

	//shuffle(vect1.begin(), vect1.end(), default_random_engine);
}

void ChangeAlgorithms::nonChangeFnc() {
	auto m = count(vect1.begin(), vect1.end(), 69);
	m = count_if(vect1.begin(), vect1.end(), [](int x) { return x > 10; });

	auto sm = max_element(vect1.begin() + 2, vect1.end());
	sm = min_element(vect1.begin(), vect1.end());
	auto pair_of_itr = minmax_element(vect1.begin(), vect1.end(), [](int x, int y) { return (x % 10) < (y % 10); });

	sm = find(vect1.begin(), vect1.end(), 69);
	sm = find_if(vect1.begin(), vect1.end(), [](int x) { return x > 10; });
	sm = find_if_not(vect1.begin(), vect1.end(), [](int x) { return x > 10; });

	sm = search_n(vect1.begin(), vect1.end(), 2, 69);
	sm = search(vect1.begin(), vect1.end(), vect2.begin(), vect2.end());

	sm = find_end(vect1.begin(), vect1.end(), vect2.begin(), vect2.end());

	sm = find_first_of(vect1.begin(), vect1.end(), vect2.begin(), vect2.end());
	sm = find_first_of(vect1.begin(), vect1.end(), vect2.begin(), vect2.end(), [](int x, int y) { return (x == y * 10); });

	sm = adjacent_find(vect1.begin(), vect1.end());
	sm = adjacent_find(vect1.begin(), vect1.end(), [](int x, int y) { return (x == y * 10); });

	//TODO
	//bool er = equal(vect1.begin(), vect1.end(), vect2.begin());
	//bool er = is_permutation(vect1.begin(), vect1.end(), vect2.begin());

	//auto mis = mismatch(vect1.begin(), vect1.end(), vect2.begin());
	lexicographical_compare(vect1.begin(), vect1.end(), vect2.begin(), vect2.end());

	bool er = is_sorted(vect1.begin(), vect1.end());
	auto sitr = is_sorted_until(vect1.begin(), vect1.end());
	auto itr = is_partitioned(vect1.begin(), vect1.end(), [](int x) { return x > 10; });
	er = is_heap(vect1.begin(), vect1.end());
	sitr = is_heap_until(vect1.begin(), vect1.end());

	all_of(vect1.begin(), vect1.end(), [](int x) { return x > 10; });
	any_of(vect1.begin(), vect1.end(), [](int x) { return x > 10; });
	none_of(vect1.begin(), vect1.end(), [](int x) { return x > 10; });

}

void ChangeAlgorithms::Sorting() {
	sort(vect1.begin(), vect1.end());
	sort(vect1.begin(), vect1.end(), [](int x, int y) { return (x % 10) < (y % 10); });
	partial_sort(vect1.begin(), vect1.begin() + 5, vect1.end(), greater<int>());
	partial_sort(vect1.begin(), vect1.begin() + 5, vect1.end());
	nth_element(vect1.begin(), vect1.begin() + 5, vect1.end(), greater<int>());
	partition(vect1.begin(), vect1.begin() + 5, [](int x) { return (x < 10); });
	stable_partition(vect1.begin(), vect1.begin() + 5, [](int x) { return x < 10; });

	make_heap(vect1.begin(), vect1.end());
	pop_heap(vect1.begin(), vect1.end());
	sort_heap(vect1.begin(), vect1.end());
}

void ChangeAlgorithms::NumericAlgs() {
	bool fn = binary_search(vect1.begin(), vect1.end(), 9);
	//TODO
	//fn = includes(vect1.begin(), vect1.end(), vect2.begin(), vect2.end());

	auto itr = lower_bound(vect1.begin(), vect1.end(), 9);
	itr = upper_bound(vect1.begin(), vect1.end(), 9);
	auto pitr = equal_range(vect1.begin(), vect1.end(), 9);

	//merge(vect1.begin(), vect1.end(), vect2.begin(), vect2.end(), vect3.begin());

	//inplace_merge(vect1.begin(), vect1.end() + 4, vect1.end());

	//set_union(vect1.begin(), vect1.end(), vect2.begin(), vect2.end(), vect3.begin());
	//set_intersection(vect1.begin(), vect1.end(), vect2.begin(), vect2.end(), vect3.begin());
	//set_difference(vect1.begin(), vect1.end(), vect2.begin(), vect2.end(), vect3.begin());
	//set_symmetric_difference(vect1.begin(), vect1.end(), vect2.begin(), vect2.end(), vect3.begin());

	int x = accumulate(vect1.begin(), vect1.end(), 10);
	x = accumulate(vect1.begin(), vect1.end(), 10, multiplies<int>());
	x = inner_product(vect1.begin(), vect1.begin() + 3, vect1.end() - 3, 10); //10+ vect2[0]*vect1[4]+vect1[2]*vect1[5]+vect1[3]*vect1[6]
	x = inner_product(vect1.begin(), vect1.begin() + 3, vect1.end() - 3, 10, multiplies<int>(), plus<int>()); //10+ vect2[0]*vect1[4]+vect1[2]*vect1[5]+vect1[3]*vect1[6]

	//partial_sum(vect1.begin(), vect1.end(), vect2.begin()); //vect2[3] = vect1[0]+vect1[1]+vect1[2]+vect1[3];
	//partial_sum(vect1.begin(), vect1.end(), vect2.begin(), multiplies<int>()); //vect2[3] = vect1[0]+vect1[1]+vect1[2]+vect1[3];

	//adjacent_difference(vect1.begin(), vect1.end(), vect2.begin()); //vect2[3] = vect1[3]-vect1[2]-vect1[1]-vect1[0];
	//adjacent_difference(vect1.begin(), vect1.end(), vect2.begin(), plus<int>());
}



