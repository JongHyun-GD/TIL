#include <vector>
#include <iostream>
#include <cmath>
#include <queue>
#include <utility>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int N; cin >> N;
	vector<int> num_parent(N+1, 0);
	vector<int> times(N+1);
	vector< vector<int> > tree(N+1);
	int p;
	for (int i=1;i<=N;++i) {
		cin >> times[i];
		while (true) {
			cin >> p;
			if (p == -1) break;
			else {
				tree[p].push_back(i);
				num_parent[i]++;
			}
		}
	}
	vector<int> ans(N+1);
	priority_queue< pair<int, int> > q;

	for (int i=1;i<=N;++i) {
		if (num_parent[i] == 0) {
			q.push(make_pair(-times[i], i));
		}
	}

	while (q.empty() == false) {
		int here = q.top().second;
		int here_time = -q.top().first;
		q.pop();

		ans[here] = here_time;
		for (int i=0;i<tree[here].size();++i) {
			int next = tree[here][i];
			num_parent[next]--;
			if (num_parent[next] == 0)
				q.push(make_pair(-(times[next] + here_time), next));
		}
	}

	for (int i=1;i<=N;i++) {
		cout << ans[i] << "\n";
	}
}
