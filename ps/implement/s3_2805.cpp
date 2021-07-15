#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
typedef unsigned long long ull;

int	main(void)
{
	cin.tie();
	int i, N, M; cin >> N >> M;
	vector<ull> woods(N);
	for(i=0;i<N;++i)
		cin >> woods[i];
	// 이분탐색
	ull l, r, c, sum, t;
	ull ans;
	l = 0;
	r = 1000000000;
	c = (l + r) / 2;
	ans = 0;
	while (l <= r)
	{
		sum = 0;
		c = (l + r) / 2;
		for (ull i = 0; i < N; i++)
		{
			if (woods[i] <= c)
				t = 0;
			else
				t = woods[i] - c;
			sum += t;
		}
		if (sum >= M) // 답의 후보 중 하나
		{
			l = c + 1;
			ans = max(ans, c);
		}
		else
			r = c - 1;
	}
	cout << ans << "\n";
}
