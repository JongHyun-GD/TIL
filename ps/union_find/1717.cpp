#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, M;
vector<int> parent;

int find(int x)
{
	if (parent[x] == x)
		return x;
	else
	{
		int y = find(parent[x]);
		parent[x] = y;
		return y;
	}
}

void ft_union(int x, int y)
{
	int p_x = find(x);
	int p_y = find(y);

	if (p_x == p_y) return;
	else
	{
		parent[p_y] = p_x;
	}
}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	parent = vector<int>(N+1, 0);
	for (int i = 0; i <= N; ++i)
	{
		parent[i] = i;
	}

	int o, a, b;
	for (int m = 0; m < M; ++m)
	{
		cin >> o >> a >> b;
		if (o == 0)
		{
			ft_union(a, b);
		}
		if (o == 1)
		{
			if (find(a) == find(b)) cout << "YES\n";
			else cout << "NO\n";
		}
	}

	return (0);
}
