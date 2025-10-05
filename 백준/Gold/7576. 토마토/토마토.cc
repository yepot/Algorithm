#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int board[1001][1001];
int dist[1001][1001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> m >> n;
    queue<pair<int, int>> Q;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
            if(board[i][j]==1) Q.push({i, j});
            else if(board[i][j]==0) dist[i][j] = -1;
        }
    }

    while(!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for(int i=0; i<4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx<0 || nx >=n || ny<0 || ny >=m) continue;
            if(dist[nx][ny]>=0) continue;
            dist[nx][ny] = dist[cur.first][cur.second]+1;
            Q.push({nx, ny});
        }
    }
    int result = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(dist[i][j]==-1) {
                cout << -1;
                return 0;
            }
            result = max(result, dist[i][j]);
        }
    }
    cout << result << '\n';
}