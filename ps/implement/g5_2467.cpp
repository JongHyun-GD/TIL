#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int INF = 2147483647;

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N; cin >> N;
	vector<int> arr(N);
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	int p1 = 0, p2 = N-1;
	int ans = INF, ans_p1, ans_p2;
	while (p1 < p2)
	{
		if (abs(arr[p1] + arr[p2]) < abs(ans))
		{
			ans = arr[p1] + arr[p2];
			ans_p1 = p1;
			ans_p2 = p2;
		}
		if (abs(arr[p1+1] + arr[p2]) < abs(arr[p1] + arr[p2-1]))
			p1++;
		else
			p2--;
	}
	cout << arr[ans_p1] << " " << arr[ans_p2] << "\n";
}
