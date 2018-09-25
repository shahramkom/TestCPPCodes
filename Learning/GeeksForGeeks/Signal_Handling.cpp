#include <stdafx.h>
void signal_handler(int signal_num) {
	cout << "The interrupt signal is (" << signal_num << "). \n";

	// terminate program  
	exit(signal_num);
}

int main() {
// 	signal(SIGABRT, signal_handler);
// 	// register signal SIGABRT and signal handler  
// 
// 	while (true)
// 		cout << "Hello GeeksforGeeks..." << endl;

	int count = 0;
	signal(SIGSEGV, signal_handler);
	// register signal SIGSEGV and signal handler  

	while (++count) {
		cout << "Hello GeeksforGeeks..." << endl;
		if (count == 5)
			raise(SIGSEGV);
	}
	getchar();
}