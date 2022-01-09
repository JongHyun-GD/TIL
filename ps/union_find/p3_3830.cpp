#include <vector>
#include <iostream>
using namespace std;

int N, M;
vector<int> parent;
vector<int> dist;

int update_diff(int a) {
	if (parent[a] == a) {
		return 0;
	}
	else {
		return dist[a] = update_diff(parent[a]) + dist[a];
	}
}

int find(int a) {
	if (parent[a] == a)
		return a;
	else {
		update_diff(a);
		return parent[a] = find(parent[a]);
	}
}

void uni(int a, int b, int c) {
	int parent_a = find(a);
	int parent_b = find(b);
	if (parent_a == parent_b) return ;
	else {
		parent[parent_a] = parent_b;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	while (true) {
		cin >> N >> M;
		if (N == 0 && M == 0) break;

		parent = vector<int>(N+1);
		for (int i=1; i<=N; ++i)
			parent[i] = i;
		dist = vector<int>(N+1, 0);

		for (int i=0; i<M; ++i) {
			char c;
			cin >> c;
			if (c == '!') {
				int a, b, c;
				cin >> a >> b >> c;
				uni(a, b, c);
			}
			if (c == '?') {
				int a, b;
				cin >> a >> b;
				int p_a = find(a);
				int p_b = find(b);
				if (p_a != p_b) {
					cout << "UNKNOWN\n";
				}
				else {
					cout << dist[a] - dist[b] << "\n";
				}
			}
		}
	}
}
