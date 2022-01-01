#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
string s1, s2;
int s1_len, s2_len;
vector< vector<int> > dp;

int dfs(int s1_idx, int s2_idx)
{
	if (dp[s1_idx][s2_idx] != -1)
	{
		return dp[s1_idx][s2_idx];
	}

	if (s1[s1_idx] == s2[s2_idx])
	{
		return dp[s1_idx][s2_idx] = (1 + dfs(s1_idx+1, s2_idx+1));
	}
	else
	{
		return dp[s1_idx][s2_idx] = max(dfs(s1_idx+1, s2_idx), dfs(s1_idx, s2_idx));
	}
}

int main()
{
	cin >> s1 >> s2;
	s1_len = s1.length();
	s2_len = s2.length();
	dp = vector< vector<int> >(s1_len, vector<int>(s2_len, -1));



	return (0);
}
