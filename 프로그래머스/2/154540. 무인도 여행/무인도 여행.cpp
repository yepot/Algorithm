#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool vis[101][101];

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    int n = maps.size();
    int m = maps[0].size();
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            
            if(maps[i][j] == 'X' || vis[i][j] == 1) continue;
            
            queue<pair<int, int>> q;
            q.push({i, j});
            vis[i][j] = 1;
            int cnt = maps[i][j] - '0';
            
            while(!q.empty()) {
                auto cur = q.front();
                q.pop();
                
                for(int idx=0; idx<4; idx++) {
                    int nx = cur.first + dx[idx];
                    int ny = cur.second + dy[idx];
                    
                    if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
                    if(maps[nx][ny] == 'X' || vis[nx][ny] == 1) continue;
                    
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                    cnt += maps[nx][ny] - '0';
                }
            }
            
            answer.push_back(cnt);
        }
    }
    if(answer.empty()) return {-1};
    sort(answer.begin(), answer.end());
    return answer;
}