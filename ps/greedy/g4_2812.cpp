#include <vector>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

vector<int> arr;

int get_length_to_greater(int i)
{
	int j;

	for (j = i + 1; j < arr.size(); ++j)
	{
		if (arr[i] < arr[j]) return (j - i);
	}
	return (-1);
}

int main(void)
{
	int N, K; cin >> N >> K;
	string str; cin >> str;
	int len = str.length();
	arr = vector<int>(len);
	for (int i = 0; i < len; ++i)
	{
		arr[i] = str[i] - '0';
	}

	int i = 0;
	while (i < len)
	{
		if (K == 0) break;
		int dist = get_length_to_greater(i);
		if (dist > K)
		{
			++i;
			continue;
		}
		else if (dist != -1)
		{
			int j;
			for (j = i; j < i + dist; ++j)
			{
				K--;
				arr[j] = -1;
			}
			i = j;
		}
		else
			i++;
	}
	for (int h = 0; h < arr.size(); ++h)
	{
		if (arr[h] != -1)
			cout << arr[h];
	}
	cout << "\n";
}
