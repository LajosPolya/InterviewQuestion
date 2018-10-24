#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<string> letterCombinations(string digits);
vector<string> stringBuilder(string digits, vector<string> listOfStrings);

int main() {
	vector<string> list = letterCombinations("234");

	for (auto l : list) {
		cout << l << endl;
	}

	while(1){}


	return 0;
}

vector<string> letterCombinations(string digits) {
	if (digits.length() == 0) {
		return vector<string>();
	}
	vector<string> listOfStrings;
	if (digits[0] == '2') {
		listOfStrings.push_back("a");
		listOfStrings.push_back("b");
		listOfStrings.push_back("c");
	}
	else if (digits[0] == '3') {
		listOfStrings.push_back("d");
		listOfStrings.push_back("e");
		listOfStrings.push_back("f");
	}
	else if (digits[0] == '4') {
		listOfStrings.push_back("g");
		listOfStrings.push_back("h");
		listOfStrings.push_back("i");
	}
	else if (digits[0] == '5') {
		listOfStrings.push_back("j");
		listOfStrings.push_back("k");
		listOfStrings.push_back("l");
	}
	else if (digits[0] == '6') {
		listOfStrings.push_back("m");
		listOfStrings.push_back("n");
		listOfStrings.push_back("o");
	}
	else if (digits[0] == '7') {
		listOfStrings.push_back("p");
		listOfStrings.push_back("q");
		listOfStrings.push_back("r");
		listOfStrings.push_back("s");
	}
	else if (digits[0] == '8') {
		listOfStrings.push_back("t");
		listOfStrings.push_back("u");
		listOfStrings.push_back("v");
	}
	else if (digits[0] == '9') {
		listOfStrings.push_back("w");
		listOfStrings.push_back("x");
		listOfStrings.push_back("y");
		listOfStrings.push_back("z");
	}

	return stringBuilder(digits.substr(1, digits.length() - 1), listOfStrings);
}

vector<string> stringBuilder(string digits, vector<string> listOfStrings) {
	if (digits == "") {
		return listOfStrings;
	}

	vector<string> newListOfStrings;
	if (digits[0] == '2') {
		for (int i = 0; i < listOfStrings.size(); i++) {
			string temp = listOfStrings[i];
			temp.append("a");
			newListOfStrings.push_back(temp);
			temp[temp.length() - 1] = 'b';
			newListOfStrings.push_back(temp);
			temp[temp.length() - 1] = 'c';
			newListOfStrings.push_back(temp);
		}
	} else if (digits[0] == '3') {
		for (int i = 0; i < listOfStrings.size(); i++) {
			string temp = listOfStrings[i];
			temp.append("d");
			newListOfStrings.push_back(temp);
			temp[temp.length() - 1] = 'e';
			newListOfStrings.push_back(temp);
			temp[temp.length() - 1] = 'f';
			newListOfStrings.push_back(temp);
		}
	}
	else if (digits[0] == '4') {
		for (int i = 0; i < listOfStrings.size(); i++) {
			string temp = listOfStrings[i];
			temp.append("g");
			newListOfStrings.push_back(temp);
			temp[temp.length() - 1] = 'h';
			newListOfStrings.push_back(temp);
			temp[temp.length() - 1] = 'i';
			newListOfStrings.push_back(temp);
		}
	}
	else if (digits[0] == '5') {
		for (int i = 0; i < listOfStrings.size(); i++) {
			string temp = listOfStrings[i];
			temp.append("j");
			newListOfStrings.push_back(temp);
			temp[temp.length() - 1] = 'k';
			newListOfStrings.push_back(temp);
			temp[temp.length() - 1] = 'l';
			newListOfStrings.push_back(temp);
		}
	}
	else if (digits[0] == '6') {
		for (int i = 0; i < listOfStrings.size(); i++) {
			string temp = listOfStrings[i];
			temp.append("m");
			newListOfStrings.push_back(temp);
			temp[temp.length() - 1] = 'n';
			newListOfStrings.push_back(temp);
			temp[temp.length() - 1] = 'o';
			newListOfStrings.push_back(temp);
		}
	}
	else if (digits[0] == '7') {
		for (int i = 0; i < listOfStrings.size(); i++) {
			string temp = listOfStrings[i];
			temp.append("p");
			newListOfStrings.push_back(temp);
			temp[temp.length() - 1] = 'q';
			newListOfStrings.push_back(temp);
			temp[temp.length() - 1] = 'r';
			newListOfStrings.push_back(temp);
			temp[temp.length() - 1] = 's';
			newListOfStrings.push_back(temp);
		}
	}
	else if (digits[0] == '8') {
		for (int i = 0; i < listOfStrings.size(); i++) {
			string temp = listOfStrings[i];
			temp.append("t");
			newListOfStrings.push_back(temp);
			temp[temp.length() - 1] = 'u';
			newListOfStrings.push_back(temp);
			temp[temp.length() - 1] = 'v';
			newListOfStrings.push_back(temp);
		}
	}
	else if (digits[0] == '9') {
		for (int i = 0; i < listOfStrings.size(); i++) {
			string temp = listOfStrings[i];
			temp.append("w");
			newListOfStrings.push_back(temp);
			temp[temp.length() - 1] = 'x';
			newListOfStrings.push_back(temp);
			temp[temp.length() - 1] = 'y';
			newListOfStrings.push_back(temp);
			temp[temp.length() - 1] = 'z';
			newListOfStrings.push_back(temp);
		}
	}
	return stringBuilder(digits.substr(1, digits.length() - 1), newListOfStrings);
}