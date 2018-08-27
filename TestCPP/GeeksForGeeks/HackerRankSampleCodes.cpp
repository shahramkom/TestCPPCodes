 #include <stdafx.h>
#include "CrashRpt.h"

//  template <class T>
//  class mypair {
//  	T a, b;
//  public:
//  	mypair(T first, T second)
//  	{
//  		a = first; b = second;
//  	}
//  	T getmax();
//  };
//  
//  template <class T>
//  T mypair<T>::getmax()
//  {
//  	T retval;
//  	retval = a > b ? a : b;
//  	return retval;
//  }
//  
//  int main()
//  {
//  	mypair <int> myobject(100, 75);
//  	cout << myobject.getmax();
//  
//  	getchar();
//  }
// int main()
// {
// 	crash_rpt::CrashRpt crpt;
// 	
// 	getchar();
// }

int sum(int x, int y)
{
	return x + y;
}
#include <strstream>

void printNum(unsigned long long num)
{
	switch (num)
	{
	case 1:
		printf("one\n");
		break;
	case 2:
		printf("two\n");
		break;
	case 3:
		printf("three\n");
		break;
	case 4:
		printf("four\n");
		break;
	case 5:
		printf("five\n");
		break;
	case 6:
		printf("six\n");
		break;
	case 7:
		printf("seven\n");
		break;
	case 8:
		printf("eight\n");
		break;
	case 9:
		printf("nine\n");
		break;
	default:
		printf("nine\n");
		break;
	}
}

void printEOdd(unsigned long long num)
{
	if (num % 2 == 0)
		printf("even\n");
	else
		printf("odd\n");
}

int main1() {
	unsigned long long a, b;
	scanf("%llu", &a);
	scanf("%llu", &b);
	if ((a >= 1 && a <= 9) && (b >= 1 && b <= 9))
	{
		printNum(a);
		printNum(b);
	}
	else
	{
		for (int i = a ; i <= b; i++)
		{
			if (i <= 9)
				printNum(i);
			else
				printEOdd(i);
		}
	}
	getchar();
	return 0;
}

int max_of_four(int a, int b, int c, int d)
{
	int myints[4] = { a,b,c,d };
	return  *max_element(myints, myints + 4);
}

void splitToArray(const string& str, vector<unsigned long long>& x)
{
	stringstream ss(str);
	unsigned long long temp;
	while (ss >> temp)
		x.push_back(temp);
}

void splitToArray(const string& str, unsigned long long* x)
{
	stringstream ss(str);
	unsigned long long temp;
	auto count = 0;
	while (ss >> temp)
		x[count++]= temp;
}

int mainVector() {
	long a = 1, b = 1;
	cin >> a;
	getchar();
	std::string str;
	str.resize(100000);
	char tst[100000];
	cin.getline(tst, 100000);
	str = string(tst);
	vector<unsigned long long> vect;
	splitToArray(str, vect);
	cin >> b;
	getchar();
	std::string str2;
	std::getline(std::cin, str2);
	vector<unsigned long long> remVect;
	splitToArray(str2, remVect);
	auto delFirst = remVect.at(0); delFirst--;
	auto delSecond = remVect.at(1); delSecond--;
	vect.erase(vect.begin() + b);
	vect.erase(vect.begin() + delFirst, vect.begin() + delSecond);
	cout << vect.size() << endl;
	for (unsigned long long i : vect)
		cout << i << " ";
	getchar();
	return 0;
}

void printNGE(const vector<unsigned long long>& vect, const unsigned long long& n)
{
	unsigned long long low = 0, high = vect.size(); // numElems is the size of the array i.e arr.size() 
	while (low != high) {
		int mid = (low + high) / 2; // Or a fancy way to avoid int overflow
		if (vect[mid] <= n) 
			low = mid + 1;
		else 
			high = mid;
	}
	/* Now, low and high both point to the element in question. */
	printf("No %llu\n", ++low);
}

void printNGE(unsigned long long* vect, int size , const unsigned long long& n)
{
	unsigned long long low = 0, high = size;
	while (low != high) {
		int mid = (low + high) / 2; // Or a fancy way to avoid int overflow
		if (vect[mid] <= n)
			low = mid + 1;
		else
			high = mid;
	}
	if (vect[--low] == n)
		printf("Yes %llu\n", low);
	else
		printf("No %llu\n", ++low);
}

#include <inttypes.h>
int mainLower() {
	long a = 1, b = 1;
	cin >> a;
	getchar();
	std::string str;
	str.resize(2000000);
	cin.getline(&str[0], 2000000);
	//vector<unsigned long long> vect;
	auto vect = new unsigned long long[a];
	splitToArray(str, vect);
	cin >> b;
	getchar();
	
// 	vector<unsigned long long> queries;
// 	for (auto cnt = 0 ; cnt < b;cnt++)
// 	{
// 		int q = 0;
// 		cin >> q;
// 		queries.emplace_back(q);
// 		getchar();
// 	}
// 	
// 	for (unsigned long long querie : queries)
// 	{
// 		auto it = std::find(vect.begin(), vect.end(), querie) ;
// 		if (it != vect.end())
// 		{
// 			auto index = std::distance(vect.begin(), it);
// 			cout << "Yes " << ++index << endl;
// 		}
// 		else
// 			printNGE(vect, querie);
// 	}

	auto queries = new unsigned long long[b];
	for (auto cnt = 0; cnt < b; cnt++)
		scanf("%llu", &queries[cnt]);

	for (auto i = 0; i < b; i++)
	{
		auto pos = lower_bound(vect, vect + a, queries[i]);
		auto index = distance(vect, pos);
		if(*pos == queries[i])
			printf("Yes %d\n", ++index);
		else
			printf("No %d\n", ++index);
	}

	getchar();
	return 0;
}

#include <limits.h>
#include <iosfwd>
using std::numeric_limits;

#undef max

#include <math.h>

#include <stdio.h>

int mainMap()
{
	int a = 1;
	cin >> a;
	getchar();
	map<string, int> maps;
	
	vector < string> ssls;
	ssls.reserve(a);
	string input;
	cin.ignore();
	while (cin.getline(&input[0], 100) && input[0] != '\0')
	{
		ssls.emplace_back(input.c_str());
	}


	for (const auto& it : ssls)
	{
		cout << it<<endl;
	}
	for (const auto& it : maps)
	{
		cout << it.first << "=" << it.second << endl;
	}
	for (const auto& it : ssls)
	{
		auto sc = maps.find(it.c_str());
		if (sc != maps.end())
			cout << sc->first << "=" << sc->second << endl;
		else
			cout << "Not found" << endl;
	}
	getchar();
	return 0;
}

#include <set>
struct spd
{
	int q;
	unsigned long long val;
	spd(int a, unsigned long long b)
		:q(a)
		, val(b)
	{}
};
inline bool operator<(const spd& lhs, const spd& rhs)
{
	return lhs.q < rhs.q;
}
set<spd> s;

int mainSet()
{
	
	int a = 1;
	cin >> a;
	getchar();

	for (int i = 0; i < a; i++)
	{
 		int q;
 		unsigned long long val;
 		scanf("%i %llu", &q, &val);
 		s.insert(spd(q, val));

	}

	for (const auto& it : s)
	{
		if (it.q == 3)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	getchar();
	return 0;
}



typedef std::tuple<int, string, int> ReadLine;
typedef vector<ReadLine> ReadLines;
void splitToTuple(const string& str, ReadLine& x)
{
	stringstream ss(str.c_str());
	int q = 0, m = 0;
	string n;
	string temp;
	vector<string> tmp;
	while (ss >> temp)
		tmp.emplace_back(temp);
	if (tmp.size() > 0)
		q = stoi(tmp[0]);
	if (tmp.size() > 1)
		n = tmp[1];
	if (tmp.size() > 2)
		m = stoi(tmp[2]);
	x = make_tuple(q, n, m);
}

int mainMapStl()
{
	int a = 1;
	cin >> a;
	getchar();

	ReadLines readLines;
	for (int i = 0; i <= a; i++)
	{
		std::string str;
		cin.getline(&str[0], 200);
		ReadLine readline;
		splitToTuple(str, readline);
		readLines.emplace_back(readline);
	}

	map<string, int> maps;
	for (const auto& it : readLines)
	{
		auto pt = maps.find(std::get<1>(it).c_str());
		switch (std::get<0>(it))
		{
		case 1:
			if (pt == maps.end())
				maps.emplace(make_pair(std::get<1>(it), std::get<2>(it)));
			else
				pt->second += std::get<2>(it);
			break;
		case 2:
			if (pt != maps.end())
				pt->second = 0;
			break;
		case 3:
			if (pt != maps.end())
				cout << pt->second << endl;
			else
				cout << "0" << endl;
			break;
		default:
			break;
		}
	}

		
	getchar();
	return 0;
}

int mainString()
{
	string a, b;
	cin >> a;
	cin >> b;
	cout<< a.size() <<" " <<b.size()<< endl;

	cout << a + b << endl;

	char tmp = a[0];
	a[0] = b[0];
	b[0] = tmp;
	cout << a << " " << b <<endl;
	getchar();
	return 0;
}

#include <ostream>

class Box
{
public:
	Box()
		: l(0)
		, b(0)
		, h(0)
	{}
	Box(int ll, int bb, int hh)
		: l(ll)
		, b(bb)
		, h(hh)
	{
	}
	Box(Box& bx)
		: l(bx.l)
		, b(bx.b)
		, h(bx.h)
	{
	}

	int getLength() { return l; }
	int getBreadth() { return b; }
	int getHeight() { return h; }
	long long CalculateVolume() { return l * b* h; }

	//Overload operator < as specified
	bool operator<(Box& b)
	{
		if (this->l < b.l)
			return true;
		else if(this->b < b.b && this->l == b.l)
			return true;
		else if(this->h < b.h && this->b == b.b && this->l == b.l)
			return true;
		return false;
	}

	//Overload operator << as specified
	friend ostream& operator<<(ostream& out, Box& B)
	{
		out << B.l << " " << B.b << " " << B.h << endl;
		return out;
	}

protected:
private:
	int l;
	int b;
	int	h;
};


void check2()
{
	int n;
	cin >> n;
	Box temp;
	for (int i = 0; i < n; i++)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			cout << temp << endl;
		}
		if (type == 2)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			temp = NewBox;
			cout << temp << endl;
		}
		if (type == 3)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			if (NewBox < temp)
			{
				cout << "Lesser\n";
			}
			else
			{
				cout << "Greater\n";
			}
		}
		if (type == 4)
		{
			cout << temp.CalculateVolume() << endl;
		}
		if (type == 5)
		{
			Box NewBox(temp);
			cout << NewBox << endl;
		}

	}
}


class Student
{
public :
	Student()
		: a1(0)
		, a2(0)
		, a3(0)
		, a4(0)
		, a5(0)
	{}
	void input()
	{
		cin >> a1 >> a2 >> a3 >> a4 >> a5;
	}
	int calculateTotalScore()
	{
		return a1 + a2 + a3 + a4 + a5;
	}
private:
	int a1, a2, a3, a4, a5;
};
int mainCalc()
{
	check2();
	return 0;
}



#include <iostream>
#include <cstddef>
using namespace std;
class Node
{
public:
	int data;
	Node *next;
	Node(int d) {
		data = d;
		next = nullptr;
	}
};
class Solution {
public:
	
	void display(Node *head)
	{
		Node *start = head;
		while (start)
		{
			cout << start->data << " ";
			start = start->next;
		}
	}

	Node* insert(Node* head, int data)
	{
		if (head == nullptr)
			return new Node(data);

		if (head->next == nullptr) {
			head->next = new Node(data);
		}
		else {
			insert(head->next, data);
		}

		return head;
	}


};
int mainList()
{
	Node* head = NULL;
	Solution mylist;
	int T, data;
	cin >> T;
	while (T-- > 0) {
		cin >> data;
		head = mylist.insert(head, data);
	}
	mylist.display(head);
	getchar();
	return 0;
}


#include <deque> 
int max(int a, int b) { return (a > b) ? a : b; }

void printKMax(vector<int> arr, int k) {
	deque<int> subs;
	vector<vector<int>> subArrays;
	for (int i = 0; i < arr.size()-1; i++)
	{
		vector<int> sa;
		int j = i;
		while (j < (i + k))
			if (j == arr.size())
				break;
			else
				sa.emplace_back(arr[j++]);
		if(sa.size() == k)
			subArrays.emplace_back(sa);
		std::sort(sa.begin(), sa.end());
	}
	for (const auto& it : subArrays)
		cout << *std::max_element(it.begin(), it.end()) << " ";
	cout << endl;
}


///DEQUE KMAX
void printKMax(int arr[], int n, int k) {

	deque<int> dq;

	for (int i = 0; i < n; i++) {

		// base case for first element
		if (dq.empty()) {
			dq.push_back(i);
		}

		// remove elements outside the current window
		if (dq.front() <= (i - k)) {
			dq.pop_front();
		}

		// move max element to the front
		while (!dq.empty() && arr[i] >= arr[dq.back()]) {
			dq.pop_back();
		}

		dq.push_back(i);

		// print out only when the first window is completed
		if (i >= (k - 1)) {
			cout << arr[dq.front()] << " ";
		}
	}
	cout << endl;
}

///DEQUE KMAX

int mainKMAX() {

	int t;
	cin >> t;
	vector<pair<vector<int>, int>> vects;

	while (t > 0) {
		int n, k;
		cin >> n >> k;
		int i;
		vector<int> arr;
		for (i = 0; i < n; i++)
		{
			int rd;
			cin >> rd;
			arr.emplace_back(rd);
		}
		vects.emplace_back(make_pair(arr, k));
		t--;
	}
	for(const auto& it : vects)
		printKMax(it.first, it.second);
	abs(-1);
	getchar();
	return 0;
}



int diagonalDifference(vector<vector<int>> arr) {
	int sum1 = 0, sum2 = 0;
	auto n = arr.size();
	for (int i = 0; i < n; i++)
	{
		sum1 += arr[i][i];
		sum2 += arr[i][n - 1 - i];
	}
	return abs(sum1 - sum2);
}

int mainDiagonalDifference ()
{
	//ofstream fout(getenv("OUTPUT_PATH"));

	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<vector<int>> arr(n);
	for (int i = 0; i < n; i++) {
		arr[i].resize(n);

		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	int result = diagonalDifference(arr);

	cout << result << "\n";

	//fout.close();
	getchar();
	return 0;
}





using namespace std;

vector<string> split_string(string);

// Complete the miniMaxSum function below.
void miniMaxSum(vector<unsigned long long> arr) {
	vector<unsigned long long> sm;
	sm.emplace_back(arr[1] + arr[2] + arr[3] + arr[4]);
	sm.emplace_back(arr[0] + arr[2] + arr[3] + arr[4]);
	sm.emplace_back(arr[0] + arr[1] + arr[3] + arr[4]);
	sm.emplace_back(arr[0] + arr[1] + arr[2] + arr[4]);
	sm.emplace_back(arr[0] + arr[1] + arr[2] + arr[3]);
	cout << *std::min_element(sm.begin(), sm.end()) << " " << *std::max_element(sm.begin(), sm.end()) << endl;
}

int mainMinMaxSum()
{
	string arr_temp_temp;
	getline(cin, arr_temp_temp);

	vector<string> arr_temp = split_string(arr_temp_temp);

	vector<unsigned long long> arr;

	for (int i = 0; i < arr_temp.size(); i++)
		arr.emplace_back(stoll(arr_temp[i]));

	miniMaxSum(arr);
	return 0;
}

vector<string> split_string(string input_string) {
	string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
		return x == y and x == ' ';
	});

	input_string.erase(new_end, input_string.end());

	while (input_string[input_string.length() - 1] == ' ') {
		input_string.pop_back();
	}

	vector<string> splits;
	char delimiter = ' ';

	size_t i = 0;
	size_t pos = input_string.find(delimiter);

	while (pos != string::npos) {
		splits.push_back(input_string.substr(i, pos - i));

		i = pos + 1;
		pos = input_string.find(delimiter, i);
	}

	splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

	return splits;
}

class Palindrom {

private:
	vector<char> stack = {};
	vector<char> queue = {};
	int stackCursor = 0;
	int queueCursor = 0;
public:
	void pushCharacter(char c) {
		stack.push_back(c);
	}

	void enqueueCharacter(char c) {
		queue.push_back(c);
		queueCursor++;
	}

	char popCharacter() {
		return stack[stackCursor];
		stackCursor++;
	}
	char dequeueCharacter() {
		return queue[queueCursor - 1];
		queueCursor - 1;
	}
};

int mainPalindrom()
{
	// read the string s.
	string s;
	getline(cin, s);

	// create the Solution class object p.
	Palindrom obj;

	// push/enqueue all the characters of string s to stack.
	for (int i = 0; i < s.length(); i++) {
		obj.pushCharacter(s[i]);
		obj.enqueueCharacter(s[i]);
	}

	bool isPalindrome = true;

	// pop the top character from stack.
	// dequeue the first character from queue.
	// compare both the characters.
	for (int i = 0; i < s.length() / 2; i++) {
		if (obj.popCharacter() != obj.dequeueCharacter()) {
			isPalindrome = false;

			break;
		}
	}

	// finally print whether string s is palindrome or not.
	if (isPalindrome) {
		cout << "The word, " << s << ", is a palindrome.";
	}
	else {
		cout << "The word, " << s << ", is not a palindrome.";
	}

	return 0;
}