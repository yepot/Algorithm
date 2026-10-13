#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> adj[100001];
int next_node;

int dfs(int start) {
    int vis[100001] = {0, };
    int dist[100001] {0, };
    int dist_max = 0;

    stack<int> s;
    s.push(start);
    vis[start] = 1;

    while(!s.empty()) {
        auto cur = s.top();
        s.pop();
        
        for(auto [next, weight] : adj[cur]) {
            if(vis[next]) continue;
            s.push(next);
            vis[next] = 1;
            dist[next] = dist[cur] + weight;
            if(dist[next] > dist_max) {
                dist_max = dist[next];
                next_node = next;
            }
        }
    }

    return dist_max;

}

int main() {
    // Please write your code here.
    cin >> N;
    for(int i=0; i<N-1; i++) {
        int u, v ,w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dfs(1);
    cout << dfs(next_node);
    
    return 0;
}