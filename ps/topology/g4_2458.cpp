#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int N, M;
vector< vector<int> > edges;
vector< int > parent_num;
vector< int > roots;
queue< int> q;

int main() {
	cin >> N >> M;
	edges = vector< vector<int> >(N+1);
	parent_num = vector< int >(N+1, 0);
	for (int i=0;i<M;++i) {
		int u, v;
		cin >> u >> v;
		edges[u].push_back(v);
		parent_num[v]++;
	}

	// 한바퀴 돌면서 부모가 없는(루트인) 노드를 찾는다.
	for (int i=1;i<=N;++i) {
		if (parent_num[i] == 0) {
			roots.push_back(i);
		}
	}

	vector<int> ans;
	vector<bool> visited(N+1, false);
	for (int i=0;i<roots.size();++i) {
		ans.push_back(roots[i]);
	}

	for (int i=0;i<roots.size();++i) {
		q.push(roots[i]);
		while (!q.empty()) {
			int here = q.front();
			q.pop();

			visited[here] = true;
			for (int j=0;j<edges[here].size();++j) {
				int next = edges[here][j];
				parent_num[next]--;
				if (parent_num[next] > 0) continue;
				else {
					ans.push_back(next);
					q.push(next);
				}
			}
		}
	}
	// 그래프에 들어오지 못한 노드는 전부 맨 앞에 밀어 넣는다.
	int cnt=0;
	for (int i=1;i<=N;++i) {
		if (visited[i] == false) {
			cnt++;
		}
	}

	cout << cnt << "\n";
}
