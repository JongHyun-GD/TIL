#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> v(N);
		for (int i=0;i<N;++i){
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		vector<bool> b_used(N, false);
		bool is_yes = true;
		for (int i=N;i>=1;i--) { // 찾는 숫자
			bool b_found = false;
			for (int j=N-1;j>=0;j--) { // 인덱스 루프
				if (b_used[j]) continue;
				for (int k=0;k<32;++k) {
					if ((v[j] >> k) == i) {
						b_used[j] = true;
						b_found = true;
						break;
					}
					else if ((v[j] >> k) < i) {
						break;
					}
				}
				if (b_found) break;
			}
			if (!b_found) {
				is_yes = false;
			}
		}
		if (is_yes) cout << "YES\n";
		else cout << "NO\n";
	}
}
