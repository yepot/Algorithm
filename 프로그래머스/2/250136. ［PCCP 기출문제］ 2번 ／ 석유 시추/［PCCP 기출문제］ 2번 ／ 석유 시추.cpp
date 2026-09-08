#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int vis[501][501] = {0, };
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int solution(vector<vector<int>> land) {
    int answer = 0;
    
    int w = land[0].size();
    int h = land.size();
    
    int pipe[501] = {0, };
    
    
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            if(vis[i][j]==1 || land[i][j]==0) continue;
            
            queue<pair<int, int>> q;
            q.push({i, j});
            vis[i][j] = 1;
            
            unordered_set<int> s;
            int cnt = 1;
            s.insert(j);
            
            while(!q.empty()) {
                auto cur = q.front();
                q.pop();
                for(int idx=0; idx<4; idx++) {
                    int nx = cur.first + dx[idx];
                    int ny = cur.second + dy[idx];
                    
                    // nx, ny 범위를 먼저 확인해야돼!!!
                    if(nx<0 || nx>=h || ny<0 || ny>=w) continue;
                    if(vis[nx][ny]==1 || land[nx][ny]==0) continue;
                    
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                    
                    s.insert(ny);
                    cnt++;
                }
            }
            
            for(auto col : s) {
                pipe[col] += cnt;
            }
            
        }
    }
    
    for(int i=0; i<w; i++) {
        if(pipe[i] > answer) answer = pipe[i];
    }
    
    return answer;
}