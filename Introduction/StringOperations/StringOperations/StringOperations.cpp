// StringOperations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

void findDirection(char input[]) {

    int x_axis = 0;
    int y_axis = 0;

    for (int idx = 0; input[idx] != '\0'; idx++) {
        switch (input[idx]) {
            case 'N':
                y_axis++;
                break;
            case 'S':
                y_axis--;
                break;
            case 'E':
                x_axis++;
                break;
            case 'W':
                x_axis--;
                break;
        }
    }

    cout << "The input string goes to the coordinates: x = " << x_axis << ", y = " << y_axis << endl;

    if (x_axis >= 0 and y_axis >= 0) {
        while (x_axis--) {
            cout << "E";
        }
        while (y_axis--) {
            cout << "N";
        }
    } else if (x_axis <= 0 and y_axis >= 0) {
        while (x_axis++) {
            cout << "W";
        }
        while (y_axis--) {
            cout << "N";
        }
    } else if (x_axis >= 0 and y_axis <= 0) {
        while (x_axis--) {
            cout << "E";
        }
        while (y_axis++) {
            cout << "S";
        }
    } else if (x_axis <= 0 and y_axis <= 0) {
        while (x_axis++) {
            cout << "W";
        }
        while (y_axis++) {
            cout << "N";
        }
    }
}

int main()
{
    char input[1000];

    cout << "Enter the direction: ";
    cin.getline(input, 1000);

    cout << endl;

    findDirection(input);

}
