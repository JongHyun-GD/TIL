#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> root;

typedef struct s_edge {
	int s;
	int e;
	int v;
}		edge;

struct cmp {
	bool operator()(edge a, edge b) {
		return a.v > b.v;
	}
};

int find_root(int idx)
{
	int temp;

	temp = root[idx];
	while (root[temp] != temp)
	{
		temp = root[temp];
	}
	return temp;
}

int main(void)
{
	cin.tie(0);

	int V, E; cin >> V >> E;
	priority_queue<edge,vector<edge>,cmp> pq;
	root = vector<int>(V+1);
	for (int i=0;i<=V;++i)
		root[i] = i;

	int ans = 0, cnt = 0;
	int s,e,v;
	while (E--)
	{
		cin >> s >> e >> v;
		edge eg;
		eg.s = s;
		eg.e = e;
		eg.v = v;
		pq.push(eg);
	}

	int r_s, r_e;
	while (!pq.empty() && cnt < V-1)
	{
		s = pq.top().s;
		e = pq.top().e;
		v = pq.top().v;
		pq.pop();

		//cout << s << " " << e << " " << v << endl;
		r_s = find_root(s);
		r_e = find_root(e);
		if (r_s == r_e) continue;
		else {
			root[r_e] = r_s;
			ans += v;
			cnt ++;
		}
	}

	cout << ans << endl;

	return (0);
}
