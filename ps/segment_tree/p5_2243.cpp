#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> box;

void update(ll start, ll end, ll here, ll num, ll idx) {
	if (idx < start || idx > end) return;
	box[here] += num;
	if (start == end) return;
	else {
		ll mid = (start + end) / 2;
		update(start, mid, here*2, num, idx);
		update(mid+1, end, here*2+1, num, idx);
	}
}

ll query(ll start, ll end, ll here, ll ql, ll qh) {
	if (ql > end || qh < start) return 0;
	if (ql <= start && qh >= end) {
		return box[here];
	}
	else {
		ll mid = (start + end) / 2;

		return query(start, mid, here*2, ql, qh) + query(mid+1, end, here*2+1, ql, qh);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	box = vector<ll>(5050505, 0);
	int a, b, c;
	while (n--) {
		cin >> a;
		if (a == 1) {
			cin >> b;
			ll l=1, h=1000000, m;
			ll ans = 0;
			while (l <= h) {
				m = (l+h)/2;
				ll res = query(1,1000000,1,1,m);
				if (res < b) {
					l = m+1;
				}
				else {
					h = m-1;
					ans = m;
				}
			}
			cout << ans << "\n";
			update(1,1000000,1,-1,ans);
		}
		else if (a == 2) {
			cin >> b >> c;
			update(1,1000000,1,c,b);
		}
	}
}
