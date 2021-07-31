#include <vector>
#include <iostream>
#include <cmath>
#include <utility>
#include <queue>
using namespace std;

int	main(void)
{
	int V, sum;
	vector< vector< pair<int, int> > > m;
	cin >> V;
	m = vector< vector< pair<int ,int> > >(V+1);
	int i, u, v, c;
	for (i=0;i<V;++i)
	{
		cin >> u;
		while (1)
		{
			cin >> v;
			if (v == -1) break;
			cin >> c;
			m[u].push_back(make_pair(c, v));
		}
	}

	int max_dist = -1, max_v, nc, nv, end_a, end_b;
	// BFS
	queue< pair<int, int> > q;
	vector< bool > visited(V+1, false);
	visited[1] = true;
	for (i=0;i<m[1].size();++i)
		q.push(make_pair(m[1][i].first, m[1][i].second));
	while (!q.empty())
	{
		c = q.front().first;
		v = q.front().second;
		q.pop();

		//cout << v << " " << c << endl;
		if (visited[v]) continue;
		else visited[v] = true;
		if (max_dist < c) {
			max_dist = c;
			max_v = v;
		}
		for (i=0;i<m[v].size();++i)
		{
			nc = m[v][i].first;
			nv = m[v][i].second;
			if (visited[nv]) continue;
			else {
				q.push(make_pair(c + nc, nv));
			}
		}
	}
	end_a = max_v;
	visited = vector<bool>(V+1, false);
	visited[end_a] = true;
	max_dist = -1;
	for (i=0;i<m[end_a].size();++i)
		q.push(make_pair(m[end_a][i].first, m[end_a][i].second));
	while (!q.empty())
	{
		c = q.front().first;
		v = q.front().second;
		q.pop();

		if (visited[v]) continue;
		else visited[v] = true;
		if (max_dist < c) {
			max_dist = c;
			max_v = v;
		}
		for (i=0;i<m[v].size();++i)
		{
			nc = m[v][i].first;
			nv = m[v][i].second;
			if (visited[nv]) continue;
			else {
				q.push(make_pair(c + nc, nv));
			}
		}
	}
	cout << max_dist << "\n";
}
