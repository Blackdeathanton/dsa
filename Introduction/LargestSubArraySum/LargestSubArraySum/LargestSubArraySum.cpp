// LargestSubArraySum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>

int printMaxSubArraySum(int arr[], int N) {
	int maxSubArraySum = INT_MIN;
	for (int I = 0; I < N; I++) {
		for (int J = I; J < N; J++) {
			int subArraySum = 0;
			for (int K = I; K <= J; K++) {
				std::cout << arr[K] << " + ";
				subArraySum += arr[K];
			}
			std::cout << " = " << subArraySum << std::endl;
			if (maxSubArraySum < subArraySum) {
				maxSubArraySum = subArraySum;
			}
			subArraySum = 0;
		}
	}
	return maxSubArraySum;
}

int printMaxSubArraySum2(int arr[], int N) {
	int maxSubArraySum = INT_MIN;
	int prefix[100] = { 0 };
	prefix[0] = arr[0];
	for (int I = 1; I < N; I++) {
		prefix[I] = prefix[I - 1] + arr[I];
	}

	for (int I = 0; I < N; I++) {
		for (int J = 0; J < N; J++) {
			int subArraySum = I > 0 ? prefix[J] - prefix[I - 1] : prefix[J];
			if (maxSubArraySum < subArraySum) {
				maxSubArraySum = subArraySum;
			}
		}
	}
	return maxSubArraySum;
}

/*
	1 -1 4 6 -8 1
*/

int kadaneAlgorithm(int arr[], int N) {
	int currentSum = 0;
	int maximumSum = 0;

	for (int idx = 0; idx < N; idx++) {
		currentSum += arr[idx];
		if (currentSum < 0) {
			currentSum = 0;
		}
		if (currentSum > maximumSum) {
			maximumSum = currentSum;
		}
	}
	return maximumSum;
}

int main()
{
	int arr[] = {1,2,3,4,5};
	int N = sizeof(arr) / sizeof(int);

	std::cout << "Max subarray sum 1 is " << printMaxSubArraySum(arr, N) << std::endl;
	std::cout << "Max subarray sum 2 is " << printMaxSubArraySum2(arr, N) << std::endl;

	int newArr[] = { 1,-1,4,6,-8,1 };
	N = sizeof(newArr) / sizeof(int);

	std::cout << "Max subarray sum from kadaneAlgorithm is " << kadaneAlgorithm(newArr, N);


	return 0;
}
