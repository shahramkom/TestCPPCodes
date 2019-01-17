Whats new in C++ 11

• auto for variable type deduction
• {}(almost) uniform initialization
• Lamdas - anonymous functions/functors
• Move-semantic, move-only types
• enums - strongly typed and scoped, constexpr
• <T>better template meta programming support
• variadic templates, type traits
• several library additions: function, tuple, regex
• smart pointers for memory management

multi-threading, memory model, thread_local
• library: thread, mutex, timed_mutex,
condition_variable
• range-for + easier algorithm use with lambdas
• inheriting/delegating ctors, =delete, =default,
non-static member initializers (NSDMI)
• constexpr functions and literal types
• noexcept spec instead of throw()
• decltype(expr) for type specification
• User-defined Literals - suffixes: 42_km, 4_min

auto for function return type deduction
• Move-ability removes Copy-ability
• Lamdas - generic and variadic
• relaxed constexpr requirements (near full C++)
• make_unique<T>
• even better template meta programming
• more convenient type_traits, tuples,
• variable templates

UDL operators for std::string, duration and complex
•“hello”s, 10s, 100ms, 3+5i
• binary literals and digit separators
•0b1010, 0b0’1000’1111, 1’234’567.890’123
• shared_timed_mutex (untimed to come)
• heterogeneous lookup in associative containers
• set<string> can efficiently find “literals”
• heterogeneous standard functors, i.e., plus<>

what’s next ?

Library Fundamentals TS
• optional<T> - optional values
• boyer_moore_searcher - efficient search!
• any - represent a value of arbitrary type
• string_view - low-overhead wrapper for character sequences (no memory management)
• polymorphic allocators - pooling, etc.
• sample() algorithm - random sampling
• apply() - call function with args from a tuple
• File System TS - standardized file access
• Dynamic arrays - (in C VLAs, but not the same)
• Feature test macros TS - version portability
• Parallel TS - vector(gpu?) and multi-core
• Concurrency TS - tasks, thread pools,continuations, executors
• Transactional memory TS - STM for C++
• Concepts-lite TS - categories for template Args


Memory
• use make_shared<Derived>(…) to create them
• Works like Java/C# garbage collected references
• Sidesteps the need to define ~Base() destructor
• shared_ptr will memorize the required derived class destructor
• Overhead for reference counting is there
• plain unique_ptr<Base> doesn’t work without virtual destructor…

• A custom polymorphic destructor can solve the efficiency overhead of shared_ptr, when only one reference to a heap-allocated polymorphic
    object can exist. Requires a little more overhead than plain unique_ptr
• Won’t go into details here, similar to a unique_ptr<Base,std::function<void(Base*)>>
• Might be proposed for a future version of the standard

• Do not use raw Pointers or self-allocated buffers from the heap!
• use smart pointers & standard library classes for managing resources.

