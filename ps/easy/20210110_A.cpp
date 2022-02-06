#include <vector>
#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;

	while (T--) {
		int N; cin >> N;
		int min_num = 1234567890, max_num = -1;
		for (int i=0;i<N;++i) {
			int num; cin >> num;
			if (min_num > num) min_num = num;
			if (max_num < num) max_num = num;
		}
		cout << max_num - min_num << "\n";
	}
}
