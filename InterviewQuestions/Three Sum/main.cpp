#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums);

int main() {
	vector<int> a = { 12,13,12,13,-3,3,11,7,10,5,1,6,6,14,2,-8,-1,-4,3,-10,3,-13,7,-15,12,10,-2,-14,3,-3,-7,0,-12,12,-1,0,0,-13,-8,-12,7,0,9,-1,-8,-12,6,6,-1,-13,3,-13,-11,-4,9,-14,-9,14,9,2,-3,-13,9,0,-15,-15,7,-8,-12,6,-5,10,14,-11,-6,-9,14,8,4,-10,10,-8,14,6,3,8,0,2,8,-6,11,12,-3,5,-3,-11,6,11,-4,1,-6,-1,-4,-7,3,-2,-9,-5,-9,10,0,8,-12,-8,-1};
	vector<int> b = { 0, 1, 2 };

	vector<vector<int>> answer = threeSum(a);


	return 0;
}

vector<vector<int>> threeSum(vector<int>& nums) {
	vector<pair<int, pair<int, int>>> pairs;
	unordered_map<int, vector<pair<int, int>>> newIdea;

	for (int i = 0; i < nums.size(); i++) {
		for (int j = 0; j < nums.size(); j++) {
			if (i != j) {
				int sum = nums[i] + nums[j];
				auto listPairs = newIdea.find(sum);
				if (listPairs == newIdea.end()) {
					if (nums[i] < nums[j]) {
						newIdea[sum] = { { i, j } };
					}
					else {
						newIdea[sum] = { { j, i } };
					}
				}
				else {
					if (nums[i] < nums[j]) {
						listPairs->second.push_back({ i, j });
					}
					else {
						listPairs->second.push_back({ j, i });
					}
				}
			}
		}
	}

	
	vector<vector<int>> triplets;
	for (int i = 0; i < nums.size(); i++) {
		auto listPairs = newIdea.find(0 - nums[i]);
		if (listPairs != newIdea.end()) {
			vector<pair<int, int>> pairs = listPairs->second;
			for (int j = 0; j < pairs.size(); j++) {
				if (i != pairs[j].first && i != pairs[j].second) {
					vector<int> triplet;
					if (nums[i] > nums[pairs[j].first] && nums[i] > nums[pairs[j].second]) {
						triplet = { nums[pairs[j].first], nums[pairs[j].second], nums[i] };
					}
					else if (nums[i] < nums[pairs[j].first] && nums[i] < nums[pairs[j].second]) {
						triplet = { nums[i], nums[pairs[j].first], nums[pairs[j].second] };
					}
					else {
						triplet = { nums[pairs[j].first], nums[i], nums[pairs[j].second] };
					}

					auto it = find(triplets.begin(), triplets.end(), triplet);

					if (it == triplets.end()) {
						triplets.push_back(triplet);
					}
				}
			}
		}
	}

	return triplets;
}
