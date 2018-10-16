#include <vector>
#include <unordered_map>

using namespace std;

int threeSumMulti(vector<int>& A, int target);

int main() {
	vector<int> A = { 3, 3, 3, 0 };

	threeSumMulti(A, 6);

	return 0;
}

int threeSumMulti(vector<int>& A, int target) {

	int numberOfTuples = 0;
	for (int i = 0; i < A.size(); i++) {
		for (int j = i + 1; j < A.size(); j++) {
			for (int k = j + 1; k < A.size(); k++) {
				if (A[i] + A[j] + A[k] == target) {
					numberOfTuples += 1;
				}
			}
		}
	}

	return numberOfTuples;
}