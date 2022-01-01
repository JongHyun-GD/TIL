#include <vector>
#include <iostream>
#include <cmath>
#include <utility>
#include <algorithm>

using namespace std;

int N, C;
int is_new_applier(vector< pair<int, int> > &v, int person)
{
	for (int i = 0; i < N; ++i)
	{
		if (v[i].first == person)
			return i;
	}
	return -1;
}

int find_lowest(vector< pair<int, int> > &v, vector<int> &time)
{
	int lowVal = v[0].second, lowIdx = 0;

	for (int i = 0; i < N; ++i)
	{
		if (v[i].second < lowVal)
		{
			lowIdx = i;
			lowVal = v[i].second;
		}
		else if (v[i].second == lowVal && time[i] > time[lowIdx])
		{
			lowIdx = i;
		}
	}
	return (lowIdx);
}

int main(void)
{
	cin >> N >> C;

	vector< pair<int, int> > v(N, make_pair(-1, -1));
	vector< int > time(N, 0);
	int applied = 0;
	for (int i = 0; i < C; ++i)
	{
		int person; cin >> person;
		int pos = is_new_applier(v, person);
		if (pos == -1)
		{
			if (applied < N)
			{
				v[applied] = make_pair(person, 1);
				time[applied] = 0;
				applied++;
			}
			else
			{
				int low_idx = find_lowest(v, time);

				v[low_idx] = make_pair(person, 1);
				time[low_idx] = 0;
			}
		}
		else
			v[pos].second++;
		for (int j = 0; j < N; ++j)
		{
			time[j]++;
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; ++i)
	{
		if (v[i].first == -1)
			continue;
		cout << v[i].first;
		if (i != N-1)
			cout << " ";
	}
}
