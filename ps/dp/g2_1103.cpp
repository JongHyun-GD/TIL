#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

#define MAX_INT 1234567890

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int H, W;

bool can_move(vector< vector<int> > &map, int ny, int nx)
{
	if (ny < 0 || ny >= H)
		return false;
	if (nx < 0 || nx >= W)
		return false;
	if (map[ny][nx] == -1)
		return false;
	return true;
}

int dfs(vector< vector<int> > &map, vector< vector<int> > &dp, vector< vector<bool> > &is_using,
		int y, int x, int move)
{
	if (is_using[y][x]) {
		dp[y][x] = MAX_INT;
		return MAX_INT;
	}
	dp[y][x] = move;
	is_using[y][x] = true;
	int res = move;

	for (int i = 0; i < 4; ++i)
	{
		int ny = y + (map[y][x] * dy[i]);
		int nx = x + (map[y][x] * dx[i]);
		if (can_move(map, ny, nx) && dp[ny][nx] < move + 1)
			res = max(res, dfs(map, dp, is_using, ny, nx, move + 1));
	}
	is_using[y][x] = false;

	return (res);
}

int main(void)
{
	cin >> H >> W;
	vector< vector<int> > map(H, vector<int>(W));
	for (int y = 0; y < H; ++y)
	{
		string str; cin >> str;
		for (int x = 0; x < W; ++x)
		{
			if (str[x] >= '0' && str[x] <= '9')
				map[y][x] = str[x] - '0';
			else
				map[y][x] = -1;
		}
	}

	vector< vector<int> > dp(H, vector<int>(W, -1));
	vector< vector<bool> > is_using(H, vector<bool>(W, false));

	int res = dfs(map, dp, is_using, 0, 0, 1);
	if (res == MAX_INT)
		cout << "-1\n";
	else
		cout << res << "\n";
}
