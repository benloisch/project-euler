#include <iostream>
#include <vector>
#include <math.h>
#include <ctime>
#include <string>
using namespace std;

/*
Author: Ben Loisch
Date: 11/16/16
Language: C++
Description:
This program finds the largest palindrome made from the product of two 3-digit numbers.
*/

//Big O of this program is O(n^3)

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
			//start at sqrt(998001) and count downwards because this 
			//increases our chance of finding a large palindrome quicker
			for (int factor = int(sqrt(998001)) - 1; factor >= 100; factor--) {
				//for P = a*b, a*b == b*a so only counter numbers where a <= b to exclude checking twice
				for (int factor2 = int(sqrt(998001)) - 1; factor2 >= 100 && factor2 > factor; factor2--) {
					if (factor * factor2 == i) {
						largestPalindrome = i;
						i = factor = factor2 = 0;
						break;
					}
				}
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