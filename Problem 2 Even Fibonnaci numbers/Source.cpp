#include <iostream>
#include <ctime>
using namespace std;

/*
Author: Ben Loisch
Date: 10/6/16
Language: C++

Description:

This program adds up the even-valued terms of all the fibonnaci 
terms whose values do not exceed four million

*/

long int sumEvenFibonnaci() {

	//start at second term of fib sequence instead of first 
	long int a = 0;
	long int b = 1;
	long int sum = 0;
	while (b <= 4000000) {
		
		//if b is evenly divisible by 2, then add to total sum
		if (b % 2 == 0)
			sum += b;

		long int temp = a + b;
		a = b;
		b = temp;
	}

	return sum;
}

//faster method
//every third number in the fib sequence is even...
//1, 1, (2), 3, 5, (8), 13, 21, (34)...

//make new function that only counts every third number
long int sumEvenFibFaster() {
	long int sum = 0;
	long int a = 1;
	long int b = 1;
	long int c = a + b;

	while (c < 4000000) {
		sum += c;
		a = b + c;
		b = c + a;
		c = a + b;
	}

	return sum;
}


int main() {

	//create clock object to track program execution time
	clock_t begin = clock();
	 
	cout << "The sum of all the even terms of the fibonnaci terms whose values do not exceed four million is: " << sumEvenFibFaster() << endl;

	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

	cout << "Program execution time: " << elapsed_secs << endl;

	system("PAUSE");
	return 0;
}