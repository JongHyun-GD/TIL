#include <cmath>
#include <vector>
#include <iostream>
using namespace std;
typedef unsigned long long ull;

int main(void)
{
	int N, M; cin >> N >> M;
	vector<ull> mem(N);
	vector<ull> cost(N);
	// dp[N][sum of costs]
	vector<ull> dp(10001, 0);
	dp[0] = 0;
	int i, j;
	ull m, c;
	for (i=0;i<N;++i)
		cin >> mem[i];
	for (i=0;i<N;++i)
		cin >> cost[i];

	// dp
	for (i=0;i<N;++i)
	{
		m = mem[i];
		c = cost[i];
		for (j=10000;j>=0;--j)
		{
			if (j+c <= 10000)
			{
				dp[j+c] = max(dp[j+c], dp[j] + mem[i]);
			}
		}
	}

	for (i=0;i<10001;++i)
		if (dp[i] >= M)
		{
			cout << i << "\n";
			break;
		}
	return (0);
}
