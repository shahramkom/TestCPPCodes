for (std::vector<int>::const_iterator itr = myvector.cbegin(); itr != myvector.cend(); ++itr)

auto x = 5; // x will be type int
auto y = 5.5; // y will be type double
auto z = y; // z will be type double
auto w = "hi"; // w will be type const char*

decltype(5) x; // x will be type int because 5 is an int
decltype(x) y = 6; // y will be type int because x is an int
auto z = x; // z will type type int

const std::vector<int> v(5); // declare a vector v
auto a = v[0]; // a will be type int because v[0] is an int
decltype(v[0]) b = 1; // b will be type const int&, which is the return type of std::vector<int>::operator[](size_type) const

int *p = 1; // illegal, can't assign an int to an int* variable
int *q = 0; // legal, 0 has a special meaning as a null pointer

int main()
{
    enum class Color
    {
        RED,
        BLUE
    };
    enum class Fruit
    {
        BANANA,
        APPLE
    };
    Color a = Color::RED; // note: RED is not accessible any more, we have to use Color::RED
    Fruit b = Fruit::BANANA; // note: BANANA is not accessible any more, we have to use Fruit::BANANA
    if (a == b) // compile error here, as the compiler doesn't know how to compare different types Color and Fruit
        cout << "a and b are equal" << endl;
    else
        cout << "a and b are not equal" << endl;
    return 0;
}

//___________________________

for (std::vector<int>::iterator itr = myvector.begin(); itr != myvector.end(); ++itr)
//  ====	
for (auto itr = myvector.begin(); itr != myvector.end(); ++itr)


for (auto x: myvector) // x is read-only
{
    cout << x;
}
// =====
for (auto& x: myvector) // x is modifiable
{
    cout << ++x;
}


static_assert(sizeof(int) >= 4, "int needs to be 4 bytes to use this code");
// ====
static_assert(__cplusplus > 199711L, "Program requires C++11 capable compiler");


struct Employee
{
    int nID;
    int nAge;
    float fWage;
};
Employee sJoe = {1, 42, 60000.0f};
int anArray[5] = { 3, 2, 7, 5, 8 };

int anArray[5] = { 3, 2, 7, 5, 8 }; // ok
std::vector<int> vArray[5] = {3, 2, 7, 5, 8}; // not okay in C++03
std::vector<int> vArray[5] = {3, 2, 7, 5, 8}; // calls constructor std::vector<int>(std::initializer_list<int>);


template <typename T>
class MyArray
{
private:
    vector<T> m_Array;
public:
    MyArray() { }
    MyArray(const initializer_list<T>& il)
    {
        // Manually populate the elements of the array from initializer_list x
        for (auto x: il) // use range-based for statement to iterate over the elements of the initializer list
            m_Array.push_back(x); // push them into the array manually
    }
};
int main()
{
    MyArray<int> foo = { 3, 4, 6, 9 };
    return 0;
}


int sum(const initializer_list<int> &il)
{
    int nSum = 0;
    for (auto x: il) // use range-based for statement to iterate over the elements of the initializer list
        nSum += x;
    return nsum;
}
cout << sum( { 3, 4, 6, 9 } );
