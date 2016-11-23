#include <iostream>
#include <vector>
#include <math.h>
#include <ctime>
#include <string>
using namespace std;

/*
Author: Ben Loisch
Date: 11/22/16
Language: C++
Description:
This program finds the smallest number that is evenly divisble by integers 1 through k
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

vector<int> allPrimesUnderNumber(int n) {
	vector<int> primes;
	int segmentSize = n;// (int)sqrt(n) + 1;

	//generate primes up to sqrt(n)
	vector<char> initialPrimes(segmentSize);
	for (int b = 0; b < segmentSize; b++) {
		initialPrimes[b] = 1;
	}
	initialPrimes[0] = initialPrimes[1] = 0;

	for (int g = 0; g < segmentSize; g++) {
		if (initialPrimes[g] == 1) {
			for (int multiple = g + g; multiple < segmentSize; multiple += g) {
				initialPrimes[multiple] = 0;
			}
		}
	}

	for (int i = 0; i < segmentSize; i++) {
		if (initialPrimes[i] == 1)
			primes.push_back(i);
	}

	return primes;
}

int main() {

	//create clock object to track program execution time
	clock_t begin = clock();

	//brute force method
	//int n = 20;
	//cout << "Smallest number divisible by all integers from 1 to " << n << " is: " << smallestMultiple(n) << endl;

	//fast O(n) method (O(n^2) if you consider primes must also be calculated)
	//N = number divisible by numbers 1 through k
	//N = 2^a * 3^b * 5^c * ..... (prime number under k)^z
	//where 2^a < k && 3^b < k && ... (prime number under k)^z < K
	//a = floor(log(k) / log(2)), b = floor(log(k) / log(3)), c = floor(log(k) / log5)), etc.

	int k = 20;
	vector<int> primes = allPrimesUnderNumber(k); //holds primes (2, 3, 5, 7, 11, ... n while n < k)

	int N = 1;
	int currPrime = 2;
	unsigned int i = 0;
	while (true) {
		if (i < primes.size()) {
			int a = int(floor(log(k) / log(primes[i])));
			N *= int(pow(primes[i], a));
			i++;
		}
		else {
			break;
		}
	}

	cout << "Smallest number that is evenly divisible by integers 1 through " << k << " is " << N << endl;

	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

	cout << "Program execution time: " << elapsed_secs << " seconds" << endl;

	system("PAUSE");
	return 0;
}