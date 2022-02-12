#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define MAX_N 101010

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0);
	int N; cin >> N;
	vector< vector<int> > arr(MAX_N);
	int u, v;
	for (int i=0;i<N;++i) {
		cin >> u >> v;
		arr[u].push_back(v);
		arr[v].push_back(u);
	}

	vector<int> pv(MAX_N, -1);
	queue<int> q;
	q.push(1);
	while (q.empty() == false) {
		u = q.front();
		q.pop();

		for (int i=0;i<arr[u].size();++i) {
			v = arr[u][i];
			if (v == pv[u]) continue;
			pv[v] = u;
			q.push(v);
		}
	}
	int i = 2;
	while (pv[i] != -1) {
		cout << pv[i++] << "\n";
	}
}
