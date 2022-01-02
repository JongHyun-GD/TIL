#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int L, C;

void dfs(vector<char> &v, string &str, int depth, int prev_i)
{
	if (depth == L) {
		int m = 0;
		for (int i = 0; i < L; ++i)
		{
			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
				m++;
		}
		if (m >= 1 && L-m >= 2)
		{
			for (int i = 0; i < L; ++i)
				cout << str[i];
			cout << "\n";
		}
	}
	else {
		for (int i = prev_i + 1; i < C; ++i)
		{
			str[depth] = v[i];
			dfs(v, str, depth + 1, i);
		}
	}
	return ;
}

int main(void)
{
	cin >> L >> C;

	vector<char> v(C);
	for (int i = 0; i < C; ++i)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	string str = "...............";
	dfs(v, str, 0, -1);

	return (0);
}
