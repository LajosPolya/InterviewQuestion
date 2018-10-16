#include <iostream>
#include <vector>

using namespace std;

vector<int> sortArrayByParityII(vector<int>& A);

int main() {

	vector<int> A = { { 4, 2, 5, 7 } };
	sortArrayByParityII(A);
	return 0;
}

vector<int> sortArrayByParityII(vector<int>& A) {

	for (int i = 0; i < A.size() - 1; i++) {
		if (i % 2 == 0 && A[i] % 2 != 0) {
			for (int j = i + 1; j < A.size(); j++) {
				if (A[j] % 2 == 0 && j % 2 != 0) {
					int temp = A[i];
					A[i] = A[j];
					A[j] = temp;
				}
			}
		}
		else if (i % 2 == 1 && A[i] % 2 != 1) {
			for (int j = i + 1; j < A.size(); j++) {
				if (A[j] % 2 == 1 && j % 2 != 1) {
					int temp = A[i];
					A[i] = A[j];
					A[j] = temp;
				}
			}
		}
	}

	return A;
}