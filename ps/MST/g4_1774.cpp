#include <vector>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <utility>
#define INF 1234567890
#define MAX_SIZE 1005
using namespace std;

int N, M, visit_cnt;
vector< vector<double> > m;
vector< pair<double, double> > pos;
vector< double > dist;
vector< bool > visited;

int main(void)
{
	cin.tie(0);
	// def
	int i, j, x, y, s, e, min_v;
	double ans, min_e;
	m = vector< vector<double> >(MAX_SIZE, vector<double>(MAX_SIZE, -1));
	pos = vector< pair<double, double> >(MAX_SIZE);
	// input
	cin >> N >> M;
	for (i=0;i<N;++i)
	{
		cin >> x >> y;
		pos[i].first = x;
		pos[i].second = y;
	}
	for (i=0;i<N;++i) // calc dist
		for (j=0;j<N;++j)
		{
			if (i == j) continue;
			m[i][j] =
			sqrt(pow(abs(pos[i].first - pos[j].first),2) +
				pow(abs(pos[i].second - pos[j].second),2));
		}
	for (i=0;i<M;++i)
	{
		cin >> s >> e;
		m[s-1][e-1] = 0;
		m[e-1][s-1] = 0;
	}
	// prim algorithm
	visited = vector< bool >(MAX_SIZE, false);
	visit_cnt = 1;
	visited[0] = true;
	dist = vector< double >(MAX_SIZE, INF);
	for (i=0;i<N;++i)
	{
		if (m[0][i] == -1) continue;
		dist[i] = min(dist[i], m[0][i]);
	}
	while (visit_cnt < N)
	{
		// find shortest edge
		min_e = INF;
		for (i=0;i<N;++i)
		{
			if (visited[i]) continue;
			if (min_e > dist[i]) {
				min_e = dist[i];
				min_v = i;
			}
		}
		//cout << "choice: " << min_v << endl;
		// update dist vector
		ans += min_e;
		visited[min_v] = true;
		visit_cnt++;
		for (i=0;i<N;++i)
			if (!visited[i])
				dist[i] = min(dist[i], m[min_v][i]);
	}

	printf("%.2f\n", ans);
	return 0;
}
