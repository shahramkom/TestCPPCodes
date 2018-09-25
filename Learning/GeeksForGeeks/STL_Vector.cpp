#include <stdafx.h>

int main()
{
	vector <int> g1;
	vector <int> ::iterator i;
	vector <int> ::reverse_iterator ir;

	for (int i = 1; i <= 5; i++)
		g1.push_back(i);

	cout << "Output of begin and end\t:\t";
	for (i = g1.begin(); i != g1.end(); ++i)
		cout << *i << '\t';

	cout << endl << endl;
	cout << "Output of rbegin and rend\t:\t";
	for (ir = g1.rbegin(); ir != g1.rend(); ++ir)
		cout << '\t' << *ir;
	cout << endl;
	vector <int> g11;

	for (int i = 1; i <= 5; i++)
		g11.push_back(i);

	cout << "Size : " << g11.size();
	cout << "\nCapacity : " << g11.capacity();
	cout << "\nMax_Size : " << g11.max_size();
	cout << endl;

	vector <int> g12;

	for (int i = 1; i <= 10; i++)
		g12.push_back(i * 10);

	cout << "Reference operator [g] : g12[2] = " << g12[2];
	cout << endl;
	cout << "at : g12.at(4) = " << g12.at(4);
	cout << endl;
	cout << "front() : g12.front() = " << g12.front();
	cout << endl;
	cout << "back() : g12.back() = " << g12.back();
	cout << endl;

	getchar();

}