#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 방향 그래프
// 누적으로 하자
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    int rank[101] = {0,};
    vector<int> adj[101];
    
    // 그래프 만들기
    for(int i=0; i<results.size(); i++) {
        adj[results[i][0]].push_back(results[i][1]);
    }
    
    // 순회하면서 타고타고 누적
    for(int i=1; i<=n; i++) {
        queue<int> q;
        bool vis[101] = {0, };
        q.push(i);
        vis[i] = 1;
        
        while(!q.empty()) {
            int cur = q.front();
            q.pop();

            for(auto next : adj[cur]) {
                if(vis[next]) continue;
                q.push(next);
                vis[next] = 1;
                rank[next]++; // i에게 진 수
                rank[i]++; // i가 이긴 수
            }
        }
    }
    
    for(int i=1; i<=n; i++) {
        if(rank[i] == n-1) answer++;
    }
    
    return answer;
}