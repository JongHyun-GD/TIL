#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void)
{
	cin.tie(0);
	int y, x;
	int N, M, B; cin >> N >> M >> B;
	vector< vector<int> > m(N, vector<int>(M));
	for (y=0;y<N;++y)
		for (x=0;x<M;++x)
		{
			cin >> m[y][x];
		}

	int ans_cost = 1234567890;
	int ans_height = -1;

	for (int h=0;h<=256;++h)
	{
		int remained = B;
		int cost = 0;
		// 깎아내기
		for (y=0;y<N;++y)
		{
			for (x=0;x<M;++x)
			{
				if (m[y][x] >= h)
				{
					cost += (m[y][x] - h) * 2;
					remained += (m[y][x] - h);
				}
			}
		}

		// 쌓기
		for (y=0;y<N;++y)
		{
			for (x=0;x<M;++x)
			{
				if (m[y][x] < h)
				{
					cost += (h - m[y][x]);
					remained -= (h - m[y][x]);
				}
			}
		}

		if (remained >= 0 && ans_cost >= cost)
		{
			ans_cost = cost;
			ans_height = h;
		}
	}
	cout << ans_cost << " " << ans_height << "\n";
}
