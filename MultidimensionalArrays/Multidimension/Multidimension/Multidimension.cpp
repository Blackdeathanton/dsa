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

pair<int, int> staircaseSearch(int arr[][4], int N, int M, int key) {
    if (arr[0][0] > key || arr[N - 1][M - 1] < key)
        return { -1,-1 };

    int I = 0;
    int J = M - 1;

    while (I <= N - 1 && J >= 0) {
        cout << I << " " << J << endl;
        if (arr[I][J] == key) {
            return { I, J };
        } else if (arr[I][J] > key) {
            J--;
        } else {
            I++;
        }
    }

    return { -1,-1 };
}

int findMinMaxMangoField(char arr[][6], int aux[][6], int N, int M) {
    int minMangoesPossible = INT_MIN;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            /*
                First quadrant = (row,col)
                Second quadrant = (row, M-1) - First quadrant
                Third quadrant = (N-1, col) - First quadrant
                Fourth quadrant = (N-1, M-1) - first - second - third
            */
            int currentMin = INT_MAX;

            int first = aux[row][col];
            int second = aux[row][M - 1] - first;
            int third = aux[N - 1][col] - first;
            int fourth = aux[N - 1][M - 1] - first - second - third;

            if (first < second) {
                if (first < third) {
                    if (first < fourth) {
                        currentMin = first;
                    }
                    else {
                        currentMin = fourth;
                    }
                }
                else {
                    currentMin = third;
                }
            }
            else {
                if (second < third) {
                    if (second < fourth) {
                        currentMin = second;
                    }
                    else {
                        currentMin = fourth;
                    }
                }
                else {
                    currentMin = third;
                }
            }

            minMangoesPossible = max(currentMin, minMangoesPossible);

        }
    }

    return minMangoesPossible;
}

void generateAuxillaryMatrix(char arr[][6], int aux[][6], int N, int M) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            int sumOfTrees = arr[row][col] == '#' ? 1 : 0;
            if (row - 1 >= 0) {
                sumOfTrees += aux[row - 1][col];
            }
            if (col - 1 >= 0) {
                sumOfTrees += aux[row][col - 1];
            }
            if (row - 1 >= 0 && col - 1 >= 0) {
                sumOfTrees -= aux[row - 1][col - 1];
            }
            aux[row][col] = sumOfTrees;
        }
    }
}

void printMatrix(char arr[][6], int N, int M) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }
}

void printMatrix(int arr[][6], int N, int M) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }
}

int main()
{
    /*int arr[100][100], R, C;
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
    printSpiralPattern(arr, R, C);*/

    /*int arr[][4] = {{10,20,30,40},
                    {15,25,35,45},
                    {27,29,37,48},
                    {32,38,39,50} };

    pair<int, int> coords = staircaseSearch(arr, 4, 4, 38);
    cout << coords.first << " " << coords.second;

    return 0;*/

    char arr[][6] = {
        {'.', '#', '#', '.', '.', '.'},
        {'#', '.', '.', '#', '#', '.'},
        {'.', '#', '.', '.', '.', '.'},
        {'.', '#', '#', '.', '.', '.'},
        {'#', '.', '.', '#', '#', '.'},
        {'.', '#', '.', '.', '.', '.'}
    };

    printMatrix(arr, 6, 6);

    int aux[6][6];
    generateAuxillaryMatrix(arr, aux, 6, 6);
    printMatrix(aux, 6, 6);

    /* 
        Rahul's father has left a farm organized as an N x N grid.
        Each square in the grid either has or does not have a mango tree. 
        He has to divide the farm with his three sisters as follows: he will draw one horizontal line and one vertical line
        to divide the field into four rectangles. His sisters will choose three of the four smaller fields and he gets the last one
    */
    cout << endl << findMinMaxMangoField(arr, aux, 6, 6);

}
