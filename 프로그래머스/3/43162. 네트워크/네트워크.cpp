#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    bool vis[205] = {};
    
    for(int i=0; i<n; i++) {
        if(vis[i]) continue;
        
        answer++;
        queue<int> Q;
        Q.push(i);
        vis[i] = 1;
        
        while(!Q.empty()) {
            auto cur = Q.front();
            Q.pop();
            
            for(int j=0; j<n; j++) {
                if(computers[cur][j]!=1 || vis[j]) continue;
                vis[j] = 1;
                Q.push(j);
            }
        }
    }
    return answer;
}