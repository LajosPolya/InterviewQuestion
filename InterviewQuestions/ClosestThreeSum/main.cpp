#include <vector>
#include <unordered_set>
#include <limits>
#include <cmath>
#include <algorithm>

using namespace std;

int threeSumClosest(vector<int>& nums, int target);

int main() {
	vector<int> list = { -1,2,1,-4 };

	int sum = threeSumClosest(list, 1);

	return 0;
}

int threeSumClosest(vector<int>& nums, int target) {
	int closest = INT_MAX;
	int absClosest = INT_MAX;
	bool breakLoop = false;

	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i++) {
		for (int j = i + 1; j < nums.size(); j++) {
			for (int k = j + 1; k < nums.size(); k++) {
				if (abs(nums[i] + nums[j] + nums[k] - target) < absClosest) {
					closest = nums[i] + nums[j] + nums[k];
					if (absClosest < abs(closest - target)) {
						return closest;
					}
					absClosest = abs(closest - target);
					if (absClosest == 0) {
						return closest;
					}
				}
			}
		}
	}
	return closest;
}
