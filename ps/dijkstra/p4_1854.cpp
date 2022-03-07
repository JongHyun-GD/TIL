#include <vector>
#include <queue>
#include <cmath>
#include <iostream>
#include <utility>
using namespace std;
#define INF 1010101010

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n, m, k; cin >> n >> m >> k;
	vector< vector< pair<int, int> > > adj(n+1);
	for (int i=0;i<m;++i) {
		int a,b,c;
		cin >> a >> b >> c;

		adj[a].push_back(make_pair(c, b));
	}

	vector< priority_queue<int> > dist(n+1);
	dist[1].push(0);
	priority_queue<pair<int,int> > pq;
	pq.push(make_pair(0, 1));

	while (pq.empty() == false) {
		int here = pq.top().second;
		int here_dist = -pq.top().first;
		pq.pop();

		for (int i=0;i<adj[here].size();++i) {
			int next = adj[here][i].second;
			int next_dist = adj[here][i].first;
			//cout << next << " " << dist[next].size() << endl;
			if (dist[next].size() < k) {
				dist[next].push(here_dist + next_dist);
				pq.push(make_pair(-(here_dist+next_dist), next));
			}
			else if (dist[next].top() > here_dist + next_dist) {
				dist[next].pop();
				dist[next].push(here_dist + next_dist);
				pq.push(make_pair(-(here_dist+next_dist), next));
			}
		}
	}

	for (int i=1;i<=n;++i) {
		if (dist[i].size() == k) {
			cout << dist[i].top() << "\n";
		}
		else {
			cout << "-1\n";
		}
	}
}
