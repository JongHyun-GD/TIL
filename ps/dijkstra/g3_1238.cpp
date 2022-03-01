#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <utility>
using namespace std;
typedef pair<int, int> pii;
#define INF 1010101010

int N, M, X;
vector< vector<pii> > adj;
vector< int > dist;

void dijkstra(int start) {
	priority_queue<pii> pq;
	dist.assign(N+1, INF);
	pq.push(make_pair(0, start));
	dist[start] = 0;
	while (pq.empty() == false) {
		int here = pq.top().second;
		int here_cost = -pq.top().first;
		pq.pop();

		if (dist[here] != here_cost) continue;

		for (int i=0; i<adj[here].size(); ++i) {
			int next = adj[here][i].second;
			int next_cost = adj[here][i].first;

			if (dist[next] > here_cost + next_cost) {
				dist[next] = here_cost + next_cost;
				pq.push(make_pair(-(here_cost+next_cost), next));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> N >> M >> X;
	adj = vector< vector<pii> >(N+1);
	for (int i=0; i<M; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back(make_pair(c, v));
	}

	vector<int> ans_dist(N+1, 0);
	for (int i=1; i<=N; ++i) {
		dijkstra(i);
		if (i==X) {
			for (int j=1;j<=N;++j) {
				ans_dist[j] += dist[j];
			}
		}
		else {
			ans_dist[i] += dist[X];
		}
	}

	int ans = -1;
	for (int i=1; i<=N; ++i) {
		ans = max(ans_dist[i], ans);
	}
	cout << ans << "\n";
}
