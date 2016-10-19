#include <iostream>
#include <vector>
#include <math.h>
#include <ctime>
using namespace std;

/*
Author: Ben Loisch
Date: 10/14/16
Language: C++
Description:
This program finds the largest prime factor under 600851475143 using the Sieve of Erathosthenes algorithm.
*/



//Big O of this function is O(nlog(log(n)))
//due to memory constraints if n is large, we will use the segmented sieve algorithm!
//steps are as follows:

//1. Divide the range 2 through n into segments of some size delta <= sqrt(n)
//2. Find primes up to delta using sieve method
//3. for each delta-sized block from sqrt(n) + 1 to n, set up a Boolean array of size delta.
//Eliminate the multiples of each prime p <= sqrt(n) found in step 2.

long long sievesLargestPrime(long long n) {
	
	n = 100;
	vector<int> primes;
	int segmentSize = (int)sqrt(n);

	//generate primes up to sqrt(n)
	//we only need to test numbers up to n against primes up to sqrt(n) for divisibility
	vector<char> initialPrimes(segmentSize);
	for (int b = 0; b < segmentSize; b++) { 
		initialPrimes[b] = 1; 
	}
	for (int g = 2; g < segmentSize; g++) {
		//set all multiples of g to 0 (not prime)
		if (initialPrimes[g - 2] == 1) {
			for (int multiple = g + g; multiple <= segmentSize; multiple += g) {
				initialPrimes[multiple - g] = 0;
			}
		}
	}

	/*
	int largestPrime = 0;
	for (int back = initialPrimes.size() - 1; back > 0; back--) {
		if (initialPrimes.at(back) == 1) {
			largestPrime = back;
			break;
		}
	}
	*/

	for (int i = 0; i < segmentSize; i++) {
		if (initialPrimes[i] == 1)
			primes.push_back(i+2);
	}

	int stop = 0;
	/*
	for (int a = 0; a < segmentSize; a++) {
		if (initialPrimes[a] == 1)
			primes.push_back(a + 2);
	}

	char *isPrime = new char[segmentSize];

	//test each number in every segment for evenness
	for (long long s = 2; s < n; s += segmentSize) {

		//set array that keeps track of primes in segment to one meaning all numbers are prime until proven otherwise
		for (int b = 0; b < segmentSize; b++) { isPrime[b] = 1; }

		//for every segment, mark off multiples of primes and keep track of each marked off number using a true/false isPrime array
		for (long long p = s; p < s + segmentSize; p++) {

		}

	}
	*/

	/*
	//create boolean that holds 0's for composite and 1's for prime, all the way up to n-1 (numbers 2 to n)
	vector<char> bIsPrime;
	for (long long p = 0; p < n; p++) { bIsPrime.push_back(1); }

	//find all multiples of i and set corresponding index in bIsPrime to 0
	for (long long i = 2; i < (int)sqrt(n); i++) {
		for (long long j = i; j < n; j += i) {
			bIsPrime[j - 2] = 0;
		}
	}

	//check the prime nearest to the end of the bIsPrime array and return end which will be the prime number
	for (long long end = n - 1; end >= 0; end--) {
		if (bIsPrime[end])
			return end;
	}
	*/

	//delete initialPrimes;
	//delete isPrime;

	return 0;
}

int main() {

	//create clock object to track program execution time
	clock_t begin = clock();

	printf("Largest prime number under 600851475143 is %lld\n", sievesLargestPrime(600851475143));

	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

	cout << "Program execution time: " << elapsed_secs << " seconds" << endl;

	system("PAUSE");
	return 0;
}