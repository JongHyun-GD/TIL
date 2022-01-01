#include <queue>
#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
#include <set>
using namespace std;

int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {-1,-1,0,1,1,1,0,-1};
vector< vector<char> > m;
vector< vector<int> > h;
vector< vector<bool> > v;
int px, py;
int n;
int k;

bool can_reach_all(int s, int e) {
	if (h[py][px] < s || h[py][px] > e) return false;
	queue< pair<int, int> > q;
	v = vector< vector<bool> >(n, vector<bool>(n, false));
	q.push(make_pair(py, px));
	v[py][px] = true;
	int visited = 0;

	while (q.empty() == false) {
		int hy = q.front().first;
		int hx = q.front().second;
		if (m[hy][hx] == 'K') visited++;
		q.pop();

		for (int i = 0; i < 8; ++i) {
			int ny = hy + dy[i];
			int nx = hx + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
			if (v[ny][nx]) continue;
			if (h[ny][nx] < s || h[ny][nx] > e) continue;
			v[ny][nx] = true;
			q.push(make_pair(ny, nx));
		}
	}

	if (visited == k) return true;
	else return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	k=0;
	m = vector< vector<char> >(n, vector<char>(n));
	h = vector< vector<int> >(n, vector<int>(n));
	vector<int> hset;
	for (int y=0;y<n;++y) {
		for (int x=0;x<n;++x) {
			cin >> m[y][x];
			if (m[y][x] == 'P') {
				px = x;
				py = y;
			}
			if (m[y][x] == 'K') {
				k++;
			}
		}
	}
	for (int y=0;y<n;++y) {
		for (int x=0;x<n;++x) {
			cin >> h[y][x];
			hset.push_back(h[y][x]);
		}
	}
	sort(hset.begin(), hset.end());
	hset.erase(unique(hset.begin(), hset.end()), hset.end());
	int s = 0, e;
	for (int i = 0; i < hset.size(); ++i)
		if (hset[i] == h[py][px]) {
			e = i;
			break;
		}

	int diff, ans = 1234567890;
	while (s <= e && e < hset.size()) {
		if (can_reach_all(hset[s], hset[e])) {
			diff = hset[e] - hset[s];
			ans = min(diff, ans);
			s++;
		}
		else {
			e++;
		}
	}
	cout << ans << "\n";
}
