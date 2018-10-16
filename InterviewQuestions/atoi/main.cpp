#include <string>
#include <vector>
#include <limits>

using namespace std;

int myAtoi(string str);

int main() {
	myAtoi(" b11228552307");
}

int myAtoi(string str) {
	bool spaceAllowed = true;
	bool positive = true;
	bool firstTrueNumber = false;
	vector<int> num;

	long long number = 0;
	if (str[0] != ' ' && (str[0] != '+' && str[0] != '-')) {
		spaceAllowed = false;
	}
	for (int i = 0; i < str.length(); i++) {
		if (spaceAllowed == true && str[i] == ' ') {
			continue;
		}
		else if (spaceAllowed == true && str[i] != ' ') {
			spaceAllowed = false;
			if (str[i] == '+') {
				positive = true;
			}
			else if (str[i] == '-') {
				positive = false;
			}
			else if (str[i] >= '0' && str[i] <= '9') {
				if (!(num.size() == 0 && str[i] == '0')) {
					num.push_back(str[i] - 48);
				}
			}
			else {
				number = 0;
				break;
			}
		}
		else if (spaceAllowed == false) {
			if (str[i] >= '0' && str[i] <= '9') {
				if (!(num.size() == 0 && str[i] == '0')) {
					num.push_back(str[i] - 48);
				}
			}
			else {
				break;
			}
		}
	}

	long long mult = 1;
	for (int i = num.size() - 1; i >= 0; i--) {
		number += num[i] * mult;
		mult *= 10;
	}

	if (positive == false) {
		number *= -1;
	}

	if (num.size() > 10 && positive == true) {
		number = INT_MAX;
	}
	else if (num.size() > 10 && positive == false) {
		number = INT_MIN;
	}

	if (number < INT_MIN) {
		number = INT_MIN;
	}
	else if (number > INT_MAX) {
		number = INT_MAX;
	}

	return number;
}