#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    
    vector<int> adj[100001];
    for(int i=0; i<roads.size(); i++) {
        adj[roads[i][0]].push_back(roads[i][1]);
        adj[roads[i][1]].push_back(roads[i][0]);
    }
    
    for(int i=0; i<sources.size(); i++) {
        bool vis[100001] = {0, };
        queue<int> q;
        int dist[100001] = {0, };
        q.push(sources[i]);
        vis[sources[i]] = 1;
        int dmin = n+1;
        
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            
            if(cur == destination && dist[cur] < dmin) {
                dmin = dist[cur];
                break;
            }
            
            for(auto next : adj[cur]) {
                if(vis[next]) continue;
                q.push(next);
                vis[next] = 1;
                dist[next] = dist[cur] + 1;
            }
        }
        if(dmin == n+1) answer.push_back(-1);
        else answer.push_back(dmin);
    }
    
    
    return answer;
}