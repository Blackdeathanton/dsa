#include <iostream>
#include <algorithm>
#include <vector>

void swap(int arr[], int x, int y) {
	int temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

void printArray(int arr[], int N) {
	std::cout << "The elements of are the array are ";
	for (int idx = 0; idx < N; idx++) {
		std::cout << arr[idx] << " ";
	}
	std::cout << std::endl;
}

void bubbleSort(int arr[], int N) {
	/*
		Intuition: Take the larger element to the end by repeatedly swapping the adjacent elements
	*/
	for (int I = 0; I < N; I++) {
		for (int J = 1; J < N - I; J++) {
			std::cout << "Checking " << arr[J] << " and " << arr[J - 1] << std::endl;
			if (arr[J] < arr[J - 1]) {
				std::cout << "Swapping " << arr[J] << " and " << arr[J - 1] << std::endl;
				swap(arr, J, J-1);
			}
		}
	}
}

void insertionSort(int arr[], int N) {
	/*
		Intuition: Assume inserting a card with number 4 to a sorted set of cards with numbers 1,2,3,5
	*/

	for (int I = 1; I < N; I++) {
		int currentElement = arr[I];
		int previousIndex = I - 1;

		while (previousIndex >= 0 and currentElement < arr[previousIndex]) {
			arr[previousIndex + 1] = arr[previousIndex];
			previousIndex--;
		}
		arr[previousIndex + 1] = currentElement;

	}
}

void selectionSort(int arr[], int N) {
	/*
		Intuition: Finds the smallest element from the unsorted array and swaps it
	*/
	for (int I = 0; I < N-1; I++) {
		int currentMin = arr[I];
		int minIdx = I;
		for (int J = I; J < N; J++) {
			if (currentMin > arr[J]) {
				currentMin = arr[J];
				minIdx = J;
			}
		}
		swap(arr, minIdx, I);
	}
}

void countingSort(int arr[], int N) {
	/*
		Intuition: Trace the count of elements are replace
	*/

	int maxElement = INT_MIN;
	for (int index = 0; index < N; index++) {
		if (maxElement < arr[index]) {
			maxElement = arr[index];
		}
	}

	std::vector<int> counter(maxElement + 1, 0);

	for (int index = 0; index < N; index++) {
		counter[arr[index]]++;
	}

	int arrIdx = 0;

	for (int index = 0; index <= maxElement; index++) {
		while (counter[index] > 0) {
			arr[arrIdx++] = index;
			counter[index]--;
		}
	}

}

int main()
{
	int arr[] = { 5, 6, 1, 2, 8, 30, 20, 10, 77, 100, 11, 13, 17, 26, 29, 31, 33 };
	int N = sizeof(arr) / sizeof(int);

	// bubbleSort(arr, N);
	// insertionSort(arr, N);
 	// selectionSort(arr, N);

	// Inbuilt Sorting Algorithm
	// include algorithm.h
	// std::sort(arr, arr + N);
	// std::reverse(arr, arr+N+1);

	countingSort(arr, N);

	printArray(arr, N);
	return 0;
}

