#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

struct node {
	vector<int> next_nodes;
	int data;
};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M; cin >> N >> M;

	vector<struct node> nodes(N+1);
	vector<int> degree(N+1, 0);

	int parent, child;
	for (int i = 0; i < M; ++i)
	{
		cin >> parent >> child;
		nodes[parent].next_nodes.push_back(child);
		degree[child]++;
	}

	priority_queue<int, vector<int>, greater<int> > pq;
	for (int i = 1; i <= N; ++i)
		if (degree[i] == 0)
			pq.push(i);

	int here, next, size;
	while (pq.empty() == false)
	{
		here = pq.top();
		pq.pop();

		size = nodes[here].next_nodes.size();
		for (int i = 0; i < size; ++i)
		{
			next = nodes[here].next_nodes[i];
			degree[next]--;
			if (degree[next] == 0)
				pq.push(next);
		}

		cout << here;
		if (pq.empty() == false)
			cout << " ";
		else
			cout << "\n";
	}
}
