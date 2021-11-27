#include <cstdio>
#include <vector>
#include <utility>

int main(void)
{
	int N; scanf("%d", &N);
	std::vector<std::pair<int, int> > v(10001);
	int x, y;
	for (int i = 0; i < N; ++i)
	{
		scanf("%d %d", &x, &y);
		v[i] = std::make_pair(x, y);
	}

	double area = 0;
	long long x1, x2, y1, y2;
	for (int i = 0; i < N; ++i)
	{
		x1 = v[i].first, y1 = v[i].second;
		if (i + 1 == N)
		{
			x2 = v[0].first, y2 = v[0].second;
		}
		else
		{
			x2 = v[i+1].first, y2 = v[i+1].second;
		}
		area += (x1 * y2 - x2 * y1);
	}
	area /= 2.0f;
	if (area < 0)
		area *= -1;

	printf("%.1f\n", area);


}
