#include <vector>
#include <queue>
#include <cmath>
#include <iostream>
#include <queue>
using namespace std;
#define INF 1010101010
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (true)
	{
		int N, M;
		cin >> N >> M;
		if (N == 0 && M == 0)
			break;
		int S, D;
		cin >> S >> D;
		vector< vector< pair<int, int> > > m(N);
		for (int i = 0; i < M; ++i)
		{
			int u, v, w;
			cin >> u >> v >> w;
			m[u].push_back(make_pair(w, v));
		}

		int shortest = INF;
		vector<int> dist(N, INF);
		vector< vector<int> > prev(N);
		dist[S] = 0;
		priority_queue< pair<int, int> > pq;
		pq.push(make_pair(0, S));

		// dijkstra 1
		while (pq.empty() == false)
		{
			int node = pq.top().second;
			int node_dist = -pq.top().first;
			pq.pop();

			if (dist[node] != node_dist)
				continue;
			for (int i = 0; i < m[node].size(); ++i)
			{
				int next = m[node][i].second;
				int next_dist = m[node][i].first;
				if (dist[next] > node_dist + next_dist)
				{
					dist[next] = node_dist + next_dist;
					prev[next].clear();
					prev[next].push_back(node);
					pq.push(make_pair(-(node_dist + next_dist), next));
				}
				else if (dist[next] == node_dist + next_dist)
				{
					prev[next].push_back(node);
				}
			}
		}

		// Remove shortest paths
		queue<int> q;
		vector< bool > visited(N, false);
		q.push(D);
		while (q.empty() == false)
		{
			int here = q.front();
			// cout << here << " ";
			q.pop();

			for (int j = 0; j < prev[here].size(); ++j)
			{
				int next = prev[here][j];
				for (int j = 0; j < m[next].size(); ++j)
				{
					if (m[next][j].second == here)
					{
						// cout << next << " " << here << endl;
						m[next][j].first = INF;
					}
				}
				if (visited[next] == false) {
					visited[next] = true;
					q.push(next);
				}
			}
		}
		// dijkstra 2
		dist.assign(dist.size(), INF);
		dist[S] = 0;
		pq.push(make_pair(0, S));
		while (pq.empty() == false)
		{
			int node = pq.top().second;
			int node_dist = -pq.top().first;
			pq.pop();

			if (dist[node] != node_dist)
				continue;
			for (int i = 0; i < m[node].size(); ++i)
			{
				int next = m[node][i].second;
				int next_dist = m[node][i].first;
				if (dist[next] > node_dist + next_dist)
				{
					dist[next] = node_dist + next_dist;
					pq.push(make_pair(-(node_dist + next_dist), next));
				}
			}
		}
		if (dist[D] == INF)
			cout << "-1\n";
		else
			cout << dist[D] << "\n";
	}
}
