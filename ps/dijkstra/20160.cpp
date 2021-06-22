#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <utility>

#define MAX_SIZE 10101
#define INF 99999999999999
typedef long long ull;
using namespace std;

vector< vector< pair<ull, ull> > >map;

void	dijkstra(ull start, vector<ull> *dist)
{
	priority_queue< pair<ull, ull>, vector< pair<ull, ull> >, greater< pair<ull,ull> > > pq;

	pq.push(make_pair(0, start));
	(*dist)[start] = 0;

	while (!pq.empty())
	{
		ull cost = pq.top().first;
		ull here = pq.top().second;

		pq.pop();
		if ((*dist)[here] < cost) continue;
		for (int i = 0; i < map[here].size(); ++i)
		{
			ull next = map[here][i].second;
			ull nextcost = map[here][i].first;

			if ((*dist)[next] > (*dist)[here] + nextcost)
			{
				(*dist)[next] = (*dist)[here] + nextcost;
				pq.push(make_pair((*dist)[next], next));
			}
		}
	}
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ull i, j, s, e, w;
	ull x_s;
	ull V, E; cin >> V >> E;
	map = vector< vector< pair<ull, ull> > >(MAX_SIZE);
	vector< ull > route(10);
	vector< ull > x_w(MAX_SIZE, INF);
	vector< ull > y_w(MAX_SIZE);

	for (i=0;i<E;++i)
	{
		cin >> s >> e >> w;
		map[s].push_back(make_pair(w, e));
		map[e].push_back(make_pair(w, s));
	}
	for (i=0;i<10;++i)
		cin >> route[i];
	cin >> x_s;

	dijkstra(x_s, &x_w);
	ull sum = 0;
	ull ans = INF;
	if (x_s == route[0]) ans = x_s;
	for (i=0;i<9;++i)
	{
		fill(y_w.begin(), y_w.end(), INF);
		dijkstra(route[i], &y_w);
		while (y_w[route[i+1]] >= INF){
			i++;
			if (i >= 9)
				break;
		}
		if (i >= 9)
			break;
		if (y_w[route[i+1]] < INF && route[i+1] < ans && sum+y_w[route[i+1]] >= x_w[route[i+1]])
			ans = route[i+1];
		if (y_w[route[i+1]] < INF)
			sum += y_w[route[i+1]];
	}
	if (ans == INF) ans = -1;
	cout << ans << "\n";
	return (0);
}
