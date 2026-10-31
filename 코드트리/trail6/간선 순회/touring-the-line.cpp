#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> adj[50001];

pair<int, int> bfs(int start) {

    int dist[50001] = {0, };
    int edge[50001] = {0, };
    bool vis[50001] = {0, };

    queue<int> q;
    q.push(start);
    vis[start] = 1;

    int idx = start;
    int min_dist = 0;
    int max_edge = 0;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto [next, weight] : adj[cur]) {
            if(vis[next] == 1) continue;
            q.push(next);
            vis[next] = 1;
            dist[next] = dist[cur] + weight;
            edge[next] = edge[cur] + 1;
            if(edge[next] > max_edge || (edge[next] == max_edge && dist[next] < min_dist)) {
                max_edge = edge[next];
                min_dist = dist[next];
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

    pair<int, int> v1 = bfs(1);
    pair<int, int> v2 = bfs(v1.first);

    cout << (v2.second + D - 1) / D;
    return 0;
}