#include <iostream>
#include <vector>
#include <math.h>
#include <ctime>
using namespace std;

/*
Author: Ben Loisch
Date: 11/2/16
Language: C++
Description:
This program finds the largest prime factor under 600851475143.
*/



//Big O of this function is O(n^2)

long long largestPrime(long long n) {

	vector<int> primes;
	int segmentSize = (int)sqrt(n) + 1;

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

	//successively divided off the primes until we are left with the highest prime the number is divisible by
	//thus, we are left with the greatest prime factor
	for (unsigned int i = 0; i < primes.size(); i++) {
		while (n % primes.at(i) == 0) {
			n /= primes.at(i);
			if (primes.at(i) > n)
				return primes.at(i);
		}
	}

	return 0;
}

int main() {

	//create clock object to track program execution time
	clock_t begin = clock();

	printf("Largest prime number under 600851475143 is %lld\n", largestPrime(600851475143));

	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

	cout << "Program execution time: " << elapsed_secs << " seconds" << endl;

	system("PAUSE");
	return 0;
}