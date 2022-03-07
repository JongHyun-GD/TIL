#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int N, M;
vector<int> parent;

void init_root()
{
	for (int i = 0; i < parent.size(); ++i)
		parent[i] = i;
}

int find(int n)
{
	if (parent[n] == n) {
		return n;
	}
	else {
		int m = find(parent[n]);
		parent[n] = m;
		return m;
	}
}

int my_union(int s, int e)
{
	int p_s, p_e;
	p_s = find(s);
	p_e = find(e);
	if (p_s == p_e) {
		return (-1);
	}
	else {
		parent[p_s] = parent[p_e];
	}
	return (0);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	parent = vector<int> (N+1);
	init_root();

	int start, end;
	for (int i = 1; i <= M; ++i)
	{
		cin >> start >> end;
		if (my_union(start, end) == -1) {
			cout << i << "\n";
			return (0);
		}
	}
	cout << "0\n";

	return (0);
}
