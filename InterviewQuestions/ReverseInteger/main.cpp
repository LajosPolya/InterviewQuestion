#include <iostream>
#include <vector>

using namespace std;

int reverse(int x);

int main() {

	cout << reverse((1534236469)) << endl;

	while (1) {

	}

	return 0;
}

int reverse(int x) {
	long long mod = 1;
	long long divide = 1;
	vector<long long> digits;

	bool isSigned = false;
	if (x < 0) {
		isSigned = true;
	}

	while (x % mod != x) {
		mod *= 10;
		int digit = x % mod;
		digit = digit / divide;
		if (isSigned == true) {
			digit *= -1;
		}
		digits.push_back(digit);

		divide *= 10;
	}

	long long times = 1;
	long long number = 0;
	for (int i = digits.size() - 1; i >= 0; i--) {
		number += digits[i] * times;
		times *= 10;
	}
	if (isSigned == true) {
		number *= -1;
	}

	if (number < -2147483648LL || number > 2147483647LL) {
		number = 0;
	}

	return number;
}