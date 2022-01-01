#include <vector>
#include <iostream>
#include <utility>
#include <cmath>

using namespace std;

int N, M;
int get_dist(vector< pair<int ,int> > &houses, int h, vector< pair<int, int> > &shops, int s)
{
	return abs(houses[h].first - shops[s].first) + abs(houses[h].second - shops[s].second);
}

int main(void)
{
	cin >> N >> M;
	vector< vector<int> > m(N, vector<int>(N));
	vector< pair<int, int> > houses;
	vector< pair<int, int> > shops;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++i)
		{
			cin >> m[i][j];
			if (m[i][j] == 1) houses.push_back(make_pair(i, j));
			if (m[i][j] == 2) shops.push_back(make_pair(i, j));
		}

	vector< vector<int> > dist(shops.size(), vector<int>(houses.size()));

	for (int s = 0; s < shops.size(); ++s)
	{
		for (int h = 0; h < houses.size(); ++h)
		{
			dist[s][h] = get_dist(houses, h, shops, s);
		}
	}

	dfs()


}
