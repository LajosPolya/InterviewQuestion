#include <vector>
#include <utility>

using namespace std;

int maxArea(vector<int>& height);
int calculateArea(pair<int, int> oldColumn, pair<int, int> newColumn);

int main() {
	vector<int> list = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	int max = maxArea(list);

	return 0;
}


int maxArea(vector<int>& height) {
	int maxCurArea = 0;
	int maxSummedHeight = 0;
	pair<int, int> highest;
	pair<int, int> lowest;

	if (height[0] >= height[1]) {
		highest = { height[0], 0 };
		lowest = { height[1], 1 };
	}
	else {
		highest = { height[1], 1 };
		lowest = { height[0], 0 };
	}
	maxCurArea = lowest.first;
	maxSummedHeight = highest.first + lowest.first;

	int i = 0;
	int j = height.size() - 1;

	while (i != j) {
		int curArea = calculateArea({ height[i], i }, { height[j], j });

		if (curArea > maxCurArea) {
			maxCurArea = curArea;
		}
		if (height[i] > height[j]) {
			j--;
		}
		else {
			i++;
		}
	}
	
	return maxCurArea;
}

int calculateArea(pair<int, int> oldColumn, pair<int, int> newColumn) {
	int area = 0;
	if (oldColumn.first >= newColumn.first) {
		area = newColumn.first * (newColumn.second - oldColumn.second);
	}
	else {
		area = oldColumn.first * (newColumn.second - oldColumn.second);
	}

	return area;
}