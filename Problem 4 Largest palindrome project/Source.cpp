#include <iostream>
#include <vector>
#include <math.h>
#include <ctime>
#include <string>
using namespace std;

/*
Author: Ben Loisch
Date: 11/6/16
Language: C++
Description:
This program finds the largest palindrome made from the product of two 3-digit numbers.
*/

string intToString(int number) {
	return to_string(number);
}

bool checkPalindrome(string numberAsString) {
	for (unsigned int i = 0; i < numberAsString.size() / 2; i++)
		if (numberAsString[i] != numberAsString[numberAsString.size() - i - 1])
			return false;
	
	//if reached halfway mark then number is palindrome
	return true;
}

int main() {

	//create clock object to track program execution time
	clock_t begin = clock();

	int largestPalindrome = -1;

	//999 * 999 = 998001
	//check all numbers under that until 10000 = 100 * 100

	for (int i = 998001; i > 10000; i--) {
		if (checkPalindrome(intToString(i))) {
			largestPalindrome = i;

			//check if it is a product of two 3-digit numbers
			for (int factor = 100; factor < int(sqrt(998001)); factor++) {
				
			}
		}
	}

	cout << "Largest palindrome under 998001 made from the product of two 3-digit numbers is: " << largestPalindrome << endl;

	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

	cout << "Program execution time: " << elapsed_secs << " seconds" << endl;

	system("PAUSE");
	return 0;
}