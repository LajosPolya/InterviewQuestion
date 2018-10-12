#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);

int main() {
	vector<int> one = { 1, 2, 3 };
	vector<int> two = { 4, 5 };
	cout << findMedianSortedArrays(one, two) << endl;

	while (1) {

	}

	return 0;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	vector<int> num;

	for (int i = 0; i < nums1.size(); i++) {
		num.push_back(nums1[i]);
	}

	for (int i = 0; i < nums2.size(); i++) {
		num.push_back(nums2[i]);
	}

	sort(num.begin(), num.end(), [](int num1, int num2) {
		return (num1 < num2);
	});

	if (num.size() % 2 == 1) {
		return (int)num[num.size() / 2];
	}
	else {
		return ((double)num[num.size() / 2] + num[num.size() / 2 + 1]) / 2.0;
	}
}