#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer = -1;
int minCnt = 1000000;
int vis[1000001];

void dfs(int x, int y, int n, int cnt) {
    
    if(x > y) return;
    if(cnt >= minCnt) return;
    if(vis[x] <= cnt) return;
    
    vis[x] = cnt;
    
    if(x == y) {
        answer = cnt;
        minCnt = cnt;
        return;
    }
    
    dfs(x+n, y, n, cnt+1);
    dfs(x*2, y, n, cnt+1);
    dfs(x*3, y, n, cnt+1);
}

int solution(int x, int y, int n) {  
    
    fill(vis, vis + 1000001, 1000000);
    dfs(x, y, n, 0);
    
    return answer;
}