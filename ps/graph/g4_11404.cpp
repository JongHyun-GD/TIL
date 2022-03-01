#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define INF 1010101010

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int N, M; cin >> N >> M;
	vector< vector<int> > dist(N+1, vector<int>(N+1, INF));
	for (int i=0;i<M;i++) {
		int a,b,c; cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
	}

	// 거쳐가는 노드
	for (int i=1;i<=N;++i) {
		// 출발 노드
		for (int j=1;j<=N;++j) {
			// 도착 노드
			for (int k=1;k<=N;++k) {
				dist[j][k] = min(dist[j][i] + dist[i][k], dist[j][k]);
			}
		}
	}

	for (int y=1;y<=N;++y) {
		for (int x=1;x<=N;++x) {
			if (dist[y][x] == INF || y == x) cout << "0 ";
			else cout << dist[y][x] << " ";
		}
		cout << "\n";
	}
}
