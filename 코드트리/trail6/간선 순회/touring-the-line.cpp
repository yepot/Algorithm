#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, int>> adj[50005];

// 지나는 간선은 최대로, weight는 최소로
pair<int, int> bfs(int start) {
    bool vis[50005] = {0, };
    int dist[50005] = {0, };
    int edge[50005] = {0, };

    int max_edge = -1;
    int min_dist = -1;
    int idx = start;

    queue<int> q;
    q.push(start);
    vis[start] = 1;
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto [next, weight] : adj[cur]) {
            if(vis[next] == 1) continue;
            q.push(next);
            vis[next] = 1;
            edge[next] = edge[cur] + 1;
            dist[next] = dist[cur] + weight;
            // 여기 주의!!
            // 간선 수가 더 많거나, 간선 수가 같으면서 가중치 합이 더 작으면 갱신
            if(edge[next] > max_edge || (edge[next] == max_edge && dist[next] < min_dist)) {
                min_dist = dist[next];
                max_edge = edge[next];
                idx = next;
            }
            
        }
    }

    return {idx, min_dist};
}

int main() {
    // Please write your code here.
    int N, D;
    cin >> N >> D;

    int a, b, w;
    for(int i=0; i<N-1; i++) {
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    auto n1 = bfs(1);
    auto n2 = bfs(n1.first);

    cout << (n2.second + D - 1) / D;

    return 0;
}