// ReverseArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void swap(int arr[], int x, int y) {
	int temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

void reverseArray(int arr[], int N) {
	int left = 0;
	int right = N - 1;

	while (left < right) {
		swap(arr, left, right);
		left++;
		right--;
	}
}

void printArray(int arr[], int N) {
	for(int idx = 0; idx < N; idx++) {
		cout << arr[idx] << " ";
	}
	cout << endl;
}


int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8 };
	int N = sizeof(arr) / sizeof(int);

	reverseArray(arr, N);
	printArray(arr, N);
}
