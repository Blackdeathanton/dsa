#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void compressString(string input) {
	int countOfChar = 1;
	string result = "";
	for (int idx = 0; input[idx] != '\0'; idx++) {
		if (input[idx + 1] != input[idx]) {
			cout << input[idx] << countOfChar;
			countOfChar = 1;
		}
		else {
			countOfChar++;
		}
	}
}


int main() {
	string str1 = "aaabbccddee";
	compressString(str1);

}