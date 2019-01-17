constexpr int getSum(int na, int nb, int nc)
{
	return na + nb + nc;
}
int array[getSum(10,10)];

const float xyz() noexcept  //Will never throw an excption
{
	return 5.f;
}

using frametime = float; //using equal to typedef  

//measure time of any operate
auto timepoint1(chrono::high_resolution_clock::now());
....
auto timepoint2(chrono::high_resolution_clock::now());
auto elapstime(timepoint2 - timepoint1);
float ft{ chrono::duration_cast<chrono::duration<float,milli>>(elapstime).count() };
auto fsec(ft / 1000 );

//initializer
class boVector {
	vector<int> m_vect;
public:
	boVector(const initializer_list<int>& v)
	{
		for (initializer_list<int>::iterator itr = v.begin();v.end();++itr)
			m_vect.push_back(*itr);
	}
};

boVector<int> v = { 2 , 3 , 4 , 5};
boVector<int> v { 1 , 6 , 8 , 5};

for(auto &i : v)
    i++   //change the values in v

for (int i:v) //work on any begin end class
    cout<< i;  //read only access

enum class apple{green , red};
apple a = apple::green;

assert(MyPointer != NULL); //Run time
static_assert(sizeof(int) == 4);//Compile time

class MyClass
{
public:
    MyClass(){ ... }
    MyClass(int a){ MyClass(); doOtherThings(a); }    
    //OR
    MyClass(int a) : MyClass() {doOtherThings(a); }    
};

class testClass final  //no class can be drived
{  
};

class testClass final  //no class can be drived
{  
    virtual void tFunc() final; //no class can override tFunc
};


class cls{
 cls(int age){}
};

cls c1; //Compiler not generated default constructor

class cls{
 cls(int age){}
 cls() = default; //force compiler to generate default constructor
};


class cls{
 cls(int age){}
 cls(double) = delete;
 cls& operator=(const cls&) = delete;
};

constexpr int A() {return 3;}
int arr[A()+3];

constexpr int cubed(int x){return x * x *x ;}
int y = cubed(1978);  //computed at compile time


char* a = u8"String";    UTF8
char16_t* b = u"String"; UTF16
char32_t* c = U"String"; UTF32
char* d = R"String";     String


//lambda
cout << [](int x , int y){return x+y;}(3,4)<<std::endl;
auto f = [](int x , int y){return x+y;};
std::cout<<f(3,4);

template<typename func>
void filter(func f, vector<int> arr)
{
    for (auto i :arr)
    {
        if(f(i))
            cout << i <<" ";
    }
}
vector<int> v{1,2,3,4,5,6};
filter([](int x){return (x>3);},v) ; //output 4 ,5 , 6
filter([](int x){return (x>2 && x<5);},v) ; //output 3,4

int y = 4;
filter([&](int x){return (x>y);},v) ; //output 5,6

