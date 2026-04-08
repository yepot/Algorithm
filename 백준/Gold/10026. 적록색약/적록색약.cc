#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define X first
#define Y second
char board[101][101];
bool vis[101][101];
int n;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int i, int j) {
    queue<pair<int, int>> q;
    vis[i][j] = 1;
    q.push({i, j});

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(int k=0; k<4; k++) {
            int nx = cur.X + dx[k];
            int ny = cur.Y + dy[k];
            if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
            if(vis[nx][ny]==1 || board[nx][ny]!=board[cur.X][cur.Y]) continue;
            vis[nx][ny]=1;
            q.push({nx, ny});
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // R/G/B 그리고 R,G/B
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> board[i][j];
        }
    }

    int num = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(vis[i][j]) continue;
            num++;
            bfs(i, j);
        }
    }
    cout << num << ' ';

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(board[i][j]=='R') board[i][j]='G';
        }
    }

    num = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            vis[i][j] = false;
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(vis[i][j]) continue;
            num++;
            bfs(i, j);
        }
    }
    cout << num;

}