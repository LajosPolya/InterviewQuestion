#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs);

int main() {


	return 0;
}

string longestCommonPrefix(vector<string>& strs) {
	int minLen = INT_MAX;
	string common;

	if (strs.size() == 0) {
		return "";
	}

	for (auto str : strs) {
		if (str.length() < minLen) {
			minLen = str.length();
		}
	}

	for (int i = 0; i < minLen; i++) {
		char f = strs[0][i];
		int j;
		for (j = 1; j < strs.size(); j++) {
			if (strs[j][i] != f) {
				break;
			}
		}
		if (j != strs.size()) {
			break;
		}
		common.append(&strs[0][i], 1);
	}

	return common;
}