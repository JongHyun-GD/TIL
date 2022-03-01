#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> stree;

ll query(ll start, ll end, ll here, ll ql, ll qh) {
	if (start > qh || end < ql) return 0;
	else if (ql <= start && qh >= end) return stree[here];
	else {
		ll mid = (start + end) / 2;
		return query(start, mid, here*2, ql, qh) + query(mid+1, end, here*2+1, ql, qh);
	}
}

void update(ll start, ll end, ll here, ll i, ll n) {
	if (i < start || i > end) return ;
	stree[here] += n;
	if (start == end) return ;
	ll mid = (start + end) / 2;
	update(start, mid, here*2, i, n);
	update(mid+1, end, here*2+1, i, n);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, Q; cin >> N >> Q;
	stree = vector<ll>(505050, 0);
	int num;
	for (int i=0;i<N;++i) {
		cin >> num;
		update(1, N, 1, i+1, num);
	}
	ll x,y,a,b,old_b;
	for (int i=0;i<Q;++i) {
		cin >> x >> y >> a >> b;
		if (x > y) swap(x, y);
		cout << query(1, N, 1, x, y) << "\n";
		old_b = query(1, N, 1, a, a);
		update(1, N, 1, a, b - old_b);
	}
}
