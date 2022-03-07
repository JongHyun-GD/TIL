#include <algorithm>
#include <utility>
#include <iostream>
#include <vector>
#include <cmath>
#include <set>
using namespace std;
typedef long long ll;
#define MAX_C 100000000
int N, K;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> N >> K;
	vector< pair<ll,ll> > jewels;
	multiset< ll > bags;
	ll m, v, c;
	for (int i=0;i<N;++i){
		cin >> m >> v;
		jewels.push_back(make_pair(-v, m));
	}
	for (int i=0;i<K;++i){
		cin >> c;
		bags.insert(c);
	}
	sort(jewels.begin(), jewels.end());

	int i = 0;
	long long ans = 0;
	while(i < N) {
		m = jewels[i].second;
		v = -jewels[i].first;
		int l=m, h=MAX_C;
		multiset<ll>::iterator bag_it=bags.lower_bound(m);
		if (bag_it != bags.end()) {
			ans += v;
			bags.erase(bag_it);
			K--;
		}
		i++;
	}
	cout << ans << "\n";
}
