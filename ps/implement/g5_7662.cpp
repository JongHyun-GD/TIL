#include <queue>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

template<typename T>
class custom_min_priority_queue : public std::priority_queue<T, std::vector<T>, std::greater<T> >
{
	public:
		bool remove(const T& value) {
			auto it = std::find(this->c.begin(), this->c.end(), value);
			if (it != this->c.end())
			{
				this->c.erase(it);
				return true;
			}
			else
				return false;
		}
};

template<typename T>
class custom_max_priority_queue : public std::priority_queue<T, std::vector<T>, std::less<T> >
{
	public:
		bool remove(const T& value) {
			auto it = std::find(this->c.begin(), this->c.end(), value);
			if (it != this->c.end())
			{
				this->c.erase(it);
				return true;
			}
			else
				return false;
		}
};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

	int T; std::cin >> T;

	while(T--)
	{
		int K;
		char o;
		int n, d;
		custom_min_priority_queue<int> minpq;
		custom_max_priority_queue<int> maxpq;

		std::cin >> K;

		while (K--)
		{
			std::cin >> o;
			std::cin >> n;
			if (o == 'I')
			{
				minpq.push(n);
				maxpq.push(n);
			}
			else if (o == 'D')
			{
				if (minpq.empty() || maxpq.empty()) continue;

				if (n == -1)
				{
					d = minpq.top();
					minpq.pop();
					maxpq.remove(d);
				}
				else if (n == 1)
				{
					d = maxpq.top();
					maxpq.pop();
					minpq.remove(d);
				}
			}
		} // end while

		if (minpq.empty() && maxpq.empty())
			std::cout << "EMPTY\n";
		else
			std::cout << maxpq.top() << " " << minpq.top() << "\n";
	} // end while
	return (0);
}
