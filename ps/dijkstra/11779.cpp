#include <vector>
#include <cmath>
#include <utility>
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PLL;
#define INF 1234567890

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int V, E; cin >> V >> E;
	int start, end;
	ll u,v,w;
	vector< vector<PLL> > m(1005);
	vector< ll > dist(1005, INF);
	vector< ll > from(1005, -1);
	priority_queue<PLL> pq;
	for (int i=0;i<E;++i)
	{
		cin >> u >> v >> w;
		int dup = -1;
		for (int j=0;j<m[u].size();++j)
			if (m[u][j].second == v)
				dup = j;
		if (dup != -1 && m[u][dup].first > w) m[u][dup].first = w;
		else if (dup == -1) m[u].push_back(make_pair(w,v));
	}
	cin >> start >> end;

	// dijkstra
	int here, cost, next, nextcost;
	dist[start] = 0;
	pq.push(make_pair(0, start));
	while (!pq.empty())
	{
		cost = -pq.top().first;
		here = pq.top().second;
		pq.pop();

		if (dist[here] < cost) continue;
		for (int i=0;i<m[here].size();++i)
		{
			next = m[here][i].second;
			nextcost = m[here][i].first;
			if (dist[next] > cost + nextcost) {
				dist[next] = cost + nextcost;
				pq.push(make_pair(-dist[next], next));
				from[next] = here;
			}
		}
	}
	cout << dist[end] << "\n";
	// 최단 경로의 벡터를 만든다.
	vector<int> route;
	here = end;
	while (here != start)
	{
		route.push_back(here);
		here = from[here];
	}
	route.push_back(start);
	cout << route.size() << "\n";
	// 최단 길이를 프린트한다
	for (int i=route.size()-1;i>=0;--i)
	{
		cout << route[i];
		if (i != 0)
			cout << " ";
	}
	return (0);
}
