#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int a, b, c;
		cin >> a >> b >> c;

		if ((2*b-c) > 0 && (2*b-c) % a == 0) {
			cout << "YES\n";
			continue;
		}
		if ((a+c)%(2*b) == 0) {
			cout << "YES\n";
			continue;
		}
		if ((2*b-a) > 0 && (2*b-a) % c == 0) {
			cout << "YES\n";
			continue;
		}
		cout << "NO\n";
	}
}
