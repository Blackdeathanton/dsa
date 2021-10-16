// LinearSearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>

using namespace std;

int linearSearch(int arr[], int N, int key) {
	for (int idx = 0; idx < N; idx++) {
		if (arr[idx] == key)
			return idx;
	}
	return -1;
}

int binarySearch(int arr[], int N, int key) {
	int low = 0;
	int high = N - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		int guess = arr[mid];
		if (guess == key) {
			return mid;
		}
		else if (key > guess) {
			low = mid + 1;
		}
		else if (key < guess) {
			high = mid - 1;
		}
	}
	return -1;
}

int main() {
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int N = sizeof(arr) / sizeof(int);
	cout << linearSearch(arr, N, 5) << endl;

	// Binary Search tests
	cout << "Binary Search Tests" << endl;
	cout << "Element 100 is in index " << binarySearch(arr, N, 100) << endl;
	cout << "Element 5 is in index " << binarySearch(arr, N, 5) << endl;
	cout << "Element 1 is in index " << binarySearch(arr, N, 1) << endl;
	cout << "Element 9 is in index " << binarySearch(arr, N, 9) << endl;
	cout << "Element 4 is in index " << binarySearch(arr, N, 4) << endl;

}
