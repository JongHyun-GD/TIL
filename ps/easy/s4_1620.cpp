#include <map>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
	cin.tie(0);
	map<string, int> m;
	vector<string> v;

	int N, M; cin >> N >> M;
	v = vector<string> (N + 1);

	// GET INPUT
	string str;
	for (int i = 1; i <= N; ++i)
	{
		cin >> str;
		m.insert(make_pair(str, i));
		v[i] = str;
	}

	int num;
	// SOLVE PROBLEM
	for (int i=0;i<M;++i)
	{
		cin >> str;
		// number
		if (isdigit(str[0]))
		{
			num = stoi(str);
			cout << v[num] << "\n";
		}
		else
		{
			cout << m[str] << "\n";
		}
	}
}
