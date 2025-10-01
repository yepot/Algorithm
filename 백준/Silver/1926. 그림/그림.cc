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
	int board[501][501];
	bool vis[501][501];
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> board[i][j];
		}
	}

	int mx = 0;
	int cnt = 0;

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(board[i][j]==0 || vis[i][j]) continue;
			cnt++;

			queue<pair<int, int>> Q;
			vis[i][j] = 1;
			Q.push({i, j});
			int area = 0;

			while(!Q.empty()) {
				pair<int, int> cur = Q.front();
				Q.pop();
				area++;

				for(int i=0; i<4; i++) {
					int nx = cur.first + dx[i];
					int ny = cur.second + dy[i];
					if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
					if(vis[nx][ny] || board[nx][ny]!=1) continue;
					vis[nx][ny]=1;
					Q.push({nx, ny});
				}
			}
			mx = max(mx, area);
		}
	}
	cout << cnt << '\n' << mx;
}