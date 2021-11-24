#include <queue>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

	int T; std::cin >> T;

	while(T--)
	{
		std::priority_queue<int, std::vector<int>, std::less<int> > maxpq;
		std::priority_queue<int, std::vector<int>, std::greater<int> > minpq;
		std::map<int, int> mp;
		int K;
		char o;
		int n, d;

		std::cin >> K;

		while (K--)
		{
			std::cin >> o;
			std::cin >> n;
			if (o == 'I')
			{
				minpq.push(n);
				maxpq.push(n);
				mp[n]++;
			}
			else if (o == 'D')
			{
				if (minpq.empty() || maxpq.empty()) continue;

				if (n == -1)
				{
					while (minpq.empty() == false && mp[minpq.top()] == 0) minpq.pop();
					if (minpq.empty()) continue;
					d = minpq.top();
					minpq.pop();
					mp[d]--;
				}
				else if (n == 1)
				{
					while (maxpq.empty() == false && mp[maxpq.top()] == 0) maxpq.pop();
					if (maxpq.empty()) continue;
					d = maxpq.top();
					maxpq.pop();
					mp[d]--;
				}
			}
		} // end while

		while (minpq.empty() == false && mp[minpq.top()] == 0) minpq.pop();
		while (maxpq.empty() == false && mp[maxpq.top()] == 0) maxpq.pop();

		if (minpq.empty() && maxpq.empty())
			std::cout << "EMPTY\n";
		else
			std::cout << maxpq.top() << " " << minpq.top() << "\n";
	} // end while
	return (0);
}
