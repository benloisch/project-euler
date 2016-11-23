#include <iostream>
#include <vector>
#include <math.h>
#include <ctime>
#include <string>
using namespace std;

/*
Author: Ben Loisch
Date: 11/23/16
Language: C++
Description:
This program finds the difference between the sum of the squares of the first n natural numbers	
and the square of the sum.

e.g. if n = 10, 1^2 + 2^2 + ... + 10^2 = 385
(1 + 2 + 3 + ... + 10)^2 = 3025
3025 - 385 = 2640
*/

//time complexity is O(n)
long unsigned int sumSquareDifference(unsigned int n) {

	long unsigned int sumOfSquares = 0;
	for (unsigned int i = 1; i <= n; i++)
		sumOfSquares += i*i;

	long unsigned int squareOfSum = n * (n + 1) * n * (n + 1) / 4; // equal to the sum of 1 to n, squared = (n(n+1)/2)^2

	return squareOfSum - sumOfSquares;
}

int main() {

	//create clock object to track program execution time
	clock_t begin = clock();

	//brute force method
	
	unsigned int n = 100;

	cout << "Sum of squares minus square of sum of natural numbers 1 to " << n << " is " << sumSquareDifference(n) << endl;

	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

	cout << "Program execution time: " << elapsed_secs << " seconds" << endl;

	system("PAUSE");
	return 0;
}