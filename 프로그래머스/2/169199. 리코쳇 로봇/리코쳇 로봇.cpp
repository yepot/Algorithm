#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<string> board) {
    int answer = 10001;

    int w = board[0].size();
    int h = board.size();
    
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    queue<pair<int, int>> q;
    bool vis[101][101] = {0, };
    int dist[101][101] = {0, };

    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            if(board[i][j] == 'R') {
                q.push({i, j});
                vis[i][j] = 1;
                break;
            }
        }
    }
    
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(int i=0; i<4; i++) {
            int d = 0;
            int nx = cur.first;
            int ny = cur.second;
            while(1) {
                nx += dx[i];
                ny += dy[i];
                
                // 항상 board 범위 내 인지 먼저 체크!!
                if(nx<0 || nx>=h || ny<0 || ny>=w || board[nx][ny] == 'D') {
                    nx -= dx[i];
                    ny -= dy[i];
                    if(vis[nx][ny] == 1) break;
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                    dist[nx][ny] = dist[cur.first][cur.second] + 1;
                    break;
                }
            }
            
            if(board[nx][ny] == 'G' && dist[nx][ny]<answer) {
                answer = dist[nx][ny];
            }
        }
    }
    if(answer == 10001) return -1;
    return answer;
}