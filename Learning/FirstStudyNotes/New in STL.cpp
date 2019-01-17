Containers:
    <array>
        New in C++11 and TR1. Provides the container class template std::array, a container for a fixed sized array.
    <bitset>
        Provides the specialized container class std::bitset, a bit array.
    <deque>
        Provides the container class template std::deque, a double-ended queue.
    <forward_list>
        New in C++11 and TR1. Provides the container class template std::forward_list, a singly linked list.
    <list>
        Provides the container class template std::list, a doubly linked list.
    <map>
        Provides the container class templates std::map and std::multimap, sorted associative array and multimap.
    <queue>
        Provides the container adapter class std::queue, a single-ended queue, and std::priority_queue, a priority queue.
    <set>
        Provides the container class templates std::set and std::multiset, sorted associative containers or sets.
    <stack>
        Provides the container adapter class std::stack, a stack.
    <unordered_map>
        New in C++11 and TR1. Provides the container class template std::unordered_map and std::unordered_multimap, hash tables.
    <unordered_set>
        New in C++11 and TR1. Provides the container class template std::unordered_set and std::unordered_multiset.
    <vector>
        Provides the container class template std::vector, a dynamic array. 

General
    <algorithm>
        Provides definitions of many container algorithms.
    <chrono>
        Provides time elements, such as std::chrono::duration, std::chrono::time_point, and clocks.
    <functional>
        Provides several function objects, designed for use with the standard algorithms.
    <iterator>
        Provides classes and templates for working with iterators.
    <memory>
        Provides facilities for memory management in C++, including the class template std::unique_ptr.
    <stdexcept>
        Contains standard exception classes such as std::logic_error and std::runtime_error, both derived from std::exception.
    <tuple>
        New in C++11 and TR1. Provides a class template std::tuple, a tuple.
    <utility>
        Provides the template class std::pair, for working with object pairs (two-member tuples), and the namespace std::rel_ops, for easier operator overloading.

Localization
    <locale>
    <codecvt>

Strings
    <string>
    <regex>

Streams and Input/Output
    <fstream>
        Provides facilities for file-based input and output. See fstream.
    <iomanip>
        Provides facilities to manipulate output formatting, such as the base used when formatting integers and the precision of floating point values.
    <ios>
        Provides several types and functions basic to the operation of iostreams.
    <iosfwd>
        Provides forward declarations of several I/O-related class templates.
    <iostream>
        Provides C++ input and output fundamentals. See iostream.
    <istream>
        Provides the template class std::istream and other supporting classes for input.
    <ostream>
        Provides the template class std::ostream and other supporting classes for output.
    <sstream>
        Provides the template class std::stringstream and other supporting classes for string manipulation.
    <streambuf>
        Provides reading and writing functionality to/from certain types of character sequences, such as external files or strings.

Language support
    <exception>
            Provides several types and functions related to exception handling, including std::exception, the base class of all exceptions thrown by the Standard Library.
    <limits>
            Provides the template class std::numeric_limits, used for describing properties of fundamental numeric types.
    <new>
            Provides operators new and delete and other functions and types composing the fundamentals of C++ memory management.
    <typeinfo>
            Provides facilities for working with C++ run-time type information. 

Thread support library
    <thread>
        New in C++11. Provide class and namespace for working with threads.
    <mutex>
        New in C++11. 30.4-1 This section provides mechanisms for mutual exclusion: mutexes, locks, and call once.
    <condition_variable>
        New in C++11. 30.5-1 Condition variables provide synchronization primitives used to block a thread until notified by some other thread that some condition is met or until a system time is reached.
    <future>
        New in C++11. 30.6.1-1 Describes components that a C++ program can use to retrieve in one thread the result (value or exception) from a function that has run in the same thread or another thread.

Numerics library
Components that C++ programs may use to perform seminumerical operations.
    <complex>
        The header <complex> defines a class template, and numerous functions for representing and manipulating complex numbers.
    <random>
        Facility for generating (pseudo-)random numbers
    <valarray>
        Defines five class templates (valarray, slice_array, gslice_array, mask_array, and indirect_array), two classes (slice and gslice),and a series of related function templates for representing and manipulating arrays of values.
    <numeric>
        Generalized numeric operations. 