#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums);

int main() {
	vector<int> vec = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };

	int size = removeDuplicates(vec);

	return 0;
}

int removeDuplicates(vector<int>& nums) {
	int replace = 1;

	if (nums.size() == 0) {
		return 0;
	}

	for (int i = 1; i < nums.size(); i++) {
		if (nums[replace - 1] != nums[i]) {
			nums[replace] = nums[i];
			replace++;
		}
	}

	return replace;
}
