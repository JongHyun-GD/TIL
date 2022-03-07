#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define INF 1010101010

class Info {
public:
	int here;
	int dist;
	int cost;
	Info(int h, int d, int c) :
		here(h), dist(d), cost(c) {}
};

bool operator<(const Info& li, const Info& ri) {
	return li.dist < ri.dist;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int V, M, E;
		cin >> V >> M >> E;
		vector< vector<Info> > m(V+1);
		int u, v, c, d;
		for (int i=0; i<E; ++i) {
			cin >> u >> v >> c >> d;
			m[u].push_back(Info(v,d,c));
		}

		vector< vector<int> > dp(V+1,vector<int>(M+1, INF));
		for (int k=0;k<=M;++k) {
			dp[0][k] = 0;
		}
		priority_queue<Info> pq;
		pq.push(Info(1,0,0));
		while (pq.empty() == false) {
			int dist = -pq.top().dist;
			int cost = pq.top().cost;
			int here = pq.top().here;
			pq.pop();

			for (int i=0; i<m[here].size(); ++i) {
				int next = m[here][i].here;
				int next_cost = m[here][i].cost;
				int next_dist = m[here][i].dist;

				if (M >= next_cost+cost && dp[next][next_cost+cost] > dist+next_dist) {
					pq.push(Info(next, -(next_dist + dist), next_cost + cost));
					for (int k=next_cost+cost; k <= M; ++k) {
						if (dp[next][k] > dist+next_dist) {
							dp[next][k] = dist+next_dist;
						}
					}
				}
			}
		}
		if (dp[V][M] == INF) {
			cout << "Poor KCM\n";
		} else {
			cout << dp[V][M] << "\n";
		}
	}
}
