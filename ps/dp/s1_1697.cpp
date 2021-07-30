#include <vector>
#include <iostream>
#include <cmath>
#include <queue>
#include <utility>
using namespace std;

int main(void) {
	int N, K; cin >> N >> K;

	queue< pair<int, int> > q;
	vector<bool> visited(300000, false);
	q.push(make_pair(0, N));

	int t, p;
	while (1)
	{
		t = q.front().first;
		p = q.front().second;
		q.pop();

		if (p == K)
		{
			cout << t << "\n";
			return (0);
		}
		// -1
		if (p-1 >= 0 && !visited[p-1])
		{
			visited[p-1] = true;
			q.push(make_pair(t+1, p-1));
		}
		// +1
		if (p+1 < 300000 && !visited[p+1])
		{
			visited[p+1] = true;
			q.push(make_pair(t+1, p+1));
		}
		// *2
		if (p*2 < 300000 && !visited[p*2])
		{
			visited[p*2] = true;
			q.push(make_pair(t+1, p*2));
		}
	}
}
