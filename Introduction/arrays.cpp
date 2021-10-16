/*
	1. Array elements are placed in contiguous memory location
	2. Size chart:
		- char: 1 byte
		- int: 4 byte
	3. NULL should be put in a character array
*/

#include<iostream>

using namespace std;

// Creating an array

int main() {
	/* 
		int a[100];
		int a[100] = { 0 }; // For initialization. Every element in the array becomes 0
		int a[100] = {}
		int a[] = {1,2,3}
		String fruits[4] = {"apple", "orange", "mango"}
	*/

	int marks[100];
	int n;

	cout << "Enter the number of students: ";
	cin >> n;

	for (int idx = 0; idx < n; idx++) {
		cin >> marks[idx];
	}


	 
}