#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestPalindrome(string s);

int main() {

	longestPalindrome("abcba");


	return 0;
}


// O(n^2) method
string longestPalindrome(string s) {
	int length = s.size();
	vector<vector<bool>> table(length, vector<bool>(length));

	for (int i = 0; i < length; i++) {
		table[i][i] = true;
	}

	int start = 0;
	int maxLength = 1;
	for (int i = 0; i < length - 1; i++) {
		if (s[i] == s[i + 1]) {
			table[i][i + 1] = true;
			maxLength = 2;
			start = i;
		}
	}

	for (int k = 3; k <= length; k++) {
		for (int i = 0; i < length - k + 1; i++) {
			int j = i + k - 1;

			if (table[i + 1][j - 1] == true && s[i] == s[j]) {
				table[i][j] = true;

				if (maxLength < k) {
					maxLength = k;
					start = i;
				}
			}
		}
	}

	return s.substr(start, maxLength);
}