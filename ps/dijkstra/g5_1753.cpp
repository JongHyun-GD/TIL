#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
#define INF 1234567890

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int V, E; cin >> V >> E;
	int start_node; cin >> start_node;

	vector< vector< pair<int,int> > > m(V+1);
	for (int i=0;i<E;++i) {
		int s, e, w;
		cin >> s >> e >> w;
		m[s].push_back(make_pair(w,e));
	}

	vector< int > dist(V+1, INF);
	dist[start_node] = 0;
	priority_queue< pair<int, int> > pq;
	pq.push(make_pair(0, start_node));
	while(pq.empty() == false) {
		int cost = -pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (dist[node] != cost) continue;
		for (int i=0;i<m[node].size();++i) {
			int next_cost = cost + m[node][i].first;
			int next = m[node][i].second;

			if (dist[next] > next_cost) {
				dist[next] = next_cost;
				pq.push(make_pair(-next_cost, next));
			}
		}
	}

	for (int i=1;i<=V;++i) {
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << "\n";
	}
}
