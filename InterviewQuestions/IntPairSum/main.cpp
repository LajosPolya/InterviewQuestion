#include <iostream>
#include <unordered_map>

#define LEN 8

int main() {

	int arr[LEN] = {
		7, 3, 2, 4, 6, 1, 5, 5
	};
	std::unordered_map<int, int> map;


	for (int i = 0; i < LEN; i++) {
		std::unordered_map<int, int>::iterator it = map.find(arr[i]);

		if (it != map.end()) {
			it->second++;
		}
		else {
			map.insert({arr[i], 1});
		}
	}

	std::unordered_map<int, int> pairs;
	for (int i = 0; i < LEN; i++) {
		std::unordered_map<int, int>::iterator it = map.find(10 - arr[i]);
		if (it != map.end()) {
			if (it->first == arr[i] && it->second >= 2) {
				pairs.insert({it->first, arr[i]});
			}
			else if (it->first != arr[i] && pairs.find(arr[i]) == pairs.end()) {
				pairs.insert({ it->first, arr[i] });
			}
		}
	}

	for (auto elem : pairs) {
		std::cout << elem.first << " " << elem.second << std::endl;
	}

	while (1) {}

	return 0;
}