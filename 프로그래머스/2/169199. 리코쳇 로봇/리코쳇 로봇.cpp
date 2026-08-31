#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dist[101][101];

int solution(vector<string> board) {
    int answer = 0;
    
    int n = board.size();
    int m = board[0].size();
    int x, y;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(board[i][j] == 'R') {
                x = i;
                y = j;
                break;
            }
        }
    }
    
    queue<pair<int, int>> q;
    q.push({x, y});
    dist[x][y] = 0;
    int cnt;
    
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = cur.first;
            int ny = cur.second;

            while(1) {
                nx += dx[i];
                ny += dy[i];

                if(nx<0 || nx>=n || ny<0 || ny>=m || board[nx][ny]=='D') break;
            }
            nx -= dx[i];
            ny -= dy[i];

            // 출발 위치와 멈춘 위치가 같거나 이미 방문했다면 넘어감 -> 주의!!
            if(nx==cur.first && ny==cur.second) continue;
            if(dist[nx][ny] != 0) continue;

            dist[nx][ny] = dist[cur.first][cur.second] + 1;

            if (board[nx][ny] == 'G') {
                return dist[nx][ny];
            }
            q.push({nx, ny});
        }
    }
    
    if(answer == 0) return -1;
}