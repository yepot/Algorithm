#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 0;
bool visited[8];

// dfs + 백트래킹
void dfs(int cur, int cnt, const vector<vector<int>>& dungeons) {
     
    answer = max(answer, cnt);
    
    for(int i=0; i<dungeons.size(); i++) {
        if(visited[i]) continue;
        if(cur < dungeons[i][0]) continue;
        
        visited[i] = 1;
        dfs(cur-dungeons[i][1], cnt+1, dungeons);
        visited[i] = 0;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    
    dfs(k, 0, dungeons);
    return answer;
}