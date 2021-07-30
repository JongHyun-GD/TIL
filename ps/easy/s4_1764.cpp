#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int N, M; cin >> N >> M;
	vector<string> v1(N);
	vector<string> v2(M);
	vector<string> ans;

	int i, j;
	for (i=0;i<N;++i)
		cin >> v1[i];
	for (i=0;i<M;++i)
		cin >> v2[i];
	std::sort(v1.begin(), v1.end());
	std::sort(v2.begin(), v2.end());

	// find
	int l,r,m;
	for (i=0;i<N;++i)
	{
		l=0,r=M-1;
		while (l <= r)
		{
			m = (l+r)/2;
			if (v1[i].compare(v2[m]) == 0)
			{
				ans.push_back(v1[i]);
				break;
			}
			if (v1[i].compare(v2[m]) > 0)
				l = m+1;
			else
				r = m-1;
		}
	}

	// print answer
	std::cout << ans.size() << "\n";
	for (i=0;i<ans.size();++i)
		std::cout << ans[i] << "\n";
}
