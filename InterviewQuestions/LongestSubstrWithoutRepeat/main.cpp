#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

int lengthOfLongestSubstring(string s);
int lengthOfLongestSubstring2(string s);
int lengthOfLongestSubstring3(string s);

int main() {

	int len = lengthOfLongestSubstring2("abcabcbb");

	cout << len << endl;

	while (1) {

	}

	return 0;
}

int lengthOfLongestSubstring(string s) {
	unordered_map<char, int> seq;
	long len = 0;
	long longest = 0;

	for (int i = 0; i < s.length(); i++) {
		auto it = seq.find(s[i]);
		if (it != seq.end()) {
			if (len > longest) {
				longest = len;
			}
			i = it->second + 1;
			len = 0;
			seq.clear();
		}
		
		seq[s[i]] = i;
		len++;
	
	}

	if (len > longest) {
		longest = len;
	}
	return longest;
}

// Sliding Window Technique
int lengthOfLongestSubstring2(string s) {
	unordered_set<char> uniqChars;
	int len = s.length();

	int i = 0, j = 0;
	int max = 0;

	while (i < len && j < len) {
		auto it = uniqChars.find(s[j]);
		if (it != uniqChars.end()) {
			uniqChars.erase(s[i]);
			i++;
		}
		else {
			uniqChars.insert(s[j]);
			j++;
			if (max < (j - i)) {
				max = j - i;
			}
		}
	}
	return max;
}

int lengthOfLongestSubstring3(string s) {
	unordered_map<char, int> uniqChars;
	int len = s.length();

	int i = 0;
	int max = 0;

	for (int j = 0; j < len; j++) {
		auto it = uniqChars.find(s[j]);
		if (it != uniqChars.end()) {
			int k = it->second;
			if (i < k + 1) {
				i = k + 1;
			}
		}
		
		if (max < (j - i + 1)) {
			max = j - i + 1;
		}
		uniqChars[s[j]] = j;
	}
	return max;
}