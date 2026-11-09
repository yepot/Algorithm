#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<vector<int> > maps) {
    int answer = -1;
    
    int h = maps.size();
    int w = maps[0].size();
    
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int dist[105][105];
    bool vis[105][105] = {0, };
    
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            dist[i][j] = 1000000000;
        }
    }
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    vis[0][0] = 1;
    dist[0][0] = 1;
    
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(int idx=0; idx<4; idx++) {
            int nx = cur.first + dx[idx];
            int ny = cur.second + dy[idx];
            if(nx<0 || nx>=h || ny<0 || ny>=w) continue;
            if(vis[nx][ny] || maps[nx][ny]==0) continue;
            q.push({nx, ny});
            vis[nx][ny] = 1;
            dist[nx][ny] = min(dist[nx][ny], dist[cur.first][cur.second] + 1);
            if(nx == h-1 && ny == w-1) answer = dist[nx][ny];
        }
    }
    
    return answer;
}