#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int board[101][101] = {0, };
bool vis[101][101] = {0, };
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0 , -1};

int main() {
    // Please write your code here.
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
        }
    }
    
    queue<pair<int, int>> Q;
    Q.push({0, 0});
    vis[0][0] = 1;

    while(!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for(int i=0; i<4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(vis[nx][ny]==1 || board[nx][ny]==0) continue;
            vis[nx][ny] = 1;
            Q.push({nx, ny});
            if(nx==n-1 && ny==m-1) {
                cout << 1;
                return 0;
            }
        }
    }

    cout << 0;
    return 0;
}