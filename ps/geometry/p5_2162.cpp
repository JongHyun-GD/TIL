#include <iostream>
#include <cmath>
#include <vector>
#include <utility>

const int INF = 1234567890;

std::vector<std::vector< std::pair<int,int> > > v;
std::vector<int> g;

int ccw(std::pair<int, int> &a, std::pair<int, int> &b, std::pair<int, int> &c) {
    int op = a.first*b.second + b.first*c.second + c.first*a.second;
    op -= (a.second*b.first + b.second*c.first + c.second*a.first);
    if (op > 0)return 1;
    else if (op == 0)return 0;
    else return -1;
}

bool is_connected(int i, int j)
{
	std::pair<int,int> a = v[i][0];
	std::pair<int,int> b = v[i][1];
	std::pair<int,int> c = v[j][0];
	std::pair<int,int> d = v[j][1];
	if (ccw(a, b, c) * ccw(a,b,d) == 0 && ccw(c,d,a) * ccw(c,d,b) == 0)
	{
		return c <= b && a <= d;
	}
	if (ccw(a, b, c) * ccw(a,b,d) <= 0 && ccw(c,d,a) * ccw(c,d,b) <= 0)
		return true;
	else return false;
}

int find(int i)
{
	if (g[i] == i)
		return i;
	else
	{
		int parent = find(g[i]);
		g[i] = parent;
		return parent;
	}
}

void ft_union(int i, int j)
{
	int parent_i = find(i);
	int parent_j = find(j);

	g[parent_i] = g[parent_j];
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	int N; std::cin >> N;
	v = std::vector<std::vector< std::pair<int,int> > >(N, std::vector< std::pair<int,int> >(2));
	g = std::vector<int>(N);
	for (int i = 0; i < N; ++i)
		g[i] = i;

	int x1, x2, y1, y2;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> x1 >> y1 >> x2 >> y2;

		if (x1 > x2 || (x1 == x2 && y1 > y2))
		{
			int tx = x1;
			int ty = y1;
			x1 = x2;
			y1 = y2;
			x2 = tx;
			y2 = ty;
		}

		v[i][0] = std::make_pair(x1, y1);
		v[i][1] = std::make_pair(x2, y2);
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (g[i] == g[j]) continue;

			if (is_connected(i, j))
				ft_union(i, j);
		}
	}

	std::vector<int> ans(N, 0);
	int g_count = 0;
	for (int i = 0; i < N; ++i)
	{
		if (ans[find(g[i])] == 0)
			g_count++;
		ans[find(g[i])]++;
	}
	int biggest = 0;
	for (int i = 0; i < N; ++i)
	{
		if (ans[biggest] < ans[i])
			biggest = i;
	}
	std::cout << g_count << "\n" << ans[biggest] << "\n";
}
