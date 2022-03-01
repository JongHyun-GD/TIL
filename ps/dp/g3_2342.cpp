#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
#define MAXINT 1234567890;

int dp[101010][5][5];

int get_tired(int from, int to) {
	if (from == to) return 1;
	if (from == 0) return 2;
	if (((from == 2 || from == 4) && (to == 1 || to == 3)) || ((from == 1 || from == 3) && (to == 2 || to == 4)))
		return 3;
	else
		return 4;
}

int main() {
	int n; cin >> n;
	int step = 0;
	memset(dp, -1, sizeof(int)*101010*5*5);
	dp[0][0][0] = 0;
	while (n != 0) {
		step++;
		for (int l=0;l<5;++l) {
			for (int r=0;r<5;++r) {
				if (dp[step-1][l][r] == -1) continue;
				// cout << step << " " << l << " " << r << endl;
				// 왼발 움직이기
				if (r != n) {
					int t = get_tired(l, n);
					if (dp[step][n][r] != -1)
						dp[step][n][r] = min(dp[step-1][l][r] + t, dp[step][n][r]);
					else
						dp[step][n][r] = dp[step-1][l][r] + t;
				}
				// 오른발 움직이기
				if (l != n) {
					int t = get_tired(r, n);
					if (dp[step][l][n] != -1)
						dp[step][l][n] = min(dp[step-1][l][r] + t, dp[step][l][n]);
					else
						dp[step][l][n] = dp[step-1][l][r] + t;
				}
			}
		}

		cin >> n;
	}
	if (step == 0) {
		cout << "0\n";
	} else {
		int ans = 1234567890;
		for (int l=0;l<5;l++) {
			for (int r=0;r<5;r++) {
				if (dp[step][l][r] != -1) ans = min(ans, dp[step][l][r]);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}


