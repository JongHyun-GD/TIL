#include <queue>
#include <vector>
#include <iostream>
#include <string>
#include <set>
using namespace std;

string N;
int K;

int main(void)
{
	cin >> N >> K;

	if (stoi(N) < 10) {
		cout << "-1\n";
		return (0);
	}
	queue<string> q;
	q.push(N);

	for (int i = 0; i < K; ++i)
	{
		int qsize = q.size();
		set<string> ss;
		while (q.empty() == false)
		{
			string s = q.front();
			q.pop();

			for (int x = 0; x < s.length(); ++x)
			{
				for (int y = x + 1; y < s.length(); ++y)
				{
					string temp = s;
					char tc = temp[x];
					temp[x] = temp[y];
					temp[y] = tc;
					if (temp[0] == '0') continue;
					ss.insert(temp);
				}
			}
		}

		set<string>::iterator it;
		for (it = ss.begin(); it != ss.end(); ++it)
		{
			q.push(*it);
		}
	}

	int res = -1;
	int numN = stoi(N);
	while (q.empty() == false)
	{
		string str = q.front();
		q.pop();
		if (str[0] == '0')
			continue;
		int temp = stoi(str);
		res = max(res, temp);
	}
	cout << res << "\n";
}
