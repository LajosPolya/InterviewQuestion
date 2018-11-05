#include <string>

using namespace std;

int main() {

	return 0;
}

int strStr(string haystack, string needle) {
	int nP = 0;

	if (needle.empty()) {
		return 0;
	}

	for (int i = 0; i < haystack.length(); i++) {
		if (haystack[i] == needle[nP]) {
			nP++;
			if (nP == needle.length()) {
				return i - nP + 1;
			}
		}
		else {
			i -= nP;
			nP = 0;
		}
	}

	return -1;
}
