#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
#define INF 1234567890

int N;
int color_cost[1001][3];
int dp[1001][3][3];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> N;
	for (int i=0; i<N; ++i) {
		cin >> color_cost[i][0] >> color_cost[i][1] >> color_cost[i][2];
	}

	for (int i=0;i<N-1;++i) {
		for (int c=0;c<3;++c) {
			for (int sc=0;sc<3;++sc){
				if (i == 0) {
					if (c != sc) {
						dp[i][c][sc] = INF;
					}
					else {
						dp[i][c][sc] = color_cost[i][c];
					}
				}
				else {
					dp[i][c][sc] = INF;
					for (int pc=0;pc<3;++pc) {
						if (pc != c) {
							dp[i][c][sc] = min(dp[i-1][pc][sc]+color_cost[i][c], dp[i][c][sc]);
						}
					}
				}
			}
		}
	}

	int ans = INF;
	for (int c=0;c<3;++c) {
		for (int sc=0;sc<3;++sc) {
			for (int hc=0;hc<3;++hc) {
				if (hc != c && hc != sc) {
					ans = min(dp[N-2][c][sc] + color_cost[N-1][hc], ans);
				}
			}
		}
	}
	cout << ans << "\n";
}
