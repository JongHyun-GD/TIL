#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector< vector<int> > dp;
vector< vector<int> > m;
int H, W, N;


int main() {
	cin >> H >> W >> N;
	dp = vector< vector<int> >(H+2, vector<int>(W+2, 0));
	m = vector< vector<int> >(H+2, vector<int>(W+2, 0));
	for (int y=0;y<H;++y)
		for (int x=0;x<W;++x)
			cin >> m[y+1][x+1];
	dp[1][1] = N-1;
	for (int y=1;y<=H;++y) {
		for (int x=1;x<=W;++x) {
			if (y == 1 && x == 1) continue;
			if (x-1 != 0) {
				dp[y][x] += dp[y][x-1] / 2;
				if (dp[y][x-1] % 2 == 1 && m[y][x-1] == 1) dp[y][x]++;
			}
			if (y-1 != 0) {
				dp[y][x] += dp[y-1][x] / 2;
				if (dp[y-1][x] % 2 == 1 && m[y-1][x] == 0) dp[y][x]++;
			}
		}
	}

	for (int y=1;y<=H;++y){
		for (int x=1;x<=W;++x){
			m[y][x] = dp[y][x] % 2 == 0 ? m[y][x] : (m[y][x] == 0) ? 1 : 0;
		}
	}

	int hy = 1, hx = 1;
	while (true) {
		if (m[hy][hx] == 0) {
			hy++;
			if (hy == H+1) break;
		}
		else {
			hx++;
			if (hx == W+1) break;
		}
	}
	cout << hy << " " << hx << "\n";

	return (0);
}
