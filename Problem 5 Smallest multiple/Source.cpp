#include <iostream>
#include <vector>
#include <math.h>
#include <ctime>
#include <string>
using namespace std;

/*
Author: Ben Loisch
Date: 11/18/16
Language: C++
Description:
This program finds...
*/

int smallestMultiple(int n) {
	int smallestMultiple = 2;
	while (true) {
		int i = 1;
		for (; i <= n; i++) {
			if (smallestMultiple % i != 0) {
				smallestMultiple++;
				break;
			}
		}

		if (i > n)
			return smallestMultiple;
	}
}

int main() {

	//create clock object to track program execution time
	clock_t begin = clock();

	int n = 20;

	cout << "Smallest number divisible by all numbers from 1 to " << n << " is: " << smallestMultiple(n) << endl;

	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

	cout << "Program execution time: " << elapsed_secs << " seconds" << endl;

	system("PAUSE");
	return 0;
}