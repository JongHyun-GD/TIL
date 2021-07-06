#include <vector>
#include <cmath>
#include <iostream>
#include <queue>
#include <utility>
#define INF 1234567890
using namespace std;

int N, M;
vector< vector<int> > input_m;
vector< vector<int> > m;
vector< vector<int> > dist_m;
vector< int > dist_vec;
int num_of_island;

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

void paint(int y, int x, int num)
{
	int hy, hx, ny, nx, i;
	queue< pair<int, int> > q;
	q.push(make_pair(y, x));

	while (!q.empty())
	{
		hy = q.front().first;
		hx = q.front().second;
		m[hy][hx] = num;
		q.pop();

		for (i=0;i<4;++i)
		{
			ny = hy + dy[i];
			nx = hx + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;
			if (input_m[ny][nx] == 0 || m[ny][nx] != 0) continue;
			q.push(make_pair(ny, nx));
		}
	}
}

void paint_all()
{
	int y, x;
	int num = 1;
	for (y=0;y<N;++y)
		for (x=0;x<M;++x)
		{
			if (m[y][x] == 0 && input_m[y][x] != 0)
			{
				paint(y,x,num);
				num++;
			}
		}
	num_of_island = num-1;
}

void measure_dist()
{
	int i, hy, hx, hn, ny, nx, nn;
	int dist;
	for (hy=0;hy<N;++hy)
	{
		for (hx=0;hx<M;++hx)
		{
			if (m[hy][hx] != 0)
			{
				hn = m[hy][hx];
				for (i=0;i<4;++i)
				{
					ny = hy + dy[i];
					nx = hx + dx[i];
					while (ny >= 0 && ny < N && nx >= 0 && nx < M)
					{
						if (m[ny][nx] != 0)
						{
							nn = m[ny][nx];
							if (nn == hn) break;
							else {
								dist = abs(hy - ny) + abs(hx - nx) - 1;
								if (dist == 1) break;
								dist_m[hn][nn] = min(dist_m[hn][nn], dist);
								dist_m[nn][hn] = min(dist_m[nn][hn], dist);
								break;
							}
						}
						ny += dy[i];
						nx += dx[i];
					}
				}
			}
		}
	}
}

int prim()
{
	vector<bool> visited(15, false);
	visited[1] = true;
	int i, visit_cnt = 1;
	int ans = 0, min_v, min_e;
	for (i=2;i<15;++i)
		dist_vec[i] = dist_m[1][i];
	while (1)
	{
		// find shortest edge
		min_e = INF;
		for (i=1;i<15;++i)
		{
			if (dist_vec[i] == INF || visited[i]) continue;
			if (dist_vec[i] < min_e)
			{
				min_e = dist_vec[i];
				min_v = i;
			}
		}
		if (min_e == INF) break;
		// update distance vector
		visit_cnt++;
		visited[min_v] = true;
		ans += min_e;
		for (i=1;i<15;++i)
		{
			if (visited[i]) continue;
			dist_vec[i] = min(dist_vec[i], dist_m[min_v][i]);
		}
	}
	if (num_of_island == visit_cnt) return ans;
	else return -1;
}

int main(void)
{
	cin >> N >> M;
	input_m = vector< vector<int> >(N, vector<int>(M, 0));
	m = vector< vector<int> >(N, vector<int>(M, 0));
	dist_m = vector< vector<int> >(15, vector<int>(15, INF));
	dist_vec = vector <int> (15, INF);
	int x, y;
	for (y=0;y<N;++y)
		for (x=0;x<M;++x)
			cin >> input_m[y][x];
	paint_all();
	// for (y=0;y<N;++y)
	// {
	// 	for (x=0;x<M;++x)
	// 	{
	// 		cout << m[y][x] << " ";
	// 	}
	// 	cout << endl;
	// }
	measure_dist();
	// for (y=1;y<=num_of_island;++y)
	// {
	// 	for (x=1;x<=num_of_island;++x)
	// 	{
	// 		if (dist_m[y][x] == INF)
	// 			cout << "-" << " ";
	// 		else
	// 			cout << dist_m[y][x] << " ";
	// 	}
	// 	cout << endl;
	// }
	cout << prim() << endl;
}
