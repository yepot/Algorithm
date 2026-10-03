#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

// 직선도로 100원, 코너 500원
// 최소 비용 구하기
int cost[30][30][4];
int vis[30][30] = {0, };
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0 ,-1};

int solution(vector<vector<int>> board) {
    
    int size = board.size();
    int answer = 1e9; //가장 큰 값으로 초기화!!
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
           for(int k=0; k<4; k++) {
               cost[i][j][k] = 1e9;
           }
        }
    }
    
    queue<tuple<int, int, int>> q; //도착 방향까지 저장해야 함!
    q.push({0, 0, -1});
    
    while(!q.empty()) {
        auto [x, y, dir] = q.front();
        q.pop();
        
        int curCost;
        if(dir == -1) curCost = 0;
        else curCost = cost[x][y][dir];
        
        for(int idx=0; idx<4; idx++) {
            int nx = x + dx[idx];
            int ny = y + dy[idx];
            
            if(nx<0 || nx>=size || ny<0 || ny>=size) continue;
            if(board[nx][ny]==1) continue;
            
            int nextCost = curCost + 100;
            if(dir!=-1 && dir!=idx) nextCost += 500;
            if(cost[nx][ny][idx] <= nextCost) continue;
            
            q.push({nx, ny, idx});
            cost[nx][ny][idx] = nextCost;
        }
    }
    
    for(int i=0; i<4; i++) {
        if(cost[size-1][size-1][i] < answer) answer = cost[size-1][size-1][i];
    }
    
    return answer;
}