#include <vector>
#include <iostream>
using namespace std;

int N, M;
vector<int> arr;
vector<int> seg;

int init_seg(int start, int end, int idx) {
	if (start==end) {
		return seg[idx] = arr[start];
	}
	else {
		int mid = (start + end) / 2;
		return 	seg[idx] =
				init_seg(start, mid, idx*2) +
				init_seg(mid+1, end, idx*2+1);
	}
}

int query(int start, int end, int idx, int low, int high) {
	if (start > high || end < low) return 0;
	if (start >= low && end <= high) return seg[idx];
	else {
		int mid = (start + end) / 2;
		return query(start, mid, idx*2, low, high) +
			   query(mid+1, end, idx*2+1, low, high);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	arr = vector<int>(N);
	seg = vector<int>((N+1)*4);
	for (int i=0;i<N;++i) {
		cin >> arr[i];
	}
	init_seg(0,N-1,1);
	while (M--) {
		int a, b; cin >> a >> b;
		cout << query(0, N-1, 1, a-1, b-1) << "\n";
	}
}
