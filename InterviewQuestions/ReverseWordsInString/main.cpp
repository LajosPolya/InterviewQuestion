#include <string>

using namespace std;

void reverseWords(string &s);

int main() {
	string words = " 1 ";
	reverseWords(words);

	return 0;
}

void reverseWords(string &s) {
	string reversed;
	int appendPointer = 0;
	bool onlySpaces = true;

	if (s[s.length() - 1] != ' ') {
		reversed += s[s.length() - 1];
		onlySpaces = false;
	}

	for (int i = s.length() - 2; i >= 0; i--) {
		if (i == s.length() - 2 && s[i] == ' ') {
			continue;
		}
		else if (i < s.length() - 2 && s[i] == ' ' && s[i + 1] != ' ') {
			reversed += ' ';
			appendPointer = reversed.length();
		}
		else if (i < s.length() - 2 && s[i] == ' ' && s[i + 1] == ' ') {
			continue;
		}
		else {
			reversed.insert(appendPointer, &s[i], 1);
			onlySpaces = false;
		}
	}

	if (onlySpaces || (s.length() == 1 && s[0] == ' ')) {
		s.resize(0);
	}
	else {
		for (int i = 0; i < reversed.length(); i++) {
			if (i < s.length()) {
				s[i] = reversed[i];
			}
			else {
				s += reversed[i];
			}
		}
	}

	if (reversed.length() < s.length()) {
		s.resize(reversed.length());
	}
	if (s[s.length() - 1] == ' ') {
		s.resize(s.length() - 1);
	}
}