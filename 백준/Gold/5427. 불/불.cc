#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, w, h;
    cin >> t;
    for(int i=0; i<t; i++) {
        cin >> w >> h;
        char board[1001][1001]={};
        bool vis[1001][1001]={};

        queue<pair<int, int>> fireQ;
        queue<pair<int, int>> personQ;

        for(int j=0; j<h; j++) {
            for(int k=0; k<w; k++) {
                cin >> board[j][k];
                if(board[j][k]=='*') {
                    fireQ.push({j, k});
                }
                if(board[j][k]=='@') {
                    personQ.push({j, k});
                    vis[j][k]=1;
                }
            }
        }

        int time = 0;
        bool escaped = false;
        
        while(!personQ.empty() && !escaped) {
            time++;

            // 불 확산
            // 현재 큐에 있는 불들만 처리
            int fireSize = fireQ.size();
            while(fireSize--) {
                auto cur = fireQ.front();
                fireQ.pop();

                for(int dir=0; dir<4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                                
                    if(nx<0 || nx>=h || ny<0 || ny>=w) continue;
                    if(board[nx][ny]=='#' || board[nx][ny]=='*') continue; //사람이있는자리도 불이 올 수 있음!
                                
                    board[nx][ny] = '*';
                    fireQ.push({nx, ny});
                }
            }

            // 사람 이동
            // 현재 큐에 있는 사람위치만 처리
            int personSize = personQ.size();
            while(personSize--) {
                auto cur = personQ.front();
                personQ.pop();

                for(int dir=0; dir<4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if(nx<0 || nx>=h || ny<0 || ny>=w) {
                        cout << time << '\n';
                        escaped=true;
                        break;
                    }

                    if(board[nx][ny]=='*' || board[nx][ny]=='#') continue;
                    if(vis[nx][ny]) continue;

                    vis[nx][ny]=1;
                    personQ.push({nx, ny});
                }
                if(escaped) break;
            }
        }
        if(!escaped) cout << "IMPOSSIBLE" << '\n';
    }
}