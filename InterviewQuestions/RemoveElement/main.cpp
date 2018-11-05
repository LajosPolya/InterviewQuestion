#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val);

int main() {


	return 0;
}

int removeElement(vector<int>& nums, int val) {
	int shift = 0;

	for (int i = 0; i < nums.size(); i++) {
		nums[shift] = nums[i];
		shift++;
		if (nums[i] == val) {
			shift--;
		}
	}
	return shift;
}
