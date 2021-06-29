// 타임머신 [Bellman ford]
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
#define INF 30000000009
typedef long long ll;
vector<ll> dist;
ll V, E;

typedef struct	s_edge {
	ll u;
	ll v;
	ll c;
}				edge;
vector< edge > edges;

edge	make_edge(ll _u, ll _v, ll _c)
{
	edge newedge;

	newedge.u = _u;
	newedge.v = _v;
	newedge.c = _c;
	return (newedge);
}

int		bellmanford()
{
	ll i, j;
	ll u, v, c;

	// init
	// 시작점을 제외한 모든 거리를 무한으로 설정한다.
	dist = vector<ll>(V+1, INF);
	dist[1] = 0;
	for (i=0;i<edges.size();++i)
		if (edges[i].u == 1)
			dist[edges[i].v] = edges[i].c;
	// 시작점을 제외한 모든 정점을 순회하면서 edge relaxation을 수행한다.
	for (i=1;i<V;++i)
	{
		for (j=0;j<edges.size();++j)
		{
			if (dist[edges[j].u] == INF) continue;
			u = edges[j].u;
			v = edges[j].v;
			c = edges[j].c;
			dist[v] = min(dist[v], dist[u] + c);
		}
	}
	// 마지막으로 사이클이 있는지 확인하기 위해 한번 돌아보면서
	// 바뀌는 값이 있는지 확인한다.
	for (j=0;j<edges.size();++j)
	{
		u = edges[j].u;
		v = edges[j].v;
		c = edges[j].c;
		if (dist[v] > dist[u] + c)
			return (-1);
	}
	return (0);
}

int		main(void)
{
	ll i;
	ll u,v,c;
	cin.tie(0);
	cin >> V >> E;
	edges = vector< edge >();

	for (i=0;i<E;++i)
	{
		cin >> u >> v >> c;
		edges.push_back(make_edge(u,v,c));
	}
	int res = bellmanford();
	if (res == -1)
		cout << "-1\n";
	else {
		for (i=2;i<=V;++i)
		{
			if (dist[i] == INF) cout << "-1\n";
			else cout << dist[i] << "\n";
		}
	}
	return (0);
}
