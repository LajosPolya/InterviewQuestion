#include <iostream>
#include <unordered_map>

#define LEN 10

int main() {
	int arr[LEN] = {
		1, 2, 3, 4, 5, 5, 6, 7, 8, 9
	};
	int mostFrequent = 0;
	int num = arr[0];
	std::unordered_map<int, int> map;

	for (int i = 0; i < LEN; i++) {
		std::unordered_map<int, int>::iterator it = map.find(arr[i]);
		if (it != map.end()) {
			it->second++;
			if (map[arr[i]] > mostFrequent) {
				mostFrequent = it->second;
				num = arr[i];
			}
		}
		else {
			map.insert({ arr[i], 1 });
		}
	}

	for (auto elem : map) {
		std::cout << elem.first << "" << elem.second << std::endl;
	}

	std::cout << std::endl << num << " " << mostFrequent << std::endl;

	while (1) {}

	return 0;
}