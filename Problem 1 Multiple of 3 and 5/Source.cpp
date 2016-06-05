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

#define TARGET 999

int SumDivisibleBy(int n) {
	/*
	3 + 6 + 9... + 999 = 3 * (1 + 2 + 3...333)
	5 + 10 + 15... + 995 = 5 * (1 + 2...199)

	Note: 199 = 995 / 5 but also 999 / 5 because integers get truncated
	Note: 1 + 2 + 3...+ p = 1/2 * p * (p + 1)

	Therefore, the sum of factors under a number would be:
	*/

	int p = TARGET / n;

	return n * (0.5) * p * (p + 1);
}

int main() {

	//create clock object to track program execution time
	clock_t begin = clock();
	 
	//find multiples of 3 or 5 below 1000 and sum them up
	/*
	int sum = 0;
	for (int i = 1; i < 1000; i++) {
		if (i % 3 == 0 || i % 5 == 0) {
			sum += i;
		}
	}
	*/

	//to get a more efficient solution, find the multiples of 3 + multiples of 5 - multiples of 15
	//because 15 gets counted twice (3 and 5 go into 15).
	//We can add this up, instead of checking every single number under 1000

	int sum = SumDivisibleBy(3) + SumDivisibleBy(5) - SumDivisibleBy(15);
	
	cout << "Sum of multiples of 3 or 5 below 1000: " << sum << endl;

	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

	cout << "Program execution time: " << elapsed_secs << endl;

	system("PAUSE");
	return 0;
}