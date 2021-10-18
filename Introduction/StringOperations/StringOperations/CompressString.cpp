#include <iostream>
#include <string>

string compressString(string input) {
	int countOfChar = 1;
	for (int idx = 1; idx < strlen(input); idx++) {
		if (input[idx - 1] != input[idx]) {
			cout << input[idx - 1] << countOfChar;
			countOfChar = 1;
		} else {
			count++;
		}
	}
}


int main() {
	string str1 = "aaabbccddee";
	cout << compressString(str1) << endl;

}