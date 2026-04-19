#include<vector>
#include<queue>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dist[105][105];

int solution(vector<vector<int> > maps)
{
    int m = maps.size();
    int n = maps[0].size();
    int answer = 0;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            dist[i][j] = -1;
        }
    }
    
    queue<pair<int, int>> Q;
    Q.push({0, 0});
    dist[0][0]=1;
    
    while(!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        
        for(int i=0; i<4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx<0 || nx >=m || ny<0 || ny>=n) continue;
            if(dist[nx][ny]>=0 || !maps[nx][ny]) continue;
            dist[nx][ny] = dist[cur.first][cur.second]+1;
            Q.push({nx, ny});
        }
    }
    answer = dist[m-1][n-1];
    return answer;
}