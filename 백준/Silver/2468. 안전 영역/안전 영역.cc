#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define X first
#define Y second
int board[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int max = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> board[i][j];
            if(board[i][j]>max) max = board[i][j];
        }
    }

    int result = 0;
    for(int i=max; i>=0; i--) {
        //물에 잠긴 부분은 board에서 0으로->arr
        int arr[101][101];
        for(int j=0; j<n; j++) {
            for(int k=0; k<n; k++) {
                if(board[j][k]<=i) arr[j][k] = 0;
                else arr[j][k] = 1;
            }
        }
        int cnt = 0;

        queue<pair<int, int>> Q;
        bool vis[101][101]={}; //{}해야지 배열 초기화!!

        for(int j=0; j<n; j++) {
            for(int k=0; k<n; k++) {
                if(vis[j][k]==0 && arr[j][k]==1) {
                    cnt++;
                    vis[j][k] = 1;
                    Q.push({j, k});

                    while(!Q.empty()) {
                        auto cur = Q.front();
                        Q.pop();
                        for(int l=0; l<4; l++) {
                            int nx = cur.X + dx[l];
                            int ny = cur.Y + dy[l];
                            if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
                            if(vis[nx][ny]==1 || arr[nx][ny]==0) continue;
                            vis[nx][ny] = 1;
                            Q.push({nx, ny});
                        }
                    }            
                }
            }
        }
        if(cnt>result) result = cnt;
    }
    cout << result;
}