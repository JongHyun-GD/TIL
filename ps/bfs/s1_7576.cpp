#include <vector>
#include <iostream>
#include <cmath>
#include <queue>
#include <utility>
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int main(void)
{
	int M, N; cin >> M >> N;
	vector< vector<int> > m(N, vector<int>(M));
	int i, j, hx, hy, nx, ny;
	queue< pair<int, int> > q;
	int today = 0, tomorrow, ans = -1;
	for (i=0;i<N;++i)
		for (j=0;j<M;++j)
		{
			cin >> m[i][j];
			if (m[i][j] == 1)
			{
				q.push(make_pair(i, j));
				today++;
			}
		}

	while (!q.empty())
	{
		hy = q.front().first;
		hx = q.front().second;
		q.pop();

		today--;
		for(i=0;i<4;++i)
		{
			ny = hy + dy[i];
			nx = hx + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;
			if (m[ny][nx] == 1 || m[ny][nx] == -1)
				continue;
			m[ny][nx] = 1;
			q.push(make_pair(ny, nx));
			tomorrow++;
		}
		if (today == 0)
		{
			ans++;
			today = tomorrow;
			tomorrow = 0;
		}
	}
	for (i=0;i<N;++i)
		for (j=0;j<M;++j)
		{
			if (m[i][j] == 0)
			{
				cout << "-1\n";
				return (0);
			}
		}
	cout << ans << endl;
	return (0);
}
