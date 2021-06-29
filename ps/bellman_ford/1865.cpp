// gold 4 | bellmanford : warmhole
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define INF 987654321
typedef long long ll;
typedef struct	s_edge {
	ll u;
	ll v;
	ll c;
}				edge;
vector<edge> edges;
vector<ll> dist;
int N, M, W;

edge make_edge(ll _u, ll _v, ll _c)
{
	edge new_edge;

	new_edge.u = _u;
	new_edge.v = _v;
	new_edge.c = _c;
	return (new_edge);
}

int bellman_ford()
{
	ll i, j;
	ll u, v, c;
	dist[1] = 0;

	// N-1 edge relaxation
	for (i=1;i<N;++i)
	{
		// iterate all edges
		for (j=0;j<edges.size();++j)
		{
			u = edges[j].u;
			v = edges[j].v;
			c = edges[j].c;
			dist[v] = min(dist[v], dist[u] + c);
		}
	}

	// final iterate to detect minus cycle
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

int main(void)
{
	cin.tie(0);
	int TC; cin >> TC;
	while (TC--)
	{
		ll i;
		ll u, v, c;
		cin >> N >> M >> W;
		edges = vector<edge>();
		dist = vector<ll>(N+1, INF);
		for (i=0;i<M;++i)
		{
			cin >> u >> v >> c;
			edges.push_back(make_edge(u, v, c));
			edges.push_back(make_edge(v, u, c));
		}
		for (i=0;i<W;++i)
		{
			cin >> u >> v >> c;
			edges.push_back(make_edge(u, v, -c));
		}
		bellman_ford();
		if (bellman_ford() == -1)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
