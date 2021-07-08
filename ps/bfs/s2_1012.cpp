#include <vector>
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int main(void)
{
	int TC; cin >> TC;
	int N, M, K, i, y, x, ny, nx;
	int ans;
	while (TC--)
	{
		ans = 0;
		cin >> M >> N >> K;
		queue< pair<int, int> >	q;
		queue< pair<int, int> > tq;
		vector< vector<int> > m(N, vector<int>(M, 0));
		vector< vector<bool> > visited(N, vector<bool>(M, false));
		for (i=0;i<K;++i)
		{
			cin >> x >> y;
			m[y][x] = 1;
			q.push(make_pair(y, x));
		}
		while (!q.empty())
		{
			y = q.front().first;
			x = q.front().second;
			q.pop();

			if (visited[y][x]) continue;
			tq.push(make_pair(y, x));
			visited[y][x] = true;
			ans++;
			while (!tq.empty())
			{
				y = tq.front().first;
				x = tq.front().second;
				tq.pop();

				for (i=0;i<4;++i)
				{
					ny = y + dy[i];
					nx = x + dx[i];
					if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
					if (m[ny][nx] == 0) continue;
					if (visited[ny][nx]) continue;
					visited[ny][nx] = true;
					tq.push(make_pair(ny, nx));
				}
			}

		}
		cout << ans << "\n";
	}

	return (0);
}
