#include <iostream>
#include <algorithm>
#include <vector>
#include <queue> 

using namespace std;

vector<pair<int, int>> adj[20005];
int dist[20005] = {0, }; // k(시작점) 에서 i까지의 최단거리
const int INF = 1e9;

void dijkstra(int start) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, start}); // 거리, 정점번호
    dist[start] = 0;

    while(!pq.empty()) {
        auto [cost, cur] = pq.top();
        pq.pop();

        if(cost > dist[cur]) continue;

        for(auto [next, weight] : adj[cur]) {
            if(dist[cur] + weight < dist[next]) {
                dist[next] = dist[cur] + weight;
                pq.push({dist[next], next});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int v, e, k;
    cin >> v >> e;
    cin >> k;

    for(int i=0; i<=v; i++) {
        dist[i] = INF;
    }

    int a, b, w;
    for(int i=0; i<e; i++) {
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }

    dijkstra(k);

    for(int i=1; i<=v; i++) {
        if(dist[i] == INF) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }

    return 0;
}