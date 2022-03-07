#include <vector>
#include <iostream>
#include <cmath>
#include <queue>
#include <utility>
using namespace std;

int N, L;
vector<int> arr;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> L;
	arr = vector<int>(N);
	priority_queue< pair<int, int> > pq;
	for (int i=0;i<N;++i) cin >> arr[i];
	for (int i=0;i<N;++i) {
		pq.push(make_pair(-arr[i], i));
		while(pq.top().second < i-L+1) pq.pop();
		cout << -pq.top().first << " ";
	}
}
