#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
using namespace std;

typedef struct Node
{
	int x;
	int y;
	int c;
}				Node;

Node make_node(int _x, int _y, int _c)
{
	Node new_node;

	new_node.x = _x;
	new_node.y = _y;
	new_node.c = _c;
	return (new_node);
}

struct customCMP
{
	bool operator()(const Node &a, const Node &b) {return a.c > b.c;}
};

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int main(void)
{
	cin.tie(0);
	int N; cin >> N;
	vector< vector<int> > m(N, vector<int>(N));
	vector< vector<int> > dist(N, vector<int>(N, 10001));
	priority_queue<Node, vector<Node>, customCMP> q;

		string str;
	for (int j=0; j<N;++j)
	{
		cin >> str;
		for (int k=0;k<N;++k)
		{
			m[j][k] = str[k] == '1' ? 0 : 1;
		}
	}

	q.push(make_node(0,0,0));
	int i,x,y,c,nx,ny,nc;
	dist[0][0] = 0;

	while (!q.empty())
	{
		x = q.top().x;
		y = q.top().y;
		c = q.top().c;
		q.pop();
		//cout << x << " " << y << " " << c << endl;
		if (dist[y][x] < c) continue;
		for (i=0;i<4;++i)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				continue;
			nc = c + m[ny][nx];
			if (nc < dist[ny][nx])
			{
				dist[ny][nx] = nc;
				//cout << "n: " << nx << " " << ny << " " << nc << endl;
				q.push(make_node(nx,ny,nc));
			}
		}
	}
	cout << dist[N-1][N-1] << "\n";
	return (0);
}
