#include <iostream>
#include <vector>
#include <math.h>
#include <ctime>
#include <string>
using namespace std;

/*
Author: Ben Loisch
Date: 11/19/16
Language: C++
Description:
This program finds the smallest number that is evenly divisble by integers 1 through n
*/

int smallestMultiple(int n) {
	int number = 2;
	while (true) {
		//check if number is divisible by integers 1 through n
		int i = 1;
		for (; i <= n; i++) {
			if (number % i != 0) {
				number++;
				break;
			}
		}

		//if divisible evenly by integers 1 through n
		if (i > n)
			return number;
	}
}

int main() {

	//create clock object to track program execution time
	clock_t begin = clock();

	int n = 20;

	cout << "Smallest number divisible by all integers from 1 to " << n << " is: " << smallestMultiple(n) << endl;

	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

	cout << "Program execution time: " << elapsed_secs << " seconds" << endl;

	system("PAUSE");
	return 0;
}