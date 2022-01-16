#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
using namespace std;
#define MAX_INT 1234567890
typedef pair<int,int> pii;

int N, max_height;
vector< vector<pii> > adj;
vector< vector<pii> > parent;
vector< int > depth;

// parent[a][b] ==> (a의 2^b번째 부모의 노드 번호, 거기까지의 거리의 합)
void find_parent(int par, int here, int dep, int dist) {
	parent[here][0].first = par;
	parent[here][0].second = dist;
	depth[here] = dep;

	for (int i=0;i<adj[here].size();++i) {
		int next = adj[here][i].second;
		int next_dist = adj[here][i].first;
		if (next == parent[here][0].first) continue;
		else {
			find_parent(here, next, dep+1, next_dist);
		}
	}
}

int find_dist_lca(int a, int b) {
	int dist_a=0, dist_b=0;
	// depth를 같게 맞춘다.
	if (depth[a] != depth[b]) {
		if (depth[a] < depth[b]) { // 항상 a가 더 깊다.
			swap(a, b);
		}

		for (int i=max_height;i>=0;--i) {
			if (depth[parent[a][i].first] >= depth[b]) {
				dist_a += parent[a][i].second;
				a = parent[a][i].first;
			}
		}
	}

	// find lca
	if (a != b) {
		while (parent[a][0].first != parent[b][0].first) {
			for (int i=max_height;i>=0;--i) {
				if (parent[a][i].first != 0 && parent[a][i].first != parent[b][i].first) {
					dist_a += parent[a][i].second;
					//cout << "dist a = " << dist_a << " " << a << " " << i << endl;
					a = parent[a][i].first;
					//cout << "dist b = " << dist_b << " " << a << " " << i << endl;
					dist_b += parent[b][i].second;
					b = parent[b][i].first;
				}
			}
		}
		dist_a += parent[a][0].second;
		dist_b += parent[b][0].second;
	}
	return (dist_a + dist_b);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> N;
	adj = vector< vector<pii> >(N+1);
	int u, v, c;
	for (int i=0;i<N-1;++i) {
		cin >> u >> v >> c;
		adj[u].push_back(make_pair(c, v));
		adj[v].push_back(make_pair(c, u));
	}
	int temp = N;
	max_height=0;
	while (temp > 1) {
		temp = temp >> 1;
		max_height++;
	}

	parent = vector< vector<pii> >(N+1, vector<pii>(max_height+1, make_pair(0,0)));
	depth = vector<int>(N+1, 0);
	find_parent(0, 1, 1, 0);

	for (int k=1;k<=max_height;++k) {
		for (int n=1;n<=N;++n) {
			if (k <= depth[n]) {
				parent[n][k].second = parent[parent[n][k-1].first][k-1].second + parent[n][k-1].second;
				parent[n][k].first = parent[parent[n][k-1].first][k-1].first;
				//cout << n << " " << k << " " << parent[n][k].second << endl;
			}
		}
	}

	int M; cin >> M;
	for (int i=0;i<M;++i) {
		int a,b;
		cin >> a >> b;
		cout << find_dist_lca(a, b) << "\n";
	}
}
