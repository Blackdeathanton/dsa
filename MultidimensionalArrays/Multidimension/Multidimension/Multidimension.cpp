// Multidimension.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void printArray(int arr[][100], int R, int C) {
    for (int row = 0; row < R; row++) {
        for (int col = 0; col < C; col++) {
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }
}

void printSpiralPattern(int arr[][100], int R, int C) {
    int top = 0, right = C-1, left = 0, bottom = R-1;
    int iter = 1;
    while (iter <= (R/2)) {
        for (int col = top; col <= right; col++) {
            cout << arr[top][col] << " ";
        }
        for (int row = top + 1; row <= bottom; row++) {
            cout << arr[row][right] << " ";
        }
        for (int col = right-1; col >= left; col--) {
            if (right == left) break;
            cout << arr[bottom][col] << " ";
        }
        for (int row = bottom - 1; row > top; row--) {
            if (top == bottom) break;
            cout << arr[row][left] << " ";
        }
        top++;
        right--;
        bottom--;
        left++;
    }
}



int main()
{
    int arr[100][100], R, C;
    cout << "Enter the number of rows: ";
    cin >> R;
    cout << endl << "Enter the number of columns: ";
    cin >> C;
    cout << endl;

    for (int row = 0; row < R; row++) {
        for (int col = 0; col < C; col++) {
            cout << "Enter arr[" << row << "]["  <<  col << "]: ";
            cin >> arr[row][col];
            cout << endl;
        }
    }

    printArray(arr, R, C);
    printSpiralPattern(arr, R, C);

    return 0;
}
