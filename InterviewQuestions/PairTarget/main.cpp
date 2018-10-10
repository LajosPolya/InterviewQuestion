#include <unordered_map>
#include <vector>

std::vector<int> twoSum(std::vector<int>& nums, int target);
std::vector<int> twoSum1(std::vector<int>& nums, int target);


int main(void) {
	return 0;
}

std::vector<int> twoSum1(std::vector<int>& nums, int target) {
	std::unordered_map<int, int> numMap{};

	for (int i = 0; i < nums.size(); i++) {
		auto it = numMap.find(target - nums[i]);
		if (it != numMap.end() && i != it->second) {
			return { i, it->second };
		}

		numMap[nums[i]] = i;
	}
}

std::vector<int> twoSum(std::vector<int>& nums, int target) {
	std::unordered_map<int, int> numMap{};

	for (int i = 0; i < nums.size(); i++) {
		numMap[nums[i]] = i;
	}

	for (int i = 0; i < numMap.size(); i++) {
		auto it = numMap.find(target - nums[i]);
		if (it != numMap.end() && i != it->second) {
			return { i, it->second };
		}
	}
}