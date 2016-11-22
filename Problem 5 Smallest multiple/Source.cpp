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

//brute force method
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

	//brute force method
	//int n = 20;
	//cout << "Smallest number divisible by all integers from 1 to " << n << " is: " << smallestMultiple(n) << endl;

	//fast O(n) method
	//N = number divisible by numbers 1 through k
	//N = 2^a * 3^b * 5^c * ..... (prime number under k)^z
	//where 2^a < k && 3^b < k && ... (prime number under k)^z < K
	//a = floor(log(k) / log(2)), b = floor(log(k) / log(3)), c = floor(log(k) / log5)), etc.

	int k = 20;
	vector<int> primes; //holds primes (2, 3, 5, 7, 11, ... n while n < k)
	primes.push_back(2);
	primes.push_back(3);
	primes.push_back(5);
	primes.push_back(7);
	primes.push_back(11);
	primes.push_back(13);
	primes.push_back(17);
	primes.push_back(19);
	int N = 1;
	int currPrime = 2;
	int i = 0;
	while (true) {
		if (i < primes.size()) {
			int a = floor(log(k) / log(primes[i]));
			N *= pow(primes[i], a);
			i++;
		}
		else {
			break;
		}
	}

	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

	cout << "Program execution time: " << elapsed_secs << " seconds" << endl;

	system("PAUSE");
	return 0;
}