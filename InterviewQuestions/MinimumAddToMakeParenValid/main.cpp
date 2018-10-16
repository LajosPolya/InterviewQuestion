#include <string>

using namespace std;

int minAddToMakeValid(string S);

int main() {

}

int minAddToMakeValid(string S) {
	int numOpen = 0;
	int counter = 0;
	for (int i = 0; i < S.length(); i++) {
		if (S[i] == '(') {
			numOpen++;
		}
		else if(S[i] == ')' && numOpen == 0) {
			counter++;
		}
		else if (S[i] == ')') {
			if (numOpen > 0) {
				numOpen--;
			}
			else {
				counter++;
			}

		}
	}

	return counter + numOpen;
}