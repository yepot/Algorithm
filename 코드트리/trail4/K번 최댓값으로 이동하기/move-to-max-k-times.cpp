#include <iostream>
#include <queue>
using namespace std;

int n, k;
int r, c;
int board[101][101];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int main() {
    // Please write your code here.
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> board[i][j];
        }
    }
    cin >> r >> c;
    int curX = r-1;
    int curY = c-1;
    int tmpX;
    int tmpY;
    for(int h=0; h<k; h++) {
        int max = -1;
        int tmpX = curX;
        int tmpY = curY;

        bool vis[101][101] = {0, };

        queue<pair<int, int>> Q;
        Q.push({curX, curY});
        vis[curX][curY] = 1;
        
        while(!Q.empty()) {
            auto cur = Q.front();
            Q.pop();

            for(int i=0; i<4; i++) {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];

                if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
                if(vis[nx][ny]==1) continue;
                if(board[nx][ny] >= board[curX][curY]) continue;

                Q.push({nx, ny});
                vis[nx][ny] = 1;

                if(board[nx][ny] > max) {
                    max = board[nx][ny];
                    tmpX = nx;
                    tmpY = ny;
                }
                else if(board[nx][ny] == max) {
                    if(nx<tmpX || (nx==tmpX && ny<tmpY)) {
                        tmpX = nx;
                        tmpY = ny;
                    }
                }
            }
        }

        if(tmpX==curX && tmpY==curY) break;

        curX = tmpX;
        curY = tmpY;
    }
    cout << curX+1 << " " << curY+1;
    return 0;
}