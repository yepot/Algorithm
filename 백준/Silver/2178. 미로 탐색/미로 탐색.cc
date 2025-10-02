#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	string board[501];
	int dist[501][501];
	for(int i=0; i<n; i++) {
		cin >> board[i];
		for(int j=0; j<m; j++) {
			dist[i][j] = -1;
		}
	}

	queue<pair<int, int>> Q;
	Q.push({0, 0});
	dist[0][0] = 0;
	while(!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();

		for(int i=0; i<4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
			if(dist[nx][ny]>=0 || board[nx][ny]!='1') continue;
			dist[nx][ny] = dist[cur.first][cur.second]+1;
			Q.push({nx, ny});
		}
	}
	cout << dist[n-1][m-1]+1 << '\n';
}