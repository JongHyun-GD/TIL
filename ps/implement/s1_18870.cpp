#include <set>
#include <vector>
#include <iostream>

using namespace std;

vector<int> orderedArr;

int bin_find(int val) {
	int l, r, c;

	l = 0; r = orderedArr.size();
	while (l <= r) {
		c = (l + r) / 2;
		if (orderedArr[c] == val)
			return c;
		else if (orderedArr[c] < val) {
			l = c + 1;
		}
		else {
			r = c - 1;
		}
	}
	return -1;
}

int main() {
	int N; cin >> N;
	set<int> s;
	vector<int> unzippedArr(N);
	vector<int> zippedArr(N);

	int val;
	for (int i = 0; i < N; ++i) {
		cin >> val;
		unzippedArr[i] = val;
		s.insert(val);
	}

	orderedArr = vector<int>(s.begin(), s.end());
	for (int i = 0; i < N; ++i) {
		cout << bin_find(unzippedArr[i]);
		if (i == N - 1) cout << "\n";
		else cout << " ";
	}
}
