#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1 ,0, -1};
int board[51][51];
bool vis[51][51];
queue<pair<int, int>> Q;
int n, m;

void bfs(int x, int y) {
    vis[x][y] = 1;
    Q.push({x, y});
    while(!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for(int i=0; i<4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(vis[nx][ny] || board[nx][ny]!=1) continue;
            vis[nx][ny] = true;
            Q.push({nx, ny});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    int k;
    while(t--) {

        for(int i=0; i<n; i++) {
            fill(board[i], board[i]+m, 0);
            fill(vis[i], vis[i]+m, false);
        }
        int x, y;
        int cnt = 0;
        cin >> m >> n >> k;
        for(int i=0; i<k; i++) {
            cin >> x >> y;
            board[y][x] = 1;
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j]==1 && !vis[i][j]) {
                    bfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
}