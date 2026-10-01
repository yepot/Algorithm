#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(pair<int, int> start, pair<int, int> end, vector<string>& maps) {
    
    int w = maps[0].size();
    int h = maps.size();
    int dist[101][101] = {0, };
    bool vis[101][101] = {0, };
    
    queue<pair<int, int>> q;
    q.push({start.first, start.second});
    vis[start.first][start.second] = 1;
    
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(int idx=0; idx<4; idx++) {
            int nx = cur.first + dx[idx];
            int ny = cur.second + dy[idx];
            
            if(nx<0 || nx>=h || ny<0 || ny>=w) continue;
            if(maps[nx][ny] == 'X' || vis[nx][ny] == 1) continue;
            
            q.push({nx, ny});
            vis[nx][ny] = 1;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            
            if(nx==end.first && ny==end.second) return dist[nx][ny];
        }
    }
    
    return 0;
    
}

int solution(vector<string> maps) {
    
    pair<int, int> start, lever, end;
    
    for(int i=0; i<maps.size(); i++) {
        for(int j=0; j<maps[0].size(); j++) {
            if(maps[i][j] == 'L') lever = {i, j};
            if(maps[i][j] == 'S') start = {i, j};
            if(maps[i][j] == 'E') end = {i ,j};
        }
    }
    
    if(bfs(start, lever, maps)==0 || bfs(lever, end, maps)==0) return -1;
    else {
        return bfs(start, lever, maps) + bfs(lever, end, maps);
    }

}