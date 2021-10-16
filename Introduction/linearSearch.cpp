#include<iostream>

using namespace std;

int linearSearch(int[] arr, int N, int key) {
	for (int idx = 0; idx < N; idx++) {
		if (arr[idx] == key)
			return idx;
	}
	return -1;
}

int main() {
	int[] arr = { 1,6,3,2,5,4,8,9 };
	cout << linearSearch(arr, sizeof(arr) / sizeof(int), 5);
	return 0;
}