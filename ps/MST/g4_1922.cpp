#include <vector>
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int N, M;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	vector< vector< pair<int, int> > > m(N+1);

	for (int i=0;i<M;++i) {
		int u,v, c;
		cin >> u >> v >> c;
		m[u].push_back(make_pair(v, c));
		m[v].push_back(make_pair(u, c));
	}

	int connected = 0;
	vector<int> dist(N+1,1234567890);
	vector<int> prev(N+1, -1);
	vector<bool> visited(N+1, false);
	priority_queue< pair<int,int> > pq;

	long long ans = 0;
	pq.push(make_pair(0, 1));
	while (pq.empty() == false) {
		int here_cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (visited[here]) continue;
		else {
			//cout << here << " " << here_cost << endl;
			visited[here] = true;
			dist[here] = here_cost;
			ans += here_cost;
			for (int i = 0; i < m[here].size(); ++i) {
				int next = m[here][i].first;
				int cost = m[here][i].second;
				if (visited[next] == false && cost < dist[next]) {
					//cout << "in next:" << next << " " << cost << endl;
 					pq.push(make_pair(-cost, next));
					prev[next] = here;
				}
			}
		}
	}
	cout << ans << "\n";
}
