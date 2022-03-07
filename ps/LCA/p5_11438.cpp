#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
using namespace std;
#define MAX_INT 1234567890
typedef pair<int,int> pii;

int N, M, max_height;
vector< vector<int> > adj;
vector< vector<int> > parent;
vector< int > depth;

// Find parent for each node
void FindParentDFS(int par, int now, int dep) {
	if (adj[now].size() == 0) return ;

	parent[now][0] = par;
	depth[now] = dep;

	for (int i=0; i<adj[now].size(); ++i) {
		if (adj[now][i] != par) {
			FindParentDFS(now, adj[now][i], dep+1);
		}
	}
}

int FindLCA(int a, int b) {
	// 깊이를 같게 맞춘다.
	if (depth[a] != depth[b]) {
		if (depth[a] < depth[b]) {
			swap(a, b);
		}
		for (int i=max_height; i>=0; --i) {
			if (depth[parent[a][i]] >= depth[b]) {
				a = parent[a][i];
			}
		}
	}

	// Find LCA
	if (a != b) {
		for (int k=max_height; k>=0; --k) {
			if (parent[a][k] != 0 && parent[a][k] != parent[b][k]) {
				a = parent[a][k];
				b = parent[b][k];
			}
		}

		a = parent[a][0];
	}

	return a;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> N;
	adj = vector< vector<int> >(N+1);
	for (int i=0;i<N-1;++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int temp = N;
	while (temp > 1) {
		temp = temp >> 1;
		max_height++;
	}

	depth = vector<int> (N+1);
	parent = vector< vector<int> >(N+1, vector<int>(max_height+1,0));

	FindParentDFS(1, 1, 1);

	for (int k=1; k<=max_height; ++k) {
		for (int idx=2; idx<=N; ++idx) {
			if (parent[idx][k-1] != 0)
				parent[idx][k] = parent[parent[idx][k-1]][k-1];
		}
	}

	cin >> M;
	for (int i=0;i<M;++i) {
		int a,b;
		cin >> a >> b;
		cout << FindLCA(a, b) << "\n";
	}
}
