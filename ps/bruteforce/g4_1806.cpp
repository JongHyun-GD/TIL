#include <iostream>
#include <vector>
#include <cmath>

int get_partial_sum(int s, int e, std::vector<int> *arr)
{
	int ps = 0;
	for (int i = s; i <= e; ++i)
	{
		ps += (*arr)[i];
	}
	return ps;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

	int N, S; std::cin >> N >> S;

	std::vector<int> arr(N + 1, 0);
	for (int i = 0; i < N; ++i)
		std::cin >> arr[i];

	int low = 0;
	int high = 0;
	int sum = arr[0];
	int l = N + 1;
	while(low <= high && high < N)
	{
		if (sum < S) {
			sum += arr[++high];
		}
		else {
			l = std::min(l, high - low + 1);
			sum -= arr[low++];
		}
	}

	if (l > N) std::cout << "0\n";
	else std::cout << l << "\n";

	return (0);
}
