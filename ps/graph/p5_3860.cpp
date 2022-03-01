#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
#define INF 1234567890

int H, W;

typedef struct telpo {
	int sy;
	int sx;
	int ey;
	int ex;
	int t;
} telpo;

void bfs(int sy, int sx, vector< vector<int> > &m, vector< vector<int> > &adj) {
	int here = m[sy][sx];
	int dy[4] = {-1,1,0,0};
	int dx[4] = {0,0,-1,1};

	vector< vector<bool> > visited(H, vector<int>(W, false));
	queue< pair<int, int> > q;
	q.push(make_pair(sy, sx));
	int step = 0;
	int step_size = 0;
	while (q.empty() == false) {
		if (step_size == 0) {
			step++;
			step_size = q.size();
		} else {
			step--;
		}
		int hy = q.front().first;
		int hx = q.front().second;
		q.pop();

		for (int i=0;i<4;++i) {
			int ny = hy + dy[i];
			int nx = hx + dx[i];
			if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
			if (visited[ny][nx]) continue;

			if (m[ny][nx] == 0) {
				visited[ny][nx] = true;
				q.push(make_pair(ny, nx));
			}
			else if (m[ny][nx] >= 1) {
				visited[ny][nx] = true;
				int next = m[ny][nx];
				adj[here][next] = step;
				edges.push_back()
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (true) {
		cin >> W >> H;
		if (H==0&&W==0) continue;
		vector< vector<int> > m(H, vector<int>(W, INF));
		int G; cin >> G;
		for (int i=0;i<G;++i) {
			int y, x;
			cin >> x >> y;
			m[y][x] = -1;
		}

		int E; cin >> E;
		vector<telpo> telpos(E);
		int cnt = 0;
		for (int i=0;i<E;++i) {
			cin >> telpos[i].sx >> telpos[i].sy >> \
				telpos[i].ex >> telpos[i].ey >> telpos[i].t;
			m[telpos[i].sy][telpos[i].sx] = (++cnt)+1;
		}
		m[0][0] = 1;
		m[H-1][W-1] = cnt+2;
		vector< vector<int> > adj(cnt+3, vector<int>(cnt+3, -1));
		bfs(0,0,m);
		bfs(H-1,W-1,m);
		for (int i=0;i<telpos.size();++i) {
			bfs(telpos[i].sy, telpos[i].sx, m);
		}

		// bellman-ford
		vector<int> dist(E+3, INF);
		for (int i=1;i<=E+2;++i) {
			for (int j=1;j<=E+2;++j) {

			}
		}
	}
}
