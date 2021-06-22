#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int INF = 99999;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int M, N;
vector<string> m;
vector<vector<int> > w;

int main(void)
{
	int i;
	queue<pair<int, pair<int, int> > > q;
	// input
	cin >> M >> N;
	m = vector<string>(N);
	w = vector<vector<int> >(N, vector<int>(M, INF));
	for (i=0;i<N;++i)
		cin >> m[i];
	w[0][0] = 0;
	for (i=0;i<100;++i)
	{
		for (int y=0;y<N;++y)
		{
			for (int x=0;x<M;++x)
			{
				int cost = m[y][x] == '0' ? 0 : 1;
				for (int d=0;d<4;++d)
					if (y+dy[d] >= 0 && y+dy[d] < N && x+dx[d] >= 0 && x+dx[d] < M && w[y+dy[d]][x+dx[d]] != INF)
						w[y][x] = min(w[y][x], w[y+dy[d]][x+dx[d]] + cost);
			}
		}
	}
	cout << w[N-1][M-1] << "\n";
	return (0);
}
