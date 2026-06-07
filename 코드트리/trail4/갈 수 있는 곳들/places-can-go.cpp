#include <iostream>
#include <queue>
using namespace std;

int n, k;
int board[101][101];
bool vis[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    // Please write your code here.
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> board[i][j];
        }
    }

    int cnt = 0;
    for(int i=0; i<k; i++) {
        int x, y;
        cin >> x >> y;
        if(vis[x-1][y-1]!=1) cnt++;
        
        queue<pair<int, int>> Q;
        Q.push({x-1, y-1});
        vis[x-1][y-1] = 1;

        while(!Q.empty()) {
            auto cur = Q.front();
            Q.pop();
            for(int j=0; j<4; j++) {
                int nx = cur.first + dx[j];
                int ny = cur.second + dy[j];
                if(nx<0 || nx>=n || ny <0 || ny>=n) continue;
                if(vis[nx][ny]==1 || board[nx][ny]==1) continue;
                cnt++;
                vis[nx][ny] = 1;
                Q.push({nx, ny});
            }
        }
    }
    cout << cnt;
    return 0;
}