#include <vector>
#include <iostream>
#include <cmath>
#include <map>
using namespace std;

vector<int> sizes;
vector<int> parent;
map<string, int> str2int;

int find(int a) {
	if (parent[a] == a)
		return a;
	else
		return parent[a] = find(parent[a]);
}

void uni(int a, int b) {
	int parent_a = find(a);
	int parent_b = find(b);

	if (parent_a != parent_b) {
		sizes[parent_a] += sizes[parent_b];
		parent[parent_b] = parent_a;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T; cin >> T;
	while (T--) {
		int cnt=0, K; cin >> K;
		sizes = vector<int>(2*(K+1), 1);
		parent = vector<int>(2*(K+1));
		for (int i=0; i<=2*K; ++i)
			parent[i] = i;
		for (int i=0; i<K; ++i) {
			string s1, s2;
			cin >> s1 >> s2;

			int a, b;
			if (str2int.find(s1) == str2int.end()) {
				str2int[s1] = ++cnt;
				a = cnt;
			}
			else {
				a = str2int[s1];
			}
			if (str2int.find(s2) == str2int.end()) {
				str2int[s2] = ++cnt;
				b = cnt;
			}
			else {
				b = str2int[s2];
			}

			uni(a, b);
			cout << sizes[find(a)] << "\n";
		}
	}
}
