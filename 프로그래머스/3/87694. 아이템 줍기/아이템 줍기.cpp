#include <string>
#include <vector>
#include <queue>

using namespace std;

// 1. 좌표를 2배로 확대
// 2. 모든 사각형을 먼저 채운 뒤 내부만 제거
// 3. 최종 거리를 2로 나눠 반환

int board[102][102];
bool vis[102][102];
int dist[102][102];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    // 모든 좌표 2배
    for (int i=0; i<rectangle.size(); i++) {
        for (int j=0; j<4; j++) {
            rectangle[i][j] *= 2;
        }
    }

    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;
    
    // 모든 사각형 영역 채우기
    for (int i=0; i<rectangle.size(); i++) {
        for (int x=rectangle[i][0]; x<=rectangle[i][2]; x++) {
            for (int y=rectangle[i][1]; y<=rectangle[i][3]; y++) {
                board[x][y] = 1;
            }
        }
    }

    // 사각형 내부 제거
    // 테두리는 남겨야 하므로 +1부터 < 끝 좌표까지
    for (int i=0; i<rectangle.size(); i++) {
        for (int x=rectangle[i][0]+1; x<rectangle[i][2]; x++) {
            for (int y=rectangle[i][1]+1; y<rectangle[i][3]; y++) {
                board[x][y] = 0;
            }
        }
    }
    
    queue<pair<int, int>> Q;

    vis[characterX][characterY] = true;
    Q.push({characterX, characterY});
    dist[characterX][characterY] = 0;

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        if (cur.first==itemX && cur.second==itemY) {
            return dist[cur.first][cur.second]/2;
        }

        for (int idx=0; idx<4; idx++) {
            int nx = cur.first+dx[idx];
            int ny = cur.second+dy[idx];

            if (nx<0 || nx>=102 || ny<0 || ny>=102) continue;
            if (!board[nx][ny] || vis[nx][ny]) continue;

            vis[nx][ny] = true;
            dist[nx][ny] = dist[cur.first][cur.second]+1;
            Q.push({nx, ny});
        }
    }
    
    
    return answer;
}