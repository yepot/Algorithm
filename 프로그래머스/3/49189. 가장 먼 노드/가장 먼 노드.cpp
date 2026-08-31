#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<int> adj[n+1];
    for(int i=0; i<edge.size(); i++) {
        adj[edge[i][0]].push_back(edge[i][1]);
        adj[edge[i][1]].push_back(edge[i][0]);
    }
    
    queue<int> q;
    int dist[20001];
    fill(dist, dist+n+1, -1); // 1~n 이므로 n+1 까지인 거 주의!
    
    q.push(1);
    dist[1] = 0;
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for(auto next : adj[cur]) {
            if(dist[next] != -1) continue;
            q.push(next);
            dist[next] = dist[cur] + 1;
        }
    }
    
    int max = 0;
    for(int i=1; i<=n; i++) {
        if(dist[i] > max) max = dist[i];
    }
    
    for(int i=0; i<=n; i++) {
        if(dist[i] == max) answer++;
    }
    
    return answer;
}