#include <iostream>
#include <ctime>
using namespace std;

/*
Author: Ben Loisch
Date: 6/4/16
Language: C++

Description:

This program finds the sum of all the multiples of 3 or 5 below 1000.

*/

int main() {

	//create clock object to track program execution time
	clock_t begin = clock();
	 
	//find multiples of 3 or 5 below 1000 and sum them up
	int sum = 0;
	for (int i = 1; i < 1000; i++) {
		if (i % 3 == 0 || i % 5 == 0) {
			sum += i;
		}
	}

	cout << "Sum of multiples of 3 or 5 below 100: " << sum << endl;

	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

	cout << "Program execution time: " << elapsed_secs << endl;

	system("PAUSE");
	return 0;
}