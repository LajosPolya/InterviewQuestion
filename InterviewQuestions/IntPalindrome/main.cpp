#include <vector>

using namespace std;

bool isPalindrome(int x);
vector<int> intToVector(int x);
bool isPalindrome(vector<int> vec);
bool isPalindrome2(int x);


int main() {

	isPalindrome(1000030001);
	return 0;
}

bool isPalindrome2(int x) {
	/*
		mod *= 10;
		int y = x % mod;
		y /= div;
		vec.push_back(y);
		div *= 10;
	*/
	if (x < 0) {
		return false;
	}
	else if (x >= 0 && x < 10) {
		return true;
	}
	else if (x >= 10 && x < 100) {
		if (x / 10 != x % 10) {
			return false;
		}
		else {
			return true;
		}
	}
	else if (x % 10 == 0) {
		return false;
	}

	int y = 0;
	while (y < x) {
		y = y * 10 + x % 10;
		x /= 10;
	}

	return x == y || x == y / 10;
}

bool isPalindrome(int x) {
	if (x < 0) {
		return false;
	}
	else if (x >= 0 && x < 10) {
		return true;
	}

	vector<int> vec = intToVector(x);
	bool isPal = isPalindrome(vec);

	return isPal;
}

vector<int> intToVector(int x) {
	vector<int> vec;
	long long div = 1;
	long long mod = 1;
	while (x % mod != x) {
		mod *= 10;
		int y = x % mod;
		y /= div;
		vec.push_back(y);
		div *= 10;
	}

	return vec;
}

bool isPalindrome(vector<int> vec) {

	if (vec.size() == 2) {
		if (vec[0] == vec[1]) {
			return true;
		}
		else {
			return false;
		}
		
	}
	else if (vec.size() == 3) {
		if (vec[0] == vec[2]) {
			return true;
		}
		else {
			return false;
		}
	}

	for (int i = 0; i < vec.size() / 2; i++) {
		if (vec[i] != vec[vec.size() - i - 1]) {
			return false;
		}
	}
	return true;
}