#include <stdafx.h>
template<typename InputIterator1, typename InputIterator2, typename OutputIterator>
OutputIterator algo(InputIterator1 first1, InputIterator1 last1,
	InputIterator2 first2, InputIterator2 last2,
	OutputIterator result);

template<typename InputIterator1, typename InputIterator2>
bool std::includes(InputIterator1 first1, InputIterator1 last1,
	InputIterator2 first2, InputIterator2 last2);

template<typename InputIterator1, typename InputIterator2, typename OutputIterator>
OutputIterator merge(InputIterator1 first1, InputIterator1 last1,
	InputIterator2 first2, InputIterator2 last2, OutputIterator result);



//first is the beginning of the collection, which is also the beginning of the first part,
//middle is the beginning of the second part of the collection,
//last is the end of the collection, which is also the end of its second part.
template<typename BidirectionalIterator>
void inplace_merge(BidirectionalIterator first, BidirectionalIterator middle, BidirectionalIterator last);

int main()
{

	vector<int> A = { 1,2,3,4,5,6,7,8,9 };// sorted vector
	set<int> B = { 10,20,30,40,50,60,70,80,90 }; // std::set is always sorted
	vector<int> results;

	algo(A.begin(), A.end(), B.begin(), B.end(), results);

	std::set_difference(A.begin(), A.end(),
		B.begin(), B.end(),
		std::back_inserter(results));

	bool AincludesB = std::includes(A.begin(), A.end(), B.begin(), B.end());

	std::merge(A.begin(), A.end(), B.begin(), B.end(), results);

}