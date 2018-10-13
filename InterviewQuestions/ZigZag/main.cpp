#include <iostream>
#include <string>
#include <vector>

using namespace std;

string convert(string s, int numRows);

int main() {
	convert("ab", 1);
	return 0;
}

string convert(string s, int numRows) {
	int numRowsInGrid = (s.length() < numRows) ? s.length() : numRows;
	vector<string> grid(numRowsInGrid);

	if (numRows == 1) {
		return s;
	}

	bool down = false;
	int curRow = 0;
	for (auto c : s) {
		grid[curRow] += c;
		down = (curRow == 0 || curRow == numRows - 1) ? !down : down;
		curRow = (down == true) ? curRow + 1 : curRow - 1;
	}

	string zigzag{};
	for (auto row : grid) {
		zigzag.append(row);
	}

	return zigzag;
}