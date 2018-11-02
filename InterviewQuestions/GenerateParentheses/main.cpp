#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

unordered_set<string> generate(int n);
vector<string> generateParenthesis(int n);

int main() {

	generateParenthesis(2);

	return 0;
}

vector<string> generateParenthesis(int n) {
	if (n < 1) {
		return vector<string>();
	}

	auto set = generate(n);

	vector<string> parens;
	for (auto i : set) {
		parens.push_back(i);
	}

	return parens;
}

unordered_set<string> generate(int n) {
	unordered_set<string> curParens;

	if (n == 1) {
		return { "()" };
	}
	unordered_set<string> priorParens = generate(n - 1);

	for (auto i : priorParens) {
		curParens.insert(i + "()");
		curParens.insert("()" + i);
		curParens.insert("(" + i + ")");
	}

	return curParens;
}
