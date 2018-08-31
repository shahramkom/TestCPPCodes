#include <stdafx.h>

template <typename ForwardIterator1, typename ForwardIterator2>
ForwardIterator1 find_first_of(ForwardIterator1 first, ForwardIterator1 last,
	ForwardIterator2 s_first, ForwardIterator2 s_last);


template <typename ForwardIterator, typename OutputIterator>
OutputIterator mergeAdjacent(ForwardIterator first, ForwardIterator last, OutputIterator results)
{
	ForwardIterator beginUnique = first;
	while (beginUnique != last)
	{
		// output all unique elements; stop when finding indentical adjacent ones
		ForwardIterator endUnique = std::adjacent_find(beginUnique, last);
		results = std::copy(beginUnique, endUnique, results);

		// identify the range of identical adjacent elements
		ForwardIterator beginIdentical = endUnique;
		ForwardIterator endIdentical = std::find_if(beginIdentical, last, [beginIdentical](const auto& element) {return element != *beginIdentical; });

		// aggregate identical flows into one
		if (beginIdentical != endIdentical)
		{
			*results = std::accumulate(beginIdentical, endIdentical, typename ForwardIterator::value_type());
			++results;
		}
		beginUnique = endIdentical;
	}
	return results;
}

//is very similar to a substring search inside a string
template <typename ForwardIterator1, typename ForwardIterator1>
ForwardIterator1 search(ForwardIterator1 first, ForwardIterator1 last,
	ForwardIterator2 s_first, ForwardIterator2 s_last);

//searches for a subrange constitued of n times the same value
template <typename ForwardIterator, typename Size, class T>
ForwardIterator search_n(ForwardIterator first, ForwardIterator last, Size n, const T& value);

template <typename ForwardIterator1, typename ForwardIterator2>
ForwardIterator1 find_end(ForwardIterator1 first, ForwardIterator1 last,
	ForwardIterator2 s_first, ForwardIterator2 s_last);

int main()
{
	vector<int> v = { 1, 4, 5, 5, 3, 42, 7, 7, 7, 7, 3, 9 };
	vector<int> results;

	//It finds the first occurrence of several identical elements with std::adjacent_find:
	auto endUnique = std::adjacent_find(beginUnique, last);

	//All elements before this point are different from their immediate neighbours, so we want to keep them in the output :
	std::copy(beginUnique, endUnique, results);

	//Then it works out until what point the consecutive elements are identical :
	/*ForwardIterator*/auto endIdentical = std::find_if(beginIdentical, last, [beginIdentical](const auto& element) {return element != *beginIdentical; });

	//These identical elements are added up together(which can be customized if you want to do something different from just adding for merging elements) :
	*results = std::accumulate(beginIdentical, endIdentical, typename ForwardIterator::value_type());

	mergeAdjacent(v.begin(), v.end(), back_inserter(results));
	// results now contains: 1 4 10 3 42 28 3 9  
}