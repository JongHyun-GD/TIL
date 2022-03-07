#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N, M; 
vector<vector<int>> m;

bool has_cheeze()
{
	for (int y=0; y<N; ++y)
	{
		for (int x=0; x<M; ++x)
		{
			if (m[y][x] == 1) return true;
		}
	}
	return false;
}

void check_outside()
{
	queue< pair<int,int> > q;
	
	pair<int, int> start = make_pair(0, 0);
	q.push(start);
	m[0][0] = 2;
	
	while (q.empty() == false)
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			if (m[ny][nx] != 0) continue;

			m[ny][nx] = 2;
			q.push(make_pair(ny, nx));
		}
	}
}

void delete_cheeze()
{
	int ny, nx;

	// count touched
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			if (m[y][x] != 1) continue;

			int touched = 0;
			for (int i = 0; i < 4; ++i) {
				ny = y + dy[i];
				nx = x + dx[i];
				
				if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
				if (m[ny][nx] == 2) touched++;
			}		
			m[y][x] = 10 + touched;
		}
	}

	// delete and recover numbers
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			if (m[y][x] >= 10 && m[y][x] <= 11) m[y][x] = 1;
			if (m[y][x] >= 12) m[y][x] = 0;
			if (m[y][x] == 2) m[y][x] = 0;
		}
	}
}

void melt_cheeze()
{
	check_outside();
	delete_cheeze();
}

int main(void)
{
	cin >> N >> M;
	m = vector< vector<int> > (N, vector<int>(M));
	for (int y=0; y<N; ++y) {
		for (int x=0; x<M; ++x) {
			cin >> m[y][x];
		}
	}

	int ans = 0;
	while (has_cheeze())
	{
		melt_cheeze();
		ans++;
	}

	cout << ans << "\n";
}
