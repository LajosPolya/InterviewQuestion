#include <vector>
#include <iostream>

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
	long totalLen = nums1.size() + nums2.size();
	long first = -1;
	long insert = 0;

	if (nums1[nums1.size() - 1] < nums2[0]) {
		if (totalLen % 2 == 1) {
			if (totalLen / 2 < nums1.size()) {
				return nums1[totalLen / 2];
			}
			else {
				return nums2[nums1.size() - (totalLen / 2)];
			}
		}
	}
	else if (nums2[nums2.size() - 1] < nums1[0]) {
		if (totalLen % 2 == 1) {
			if (totalLen / 2 < nums2.size()) {
				return nums2[totalLen / 2];
			}
			else {
				return nums1[nums2.size() - (totalLen / 2)];
			}
		}
	}
	else {

	}
}