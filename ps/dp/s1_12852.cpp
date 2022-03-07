#include <cmath>
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
using namespace std;

// first => prev value
// second => count
vector<pair<int, int> > dp;

int main(void)
{
	ios::sync_with_stdio(false);

	int cur, count;
	int N; cin >> N;
	dp = vector<pair<int, int> > (N, make_pair(-1, 1234567890));
	// first => current value
	// second => count
	queue<pair<int, int> > q;

	q.push(make_pair(N, 0));
	while(!q.empty())
	{
		cur = q.front().first;
		count = q.front().second;
		q.pop();

		if (cur % 3 == 0 && dp[cur / 3].second > count + 1)
		{
			dp[cur / 3] = make_pair(cur, count + 1);
			q.push(make_pair(cur / 3, count + 1));
		}
		if (cur % 2 == 0 && dp[cur / 2].second > count + 1)
		{
			dp[cur / 2] = make_pair(cur, count + 1);
			q.push(make_pair(cur / 2, count + 1));
		}
		if (cur - 1 > 0 && dp[cur - 1].second > count + 1)
		{
			dp[cur - 1] = make_pair(cur, count + 1);
			q.push(make_pair(cur - 1, count + 1));
		}
	}
	int num = 1;
	stack<int> ans;
	while (1)
	{
		ans.push(num);
		if (num == N) break;
		num = dp[num].first;
	}

	cout << ans.size() - 1 << "\n";
	while (!ans.empty())
	{
		cout << ans.top();
		ans.pop();

		if (ans.empty() == false) cout << " ";
	}

	return 0;
}
