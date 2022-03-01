#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <utility>

using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int H, W;

void flood(vector<string> &map, queue< pair<int, int> > &wq)
{
	int wsize = wq.size();
	for (int i = 0; i < wsize; ++i)
	{
		int y = wq.front().first;
		int x = wq.front().second;
		wq.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (ny < 0 || ny >= H || nx < 0 || nx >= W)
				continue;
			if (map[ny][nx] == '.' || map[ny][nx] == 'S')
			{
				map[ny][nx] = '*';
				wq.push(make_pair(ny, nx));
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> H >> W;
	vector<string> map(H);
	for (int i =0; i < H; ++i)
		cin >> map[i];

	queue< pair<int, int> > dq;
	queue< pair<int, int> > wq;
	for (int y=0;y<H;++y)
		for (int x=0;x<W;++x)
		{
			if (map[y][x] == 'S')
				dq.push(make_pair(y, x));
			else if (map[y][x] == '*')
				wq.push(make_pair(y, x));
		}
	vector< vector<bool> > visited(H, vector<bool>(W, false));
	visited[dq.front().first][dq.front().second] = true;
	int step = 0;
	while (dq.empty() == false)
	{
		step++;
		flood(map, wq);
		int dcase = dq.size();
		for (int i = 0; i < dcase; ++i)
		{
			int y = dq.front().first;
			int x = dq.front().second;
			dq.pop();
			for (int dir=0;dir<4;++dir)
			{
				int ny = y + dy[dir];
				int nx = x + dx[dir];

				if (ny < 0 || ny >= H || nx < 0 || nx >= W)
					continue;
				if (map[ny][nx] == '.' && visited[ny][nx] == false)
				{
					visited[ny][nx] = true;
					dq.push(make_pair(ny, nx));
				}
				if (map[ny][nx] == 'D')
				{
					cout << step << "\n";
					return (0);
				}
			}
		}
	}
	cout << "KAKTUS\n";
}
