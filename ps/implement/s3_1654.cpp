#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef unsigned long long ull;

int main(void)
{
	cin.tie(0);
	int K, N; cin >> K >> N;
	vector<int> arr(K);
	int i;
	ull left, right, mid, sum;
	for (i=0;i<K;++i)
		cin >> arr[i];
	left = 1;
	right = 2147483647;
	mid = 0;
	while (mid != (left + right) / 2)
	{
		sum = 0;
		mid = (left + right) / 2;
		//cout << left << " " << mid << " " << right << endl;
		for (i=0;i<K;++i)
		{
			sum += arr[i] / mid;
		}
		if (sum < N)
			right = mid - 1;
		else
			left = mid + 1;
	}
	cout << mid << "\n";
}
