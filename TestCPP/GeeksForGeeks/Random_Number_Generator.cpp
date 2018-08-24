#include <stdafx.h>

// driver program
int main()
{

	// finds the time between the system clock
	//(present time) and clock's epoch

	//auto seed = chrono::system_clock::now().time_since_epoch().count();
	unsigned seed = 100;
	// minstd_rand0 is a standard
	// linear_congruential_engine
	minstd_rand0 generator(seed);

	// generates the random number
	cout << generator() << " is a random number between ";

	//use of min and max functions
	cout << generator.min() << " and " << generator.max();

	cout << endl;
	// mt19937 is a standard mersenne_twister_engine
	mt19937 generatorM(seed);

	// use of operator() 
	cout << generatorM() << " is a random number between ";

	// use of max and min
	cout << generatorM.min() << " and " << generatorM.max();

	cout << endl;

	subtract_with_carry_engine<unsigned, 24, 10, 24> generatorAS(seed);

	// use of operator()
	cout << generatorAS() << " is a random number between ";

	// use of min and max
	cout << generatorAS.min() << " and " << generatorAS.max();

	cout << endl;

	random_device example;

	cout << "default random_device characteristics:" << endl;

	// use of min
	cout << "minimum: " << example.min() << endl;

	// use of max
	cout << "maximum: " << example.max() << endl;

	// use of entropy
	cout << "entropy: " << example.entropy() << endl;

	// use of operator()
	cout << "a random number: " << example() << endl;

	cout << endl;

	//unsigned seeds = chrono::system_clock::now().time_since_epoch().count();
	unsigned seeds = 100;
	subtract_with_carry_engine<unsigned, 24, 10, 24> generatords(seeds);

	//use of operator()
	cout << generatords() << " is a random number between ";

	//use of max and min
	cout << generatords.min() << " and " << generatords.max();

	cout << endl;
	ranlux24 generatorrn(200);

	//use of operator()
	cout << generatorrn() << " is a random number between ";

	//use of max and min
	cout << generatorrn.min() << " and " << generatorrn.max();

	cout << endl;
	independent_bits_engine<mt19937, 64, uint_fast64_t> generatorin(300);

	//use of operator()
	cout << generatorin() << " is a random number between ";

	//use of max and min
	cout << generatorin.min() << " and " << generatorin.max();
	cout << endl;

	ranlux24 generatorlx(400);

	//use of operator()
	cout << generatorlx() << " is a random number between ";

	//use of max and min
	cout << generatorlx.min() << " and " << generatorlx.max();
	cout << endl;

	unsigned s = 2;

	// The random number generator
	default_random_engine generatordr(s);

	uniform_int_distribution<int> distribution(1, 10);
	cout << "Some random numbers between 1 and 10 ";
	for (int i = 0; i < 10; ++i)
		cout << distribution(generatordr)<<" ";

	cout << endl;
	getchar();
}